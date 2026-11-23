"""Build and test independent C11 programs. Run from any working directory."""
import argparse
import hashlib
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
import json
import os
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parent.parent
DATA = Path(__file__).resolve().parent

def normalized(data):
    # Windows text streams use CRLF. Accept exactly one optional final newline.
    return data.replace(b"\r\n", b"\n").removesuffix(b"\n")

def run_case(exe, case):
    with tempfile.TemporaryDirectory() as directory:
        cwd = Path(directory)
        for name, content in case.get("files", {}).items():
            (cwd / name).write_bytes(content.encode())
        try:
            run = subprocess.run([str(exe)], cwd=cwd, input=case["input"].encode(),
                                 capture_output=True, timeout=5)
            checks = {"stdout": (case["output"].encode(), run.stdout)}
            for name, content in case.get("writes", {}).items():
                path = cwd / name
                checks[name] = (content.encode(), path.read_bytes() if path.is_file() else None)
            for name, content in case.get("bytes_written", {}).items():
                path = cwd / name
                checks[name] = (bytes.fromhex(content), path.read_bytes() if path.is_file() else None)
            differences = {}
            for name, (expected, actual) in checks.items():
                binary = name in case.get("bytes_written", {})
                if actual is None or (expected != actual if binary else normalized(expected) != normalized(actual)):
                    differences[name] = {"expected": expected.hex() if binary else expected.decode(),
                                         "actual": None if actual is None else
                                         (actual.hex() if binary else actual.decode(errors="replace"))}
            status = "failed" if run.returncode or differences else "passed"
            return dict(status=status, exit=run.returncode, differences=differences)
        except subprocess.TimeoutExpired:
            return dict(status="failed", error="Execution timed out")
        except OSError as exc:
            return dict(status="untested", error=str(exc))

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--cc", default="gcc")
    parser.add_argument("--through", type=int, choices=range(1, 97), default=96, metavar="DAY")
    parser.add_argument("--report", type=Path)
    args = parser.parse_args()
    bank = json.loads((DATA / "questions.json").read_text(encoding="utf-8"))
    extra = json.loads((DATA / "cases.json").read_text(encoding="utf-8"))
    assert [q["id"] for q in bank] == list(range(1, 147))
    compiler = subprocess.check_output([args.cc, "--version"], text=True).splitlines()[0]
    with tempfile.TemporaryDirectory() as build:
        def verify(q):
            number, day = q["id"], q["day"]
            source = ROOT / f"Day{day:02d}" / f"Question_{number}.c"
            exe = Path(build) / (f"q{number}" + (".exe" if os.name == "nt" else ""))
            assert source.read_text(encoding="utf-8").startswith("/*\n" + q["text"] + "\n*/")
            cmd = [args.cc, "-std=c11", "-Wall", "-Wextra", "-pedantic", str(source), "-o", str(exe), "-lm"]
            built = subprocess.run(cmd, capture_output=True, timeout=120)
            clean = built.returncode == 0 and not built.stderr
            row = dict(id=number, day=day, compiled=built.returncode == 0, clean=clean,
                       sha256=hashlib.sha256(source.read_bytes().replace(b"\r\n", b"\n")).hexdigest(),
                       diagnostics=built.stderr.decode(errors="replace"), cases=[])
            settings = extra.get(str(number), {})
            for group, cases in [("sample", q["testCases"]), ("extra", settings.get("extra", []))]:
                for i, original in enumerate(cases, 1):
                    adapter = settings.get("samples", {}).get(str(i), {}) if group == "sample" else {}
                    case = original | adapter
                    if not clean:
                        result = dict(status="untested", reason="Compilation diagnostics")
                    elif "uncheckable" in case:
                        # Attempt the literal example too, retaining the transcript.
                        result = run_case(exe, case)
                        result.update(status="untested", reason=case["uncheckable"])
                    else:
                        result = run_case(exe, case)
                    row["cases"].append(dict(group=group, index=i, **result))
            return row
        questions = [q for q in bank if q["day"] <= args.through]
        with ThreadPoolExecutor(max_workers=4) as pool:
            rows = list(pool.map(verify, questions))
    checkpoints = []
    for day in [*range(10, args.through + 1, 10), args.through]:
        if checkpoints and checkpoints[-1]["day"] == day:
            continue
        subset = [r for r in rows if r["day"] <= day]
        counts = Counter((c["group"], c["status"]) for r in subset for c in r["cases"])
        checkpoints.append(dict(day=day, programs=len(subset), clean=sum(r["clean"] for r in subset),
                                **{"_".join(k): v for k, v in sorted(counts.items())}))
    result = dict(compiler=compiler, checkpoints=checkpoints, programs=rows)
    if args.report:
        args.report.write_text(json.dumps(result, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(json.dumps(checkpoints[-1]))
    for row in rows:
        if not row["clean"]:
            print("Compiler diagnostics", row["id"], row["diagnostics"])
        for case in row["cases"]:
            if case["status"] != "passed":
                print(row["id"], json.dumps(case, ensure_ascii=True))
    return int(any(not r["clean"] or any(c["status"] != "passed" for c in r["cases"]) for r in rows))

if __name__ == "__main__":
    raise SystemExit(main())

"""Audit the published layout and simulated history from a complete Git clone."""
import hashlib
import json
import re
import subprocess
from datetime import date, datetime, timedelta, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
BASE = "08f5146112fbe02b1f4db54edb5de94088717711"
IST = timezone(timedelta(hours=5, minutes=30))
def git(*args):
    return subprocess.check_output(["git", "-C", str(ROOT), *args], encoding="utf-8").rstrip("\n")

def require(ok, message):
    if not ok:
        raise SystemExit(message)

def schedule(day):
    weeks, weekday = divmod(day - 1, 5)
    when = date(2026, 7, 13) + timedelta(days=7 * weeks + weekday)
    minutes = 600 + (137 * day + 41) % 601
    return datetime(when.year, when.month, when.day, minutes // 60, minutes % 60, tzinfo=IST)

def ids_for(day):
    return [2 * day - 1, 2 * day] if day <= 50 else [day + 50]

def subject(day):
    ids = ids_for(day)
    label = f"Questions {ids[0]} and {ids[1]}" if len(ids) == 2 else f"Question {ids[0]}"
    return f"Day {day:02d}: Complete {label}"

def main():
    require(git("status", "--porcelain") == "", "Working tree has local changes")
    require(git("merge-base", BASE, "HEAD") == BASE, "Original destination history missing")
    commits = git("rev-list", "--first-parent", "--reverse", BASE + "..HEAD").splitlines()
    require(len(commits) == 96, "Expected 96 daily commits")
    author = git("show", "-s", "--format=%an%x09%ae", BASE)
    require(author.split("\t")[0] == "student-kunal", "Unexpected base identity")
    question_path = ROOT / "verification" / "questions.json"
    bank = json.loads(question_path.read_text(encoding="utf-8"))
    report = json.loads((question_path.parent / "results.json").read_text(encoding="utf-8"))
    fixtures = json.loads((question_path.parent / "cases.json").read_text(encoding="utf-8"))
    expected_samples = [("failed", 4, 1), ("failed", 9, 2), ("failed", 44, 1),
                        ("failed", 45, 1), ("failed", 45, 2), ("failed", 50, 2),
                        ("failed", 52, 1), ("failed", 54, 1), ("failed", 120, 1),
                        ("failed", 123, 1), ("untested", 126, 1), ("untested", 142, 1)]
    observed = []
    require([q["id"] for q in bank] == list(range(1, 147)), "Question bank mismatch")
    require([q["id"] for q in report["programs"]] == list(range(1, 147)), "Report coverage mismatch")
    days = {p.name for p in ROOT.iterdir() if p.is_dir() and p.name.lower().startswith("day")}
    require(days == {f"Day{d:02d}" for d in range(1, 97)}, "Day folders mismatch")
    parent = BASE
    all_sources = set()
    for day, commit in enumerate(commits, 1):
        timestamp = schedule(day).isoformat()
        meta = git("show", "-s", "--format=%P%n%aI%n%cI%n%an%x09%ae%n%cn%x09%ce%n%s", commit).splitlines()
        require(meta == [parent, timestamp, timestamp, author, author, subject(day)], f"Day {day} metadata mismatch")
        changes = set(git("diff", "--name-only", parent, commit).splitlines())
        programs = {f"Day{day:02d}/Question_{i}.c" for i in ids_for(day)}
        expected = set(programs)
        if day == 1:
            expected.update([".gitignore", ".gitattributes", "README.md"])
            require("simulated" in git("show", commit + ":README.md").lower(), "Day 01 disclosure missing")
        if day == 96:
            expected.update(["README.md"] + git("ls-tree", "-r", "--name-only", "HEAD", "verification/").splitlines())
        require(expected == changes, f"Unexpected files changed on Day {day}")
        for i in ids_for(day):
            q, row = bank[i - 1], report["programs"][i - 1]
            path = ROOT / f"Day{day:02d}/Question_{i}.c"
            data = path.read_bytes().replace(b"\r\n", b"\n")
            require(data.decode().startswith("/*\n" + q["text"] + "\n*/"), f"Q{i} statement mismatch")
            require(q["day"] == day and row["day"] == day and row["clean"] and row["compiled"]
                    and hashlib.sha256(data).hexdigest() == row["sha256"], f"Q{i} build evidence mismatch")
            samples = [c for c in row["cases"] if c["group"] == "sample"]
            extra = [c for c in row["cases"] if c["group"] == "extra"]
            require([c["index"] for c in samples] == list(range(1, len(q["testCases"]) + 1)), f"Q{i} sample coverage")
            require(len(extra) == len(fixtures[str(i)]["extra"]) and extra
                    and all(c["status"] == "passed" for c in extra), f"Q{i} additional cases")
            observed.extend((c["status"], i, c["index"]) for c in samples if c["status"] != "passed")
        all_sources.update(programs)
        parent = commit
    require(sorted(expected_samples) == sorted(observed), "Sample discrepancies differ from the reviewed report")
    require(all_sources == {p.relative_to(ROOT).as_posix() for p in ROOT.rglob("*.c")}, "C file inventory mismatch")
    readme = (ROOT / "README.md").read_text(encoding="utf-8")
    links = re.findall(r"\[[^\]\n]*\]\(([^)\n]+)\)", readme)
    require(all_sources == {link for link in links if link.endswith(".c")}, "Program link coverage mismatch")
    for doc in [ROOT / "README.md", ROOT / "verification" / "REPORT.md"]:
        for target in re.findall(r"\[[^\]\n]*\]\(([^)\n]+)\)", doc.read_text(encoding="utf-8")):
            if not target.startswith(("https://", "#")):
                require((doc.parent / target).is_file(), f"Broken link in {doc.name}: {target}")
    tracked = set(git("ls-files").splitlines())
    require(not any(Path(p).suffix.lower() in {".exe", ".o", ".obj", ".pyc", ".zip"} for p in tracked), "Build artifact tracked")
    require(git("status", "--porcelain") == "", "Audit left unexpected changes")
    print("Verified 96 daily commits, both IST timestamps, authors, file changes, 146 source hashes and README links.")

if __name__ == "__main__":
    main()

# Verification through Day 96

On November 25, 2026, all 146 C programs compiled independently with MSYS2 UCRT64 GCC 16.2.0 on Windows 11 x64. GCC emitted zero diagnostics with `-std=c11 -Wall -Wextra -pedantic`. Each compiled program ran. The 259 published examples yielded 247 passes, 10 literal mismatches and 2 indeterminate outcomes. All 168 additional tests passed. Of the 146 programs, 135 passed every associated case. The 11 programs with exceptions are listed below.

## Reproduce the checks

From the repository root, run `python verification/verify.py --report new-results.json` with Python 3.9+ and GCC on PATH. The runner returns status 1 for a failed or indeterminate case. Each result includes a program identifier, case group, case index, exit status where available, and the full difference for any mismatch. A SHA-256 hash binds each build result to its LF-normalized C source. [Runner](verify.py) · [Recorded results](results.json)

The runner compares UTF-8 output after normalizing CRLF and allowing one final newline. All other text, including leading spaces and blank lines in patterns, participates in the comparison. File exercises run in isolated directories. Text files use the same newline rules. The binary copy check compares every byte, including NUL, LF and CRLF.

The pinned question bank preserves the statements, examples, original explanations and notes. Its 146 IDs were checked for continuity and mapped in website order before implementation. The live JSON and scheduling script matched their respective files at revision `3dd9a87323f5a8de608b1bbe2137c8a804db871c`. The SHA-256 of the complete upstream JSON was `c513766b0ba4b63fb9d5046ef3ae2605d447c7851d7a6200f3314b23ef3956a8`. [Local questions and day mapping](questions.json) · [Upstream JSON](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/questions2.json)

## Published sample exceptions

| Question and sample | Published expectation | Observed result and interpretation |
| --- | --- | --- |
| Q4, sample 1 | Circumference 43.96 | For radius 7, 14π rounds to 43.98. The published area agrees with π. |
| Q9, sample 2 | Compound interest 1125.76 | For principal 5000 at 7% for three years, 5000 × (1.07³ − 1) rounds to 1125.22. |
| Q44, sample 1 | 3.3 | The first three specified terms sum to 1 + 3/4 + 5/6, which rounds to 2.6 at one decimal place. |
| Q45, samples 1 and 2 | 1.56 and 2.22 | Summing 2i/(4i−1) for i = 1 through 3 or 5 gives 1.78 and 2.84 to two decimals. |
| Q50, sample 2 | An explanatory sentence about spaces | The same empty input as sample 1 produces the five-line indented star pattern shown in the statement. Sample 1 passes exactly. |
| Q52, sample 1 | A prose description of spacing | The program prints vertical groups of 1, 3, 5, 3 and 1 stars as drawn. A separate exact-output check covers the drawing. |
| Q54, sample 1 | A prose description of star layers | The program prints all seven centered rows. A separate exact-output check covers the drawing. |
| Q120, sample 1 | Capitalized words with the final period removed | The statement calls this sentence case. All three examples capitalize words, and samples 2 and 3 keep their periods. The program follows the word-capitalization examples and preserves punctuation. |
| Q123, sample 1 | 31 characters, 5 words, 2 lines | The supplied text contains 33 characters including one LF, 6 words and 2 lines. A trailing newline is absent from the input description. |
| Q126, sample 1 | A message followed by a placeholder for file contents | The source omits the contents of the file. A representative file was opened and the observed output recorded. This source sample is indeterminate. A separate concrete file test passed. |
| Q142, sample 1 | A description of a five-row table | The example provides no student records or expected cells. Its literal input was attempted and rejected. A separate case supplies five records and checks the table, tabs and all. |

## Input conventions

Most programs use the input exactly as displayed in the bank. Arrays in Q56–70 start with their lengths when the example supplies a length. The insertion and deletion examples use zero-based indices. For Q101–119, use the labeled, bracketed arrays or quoted strings illustrated in the corresponding samples. The integer arrays in that section accept up to 4096 entries per array. The earlier array exercises use a 10,000-element capacity and matrix exercises accept dimensions through 100. The short string exercises use ASCII character semantics.

Q121–130 describe file setup in prose. The runner creates the named files, supplies actual input, and checks the resulting stdout and file contents. For Q124, enter the source filename and destination filename on separate lines. For Q125, enter the line to append. For Q126, enter the filename. Q127's expected output refers to the contents of `output.txt`. For Q130, Q143 and Q145, enter the record count followed by whitespace-separated name, roll number and marks for each record. Q142 reads exactly five records. The original samples and all fixture translations are available side by side. [Original examples](questions.json) · [Fixtures and additional tests](cases.json)

## Ten-day checkpoints

The totals are cumulative. Each checkpoint has zero compiler warnings and zero additional test failures.

| Through day | Clean builds | Samples passed | Samples failed | Indeterminate | Additional passed |
| --- | ---: | ---: | ---: | ---: | ---: |
| 10 | 20 | 46 | 2 | 0 | 23 |
| 20 | 40 | 91 | 2 | 0 | 46 |
| 30 | 60 | 116 | 8 | 0 | 69 |
| 40 | 80 | 141 | 8 | 0 | 91 |
| 50 | 100 | 165 | 8 | 0 | 111 |
| 60 | 110 | 196 | 8 | 0 | 123 |
| 70 | 120 | 223 | 9 | 0 | 134 |
| 80 | 130 | 232 | 10 | 1 | 147 |
| 90 | 140 | 242 | 10 | 1 | 162 |
| 96 | 146 | 247 | 10 | 2 | 168 |

## History verification

Run `python verification/audit.py` in a full, clean clone to check the retained base commit, 96 daily commits, both timestamps, timezone, authorship, messages, changed paths, README links, sample exceptions and all 146 source hashes. The simulated work descends from the destination’s original commit `08f5146112fbe02b1f4db54edb5de94088717711`. GitHub links its author to `student-kunal` and verifies the signed commit. Local daily commits use that existing author identity. [Audit script](audit.py) · [Original destination commit](https://github.com/student-kunal/Hundred_Days_Of_Code/commit/08f5146112fbe02b1f4db54edb5de94088717711)

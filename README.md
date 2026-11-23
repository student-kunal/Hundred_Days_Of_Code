# Hundred_Days_Of_Code

## 100 Days of Code in C

Independent C11 programs for the UPES daily coding challenge. The exercises come from Soumik Maity’s public question bank. [Challenge website](https://maitysoumik.github.io/basic-coding-with-c/) · [Original questions](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/questions2.json)

### Historical Git simulation

The daily author and committer dates are simulated. They illustrate a Monday–Friday schedule and do not record when the code was written, tested or submitted. Codex generated the solutions and tests with AI assistance on November 25, 2026. The original repository commit is preserved.

### Progress through Day 96

All 146 programs compile independently with GCC 16.2.0 under C11 with zero diagnostics. Days 01–50 contain two programs each. Days 51–96 contain one each. The 259 published samples produced 247 passes, 10 output mismatches and two indeterminate results. All 168 additional checks passed. For 135 programs every associated case passed. [Verification report](verification/REPORT.md) · [Per-case results](verification/results.json)

### Compile and run

From the repository root in PowerShell, run these commands to build Question 1 and enter its first example.

```powershell
gcc -std=c11 -Wall -Wextra -pedantic Day01/Question_1.c -o sum.exe
'3 4' | .\sum.exe
```

The result is `Sum = 7`. Add `-lm` after the source file when linking programs that call math functions on systems with a separate math library. Each program reads from standard input unless its exercise calls for a file. Run file exercises in a scratch directory because they create or update files there. The verification runner builds temporary executables and creates a separate directory for each test.

```powershell
python verification/verify.py
python verification/audit.py
```

The test runner prints all mismatches and returns status 1 while any published example fails or lacks an exact expected result. Run it with `--through 10` to check an earlier milestone or `--report <path>` to write a fresh JSON report. The history audit requires Git, a full clone and a clean working tree. Both scripts use only the Python standard library and support Python 3.9 or later. [Test runner](verification/verify.py) · [History audit](verification/audit.py)

### Dates and source mapping

The question order follows the live site's two-phase selection logic. Its release calendar starts August 10, 2026 and adjusts for a September midsemester pause. The simulation below uses the requested July 13 start, every Monday through Friday, and no holiday exclusions. It ends on Monday, November 23. The college's release dates and the dates in this index serve different purposes. [Website scheduling code](https://github.com/maitysoumik/basic-coding-with-c/blob/3dd9a87323f5a8de608b1bbe2137c8a804db871c/script2.js)

Both timestamps on each simulated commit use the same instant in Asia/Kolkata (UTC+05:30). For day number `d`, minutes after 10:00 are `(137 * d + 41) % 601`. The original November 25 repository commit precedes Day 01 in Git ancestry. Its real date is later than the simulated dates. The daily commits themselves are chronological.

### Day-wise question index

| Day | Simulated date (IST) | C programs |
| --- | --- | --- |
| 01 | 2026-07-13 | [Q1 · Sum of two numbers](Day01/Question_1.c) · [Q2 · Four arithmetic operations](Day01/Question_2.c) |
| 02 | 2026-07-14 | [Q3 · Rectangle area and perimeter](Day02/Question_3.c) · [Q4 · Circle area and circumference](Day02/Question_4.c) |
| 03 | 2026-07-15 | [Q5 · Celsius to Fahrenheit](Day03/Question_5.c) · [Q6 · Swap with a temporary variable](Day03/Question_6.c) |
| 04 | 2026-07-16 | [Q7 · Swap without a temporary variable](Day04/Question_7.c) · [Q8 · Sum of natural numbers](Day04/Question_8.c) |
| 05 | 2026-07-17 | [Q9 · Simple and compound interest](Day05/Question_9.c) · [Q10 · Seconds to hours, minutes and seconds](Day05/Question_10.c) |
| 06 | 2026-07-20 | [Q11 · Even or odd](Day06/Question_11.c) · [Q12 · Sign of an integer](Day06/Question_12.c) |
| 07 | 2026-07-21 | [Q13 · Leap year](Day07/Question_13.c) · [Q14 · Vowels and consonants](Day07/Question_14.c) |
| 08 | 2026-07-22 | [Q15 · Character classification](Day08/Question_15.c) · [Q16 · Largest of three numbers](Day08/Question_16.c) |
| 09 | 2026-07-23 | [Q17 · Quadratic roots](Day09/Question_17.c) · [Q18 · Percentage grades](Day09/Question_18.c) |
| 10 | 2026-07-24 | [Q19 · Triangle classification](Day10/Question_19.c) · [Q20 · Weekday names](Day10/Question_20.c) |
| 11 | 2026-07-27 | [Q21 · Month lengths](Day11/Question_21.c) · [Q22 · Profit and loss percentages](Day11/Question_22.c) |
| 12 | 2026-07-28 | [Q23 · Library fines](Day12/Question_23.c) · [Q24 · Electricity tariffs](Day12/Question_24.c) |
| 13 | 2026-07-29 | [Q25 · Switch-based calculator](Day13/Question_25.c) · [Q26 · Count from 1 to n](Day13/Question_26.c) |
| 14 | 2026-07-30 | [Q27 · Sum of the first n odd numbers](Day14/Question_27.c) · [Q28 · Product of even numbers](Day14/Question_28.c) |
| 15 | 2026-07-31 | [Q29 · Factorial](Day15/Question_29.c) · [Q30 · Reverse an integer](Day15/Question_30.c) |
| 16 | 2026-08-03 | [Q31 · Binary representation](Day16/Question_31.c) · [Q32 · Palindrome numbers](Day16/Question_32.c) |
| 17 | 2026-08-04 | [Q33 · Armstrong numbers](Day17/Question_33.c) · [Q34 · Primality](Day17/Question_34.c) |
| 18 | 2026-08-05 | [Q35 · Factors](Day18/Question_35.c) · [Q36 · Greatest common divisor](Day18/Question_36.c) |
| 19 | 2026-08-06 | [Q37 · Least common multiple](Day19/Question_37.c) · [Q38 · Digit sum](Day19/Question_38.c) |
| 20 | 2026-08-07 | [Q39 · Product of odd digits](Day20/Question_39.c) · [Q40 · Ones’ complement](Day20/Question_40.c) |
| 21 | 2026-08-10 | [Q41 · Swap first and last digits](Day21/Question_41.c) · [Q42 · Perfect numbers](Day21/Question_42.c) |
| 22 | 2026-08-11 | [Q43 · Strong numbers](Day22/Question_43.c) · [Q44 · Series starting with 1 and 3/4](Day22/Question_44.c) |
| 23 | 2026-08-12 | [Q45 · Series starting with 2/3 and 4/7](Day23/Question_45.c) · [Q46 · Square star pattern](Day23/Question_46.c) |
| 24 | 2026-08-13 | [Q47 · Left-aligned star triangle](Day24/Question_47.c) · [Q48 · Increasing digit triangle](Day24/Question_48.c) |
| 25 | 2026-08-14 | [Q49 · Right-ending digit rows](Day25/Question_49.c) · [Q50 · Indented inverted triangle](Day25/Question_50.c) |
| 26 | 2026-08-17 | [Q51 · Right-aligned digit triangle](Day26/Question_51.c) · [Q52 · Vertical star groups](Day26/Question_52.c) |
| 27 | 2026-08-18 | [Q53 · Diamond of odd-width rows](Day27/Question_53.c) · [Q54 · Centered diamond](Day27/Question_54.c) |
| 28 | 2026-08-19 | [Q55 · List primes](Day28/Question_55.c) · [Q56 · Read and print an array](Day28/Question_56.c) |
| 29 | 2026-08-20 | [Q57 · Array sum](Day29/Question_57.c) · [Q58 · Array extrema](Day29/Question_58.c) |
| 30 | 2026-08-21 | [Q59 · Count even and odd elements](Day30/Question_59.c) · [Q60 · Count positive, negative and zero values](Day30/Question_60.c) |
| 31 | 2026-08-24 | [Q61 · Linear search](Day31/Question_61.c) · [Q62 · Reverse an array in place](Day31/Question_62.c) |
| 32 | 2026-08-25 | [Q63 · Concatenate arrays](Day32/Question_63.c) · [Q64 · Most frequent digit](Day32/Question_64.c) |
| 33 | 2026-08-26 | [Q65 · Binary search](Day33/Question_65.c) · [Q66 · Insert in sorted order](Day33/Question_66.c) |
| 34 | 2026-08-27 | [Q67 · Insert by index](Day34/Question_67.c) · [Q68 · Delete by index](Day34/Question_68.c) |
| 35 | 2026-08-28 | [Q69 · Second distinct largest value](Day35/Question_69.c) · [Q70 · Rotate an array](Day35/Question_70.c) |
| 36 | 2026-08-31 | [Q71 · Read and print a matrix](Day36/Question_71.c) · [Q72 · Matrix sum](Day36/Question_72.c) |
| 37 | 2026-09-01 | [Q73 · Row sums](Day37/Question_73.c) · [Q74 · Transpose](Day37/Question_74.c) |
| 38 | 2026-09-02 | [Q75 · Matrix addition](Day38/Question_75.c) · [Q76 · Symmetry](Day38/Question_76.c) |
| 39 | 2026-09-03 | [Q77 · Distinct diagonal entries](Day39/Question_77.c) · [Q78 · Main diagonal sum](Day39/Question_78.c) |
| 40 | 2026-09-04 | [Q79 · Zigzag diagonal traversal](Day40/Question_79.c) · [Q80 · Matrix multiplication](Day40/Question_80.c) |
| 41 | 2026-09-07 | [Q81 · String length](Day41/Question_81.c) · [Q82 · One character per line](Day41/Question_82.c) |
| 42 | 2026-09-08 | [Q83 · Count vowels and consonants](Day42/Question_83.c) · [Q84 · Uppercase conversion](Day42/Question_84.c) |
| 43 | 2026-09-09 | [Q85 · Reverse a string](Day43/Question_85.c) · [Q86 · Palindrome strings](Day43/Question_86.c) |
| 44 | 2026-09-10 | [Q87 · Count spaces, digits and special characters](Day44/Question_87.c) · [Q88 · Replace spaces with hyphens](Day44/Question_88.c) |
| 45 | 2026-09-11 | [Q89 · Character frequency](Day45/Question_89.c) · [Q90 · Toggle letter case](Day45/Question_90.c) |
| 46 | 2026-09-14 | [Q91 · Remove vowels](Day46/Question_91.c) · [Q92 · First repeating lowercase letter](Day46/Question_92.c) |
| 47 | 2026-09-15 | [Q93 · Anagrams](Day47/Question_93.c) · [Q94 · Longest word](Day47/Question_94.c) |
| 48 | 2026-09-16 | [Q95 · String rotation](Day48/Question_95.c) · [Q96 · Reverse individual words](Day48/Question_96.c) |
| 49 | 2026-09-17 | [Q97 · Name initials](Day49/Question_97.c) · [Q98 · Initials with full surname](Day49/Question_98.c) |
| 50 | 2026-09-18 | [Q99 · Format a date](Day50/Question_99.c) · [Q100 · Enumerate substrings](Day50/Question_100.c) |
| 51 | 2026-09-21 | [Q101 · First and last occurrence](Day51/Question_101.c) |
| 52 | 2026-09-22 | [Q102 · Ceiling index](Day52/Question_102.c) |
| 53 | 2026-09-23 | [Q103 · Pivot index](Day53/Question_103.c) |
| 54 | 2026-09-24 | [Q104 · Pivot integer](Day54/Question_104.c) |
| 55 | 2026-09-25 | [Q105 · Majority element](Day55/Question_105.c) |
| 56 | 2026-09-28 | [Q106 · Next greater element](Day56/Question_106.c) |
| 57 | 2026-09-29 | [Q107 · Previous greater element](Day57/Question_107.c) |
| 58 | 2026-09-30 | [Q108 · Product except self](Day58/Question_108.c) |
| 59 | 2026-10-01 | [Q109 · Maximum fixed-window sum](Day59/Question_109.c) |
| 60 | 2026-10-02 | [Q110 · Maximum in each window](Day60/Question_110.c) |
| 61 | 2026-10-05 | [Q111 · First negative in each window](Day61/Question_111.c) |
| 62 | 2026-10-06 | [Q112 · Maximum subarray sum](Day62/Question_112.c) |
| 63 | 2026-10-07 | [Q113 · Kth smallest element](Day63/Question_113.c) |
| 64 | 2026-10-08 | [Q114 · Longest substring without repeats](Day64/Question_114.c) |
| 65 | 2026-10-09 | [Q115 · Lowercase anagrams](Day65/Question_115.c) |
| 66 | 2026-10-12 | [Q116 · Two-sum indices](Day66/Question_116.c) |
| 67 | 2026-10-13 | [Q117 · Merge sorted arrays](Day67/Question_117.c) |
| 68 | 2026-10-14 | [Q118 · Missing number](Day68/Question_118.c) |
| 69 | 2026-10-15 | [Q119 · Repeated element](Day69/Question_119.c) |
| 70 | 2026-10-16 | [Q120 · Capitalize words](Day70/Question_120.c) |
| 71 | 2026-10-19 | [Q121 · Write a name and age to a file](Day71/Question_121.c) |
| 72 | 2026-10-20 | [Q122 · Read a file line by line](Day72/Question_122.c) |
| 73 | 2026-10-21 | [Q123 · Count characters, words and lines](Day73/Question_123.c) |
| 74 | 2026-10-22 | [Q124 · Copy a file](Day74/Question_124.c) |
| 75 | 2026-10-23 | [Q125 · Append a line](Day75/Question_125.c) |
| 76 | 2026-10-26 | [Q126 · Open and display a named file](Day76/Question_126.c) |
| 77 | 2026-10-27 | [Q127 · Uppercase a text file](Day77/Question_127.c) |
| 78 | 2026-10-28 | [Q128 · Count vowels and consonants in a file](Day78/Question_128.c) |
| 79 | 2026-10-29 | [Q129 · Sum and average from a file](Day79/Question_129.c) |
| 80 | 2026-10-30 | [Q130 · Store and retrieve student records](Day80/Question_130.c) |
| 81 | 2026-11-02 | [Q131 · Weekday enum](Day81/Question_131.c) |
| 82 | 2026-11-03 | [Q132 · Traffic lights](Day82/Question_132.c) |
| 83 | 2026-11-04 | [Q133 · Month-length enum](Day83/Question_133.c) |
| 84 | 2026-11-05 | [Q134 · Operation status](Day84/Question_134.c) |
| 85 | 2026-11-06 | [Q135 · Explicit enum values](Day85/Question_135.c) |
| 86 | 2026-11-09 | [Q136 · Arithmetic menu](Day86/Question_136.c) |
| 87 | 2026-11-10 | [Q137 · User roles](Day87/Question_137.c) |
| 88 | 2026-11-11 | [Q138 · Iterate over enum names](Day88/Question_138.c) |
| 89 | 2026-11-12 | [Q139 · Integer values of status codes](Day89/Question_139.c) |
| 90 | 2026-11-13 | [Q140 · Gender in a structure](Day90/Question_140.c) |
| 91 | 2026-11-16 | [Q141 · Read and display a student](Day91/Question_141.c) |
| 92 | 2026-11-17 | [Q142 · Five-student table](Day92/Question_142.c) |
| 93 | 2026-11-18 | [Q143 · Highest marks](Day93/Question_143.c) |
| 94 | 2026-11-19 | [Q144 · Pass a structure by value](Day94/Question_144.c) |
| 95 | 2026-11-20 | [Q145 · Return the top student](Day95/Question_145.c) |
| 96 | 2026-11-23 | [Q146 · Employee and joining date](Day96/Question_146.c) |

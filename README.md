<div align="center">

# FAANG Array System Design

**Five FAANG-style system design problems solved in C++ with arrays as the primary structure.**

Cache-friendly vectors, binary search, and ring buffers in place of heavier trees and hash maps —
each module is a self-contained, runnable program that proves simple contiguous storage is often
the fastest, leanest answer to a hard design question.

![C++](https://img.shields.io/badge/C%2B%2B-14-blue?style=flat-square&logo=cplusplus&logoColor=white)
![Modules](https://img.shields.io/badge/modules-5-brightgreen?style=flat-square)
![Dependencies](https://img.shields.io/badge/dependencies-0-green?style=flat-square)
![Warnings](https://img.shields.io/badge/build%20warnings-0-orange?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-blue?style=flat-square)

</div>

---

## Table of Contents

- [Overview](#overview)
- [Why Arrays](#why-arrays)
- [Modules](#modules)
- [Complexity](#complexity)
- [Requirements](#requirements)
- [Build and Run](#build-and-run)
- [Example Output](#example-output)
- [Project Structure](#project-structure)
- [Design Notes](#design-notes)
- [Contributing](#contributing)
- [Author](#author)
- [License](#license)

---

## Overview

This collection tackles a recurring interview theme: how far can you get with just an array?
Every file in `src/` compiles to its own executable with a `main` and a worked example, so each
solution can be built, run and studied in isolation. The implementations deliberately favour
sorted arrays, `lower_bound` binary search and fixed-capacity ring buffers over trees or hash maps,
because contiguous memory wins on cache locality, simplicity and constant factors for the data
sizes these problems imply.

---

## Why Arrays

Heavier structures add pointer chasing, allocation overhead and branchy balancing logic. For
read-mostly or bounded-window workloads, a plain vector with binary search is frequently faster in
practice:

- Sorted arrays make prefix ranges and interval neighbours a two-call `lower_bound`
- A ring buffer gives O(1) rolling statistics over the last K items with zero allocation churn
- Linear scans over small, densely packed arrays beat tree lookups on real hardware
- Encoding and decoding are single forward passes with predictable memory access

---

## Modules

| File | Problem | Approach |
| --- | --- | --- |
| `src/stock_tracker.cpp` | Rolling stock statistics | Ring buffer for the moving average of the last K prices, with running min, max and current value |
| `src/leaderboard.cpp` | Player leaderboard | Array of player-score pairs supporting add, top-K sum, and reset |
| `src/autocomplete.cpp` | Prefix autocomplete | Sorted dictionary queried with binary search over a prefix range |
| `src/video_rle.cpp` | Run-length encoding | Row-wise RLE encode and decode for a 2D frame |
| `src/my_calendar.cpp` | Calendar booking | Sorted interval array with binary search to reject overlaps |

---

## Complexity

| Module | Operation | Cost |
| --- | --- | --- |
| Stock Tracker | update / getCurrent / getMin / getMax / getAvgK | O(1) |
| Leaderboard | addScore / reset | O(n) |
| Leaderboard | top(K) | O(n log n) |
| Autocomplete | construct (sort) | O(n log n) |
| Autocomplete | suggest | O(log n + results) |
| Video RLE | encode / decode | O(rows x cols) |
| My Calendar | book | O(n) insert, O(log n) conflict search |

---

## Requirements

- A C++ compiler supporting **C++14 or later** (GCC `g++` or Clang `clang++`)
- No external libraries, package managers or build tools

> The sources include the non-standard `<bits/stdc++.h>` convenience header, so they are built
> with GCC or Clang. They do not target MSVC (`cl.exe`).

---

## Build and Run

Compile any single module from the project root and run it:

```bash
g++ -std=c++14 -O2 -Wall src/stock_tracker.cpp -o stock_tracker
./stock_tracker
```

On Windows, the same command produces `stock_tracker.exe`:

```bat
g++ -std=c++14 -O2 -Wall src\stock_tracker.cpp -o stock_tracker.exe
stock_tracker.exe
```

Build every module in one pass on Linux or macOS:

```bash
mkdir -p bin
for file in src/*.cpp; do
  name=$(basename "$file" .cpp)
  g++ -std=c++14 -O2 -Wall "$file" -o "bin/$name"
done
```

Build every module in one pass on Windows:

```bat
mkdir bin
for %f in (src\*.cpp) do g++ -std=c++14 -O2 -Wall "%f" -o "bin\%~nf.exe"
```

Swap in the source file of any module listed in [Modules](#modules) to run a different example.

---

## Example Output

### `stock_tracker`

```text
15 5 20 13.33
```

### `leaderboard`

```text
73
141
```

### `autocomplete`

```text
ban band banner
```

### `my_calendar`

```text
true
false
true
```

### `video_rle`

```text
1 1 1 2 2
3 3 4 4 4
```

---

## Project Structure

```text
faang-array-system-design/
├── src/
│   ├── stock_tracker.cpp
│   ├── leaderboard.cpp
│   ├── autocomplete.cpp
│   ├── video_rle.cpp
│   └── my_calendar.cpp
├── .gitignore
├── LICENSE
└── README.md
```

---

## Design Notes

- **Ring buffer.** The stock tracker writes each price into a fixed K-slot array and advances a
  head index with modulo arithmetic, subtracting the value being overwritten so the rolling sum
  stays exact with no resizing.
- **Binary-search prefix window.** Autocomplete finds the first word not less than the prefix and
  the first word past every string that starts with it, so the suggestion slice is a single
  contiguous range of the sorted array.
- **Sorted interval insert.** My Calendar keeps bookings ordered by start time and uses two
  neighbour checks, against the previous and next interval, to confirm a slot is free before an
  in-order insert.
- **Row-wise RLE.** The video encoder compresses each row independently into value-count pairs and
  the decoder expands them back, resizing to the frame width when a row is short.
- **Pair-based leaderboard.** Players live in a vector of id-score pairs; addScore merges by id,
  reset removes by id, and top copies scores for a descending partial sort.

---

## Contributing

Contributions are welcome.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/amazing-solution`)
3. Compile with `-Wall` and confirm zero warnings
4. Commit your changes (`git commit -m "Add amazing solution"`)
5. Push to the branch (`git push origin feature/amazing-solution`)
6. Open a Pull Request

---

## Author

Created by **[Kumar44developer](https://github.com/Kumar44developer)**.

---

## License

Distributed under the MIT License. See `LICENSE` for more information.

# FAANG Array System Design

A set of compact, high-performance C++ solutions to FAANG-style system design problems, each built primarily on arrays and vectors rather than heavier data structures. Every file is self-contained with its own `main` function and a runnable example.

## Overview

The goal of this collection is to show how common interview and system design problems can be solved efficiently using simple contiguous storage. The implementations favor cache-friendly arrays, binary search, and ring buffers over trees or hash maps where an array-based approach is competitive.

## Modules

| File | Problem | Approach |
| --- | --- | --- |
| src/stock_tracker.cpp | Rolling stock statistics | Ring buffer for the moving average over the last K prices, with running min and max |
| src/leaderboard.cpp | Player leaderboard | Array of player-score pairs with add, top-K sum, and reset operations |
| src/autocomplete.cpp | Prefix autocomplete | Sorted dictionary queried with binary search over a prefix range |
| src/video_rle.cpp | Run-length encoding | Row-wise RLE encode and decode for a 2D frame |
| src/my_calendar.cpp | Calendar booking | Sorted interval array with binary search to reject overlaps |

## Requirements

- A C++ compiler supporting C++14 or later, such as g++ (GCC) or Clang

## Build and Run

Compile and run any module from the project root:

```bash
g++ -std=c++14 src/stock_tracker.cpp -o stock_tracker
./stock_tracker
```

On Windows, run the generated `stock_tracker.exe`.

## Example Output

| Module | Output |
| --- | --- |
| stock_tracker | `15 5 20 13.33` |
| leaderboard | `73` then `141` |
| autocomplete | `ban band banner` |
| my_calendar | `true false true` |
| video_rle | Decoded frame matching the original rows |

## Author

Created by [Kumar44developer](https://github.com/Kumar44developer).

*This project has been created as part of the 42 curriculum by fiolivei and ipinto-m*

# push_swap

## Description

push_swap is a sorting algorithm project. The goal is to sort a stack of integers using two stacks — **A** (input) and **B** (auxiliary) — and a restricted set of operations, producing the smallest possible sequence of moves.

The program receives a list of integers as arguments and prints to stdout the ordered list of operations that sorts stack A in ascending order.

Available operations:

| Operation | Effect |
|-----------|--------|
| `sa` / `sb` | Swap the top two elements of stack A / B |
| `ss` | `sa` + `sb` simultaneously |
| `pa` / `pb` | Push top of B onto A / top of A onto B |
| `ra` / `rb` | Rotate A / B (top becomes bottom) |
| `rr` | `ra` + `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate A / B (bottom becomes top) |
| `rrr` | `rra` + `rrb` simultaneously |

## Instructions

**Compile:**
```bash
make
```

**Run:**
```bash
./push_swap 3 1 4 1 5 9 2 6
```

**Validate with checker:**
```bash
ARG="3 1 4 1 5 9"; ./push_swap $ARG | ./checker_Mac $ARG
```

The program exits with no output if the input is already sorted, and prints `Error` to stderr for invalid input (non-integer, duplicate, out of int range).

## Algorithm

> To be completed once the algorithm is chosen.

The algorithm selection will be documented here with a detailed explanation and justification of the approach, including time complexity analysis and the reasoning behind the choice for each input size (e.g., 3, 5, and 100/500 elements).

## Resources

- [Push_swap — The least amount of moves with two stacks](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Sorting Algorithms — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix Sort explanation](https://www.geeksforgeeks.org/radix-sort/)
- [Turk Algorithm explanation](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Push_swap Tutorial! (YouTube)](https://www.youtube.com/watch?v=wRvipSG4Mmk&t=797s)

**AI usage:** Claude (claude.ai/claude-code) was used to generate the initial project skeleton — file structure, Makefile, header with type definitions, and empty function stubs. The algorithm design and implementation are done manually.

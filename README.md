*This project has been created as part of the 42 curriculum by fiolivei, ipinto-m*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum.

The objective is to sort a stack of integers using only a limited set of stack operations and an auxiliary stack. The challenge is not only to sort the numbers correctly, but also to produce the smallest possible sequence of operations.

The program receives a list of integers as command-line arguments and outputs the operations required to sort stack **A** in ascending order using stack **B** as temporary storage.

### Allowed Operations

| Operation | Description                            |
| --------- | -------------------------------------- |
| `sa`      | Swap the first two elements of stack A |
| `sb`      | Swap the first two elements of stack B |
| `ss`      | `sa` and `sb` at the same time         |
| `pa`      | Push the top element of B to A         |
| `pb`      | Push the top element of A to B         |
| `ra`      | Rotate stack A upwards                 |
| `rb`      | Rotate stack B upwards                 |
| `rr`      | `ra` and `rb` simultaneously           |
| `rra`     | Reverse rotate stack A                 |
| `rrb`     | Reverse rotate stack B                 |
| `rrr`     | `rra` and `rrb` simultaneously         |

---

## Features

* Input validation
* Duplicate detection
* Integer overflow protection
* Multiple sorting strategies
* Adaptive strategy selection
* Operation optimization through cost analysis
* Compatible with the official 42 checker

---

## Instructions

### Compilation

```bash
make
```

This will generate the executable:

```bash
./push_swap
```

### Usage

```bash
./push_swap 4 2 7 1 3
```

Example:

```bash
$ ./push_swap 3 2 1
sa
rra
```

### Validation with Checker

```bash
ARG="3 2 5 1 4"

./push_swap $ARG | ./checker_linux $ARG
```

Expected output:

```bash
OK
```

---

## Algorithm Design and Justification

This project implements multiple sorting strategies and can select the most appropriate one depending on the input characteristics.

### 1. Simple Strategy (Small Inputs)

For small datasets, a cost-based approach is used.

Each element in stack A is evaluated according to:

* The number of rotations required in stack A.
* The number of rotations required in stack B.
* The total cost of moving that element to its correct position.

The algorithm repeatedly selects the cheapest move available and pushes the element to stack B until only three elements remain in stack A.

The remaining three elements are sorted directly, after which all elements are reinserted into stack A in their correct positions.

#### Why this approach?

For small inputs, minimizing the number of operations is more important than asymptotic complexity. Cost analysis generally produces significantly fewer instructions than generic sorting methods.

---

### 2. Medium Strategy (Chunk-Based Sorting)

For medium-sized inputs, the stack is divided into chunks.

The chunk size is calculated using:

```text
chunk_size = 2 × √n
```

Elements are pushed from A to B in groups according to their normalized index.

When an element belongs to the current chunk:

* It is pushed to stack B.
* Additional rotations may be performed to improve element distribution inside B.

After all elements have been transferred, the largest element in stack B is repeatedly moved back to stack A.

#### Why this approach?

Chunk sorting reduces the number of unnecessary rotations and generally performs better than simple cost-based methods on medium-sized datasets.

The square-root chunk sizing offers a good balance between:

* Number of passes
* Rotation count
* Overall operation count

---

### 3. Complex Strategy (Turk Algorithm)

For large and highly disordered datasets, the project uses a cost-based implementation inspired by the Turk Algorithm, one of the most popular approaches for the push_swap project.

Each element in stack A is evaluated according to:
* Its target position in stack B
* The number of rotations required in both stacks.
* The total movement cost required to place the element correctly.

The algorithm repeatedly:

1. Calculates the cost of moving every candidate element.
2. Selects the cheapest move.
3. Executes the required rotations.
4. Pushes the element to stack B.

Once only a small subset of elements remains in stack A, they are sorted directly. The elements stored in stack B are then reinserted into their correct positions until stack A becomes fully sorted.

#### Why this approach?

The Turk Algorithm is specifically designed for the push_swap constraints and focuses on minimizing operation count rather than raw computational complexity.

Its advantages include:

* Efficient move selection.
* Reduced rotation count.
* Good performance on large random datasets.
* Lower instruction counts compared to simpler approaches.

---

### 4. Extra Strategy (Binary Radix Sort)

For large datasets, the project uses a Binary Radix Sort.

Before sorting:

1. Every value receives a normalized index.
2. The smallest number receives index `0`.
3. The largest number receives index `n - 1`.

The algorithm then processes the indices bit by bit.

For each bit:

* Elements with bit `0` are pushed to stack B.
* Elements with bit `1` are rotated within stack A.

At the end of each pass, all elements from B are pushed back to A.

The process continues until every bit has been processed.

#### Why this approach?

Binary Radix Sort is one of the most reliable solutions for the push_swap constraints because:

* It is deterministic.
* It scales efficiently to hundreds of numbers.
* It consistently achieves the performance requirements imposed by the project.

#### Complexity

| Case  | Complexity |
| ----- | ---------- |
| Time  | O(n log n) |
| Space | O(n)       |

---

### 5. Adaptive Mode

The project also includes an adaptive mode.

A disorder metric is calculated before sorting.

Depending on the measured disorder:

* Low disorder → Simple Strategy
* Medium disorder → Chunk Strategy
* High disorder → Radix Strategy

This allows the program to automatically select the most suitable algorithm for the current input.

---

## Error Handling

The program prints:

```bash
Error
```

when:

* A value is not a valid integer.
* An integer exceeds the `int` range.
* Duplicate values are detected.
* Invalid arguments are supplied.

If the stack is already sorted, the program exits without producing operations.

---

## Project Structure

```text
src/
├── sort/
│   ├── sort_simple.c
│   ├── sort_medium.c
│   ├── sort_complex.c
│   └── sort_turk.c
├── operations/
├── parsing/
├── utils/
└── main.c
```

---

## Resources

### Push Swap References

* https://medium.com/@ayogun/push-swap-c1f5d2d41e97
* https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
* https://en.wikipedia.org/wiki/Radix_sort
* https://www.geeksforgeeks.org/radix-sort/

### 42 Documentation

* https://github.com/42School
* https://harm-smits.github.io/42docs/

### AI Usage

AI tools were used exclusively as development assistants.

Usage included:

* Reviewing algorithmic approaches.
* Discussing optimization strategies.
* Generating documentation drafts.
* Explaining concepts related to Radix Sort, chunk sorting, and move-cost analysis.

All project architecture, algorithm selection, implementation decisions, debugging, testing, and final code were developed and validated manually by the authors.

---

## Contributions

### ipinto-m

Responsible for:

* Input validation and error handling.
* Small dataset sorting strategy (**Simple Sort**).
* Medium dataset sorting strategy (**Chunk Sort**).
* Development of the additional **Binary Radix Sort** implementation.
* Testing and optimization of sorting performance.

### fiolivei

Responsible for:

* Argument parsing and input processing.
* Implementation of the **Turk Algorithm** for large datasets.
* Development of benchmarking and performance evaluation tools.
* Integration and validation of the overall sorting workflow.

### Collaborative Work

Both contributors participated in:

* Project design and architecture decisions.
* Algorithm evaluation and strategy selection.
* Debugging and testing.
* Performance analysis and optimization.
* Documentation and final review.

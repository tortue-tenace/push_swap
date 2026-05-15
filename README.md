*This activity has been created as part of the 42 curriculum by thattal, lmurie.*

# Push_swap

## Description

Push_swap is a sorting algorithm project using two stacks (`a` and `b`) and a limited set of operations. The goal is to sort stack `a` in ascending order using the fewest possible operations.

The program implements four distinct sorting strategies, each targeting a different complexity class in the Push_swap operation model, and selects the appropriate one at runtime based on a flag or the measured disorder of the input.

## Instructions

### Compilation

```bash
make
```

Builds `push_swap` after compiling the bundled `ft_printf` static library.

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers>
```

### Flags

| Flag | Strategy | Complexity |
|---|---|---|
| `--simple` | Bubble sort | O(n²) |
| `--medium` | Chunk sort (√n buckets) | O(n√n) |
| `--complex` | Radix sort (binary, LSD) | O(n log n) |
| `--adaptive` | Picks a strategy from measured disorder (default) | depends |
| `--bench` | Emit metrics on stderr (operation counts, strategy, disorder) | — |

### Examples

```bash
# Default (adaptive) sort
./push_swap 5 3 1 4 2

# Force medium strategy
./push_swap --medium 5 3 1 4 2

# Show benchmark metrics on stderr while piping ops to the checker
ARG="4 67 3 87 23"; ./push_swap --bench $ARG 2>bench.txt | ./checker_linux $ARG
cat bench.txt

# Count operations
./push_swap 5 3 1 4 2 | wc -l
```

### Error handling

```bash
./push_swap 1 2 one      # not an integer
./push_swap 1 2 2        # duplicate value
./push_swap 1 99999999999  # out of int range
```

All errors print `Error\n` on stderr and exit with code 1.

## Algorithms

### Simple — Selection Sort O(n²)

Repeatedly extracts the minimum from `a` to `b`:
1. Scan `a` to find the index of the minimum.
2. Bring it to the top using `ra` or `rra` (shorter side wins).
3. `pb` to push it to `b`.
4. Repeat until `a` is empty, then `pa` everything back.

Each iteration does at most `n/2` rotations + 1 push. With `n` iterations, the total operation count is O(n²). Space is O(1) auxiliary on top of the input.

### Medium — Chunk Sort O(n√n)

1. **Normalize**: replace each value by its rank (0 to n−1). Backing arrays remember the original values.
2. **Divide**: cut the rank space into √n contiguous ranges of size √n.
3. **Push** each chunk into `b`, rotating `a` over values outside the current range. While pushing, an `rb` is inserted right after `pb` if it places a smaller element on top of a larger one in `b`, so `b` stays roughly sorted ascending top-to-bottom.
4. **Pull back**: while `b` is non-empty, find the current max in `b`, rotate to it via the shortest side (`rb` vs `rrb`), and `pa`.
5. **Restore** original values from the sorted-rank table.

Push phase: each chunk requires up to `n` rotations + √n pushes → √n × O(n) = O(n√n).
Pull phase: O(n × √n / 2) on average due to bidirectional rotation. Total: **O(n√n)**.

### Complex — Radix Sort O(n log n)

Binary LSD radix sort over ranks:
- For each bit `j` from 0 to `log₂(max)`:
  - If `(top >> j) & 1`, `ra` (keep in `a`).
  - Else, `pb`.
- After each bit pass, drain `b` back into `a` with `pa`.

Negative values are shifted to non-negative before sorting and shifted back after.

`log₂(n)` passes × O(n) operations each = **O(n log n)**.

### Adaptive — Disorder-driven dispatch

Before sorting, `compute_disorder` counts inverted pairs `(i, j)` where `i < j` and `a[i] > a[j]`, divided by the total number of pairs `n(n−1)/2`. The result lies in `[0, 1]`.

| Measured disorder | Routed to | Complexity class |
|---|---|---|
| < 0.2 (low) | Selection sort | O(n²) worst case — but in practice the rotation cost shrinks because most mins are near the current top, so the operation count grows roughly linearly with the number of misplaced elements. |
| 0.2 – 0.5 (medium) | Chunk sort | O(n√n) |
| ≥ 0.5 (high) | Radix sort | O(n log n) |

**Rationale for the thresholds:**
- The 0.2 cutoff isolates inputs where only a small fraction of pairs are inverted (a few local swaps, a tail rotation, etc.). At this regime, selection sort spends most of its iterations doing zero rotations, so its observed operation count stays close to O(n).
- Between 0.2 and 0.5, the data is partially shuffled. Chunk sort's deterministic O(n√n) profile dominates the variance of radix on this range.
- Above 0.5, the data is nearly uniformly random. Radix sort guarantees O(n log n) regardless of the input distribution.

**Honest complexity note**: the subject targets O(n) for the low-disorder branch. Our implementation uses selection sort there, which is theoretically O(n²) but whose *observed* operation count on near-sorted inputs is linear in the number of misplaced elements. A stricter O(n) variant would require an explicit pass that pushes only the misplaced elements to `b`, sorts `b`, and merges back — left as a future optimization.

## Performance

| Input size | Minimum | Good | Excellent | Measured (adaptive) |
|---|---|---|---|---|
| 100 numbers | < 2000 | < 1500 | < 700 | ~1500 |
| 500 numbers | < 12000 | < 8000 | < 5500 | ~8300 |

Numbers are random; results vary across runs. Forcing `--medium` typically gives the best operation count.

## Resources

### References
- Knuth, D. — *The Art of Computer Programming, Vol. 3: Sorting and Searching*
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com)
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Push_swap chunk sort — Ayşegül Oğuz](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### AI Usage

- **Debugging**: reviewing the parser, the chunk-sort push/pull phases, and tracking down the bug where the original `--simple` implementation called `sa` on arbitrary list positions instead of the top of the stack.
- **Conceptual explanations**: rank normalization for radix and chunk sort, choosing thresholds for the adaptive dispatch, and arguments about operation-model complexity vs. classical big-O.

All algorithm choices, code structure decisions, and final implementations were authored, understood, and tested by the project members.

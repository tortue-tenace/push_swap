*This activity has been created as part of the 42 curriculum by thattal, lmurie.*

# Push_swap

## Description

Push_swap is a sorting algorithm project using two stacks (`a` and `b`) and a limited set of operations. The goal is to sort stack `a` in ascending order using the fewest possible operations.

The program implements four distinct sorting strategies, each targeting a different complexity class, and selects the appropriate one at runtime based on a flag or the measured disorder of the input.

## Instructions

### Compilation

```bash
make
```

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers>
```

### Flags

| Flag | Strategy | Complexity |
|---|---|---|
| `--simple` | Bubble sort | O(n²) |
| `--medium` | Chunk sort | O(n√n) |
| `--complex` | Radix sort | O(n log n) |
| `--adaptive` | Adaptive (default) | Depends on disorder |
| `--bench` | Show benchmark metrics | — |

### Examples

```bash
# Default (adaptive) sort
./push_swap 5 3 1 4 2

# Force medium strategy
./push_swap --medium 5 3 1 4 2

# Show benchmark metrics
./push_swap --bench 5 3 1 4 2

# Count operations
./push_swap 5 3 1 4 2 | wc -l

# Verify correctness
ARG="5 3 1 4 2"; ./push_swap $ARG | ./checker_linux $ARG
```

### Error handling

```bash
./push_swap 1 2 one      # Error: not an integer
./push_swap 1 2 2        # Error: duplicate value
```

## Algorithms

### Simple — Bubble Sort O(n²)

Repeatedly finds the minimum element in `a` and moves it to the correct position. Each pass requires up to `n` rotations to find the minimum and place it, giving O(n) passes × O(n) operations = **O(n²)** total.

### Medium — Chunk Sort O(n√n)

1. **Normalize** values to ranks 0 to n-1 (enables uniform chunk distribution)
2. **Divide** into √n chunks of size √n each
3. **Push** each chunk to `b`, placing the largest values on top using smart rotations (`rb` after `pb` when needed)
4. **Pull back** to `a` by always extracting the max from `b` using the shortest rotation path (forward `rb` or backward `rrb`)
5. **Restore** original values from a sorted copy

Complexity: √n chunks × n rotations per push phase + n × √n/2 for pull phase = **O(n√n)**.

### Complex — Radix Sort O(n log n)

Sorts by processing bits from least significant to most significant. For each bit position:
- Elements with bit = 0 → push to `b`
- Elements with bit = 1 → rotate in `a`
- Pull everything back from `b`

Requires `log2(n)` passes of `n` operations each = **O(n log n)**.

### Adaptive Algorithm

Measures disorder before sorting (ratio of inverted pairs over total pairs, between 0 and 1) and selects the strategy accordingly:

| Disorder | Strategy | Complexity |
|---|---|---|
| < 0.2 (low) | Insertion-style: find and place each element | O(n) |
| 0.2 – 0.5 (medium) | Chunk sort | O(n√n) |
| ≥ 0.5 (high) | Radix sort | O(n log n) |

**Rationale for thresholds:**
- Below 20% disorder, most elements are already in place — a few targeted rotations and swaps suffice, costing O(n) in practice.
- Between 20% and 50%, the data is partially shuffled — chunk sort's O(n√n) is efficient without the overhead of full radix passes.
- Above 50%, the data is highly random — radix sort's guaranteed O(n log n) outperforms chunk sort's worst-case behavior.

## Performance

| Input size | Minimum | Good | Excellent |
|---|---|---|---|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

## Resources

### References
- Knuth, D. — *The Art of Computer Programming, Vol. 3: Sorting and Searching*
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com)
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Chunk Sort explanation — 42 community](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

### AI Usage

Claude (Anthropic) was used throughout this project for:
- **Debugging**: identifying bugs in normalize, push_chunk, and back_to_a functions
- **Conceptual explanations**: understanding chunk sort mechanics, range-based partitioning, and disorder metrics
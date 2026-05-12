*This activity has been created as part of the 42 curriculum by thattal.*

# ft_printf

## Description

`ft_printf` is a recoded version of the standard C `printf()` function from `libc`. The goal of this project is to learn how to handle a variable number of arguments (variadic functions) in C, and to design a clean, extensible parser for format strings.

The function follows this prototype:

```c
int ft_printf(const char *format, ...);
```

It reads a format string and replaces every conversion specifier (introduced by `%`) by the formatted version of the corresponding argument, writing the result on the standard output. It returns the number of characters printed (excluding the trailing null byte that terminates the format string itself).

The buffer management of the original `printf()` is **not** implemented — every character is written directly with `write(2)`.

### Supported conversions

| Specifier | Description                                            |
|-----------|--------------------------------------------------------|
| `%c`      | Prints a single character.                             |
| `%s`      | Prints a string (C-style, null-terminated).            |
| `%p`      | Prints a `void *` pointer in hexadecimal (with `0x`).  |
| `%d`      | Prints a signed decimal integer (base 10).             |
| `%i`      | Prints a signed integer in base 10.                    |
| `%u`      | Prints an unsigned decimal integer (base 10).          |
| `%x`      | Prints an unsigned number in hexadecimal (lowercase).  |
| `%X`      | Prints an unsigned number in hexadecimal (uppercase).  |
| `%%`      | Prints a literal percent sign.                         |

## Instructions

### Compilation

A `Makefile` is provided at the root of the repository. It compiles the project with `-Wall -Wextra -Werror` using `cc`, and produces a static archive named `libftprintf.a` using `ar`.

| Rule     | Effect                                                       |
|----------|--------------------------------------------------------------|
| `make`   | Same as `make all` — builds `libftprintf.a`.                 |
| `all`    | Builds the library `libftprintf.a` at the root of the repo.  |
| `clean`  | Removes the object files (`*.o`).                            |
| `fclean` | Runs `clean` and also removes `libftprintf.a`.               |
| `re`     | Runs `fclean` then `all` — full rebuild.                     |

The Makefile **does not relink**: object files are only rebuilt when their source or the header changes.

### Usage

After compilation, link your program with the produced archive and include the header:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old (%%).\n", "world", 42);
    return (0);
}
```

Compile your test program with:

```sh
cc main.c -L. -lftprintf -o test
./test
```

## Project structure

```
.
├── Makefile      # Build rules for libftprintf.a
├── ft_printf.h      # Public header (prototypes of helpers and ft_printf)
├── ft_put.c      # Low-level output helpers (ft_putchar, ft_putstr,
│                 #   ft_putnbr, ft_putp)
├── ft_utils.c    # Format dispatcher (print_format) and ft_printf entry point
└── README.md
```

## Algorithm and data structures

The implementation is intentionally minimal and recursive — there is no buffer, no allocated state, and no struct to carry options around. The reasoning behind each choice is detailed below.

### High-level flow

`ft_printf` walks the format string character by character with a single pointer. For each character it has to decide between two paths:

1. The character is **not** a `%` → it is written as-is to `stdout` with `write(1, c, 1)`, and the running counter `i` is incremented by the return value of `write`.
2. The character is a `%` → the next character is consumed and dispatched to `print_format(type, ap)`, which extracts the corresponding argument from the variadic list and prints it.

The total returned by `ft_printf` is the sum of the lengths produced by every individual write, so it matches the number of bytes effectively written, exactly as the standard `printf` does.

### Variadic arguments — `<stdarg.h>`

Variadic arguments are accessed through a `va_list`, initialized with `va_start` on the last named argument (the format string), consumed one at a time with `va_arg`, and released with `va_end`. The `va_list` is passed by value to `print_format`, which keeps the parser short and makes each conversion handler independent.

The type given to `va_arg` matters and is chosen to match how each specifier promotes its argument:

- `%c` reads an `int` (because `char` is promoted to `int` when passed through `...`).
- `%s` reads a `char *`.
- `%d` and `%i` read an `int`.
- `%u`, `%x`, `%X` read an `unsigned int`.
- `%p` reads a `void *`.

### Number printing — recursive division

`ft_putnbr(long n, int base, char *symbols)` is the single workhorse used for `%d`, `%i`, `%u`, `%x`, `%X` and (indirectly) `%p`. Its logic is:

1. If `n` is negative, write `'-'` and recurse on `-n`. Using a `long` for `n` is crucial here: it lets us safely negate `INT_MIN` (whose absolute value does not fit in `int`).
2. If `n` is smaller than the base, write the corresponding digit from the `symbols` table and stop.
3. Otherwise, recurse on `n / base`, then print the digit `n % base`.

The `symbols` parameter is what allows the same function to print in different bases and different cases:

- `"0123456789abcdef"` is used for `%d`, `%i`, `%u`, `%x`.
- `"0123456789ABCDEF"` is used for `%X`.

This avoids duplicating one function per base. Each call returns the number of characters it printed, so the count propagates naturally up the recursion.

### Pointer printing — `%p`

`ft_putp` handles the two specific rules of `%p`:

- A `NULL` pointer is printed as `(nil)` (matching the behavior of glibc's `printf`).
- Any other pointer is printed as `0x` followed by its address in lowercase hexadecimal, by casting the `void *` to `long` and reusing `ft_putnbr` with base 16.

### Why these choices?

- **No struct, no buffer**: the project explicitly forbids reproducing the original `printf` buffer management. Direct `write(1, ...)` calls keep the code short and easy to audit, at the cost of more system calls — acceptable for a learning exercise.
- **Recursion for digits**: the recursive version of `ft_putnbr` mirrors the mathematical definition of base conversion ("the most significant digits come from `n / base`, the least significant from `n % base`"), which makes it easy to read and verify.
- **Single dispatcher (`print_format`)**: a flat sequence of `if` checks on the conversion character is the cheapest data structure here. With only nine specifiers there is no benefit in building a lookup table or a function-pointer array — the `if` chain stays under the Norm's line and column limits and is trivially extensible.
- **Counter as a plain `int`**: the return value of every helper is the number of bytes written, summed into a single `int`, so the final return value of `ft_printf` is always consistent with what was actually sent to `stdout`.

## Resources

- The C standard library `printf(3)` man page — reference for the expected behavior of every specifier.
- The C standard library `stdarg(3)` man page — reference for `va_start`, `va_arg`, `va_copy`, `va_end`.
- *The C Programming Language* (Kernighan & Ritchie), chapter on variadic functions.
- 42 internal documentation about the Norm and the `libft` toolbox.

### AI usage

AI tools were used **only** as a documentation aid: to clarify edge cases of the standard `printf` (behavior of `%p` on `NULL`, integer promotion rules through `...`) and to review the README's structure. The algorithm, the source code (`ft_put.c`, `ft_utils.c`, `ft_printf.h`) and the test cases were designed and written by hand, then iterated on through manual debugging and comparison against the system `printf`. No code was copied from an AI generation.

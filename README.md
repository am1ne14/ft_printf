# ft_printf

This project is a small `printf`-style library. It writes formatted output to
standard output and returns the number of printed characters.

The public function is:

```c
int ft_printf(const char *format, ...);
```

## Build

```sh
make
```

This creates `libftprintf.a`. Clean generated files with:

```sh
make clean
make fclean
```

## Use it in another program

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("name: %s, value: %d, hex: %x\n", "amine", 42, 42);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -I. -L. -lftprintf -o demo
./demo
```

## Supported conversions

| Conversion | Output |
| --- | --- |
| `%c` | one character |
| `%s` | a string (`(null)` for a null pointer) |
| `%p` | a pointer as lowercase hexadecimal, with `0x` prefix |
| `%d`, `%i` | signed decimal integer |
| `%u` | unsigned decimal integer |
| `%x`, `%X` | lowercase or uppercase hexadecimal |
| `%%` | a percent character |

## How it works

`ft_printf.c` walks through the format string one character at a time. Normal
characters go directly to `ft_put_char`. When it finds `%`, it first checks
the following character with `ft_strchr`; supported conversions are then sent
to `check_format` with the active `va_list`.

`check_format.c` is the dispatcher. It reads the correct argument type with
`va_arg` and calls a dedicated output helper. Each helper returns its own
character count, and `ft_printf` adds those counts to produce the final return
value.

The number helpers use recursion for output:

- `ft_put_nbr` prints signed values through a `long`, so the negative range of
  an `int` is handled safely.
- `ft_put_hex` and `ft_put_ptr` repeatedly divide by 16 and print digits while
  unwinding the recursion.
- `ft_put_ptr` prints `(nil)` for a null pointer and otherwise prepends `0x`.
- `ft_put_unsigned` converts an unsigned value to an allocated decimal string,
  prints it with `ft_put_str`, then frees it.

The Makefile compiles every source file into an object and archives them into
`libftprintf.a` with `ar rcs`.

# Math-library
This is a simple math library with some functions i sometimes need. This library is not very optimized, and uses aproaches which are not always optimal. It is made to be simple to understand and use.
## Compiling
### Windows
If using vscode on windows, just clone and run it in vscode. Untested, but should work.
### Linux (gcc)
> gcc main.c matrix.c graph.c -o -lncurses -lpanel -lm math-library
### Mac
If using gcc the snippet for linux should work

## Specifications
- The matrix struct stores its data as double. I'm concidering making an alternative struct storing its data as int. This should improve performance by quite a bit, especially with more complex functions. But then again the library is not necessarily focused on performance.
- The graphing function uses the ncurses library which is not really available on windows. There is probably some rather easy workaround(s). Will update with more info later
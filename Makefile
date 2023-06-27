math-library: main.c
	gcc main.c matrix.c graph.c -o math-library -lm -lncurses -lpanel 2> errors.txt; cat errors.txt

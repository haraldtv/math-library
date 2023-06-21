main: main.c
	gcc main.c matrix.c graph.c -o main -lm -lncurses -lpanel 2> errors.txt; cat errors.txt

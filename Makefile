sourceFiles := main.c matrix.c graph.c

SRC_dir := ./src
SRC_files := $(shell find $(SRC_dir) -name '*.c')

math-library: $(SRC_files)
	gcc -Wall $(SRC_files) -o math-library -lm -lncurses -lpanel 2> errors.txt; cat errors.txt



clean:
	rm main main.exe errors.txt
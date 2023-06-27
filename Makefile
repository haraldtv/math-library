sourceFiles := main.c matrix.c graph.c
cleanFiles := main main.exe errors.txt math-library

SRC_dir := ./src
SRC_files := $(shell find $(SRC_dir) -name '*.c')

TARGET := math-library

GCC_LINKS := -lm -lncurses -lpanel
GCC_ARGS := -Wall

math-library: $(SRC_files)
	gcc $(GCC_ARGS) $(SRC_files) -o $(TARGET) $(GCC_LINKS) | tee ./errors



clean:
	rm $(cleanFiles)

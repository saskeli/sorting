CFLAGS=-std=c++23 -Wall -Wextra -Wshadow -pedantic -march=native -fopenmp

HEADER=include/shell_sort.hpp include/util.hpp

.DEFAULT_GOAL=run

run: $(HEADER) run.cpp
	g++ $(CFLAGS) run.cpp -o run
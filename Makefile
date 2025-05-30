CFLAGS=-std=c++23 -Wall -Wextra -Wshadow -pedantic -march=native -fopenmp

HEADER=include/shell_sort.hpp include/insertion_sort.hpp include/counting_sort.hpp include/unbalanced_quicksort.hpp include/util.hpp

.DEFAULT_GOAL=run

run: $(HEADER) run.cpp
	g++ $(CFLAGS) -Ofast -DNDEBUG run.cpp -o run

run_deb: $(HEADER) run.cpp
	g++ $(CFLAGS) -g run.cpp -o run_deb
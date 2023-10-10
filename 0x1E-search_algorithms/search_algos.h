#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void print_search_range(int *array, int low, int high);
int jump_search(int *array, size_t size, int value);
size_t linear_search_for_jump(int *array, size_t start, size_t end, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int binary_search_for_exponential(int *array, size_t start,
								  size_t end, int value);
int min(int a, int b);

#endif

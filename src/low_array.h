// C-array utilities/sorting

#ifndef low_array_h
#define low_array_h

#include "common.h"

#define arr_length(arr) sizeof(arr) / sizeof(arr[0]);

void arr_print(int arr[], size_t length);
void sort_insertion(int* arr, size_t length);
void bogosort(int arr[], size_t length);
bool sort_mergesort(int *arr, size_t size);

#endif
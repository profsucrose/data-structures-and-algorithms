#include "common.h"
#include "low_array.h"

int main() {
    size_t length = 100000;
    int *arr = malloc(sizeof(int) * length);
    for (int i = 1; i < length; i++) arr[i - 1] = i;

    printf("Mergesort:\n");
    arr_print(arr, length);
    sort_mergesort(arr, length);
    arr_print(arr, length);
}
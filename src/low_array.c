#include "low_array.h"
#include "time.h"

void arr_print(int arr[], size_t length) {
    for (int i = 0; i < length; i++) {
        printf("%d", arr[i]);
        if (i < length - 1) printf(" ");
    }

    printf("\n");
}

bool is_sorted(int arr[], size_t length) {
    for (int i = 1; i < length; i++) {
        if (arr[i - 1] > arr[i])
            return false;
    }

    return true;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void seed_rand() {
    srand(time(0));
}

void shuffle(int arr[], size_t length) {
    for (int i = length - 1; i > 0; i--) {
        int r = rand() % i;
        swap(&arr[i], &arr[r]);
    }
}

void bogosort(int arr[], size_t length) {
    seed_rand();
    while (!is_sorted(arr, length))
        shuffle(arr, length);
}

void sort_insertion(int* arr, size_t length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1; 
        while (j > 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

static int max(int x, int y) {
    return x > y ? x : y;
}

static void merge_helper(int* arr, int left, int right, int *scratch) {
    // base case - one element
    if (right == left + 1) {
        return;
    } else {
        int length = right - left;
        int midpoint_distance = length / 2;

        // l and r are to the positions in the left and right subarrays
        int l = left, r = left + midpoint_distance;

        merge_helper(arr, left, left + midpoint_distance, scratch);
        merge_helper(arr, left + midpoint_distance, right, scratch);

        // merge arrays together
        for (int i = 0; i < length; i++) {
            // Check to see if there are any elements in the left array,
            // if so check if there are elements in the right array, if
            // so, compare them. Otherwise, we know that the merge must
            // take an element from the left
            if (l < left + midpoint_distance &&
                    (r == right || max(arr[l], arr[r]) == arr[l])) {
                scratch[i] = arr[l];
                l++;
            } else {
                scratch[i] = arr[r];
                r++;
            }
        }

        // copy scratch to arr
        for (int i = left; i < right; i++)
            arr[i] = scratch[i - left];
    }
}

bool sort_mergesort(int *arr, size_t size) {
    int *scratch = (int*)malloc(size * sizeof(int));
    if (scratch != NULL) {
        merge_helper(arr, 0, size, scratch);
        free(scratch);
        return true;
    } else {
        return false;
    }
}
#include "vector.h"

Vector vector_new() {
    Vector vector;
    vector.capacity = 10;
    int *array = malloc(vector.capacity * sizeof(int));
    vector.array = array;
    vector.length = 0;
    return vector;
}

void vector_push(Vector *vector, int element) {
    vector->array[vector->length] = element;
    vector->length += 1;
    if (vector->length == vector->capacity) {
        vector->capacity = vector->capacity * 2;
        int *array = malloc(vector->capacity * sizeof(int));
        for (int i = 0; i < vector->length; i++)
            array[i] = vector->array[i];
        free(vector->array);
        vector->array = array;
    }
}

int vector_get(Vector *vector, int index) {
    return vector->array[index];
}

bool vector_contains(Vector *vector, int element) {
    for (int i = 0; i < vector->length; i++) {
        if (vector->array[i] == element) 
            return true;
    }

    return false;
}
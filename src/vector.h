#ifndef vector_h
#define vector_h

#include "common.h"

typedef struct {
    int *array;
    int capacity;
    int length;
} Vector;

Vector vector_new();
void vector_push(Vector *vector, int element);
int vector_get(Vector *vector, int index);
bool vector_contains(Vector *vector, int element);

#endif
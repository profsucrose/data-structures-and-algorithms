#ifndef queue_h
#define queue_h

#include "common.h"
#include "list.h"

// linked-list wrapper

typedef List Queue;

Elmt *queue_dequeue(Queue *queue);
void queue_enqueue(Queue *queue, Elmt *elmt);

#endif
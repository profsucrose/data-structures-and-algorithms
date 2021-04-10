#include "queue.h"

Elmt *queue_dequeue(Queue *queue) {
    Elmt *tail = queue->tail;
    list_remove_tail(queue);
    return tail;
}

void queue_enqueue(Queue *queue, Elmt *elmt) {
    if (queue->head != NULL)
        queue->head->prev = elmt;

    queue->head = elmt;
}
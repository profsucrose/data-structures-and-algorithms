#include "list.h"

void elmt_init(Elmt *elmt, void *data) {
    elmt->next = NULL;
    elmt->prev = NULL;
    elmt->data = data;
}

void list_init(List *list) {
    list->length = 0;
    list->tail = NULL;
    list->head = NULL;
}

void list_push(List *list, Elmt *elmt) {
    if (list->tail != NULL) {
        list->tail->next = elmt;
        elmt->prev = list->tail;
    }

    list->tail = elmt;
}

void list_remove_elmt(List *list, Elmt *elmt) {
    if (elmt->next != NULL)
        elmt->next->prev = elmt->prev;

    if (elmt->prev != NULL)
        elmt->prev->next = elmt->next;

    list->length--;
}

void list_remove_tail(List *list) {
    if (list->tail != NULL)
        list_remove_elmt(list, list->tail);
}

void list_iter(List *list, IterFunctor functor) {
    Elmt *elmt = list->head;
    while (elmt != NULL) 
        functor(elmt->data);
}

void list_remove_val(List *list, void *data) {
    Elmt *elmt = list->head;
    while (elmt != NULL) {
        if (elmt->data == data) {
            list_remove_elmt(list, elmt);
            return;
        }
    }
}

void list_clear(List *list) {
    Elmt *elmt = list->head;
    while (elmt != NULL)
        list_remove_elmt(list, elmt);
}

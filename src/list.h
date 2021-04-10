#ifndef list_h
#define list_h

#include "common.h"

// doubly-linked list

typedef struct _Elmt {
    void *data;
    struct _Elmt *next;
    struct _Elmt *prev;
} Elmt;

typedef struct {
    int length;
    Elmt *head;
    Elmt *tail;
} List;

typedef void (*IterFunctor)(Elmt*);

void elmt_init(Elmt *elmt, void *data);
void list_init(List *list);
void list_push(List *list, Elmt *elmt);
void list_remove_elmt(List *list, Elmt *elmt);
void list_remove_tail(List *list);
void list_remove_val(List *list, void *data);
void list_clear(List *list);
void list_iter(List *list, IterFunctor functor);

#endif
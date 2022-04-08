#ifndef LIST_H
#define LIST_H

#include "config.h"

typedef long   indx_t;

const indx_t INVLD_INDX = -666;

struct Node
{
    indx_t next = 0;
    indx_t prev = 0;

    elem_t data = 0;
};

struct List 
{
    indx_t capacity = 0;
    indx_t size     = 0;
    indx_t free     = 0;
    bool   sorted   = 0;

    Node* node_arr = nullptr;
};

enum List_err
{
    LIST_NOERR        =   0,
    LIST_NULLPTR      =  -1,
    LIST_BAD_ALLOC    =  -2,
    LIST_BAD_INDX     =  -3,
    LIST_MISS         =  -7,
    LIST_CYCLE        =  -8,
    LIST_RIP          =  -9,
    LIST_FREE_MISS    = -10,
    LIST_FREE_CYCLE   = -11,
    LIST_FREE_BADINDX = -12,
    LIST_ACCESS_FREE  = -13,
    LIST_REINIT       = -14,
    LIST_NOT_INIT     = -15,
    LIST_EMPTY        = -16,
};

indx_t list_init      (List* list, indx_t init_cap = 0);
indx_t list_dstr      (List* list);

indx_t list_push_front(List* list, elem_t  elem);
indx_t list_pop_front (List* list, elem_t* elem);

indx_t list_push_back (List* list, elem_t  elem);
indx_t list_pop_back  (List* list, elem_t* elem);

indx_t list_insert    (List* list, indx_t pos, elem_t  elem);
indx_t list_extract   (List* list, indx_t pos, elem_t* elem);

indx_t list_find           (List* list, indx_t lpos);
indx_t list_defragmentation(List* list);

#endif // LIST_H
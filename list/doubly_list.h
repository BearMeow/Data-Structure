#ifndef DOUBLY_LIST_H
#define DOUBLY_LIST_H

#include <stdbool.h>

/* To determine data type that node store. */
typedef int type;

typedef struct d_node
{
  /* doubly linked list node structure */
  type data;            /* Data that node store */
  struct d_node *prev;  /* Pointer point previous node in linked list. */
  struct d_node *next;  /* Pointer point next node in linked list. */
} d_node;

typedef struct
{
  /* doubly linked list structure */
  int size;     /* How many nodes are in doubly linked list. */
  d_node head;  /* Head node in linked list. */
} d_list;

void d_list_init(d_list *dl);
bool d_list_insert_front(d_list *dl, type data);
bool d_list_insert_back(d_list *dl, type data);
void d_list_delete(d_list *dl, type data);
void d_list_clear(d_list *dl);
int d_list_size(d_list *dl);

#endif /* DOUBLYLIST_H */

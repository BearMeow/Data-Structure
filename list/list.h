#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/* To determine data type that node store. */
typedef int type;

typedef struct node
{
  /* node structure */
  type data;   /* Data that node store */
  struct node *next;  /* Pointer point next node in linked list. */
} node;

typedef struct
{
  /* list structure */
  int size;     /* How many nodes are in linked list. */
  node *begin;  /* Pointer point first node in linked list. */
} list;

void list_init(list *l);
bool list_insert_front(list *l, type data);
bool list_insert_back(list *l, type data);
void list_delete(list *l, type data);
void list_clear(list *l);
void list_reverse(list *l);
int list_size(list *l);

#endif /* LIST_H */

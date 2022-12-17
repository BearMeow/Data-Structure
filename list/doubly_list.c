#include <stdlib.h>
#include "doubly_list.h"

void d_list_init(d_list *dl)
{
  dl->size = 0;
  dl->head.prev = &dl->head;
  dl->head.next = &dl->head;
}

bool d_list_insert_front(d_list *dl, type data)
{
  d_node *new_node = NULL;
  
  new_node = (d_node *)malloc(sizeof(d_node));
  if(new_node != NULL)
  {
    /* Insert new node after head node. */
    new_node->data = data;
    new_node->prev = &dl->head;
    new_node->next = dl->head.next;

    dl->head.next->prev = new_node;
    dl->head.next = new_node;

    dl->size++;
    
    return true;
  }
  else
  {
    /* Memory allocation of new node failed. */
    return false;
  }
}

bool d_list_insert_back(d_list *dl, type data)
{
  d_node *new_node = NULL;
  
  new_node = (d_node *)malloc(sizeof(d_node));
  if(new_node != NULL)
  {
    /* Insert new node before head node. */
    new_node->data = data;
    new_node->prev = dl->head.prev;
    new_node->next = &dl->head;

    dl->head.prev->next = new_node;
    dl->head.prev = new_node;

    dl->size++;
    
    return true;
  }
  else
  {
    /* Memory allocation of new node failed. */
    return false;
  }
}

void d_list_delete(d_list *dl, type data)
{
  d_node *cur = dl->head.next, *pre = NULL;
  
  while(cur != &dl->head && cur->data != data)
  {
    pre = cur;
    cur = cur->next;
  }

  if(cur != NULL)
  {
    /* Node which stored data equal data in linked list. */
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;

    free(cur);  /* Free deleted node memory */
    dl->size--;
  }
}

void d_list_clear(d_list *dl)
{
  d_node *cur = dl->head.next, *tmp;
  
  while(cur != &dl->head)
  {
    tmp = cur->next;
    free(cur);
    cur = tmp;

    dl->size--;
  }
  
  dl->head.prev = &dl->head;
  dl->head.next = &dl->head;
}

int d_list_size(d_list *dl)
{
  return dl->size;
}

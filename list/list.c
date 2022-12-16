#include <stdlib.h>
#include "list.h"

void list_init(list *l)
{
  l->size = 0;
  l->begin = NULL;
}

bool list_insert_front(list *l, type data)
{
  node *new_node = NULL;
  
  new_node = (node *)malloc(sizeof(node));
  if(new_node != NULL)
  {
    new_node->data = data;
    new_node->next = l->begin;
    l->begin = new_node;
    l->size++;

    return true;
  }
  else
  {
    /* Memory allocation of new node failed. */
    return false;
  }
}

bool list_insert_back(list *l, type data)
{
  node *new_node = NULL;
  
  new_node = (node *)malloc(sizeof(node));
  if(new_node != NULL)
  {
    new_node->data = data;
    new_node->next = NULL;
    
    if(l->begin == NULL)
    {
      l->begin = new_node;
    }
    else
    {
      node *cur = l->begin;
      while(cur->next != NULL)
      {
        cur = cur->next;
      }
      cur->next = new_node;
    }
    l->size++;
    
    return true;
  }
  else
  {
    /* Memory allocation of new node failed. */
    return false;
  }
}

void list_delete(list *l, type data)
{
  node *cur = l->begin, *pre = NULL;
  
  while(cur != NULL && cur->data != data)
  {
    pre = cur;
    cur = cur->next;
  }

  if(cur != NULL)
  {
    /* Node which stored data equal data in linked list. */
    if(cur == l->begin)
    {
      l->begin = cur->next;
    }
    else
    {
      pre->next = cur->next;
    }
    free(cur);  /* Free deleted node memory */
    l->size--;
  }
}

void list_clear(list *l)
{
  node *cur;

  while(l->begin != NULL)
  {
    cur = l->begin;
    l->begin = l->begin->next;
    free(cur);
    l->size--;
  }
}

void list_reverse(list *l)
{
  if(l->begin == NULL || l->begin->next == NULL)
  {
    /* List is empty or list has only one node. */
    return;
  }

  node *pre = NULL;            /* previous node of current node */
  node *cur = l->begin;        /* current node */
  node *nex = l->begin->next;  /* next node of current node */

  while(nex != NULL)
  {
    cur->next = pre;  /* To rotate current node next pointer. */

    pre = cur;        /* previous node back 1 node */
    cur = nex;        /* current node back 1 node */
    nex = nex->next;  /* next node back 1 node */
  }

  cur->next = pre;
  l->begin = cur;  
}

int list_size(list *l)
{
  return l->size;
}

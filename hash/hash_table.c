#include "hash_table.h"
#include <stdlib.h>

void hash_init(hash_table *h)
{
  for(int i=0; i<TABLE_SIZE; i++)
  {
    h->table[i].next = NULL;
  }
}

bool hash_search(hash_table *h, type data)
{
  /* Calculate slot location. */
  node *cur = h->table[HASH(PREHASHING(data))].next;

  while(cur != NULL)
  {
    if(cur->data == data)
    {
      return true;
    }
    cur = cur->next;
  }

  return false;
}

bool hash_insert(hash_table *h, type data)
{
  /* Calculate slot location. */
  node *cur = &h->table[HASH(PREHASHING(data))];

  while(cur->next != NULL)
  {
    cur = cur->next;
  }
  
  node *new_node = (node *)malloc(sizeof(node));
  if(new_node != NULL)
  {
    new_node->data = data;
    new_node->next = NULL;
    cur->next = new_node;
    
    return true;
  }
  else
  {
    /* Memory allocation of new node failed. */
    return false;
  }
}

void hash_delete(hash_table *h, type data)
{
  node *pre = &h->table[HASH(PREHASHING(data))];
  node *cur = pre->next;

  while(cur != NULL)
  {
    if(cur->data == data)
    {
      pre->next = cur->next;
      free(cur);

      return ;
    }
    pre = cur;
    cur = cur->next;
  }
}

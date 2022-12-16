#include <stdio.h>
#include "list.h"

void print(list *l);

int main(void)
{
  list l;
  
  list_init(&l);
  list_insert_front(&l, 1);
  list_insert_back(&l, 2);
  list_insert_back(&l, 3);
  printf("linked list                =");
  print(&l);
  
  list_reverse(&l);
  printf("linked list after reverse  =");
  print(&l);

  list_delete(&l, 2);
  printf("linked list after delete 2 =");
  print(&l);
  
  list_clear(&l);
  printf("linked list after clear    =");
  print(&l);

  printf("linked list size = %d\n", list_size(&l));

  return 0;
}

void print(list *l)
{
  node *cur = l->begin;
  
  while(cur != NULL)
  {
    printf(" %d", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

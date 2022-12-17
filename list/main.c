#include <stdio.h>
#include "list.h"
#include "doubly_list.h"

#define SINGLY 0
#define DOUBLY 1
#define LIST   SINGLY

void print(list *l);
void d_print(d_list *dl);
void d_print_reverse(d_list *dl);

int main(void)
{
#if (LIST == SINGLY)
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
#elif (LIST == DOUBLY)
  d_list dl;
  
  d_list_init(&dl);
  d_list_insert_front(&dl, 1);
  d_list_insert_back(&dl, 2);
  d_list_insert_back(&dl, 3);
  printf("doubly linked list                =");
  d_print(&dl);

  printf("doubly linked list reverse print  =");
  d_print_reverse(&dl);

  d_list_delete(&dl, 2);
  printf("doubly linked list after delete 2 =");
  d_print(&dl);
  
  d_list_clear(&dl);
  printf("doubly linked list after clear    =");
  d_print(&dl);

  printf("doubly linked list size = %d\n", d_list_size(&dl));
#endif

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

void d_print(d_list *dl)
{
  d_node *cur = dl->head.next;
  
  while(cur != &dl->head)
  {
    printf(" %d", cur->data);
    cur = cur->next;
  }
  printf("\n");
}

void d_print_reverse(d_list *dl)
{
  d_node *cur = dl->head.prev;
  
  while(cur != &dl->head)
  {
    printf(" %d", cur->data);
    cur = cur->prev;
  }
  printf("\n");
}

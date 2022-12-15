#include <stdio.h>
#include "stack.h"

int main(void)
{
  stack st;
  int data = 0;

  stack_init(&st);
  
  if(stack_push(&st, 8))
  {
    printf("push %d to into stack\n", 8);
  }

  printf("pop %d from stack\n", stack_pop(&st));

  return 0;
}

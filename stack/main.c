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
  
  if(stack_pop(&st, &data))
  {
    printf("pop %d from stack\n", data);
  }

  return 0;
}

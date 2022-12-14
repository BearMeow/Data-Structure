#include "stack.h"

void stack_init(stack *st)
{
  st->top = -1;
  st->size = 0;
}

bool stack_push(stack *st, int data)
{
  if(st->size + 1 > CAPACITY)
  {
    /* Full stack can not push any more element. */
    return false;
  }
  else
  {
    /* Placing new element at top + 1. */
    st->arr[++st->top] = data;
    st->size++;

    return true;
  }
}

bool stack_pop(stack *st, int *data)
{
  if(st->size <= 0)
  {
    /* Empty stack can not pop any element. */
    return false;
  }
  else
  {
    /* Removing last insert element from top index. */
    *data = st->arr[st->top--];
    st->size--;

    return true;
  }
}

bool stack_empty(stack *st)
{
  return (st->size == 0);
}

bool stack_full(stack *st)
{
  return (st->size >= CAPACITY);
}

int stack_size(stack *st)
{
  return st->size;
}

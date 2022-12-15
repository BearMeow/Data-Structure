#include "stack.h"

void stack_init(stack *st)
{
  st->top = -1;
  st->size = 0;
}

bool stack_push(stack *st, type data)
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

type stack_pop(stack *st)
{
  /* Removing last insert element from top index. */
  st->size--;
  return st->arr[st->top--];
}

type stack_peek(stack *st)
{
  /* Peeking last insert element from top index. */
  return st->arr[st->top];
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

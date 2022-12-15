#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/* To determine maximum stack storage size. */
#define CAPACITY (16)

/* To determine data type of stack element. */
typedef int type;

typedef struct
{
  /* stack data structure */
  int top;            /* Index point last push element. */
  int size;           /* Size of stack. */
  type arr[CAPACITY];  /* Storage of stack (array implementation). */
} stack;

void stack_init(stack *st);
bool stack_push(stack *st, type data);
type stack_pop(stack *st);
type stack_peek(stack *st);
bool stack_empty(stack *st);
bool stack_full(stack *st);
int stack_size(stack *st);

#endif /* STACK_H */

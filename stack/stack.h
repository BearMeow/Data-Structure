#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/* To determine maximum stack storage size. */
#define CAPACITY (1)

typedef struct
{
  /* stack data structure */
  int top;            /* Index point last push element. */
  int size;           /* Size of stack. */
  int arr[CAPACITY];  /* Storage of stack (array implementation). */
} stack;

void stack_init(stack *st);
bool stack_push(stack *st, int data);
bool stack_pop(stack *st, int *data);
bool stack_empty(stack *st);
bool stack_full(stack *st);
int stack_size(stack *st);

#endif /* STACK_H */

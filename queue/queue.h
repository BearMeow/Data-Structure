#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

/* To determine maximum queue storage size. */
#define CAPACITY (1)

typedef struct
{
  /* queue data structure */
  int front;          /* Index + 1 point first pushed element in queue. */
  int back;           /* Index point last pushed element in queue. */
  int size;           /* Size of queue. */
  int arr[CAPACITY];  /* Storage of queue (array implementation). */
} queue;

void queue_init(queue *q);
bool queue_push(queue *q, int data);
bool queue_pop(queue *q, int *data);
bool queue_empty(queue *q);
bool queue_full(queue *q);
int queue_size(queue *q);

#endif /* QUEUE_H */

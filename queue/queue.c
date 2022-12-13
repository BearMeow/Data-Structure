#include "queue.h"

void queue_init(queue *q)
{
  q->front = 0;
  q->back = 0;
  q->size = 0;
}

bool queue_push(queue *q, int data)
{
  if(q->size + 1 > CAPACITY)
  {
    /* Full queue can not push any more element. */
    return false;
  }
  else
  {
    /* Placing new element at back + 1 modulo queue capacity 
     * because circular queue implementation. */
    q->arr[(++q->back) % CAPACITY] = data;
    q->size++;

    return true;
  }
}

bool queue_pop(queue *q, int *data)
{
  if(q->size <= 0)
  {
    /* Empty queue can not pop any element. */
    return false;
  }
  else
  {
    /* Removing first insert element from front + 1 modulo queue
     * capacity because circular queue implementation. */
    *data = q->arr[(++q->front) % CAPACITY];
    q->size--;

    return true;
  }
}

bool queue_empty(queue *q);
bool queue_full(queue *q);
int queue_size(queue *q);


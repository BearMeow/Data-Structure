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
    q->back = (q->back + 1) % CAPACITY;
    q->arr[q->back] = data;
    q->size++;

    return true;
  }
}

type queue_pop(queue *q)
{
  /* Removing first insert element from front + 1 modulo queue
   * capacity because circular queue implementation. */
  q->size--;
  q->front = (q->front + 1) % CAPACITY;
  
  return q->arr[q->front];
}

bool queue_empty(queue *q)
{
  return (q->back == q->front);
}

bool queue_full(queue *q)
{
  return (((q->back + 1) % CAPACITY) == q->front);
}

int queue_size(queue *q)
{
  return q->size;
}

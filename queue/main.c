#include <stdio.h>
#include "queue.h"

int main(void)
{
  queue q;
  int data = 0;

  queue_init(&q);
  
  if(queue_push(&q, 8))
  {
    printf("push %d to into queue\n", 8);
  }

  if(queue_pop(&q, &data))
  {
    printf("pop %d from queue\n", data);
  }

  return 0;
}

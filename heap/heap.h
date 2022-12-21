#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>

/* tree[0] is unused 
 * parent(node i)      = floor(i / 2) 
 * left_child(node i)  = 2 * i
 * right_child(node i) = (2 * i) + 1 */
#define MAX_SIZE  8
#define ROOT      1
#define PARENT(i) (i/2)
#define LEFT(i)   (2*i)
#define RIGHT(i)  (2*i+1)

/* To determine data type that node store. */
typedef int type;

typedef struct
{
  /* heap structure */
  int size;             /* How many nodes in heap. */
  type tree[MAX_SIZE];  /* Complete binary tree with array representation. */
} heap;


void heap_init(heap *h, type *arr, int n);
type heap_pop(heap *h);
void heap_insert(heap *h, type data);
int heap_size(heap *h);
void heap_sort(type *arr, int n);

#endif /* HEAP_H */

#include "heap.h"

void heapify(heap *h, int i)
{
  /* Heapify node i in binary tree of heap h. */
  int left = LEFT(i), right = RIGHT(i), smallest;

  if(left <= h->size && h->tree[left] < h->tree[i])
  {
    smallest = left;
  }
  else
  {
    smallest = i;
  }

  if(right <= h->size && h->tree[right] < h->tree[smallest])
  {
    smallest = right;
  }

  if(smallest != i)
  {
    type tmp = h->tree[smallest];
    h->tree[smallest] = h->tree[i];
    h->tree[i] = tmp;

    heapify(h, smallest);
  }
}

void heap_init(heap *h, type *arr, int n)
{
  for(int i=0; i<n; i++)
  {
    h->tree[i+1] = arr[i];
  }
  h->size = n;

  for(int i=h->size/2; i>=1; i--)
  {
    heapify(h, i);
  }
}

type heap_pop(heap *h)
{
  type min = h->tree[1];
  h->tree[1] = h->tree[h->size];
  heapify(h, 1);
  h->size--;

  return min;
}

void heap_insert(heap *h, type data)
{
  /* New data at end location. */
  h->tree[++h->size] = data;

  int i = h->size;

  while(i>1 && h->tree[PARENT(i)] > h->tree[i])
  {
    /* Compare with parent if current < parent
     * then swap two node. contiune execute
     * until reach root or current > parent */
    type tmp = h->tree[i];
    h->tree[i] = h->tree[PARENT(i)];
    h->tree[PARENT(i)] = tmp;

    i = PARENT(i);
  }
}

int heap_size(heap *h)
{
  return h->size;
}

void heap_sort(type *arr, int n)
{
  /* MIN heap = descending order sorting */
  heap h;

  heap_init(&h, arr, n);

  for(int i=h.size; i>=2; i--)
  {
    /* Swap root(minimum) and end node. */
    type tmp = h.tree[i];
    h.tree[i] = h.tree[1];
    h.tree[1] = tmp;
    
    /* Ignoring end node which is already sorting. */
    h.size--;
    heapify(&h, 1);
  }

  /* Binary tree of heap is a sorting array
   * copy content to arr. */
  for(int i=0; i<n; i++)
  {
    arr[i] = h.tree[i+1];
  }
}

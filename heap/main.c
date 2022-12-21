#include <stdio.h>
#include "heap.h"

void print_heap(heap *h);

int main(void)
{
  int arr[6] = {8, 4, 9, 6, 5, 7};
  
  heap h;
  heap_init(&h, arr, sizeof(arr)/sizeof(arr[0]));

  printf("heap                 = ");
  print_heap(&h);
  printf("\n");

  printf("heap minimum         = %d\n", heap_pop(&h));

  printf("heap after pop       = ");
  print_heap(&h);
  printf("\n");

  heap_insert(&h, 1);

  printf("heap after insert 1  = ");
  print_heap(&h);
  printf("\n");

  printf("arr before heap sort = ");
  for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");

  heap_sort(arr, sizeof(arr)/sizeof(arr[0]));
  printf("arr after heap sort  = ");
  for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}

void print_heap(heap *h)
{
  for(int i=1; i<=h->size; i++)
  {
    printf("%d ", h->tree[i]);
  }
}

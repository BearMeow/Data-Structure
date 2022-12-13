#include <stdio.h>

void selection_sort(int *arr, int n);
void swap(int *a, int *b);
void print(int *arr, int n);

int main(void)
{
  int arr[7] = {3, 2, 1, 6, 5, 4, 7};
  
  printf("before sorting = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));
  
  selection_sort(arr, sizeof(arr)/sizeof(arr[0]));
  
  printf("after sorting  = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));

  return 0;
}

void selection_sort(int *arr, int n)
{
  int min_idx;

  for(int i=0; i<n-1; i++)
  {
    min_idx = i;
    for(int j=i+1; j<n; j++)
    {
      /* Selecting minimum number in unsorting array. */
      if(arr[min_idx]>arr[j])
      {
        min_idx = j;
      }
    }

    if(min_idx != i)
    {
      swap(&arr[min_idx], &arr[i]);
    }
  }
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void print(int *arr, int n)
{
  for(int i=0; i<n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

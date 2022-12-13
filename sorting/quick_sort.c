#include <stdio.h>

int partition(int *arr, int front, int end);
void quick_sort(int *arr, int front, int end);
void swap(int *a, int *b);
void print(int *arr, int n);

int main(void)
{
  int arr[7] = {3, 2, 1, 6, 5, 4, 7};
  
  printf("before sorting = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));

  quick_sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
  
  printf("after sorting  = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));

  return 0;
}

void quick_sort(int *arr, int front, int end)
{
  if(front < end)
  {
    int pivot = partition(arr, front, end);
    quick_sort(arr, front, pivot - 1);
    quick_sort(arr, pivot + 1, end);
  }
}

int partition(int *arr, int front, int end)
{
  int pivot = arr[end];
  int i = front - 1;

  for(int j=front; j<end; j++)
  {
    if(arr[j] < pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  i++;
  swap(&arr[i], &arr[end]);

  return i;
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

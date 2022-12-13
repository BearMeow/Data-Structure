#include <stdio.h>

void bubble_sort(int *arr, int n);
void swap(int *a, int *b);
void print(int *arr, int n);

int main(void)
{
  int arr[7] = {3, 2, 1, 6, 5, 4, 7};
  
  printf("before sorting = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));
  
  bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));
  
  printf("after sorting  = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));

  return 0;
}

void bubble_sort(int *arr, int n)
{
  for(int i=0; i<n-1; i++)
  {
    for(int j=0; j<n-i-1; j++)
    {
      if(arr[j]>arr[j+1])
      {
        swap(&arr[j], &arr[j+1]);
      }
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

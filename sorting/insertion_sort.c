#include <stdio.h>

void insertion_sort(int *arr, int n);
void swap(int *a, int *b);
void print(int *arr, int n);

int main(void)
{
  int arr[7] = {3, 2, 1, 6, 5, 4, 7};
  
  printf("before sorting = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));

  insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
  
  printf("after sorting  = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));

  return 0;
}

void insertion_sort(int *arr, int n)
{
  int i, j, key;

  for(i=1; i<n; i++)
  {
    key = arr[i];
    for(j=i-1; j>=0; j--)
    {
      if(arr[j]>key)
      {
        arr[j+1] = arr[j];
      }
      else
      {
        break;
      }
    }
    arr[j+1] = key;
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

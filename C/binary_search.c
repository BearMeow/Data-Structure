#include <stdio.h>

int binary_search(int *arr, int n, int x);

int main(void)
{
  int arr[5] = {3, 5, 7, 8, 9};
  int i;

  i = binary_search(arr, 5, 8);
  if(i != -1)
  {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
  else
  {
    printf("8 not found\n");
  }

  i = binary_search(arr, 5, 1);
  if(i != -1)
  {
    printf("arr[%d] = %d\n", i, arr[i]);
  }
  else
  {
    printf("1 not found\n");
  }


  return 0;
}

int binary_search(int *arr, int n, int x)
{
  int begin = 0, end = n - 1, mid;

  while(begin <= end)
  {
    mid = (begin + end) / 2;
    if(arr[mid] < x) {
      begin = mid + 1;
    }
    else if(x < arr[mid])
    {
      end = mid - 1;
    }
    else
    {
      /* arr[mid] == x */
      return mid;
    }
  }

  return -1; /* x not found */
}

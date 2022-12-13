#include <stdio.h>

void merge(int *arr, int left, int mid, int right);
void merge_sort(int *arr, int left, int right);
void swap(int *a, int *b);
void print(int *arr, int n);

int main(void)
{
  int arr[7] = {3, 2, 1, 6, 5, 4, 7};
  
  printf("before sorting = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));

  merge_sort(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
  
  printf("after sorting  = ");
  print(arr, sizeof(arr)/sizeof(arr[0]));

  return 0;
}

void merge_sort(int *arr, int left, int right)
{
  if(left < right)
  {
    /* Same as (l+r)/2, but avoids overflow for large l and h. */
    int mid = left + (right - left) / 2;

    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
 
    merge(arr, left, mid, right);
  }
}

void merge(int *arr, int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1], R[n2];

  for(i=0; i<n1; i++)
  {
    L[i] = arr[left + i];
  }
  for(j=0; j<n2; j++)
  {
    R[j] = arr[mid + 1 + j];
  }
        
  i = 0;     /* Initial index of first subarray. */
  j = 0;     /* Initial index of second subarray. */
  k = left;  /* Initial index of merged subarray. */

  /* Merge the temp arrays back into arr[left ~ right]. */
  while(i < n1 && j < n2)
  {
    if(L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
 
  /* Copy the remaining elements of L[], if there are any. */
  while(i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }
 
  /* Copy the remaining elements of R[], if there are any. */
  while(j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
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

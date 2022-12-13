#include <stdio.h>

typedef enum
{
  A,
  B,
  C
} E;

int main(void)
{
  E e = A;

  if(e == A)
  {
    printf("e == A\n");
  }

  printf("A = %d\n", A);
  printf("B = %d\n", B);
  printf("C = %d\n", C);

  return 0;
}

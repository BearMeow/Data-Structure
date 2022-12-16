#include <stdio.h>

void f0(int a)
{
  printf("Hello World\n");
}

/* Function pointer as a parameter. */
void f1(void (*f)(int))
{
  f(0);
}

/* f_type = function pointer with prototype void f(int). */
typedef void (*f_type)(int);

/* Array that store function pointer. */
void (*f_arr[])(int) = {f0, f0};

int main(void)
{
  /* Declaring a function pointer. */
  void (*fp)(int);
  fp = f0;
  fp(0);
  f1(f0);

  return 0;
}

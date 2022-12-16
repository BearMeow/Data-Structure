#include <stdio.h>

int main(void)
{
  char s0[8] = "12345";
  char s1[]  = "12345";
  char *s2   = "12345";
  char t[64];

  /* 8 = char array with 8 items ['1', '2', '3', '4', '5', '\0', ?, ?] */
  sprintf(t, "sizeof(s0) = %lu -> char s0[8] = \"%s\";\n", sizeof(s0), s0);
  fputs(t, stdout);

  /* 6 = char array with 6 items ['1', '2', '3', '4', '5', '\0'] */
  sprintf(t, "sizeof(s1) = %lu -> char s1[]  = \"%s\";\n", sizeof(s1), s1);
  fputs(t, stdout);

  /* 4 = char pointer size, 32-bit computer architecture = 32-bit = 4 byte */
  sprintf(t, "sizeof(s2) = %lu -> char *s2   = \"%s\";\n", sizeof(s2), s2);
  fputs(t, stdout);

  return 0;
}

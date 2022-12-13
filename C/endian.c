#include <stdio.h>
#include <stdint.h>

typedef union
{
  uint16_t n;
  uint8_t  c[2];
} endian;

int main(void)
{
  endian e;

  e.n = 0x1234;

  if(e.c[0] == 0x12 && e.c[1] == 0x34)
  {
    printf("big-endian\n");
  }
  else if(e.c[0] == 0x34 && e.c[1] == 0x12)
  {
    printf("little-endian\n");
  }

  return 0;
}

#include <stdio.h>
#include <stdint.h>

typedef union
{
  uint32_t a;
  uint8_t b[8];
} U;

int main(void)
{
  U u;

  printf("sizeof(U) = %lu\n", sizeof(U));

  for(int i=0; i<8; i++)
  {
    /* Clear array. */
    u.b[i] = 0x00;
  }

  u.a = 0x12345678;
  for(int i=0; i<8; i++)
  {
    printf("%02X ", u.b[i]);
  }
  printf("\n");

  return 0;
}
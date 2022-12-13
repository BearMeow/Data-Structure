#include <stdio.h>
  
/* Alignment requirements (typical 32 bit machine)
 * char         1 byte
 * short        2 bytes
 * int          4 bytes
 * double       8 bytes */

typedef struct
{
  /* char + 1 padding + short = 4 */
  char  c;
  short s;
} A;

typedef struct
{
  /* short + char + 1 padding + int = 8 */
  short s;
  char  c;
  int   i;
} B;

typedef struct
{
  /* char + 7 padding + double + int + 4 padding =
   * 24 = 3 * MAX(data type in struct) */
  char   c;
  double d;
  int    s;
} C;

typedef struct
{
  /* double + int + char + 3 padding =
   * 16 = 2 * MAX(data type in struct) */
  double d;
  int    s;
  char   c;
} D;

typedef struct
{
  /* char + 7 padding + double + int =  20 */
  char   c;
  double d;
  int    s;
} __attribute__((packed)) C_packed;

int main(void)
{
  printf("sizeof(A) = %lu\n", sizeof(A));
  printf("sizeof(B) = %lu\n", sizeof(B));
  printf("sizeof(C) = %lu\n", sizeof(C));
  printf("sizeof(D) = %lu\n", sizeof(D));

  printf("----------------packed attribute----------------\n");
  printf("sizeof(C)        = %lu\n", sizeof(C));
  printf("sizeof(C_packed) = %lu\n", sizeof(C_packed));
  
  return 0;
}
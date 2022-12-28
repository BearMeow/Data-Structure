#include <stdio.h>

typedef struct
{
  int x;
  int y;
  int w;  /* weight of edge */
} edge_t;


int main(void)
{
  /*     10
      0--------1
      | \      |
     6|   5\   |15
      |      \ |
      2--------3
          4        */

  /* increasing sorted edges array */
  edge_t edges[5] = {{2,3,4},
                     {0,3,5},
                     {0,2,6},
                     {0,1,10},
                     {1,3,15},};
}


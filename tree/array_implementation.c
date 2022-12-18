#include <stdio.h>

/* Tree with height = 2, tree[0] is unused 
 * parent(node i)      = floor(i / 2) 
 * left_child(node i)  = 2 * i
 * right_child(node i) = (2 * i) + 1 */
#define MAX_SIZE  8
#define ROOT      1
#define PARENT(i) (i/2)
#define LEFT(i)   (2*i)
#define RIGHT(i)  (2*i+1)
int tree[MAX_SIZE];

const int EMPTY_NODE = -1;
void preorder(int i);

int main(void)
{
  /*      8
   *     / \
   *    7   2
   *   / \ 
   *  3   9       */

  for(int i=0; i<MAX_SIZE; i++)
  {
    tree[i] = EMPTY_NODE;
  }

  tree[ROOT] = 8; /* root node */
  tree[LEFT(ROOT)] = 7;
  tree[RIGHT(ROOT)] = 2;
  tree[LEFT(LEFT(ROOT))] = 3;
  tree[RIGHT(LEFT(ROOT))] = 9;

  printf("preorder = ");
  preorder(ROOT);
  printf("\n");

  return 0;
}

void preorder(int i)
{
  if(i < MAX_SIZE && tree[i] != EMPTY_NODE)
  {
    printf("%d ", tree[i]);
    preorder(LEFT(i));
    preorder(RIGHT(i));
  }
}
#include <stdio.h>

/* tree[0] is unused 
 * parent(node i)      = floor(i / 2) 
 * left_child(node i)  = 2 * i
 * right_child(node i) = (2 * i) + 1 */
#define MAX_SIZE  8
#define ROOT      1
#define PARENT(i) (i/2)
#define LEFT(i)   (2*i)
#define RIGHT(i)  (2*i+1)
int tree[MAX_SIZE];


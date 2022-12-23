#include <stdio.h>
#include <stdbool.h>
#include "hash_table.h"

int main(void)
{
  hash_table h;
  bool b;

  hash_init(&h);

  hash_insert(&h, 3);
  printf("insert 3\n");
  hash_insert(&h, 14);
  printf("insert 14\n");

  if(hash_search(&h, 3))
  {
    printf("3 in hash table\n");
  }
  else
  {
    printf("3 not in hash table\n");
  }

  if(hash_search(&h, 14))
  {
    printf("14 in hash table\n");
  }
  else
  {
    printf("14 not in hash table\n");
  }

  hash_delete(&h, 3);
  printf("delete 3\n");

  if(hash_search(&h, 3))
  {
    printf("3 in hash table\n");
  }
  else
  {
    printf("3 not in hash table\n");
  }

  return 0;
}



#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdbool.h>

/* Division Method : table size is a prime
 * which far from exponent of 2. */
#define TABLE_SIZE 11
#define HASH(key) (key % TABLE_SIZE)
#define PREHASHING(data) (data)

/* To determine data type that node store. */
typedef int type;

typedef struct node
{
  /* node structure */
  type data;          /* Data that node store */
  struct node *next;  /* Pointer point next node in linked list. */
} node;

typedef struct
{
  /* Chaning method to slove collision.
   * First node of list is unused. */
  node table[TABLE_SIZE];
} hash_table;

void hash_init(hash_table *h);
bool hash_search(hash_table *h, type data);
bool hash_insert(hash_table *h, type data);
void hash_delete(hash_table *h, type data);

#endif /* HASH_TABLE_H */

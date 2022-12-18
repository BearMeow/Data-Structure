#ifndef BINARY_TREE_H
#define BINARY_TREE_H

/* To determine data type that tree node store. */
typedef int type;

typedef struct tree_node
{
  /* tree node structure */
  type data;                /* Data that node store */
  struct tree_node *left;   /* Pointer point left child of node. */
  struct tree_node *right;  /* Pointer point right child of node. */
} tree_node;

tree_node * new_tree_node(type data);
void preorder(tree_node *t);
void inorder(tree_node *t);
void postorder(tree_node *t);
void level_order(tree_node *t);

#endif /* BINARY_TREE_H */

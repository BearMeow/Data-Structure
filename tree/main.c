#include <stdio.h>
#include "binary_tree.h"

int main(void)
{
  /*      8
   *     / \
   *    7   2
   *   / \ 
   *  3   9       */
  tree_node *root = new_tree_node(8);
  root->left = new_tree_node(7);
  root->right = new_tree_node(2);
  root->left->left = new_tree_node(3);
  root->left->right = new_tree_node(9);

  printf("preorder    = ");
  preorder(root);
  printf("\n");

  printf("inorder     = ");
  inorder(root);
  printf("\n");

  printf("postorder   = ");
  postorder(root);
  printf("\n");

  printf("level order = ");
  level_order(root);
  printf("\n");

  return 0;
}

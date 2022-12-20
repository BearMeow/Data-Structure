#include <stdio.h>
#include "binary_tree.h"

tree_node * BST_search(tree_node *t, const int KEY);

int main(void)
{
  /*      7
   *     / \
   *    4   9
   *   / \ 
   *  1   6       */
  tree_node *root = new_tree_node(7);
  root->left = new_tree_node(4);
  root->right = new_tree_node(9);
  root->left->left = new_tree_node(1);
  root->left->right = new_tree_node(6);

  printf("inorder = ");
  inorder(root);
  printf("\n");

  tree_node *tmp;
  tmp = BST_search(root, 6);
  if(tmp != NULL)
  {
    printf("node %d found\n", tmp->data);
  }
  else
  {
    printf("node 6 not found\n");
  }
  

  return 0;
}

tree_node * BST_search(tree_node *t, const int KEY)
{
  tree_node *cur = t;

  while(cur != NULL && KEY != cur->data)
  {
    if(KEY < cur->data)
    {
      cur = cur->left;
    }
    else
    {
      cur = cur->right;
    }
  }

  return cur;
}

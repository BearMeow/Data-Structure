#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

tree_node * new_tree_node(type data)
{
  tree_node *ptr = (tree_node *)malloc(sizeof(tree_node));
  
  if(ptr != NULL)
  {
    ptr->data  = data;
    ptr->left  = NULL;
    ptr->right = NULL;
  }
  
  return ptr;
}

void preorder(tree_node *t)
{
  if(t != NULL)
  {
    printf("%d ", t->data);
    preorder(t->left);
    preorder(t->right);
  }
}

void inorder(tree_node *t)
{
  if(t != NULL)
  { 
    inorder(t->left);
    printf("%d ", t->data);
    inorder(t->right);
  }
}

void postorder(tree_node *t)
{
  if(t != NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("%d ", t->data);
  }
}

void level_order(tree_node *t)
{
  #define CAPACITY 16
  tree_node *q[CAPACITY];
  int front = 0, back = 0;

  back = (back + 1) % CAPACITY;
  q[back] = t;
  while(front != back)  /* Queue is not empty. */
  {
    front = (front + 1) % CAPACITY;
    tree_node *tmp = q[front];
    
    if(tmp != NULL)
    {
      printf("%d ", tmp->data);

      /* If child exist then push into queue. */
      if(tmp->left != NULL)
      {
        back = (back + 1) % CAPACITY;
        q[back] = tmp->left;
      }
      if(tmp->right != NULL)
      {
        back = (back + 1) % CAPACITY;
        q[back] = tmp->right;
      }
    }
  }
}

#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
  if (t == NULL) //if the tree is empty 
  {
    struct tree_node* helper = (struct tree_node*)malloc(sizeof(struct tree_node));
    helper->item = x;
    helper->left=NULL;
    helper->right=NULL; 
  }
  else if (x > t->item)
  {
    t->right = Insert(x,t->right); //if x is greater than the value of the root insert to the right 
  }
  else{
    t->left = Insert(x, t->left); //if it smaller insert to the lefter according to the rule of tree
  }
  return t; 
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
if (t == NULL)
{
  return t; // if it's empty then just return t, no work to do 
}
else if (x < t->item )
{
 t->left = Remove(x,t->left);
}
else if (x > t->item)
{
  t->right= Remove(x,t->right);
}
else{ 
  // if the input is either grater or lesser then we have to cosider other option 
  // there is no children and there is children 
  struct node* temp = t;
  if (t->left == NULL && t->right == NULL) {
  free(t);
  t = NULL;
  }
  else if (t->right == NULL)
  {
    t = t-> left;
    free (temp);
  }
  else if (t->left == NULL)
  {
    t = t->right;
    free(temp);
  }
  else {
    if (t->left->item > t->right->item){
      t =t->right;
      free(temp);
    }
    else {
      t =t->left;
      free(temp);
    }
  }
    
}
  return t;
}

int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
  if (t == NULL)
  {
    return false;
  }
  
  else if (t->item == x) {
    return true;
  }
  else if (x <= t->item) {
    return Contains(x, t->left);
  }
  else {
    return Contains(x, t->right);
  }
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree¨
  t = NULL;
  return NULL;
}

int Empty(struct tree_node *t) {
  // Test if empty
  if(t == NULL){
    return true;
  }
else {
  return false;
}
  return 0;
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}

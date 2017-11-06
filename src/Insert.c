#include "Insert.h"
#include "stdlib.h"
#include "stdio.h"
#include "node.h"
#include "rotate.h"

//insert new node

Node *insert(Node **rootPtr, Node *nodeToAdd){

    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
        return *rootPtr;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
        (*rootPtr)->left = insert(&(*rootPtr)->left,nodeToAdd);
        (*rootPtr)->balanceFactor -= 1;
      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
        (*rootPtr)->right = insert(&(*rootPtr)->right,nodeToAdd);
        (*rootPtr)->balanceFactor += 1;
      }
    }
    if((*rootPtr)->balanceFactor >= 2)
        avlBalanceRightTree(&(*rootPtr));
    else if((*rootPtr)->balanceFactor <= -2)
        avlBalanceLeftTree(&(*rootPtr));
    else{
        *rootPtr = *rootPtr;
      }
        return *rootPtr;

 }
/*
int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->right;

  if(child->balanceFactor == 1){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
  }
  else if(child->balanceFactor == 0){
    node->balanceFactor = 1;
    child->balanceFactor = -1;
  }
  *rootPtr = rotateleft(*rootPtr) ;
  return 0;
}*/

int avlBalanceRightTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->right;
  Node *grandChild = node->right->left;

  if(child->balanceFactor == -1){
    if(grandChild->balanceFactor == -1)
    {
      node->balanceFactor = 0;
      child->balanceFactor = 1;
      grandChild->balanceFactor = 0;
    }
    else if(grandChild->balanceFactor == 0)
    {
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
    }
    else if(grandChild->balanceFactor == 1)
    {
      node->balanceFactor = -1;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
    }
    *rootPtr = rotaterightleft(*rootPtr);
    return 0;
  }

  else if(child->balanceFactor == 1){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
    }
  else if(child->balanceFactor == 0){
      node->balanceFactor = 1;
      child->balanceFactor = -1;
    }
    *rootPtr = rotateleft(*rootPtr) ;
    return 0;

}

int avlBalanceLeftTree(Node **rootPtr){
  Node *node = *rootPtr;
  Node *child = node->left;
  Node *grandChild = node->left->right;

  if(child->balanceFactor == 1){
    if(grandChild->balanceFactor == 1){
      node->balanceFactor = 0;
      child->balanceFactor = -1;
      grandChild->balanceFactor = 0;
    }
    else if(grandChild->balanceFactor == 0){
      node->balanceFactor = 0;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
    }
    else if(grandChild->balanceFactor == -1){
      node->balanceFactor = 1;
      child->balanceFactor = 0;
      grandChild->balanceFactor = 0;
    }
    *rootPtr = rotateleftright(*rootPtr);
    return 0;
  }
  else if(child->balanceFactor == -1){
    node->balanceFactor = 0;
    child->balanceFactor = 0;
  }
  else if(child->balanceFactor == 0){
    node->balanceFactor = 1;
    child->balanceFactor = -1;
  }
  *rootPtr = rotateright(*rootPtr);
  return 0;
}

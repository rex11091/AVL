#include "Insert.h"
#include "stdlib.h"
#include "stdio.h"
#include "node.h"
#include "rotate.h"


/*

Node *searchNearest(Node **numberTofind,Node *Closer){
}






Node *remove(Node **rootPtr,Node *nodeToRemove){
      if(*rootPtr == nodeToRemove)
        *rootPtr = NULL:
        return *rootPtr;
      }else{
        if((*rootPtr)->left->data == nodeToRemove->data)
          (*rootPtr->left) = remove(*rootPtr)->left,nodeToRemove);

        else if((*rootPtr)->right->data==nodeToRemove->data)
          (*rootPtr)->right = remove(&(*rootPtr)->right,nodeToRemove);
        return *rootPtr;
      }
        return *rootPtr;
}




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

int insert(Node **rootPtr, Node *nodeToAdd){
  int m;//heigh
    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
        return m=1;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
      m = insert(&(*rootPtr)->left,nodeToAdd);   //if adding data will change the heigh,m =1 else m =0;
        if(m==1){
        (*rootPtr)->balanceFactor -= 1;
          if((*rootPtr)->balanceFactor==0)
          m=0;
        }
      else
      (*rootPtr)->balanceFactor =(*rootPtr)->balanceFactor;

      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
      m = insert(&(*rootPtr)->right,nodeToAdd);
        if(m==1){
        (*rootPtr)->balanceFactor += 1;
          if((*rootPtr)->balanceFactor==0)
            m=0;;
          }
        else
          (*rootPtr)->balanceFactor =(*rootPtr)->balanceFactor;
      }
    }
    if((*rootPtr)->balanceFactor >= 2)
        avlBalanceRightTree(&(*rootPtr));
    else if((*rootPtr)->balanceFactor <= -2)
        avlBalanceLeftTree(&(*rootPtr));
    else{
       *rootPtr = *rootPtr;
      }
        return m;
 }
/*
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
*/

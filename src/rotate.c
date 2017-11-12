#include "rotate.h"


/**
---------rotateleft-----------------
*        10            30
*         \           /   \
*          30  ->    10    40
*         / \         \
*        25  40       25
*
**/
/**
---------rotateLeft----------------------
*        30 (+2)                   40
*          \                     /   \
*           40 (+1)   ------->  30    50
*            \
*            50
*
**/
Node *rotateleft(Node *node){
  Node *root;
  root = node->right;
  node->right = node->right->left;
  root->left = node;
  return root;
}


/**
---------rotateright-----------------
*        30         10
*       /          /   \
*      10     ->  5     30
*     / \               /
*    5  20             20
*
**/
Node *rotateright(Node *node){
  Node *root;
  root = node->left;
  node->left = node->left->right;
  root->right = node;
return root;
}
/**
---------rotateleftright-----------------
*        45                   45                   30
*       /  \      RL"10"    /   \      RR"45"     /   \
*      10   50  ------->  30    50  ----------> 10     45
*        \               /  \                     \    / \
*        30             10   40                   25  40 50
*       /  \              \
*      25   40             25
*
**/
Node *rotateleftright(Node *node){
  Node *root;
  node->left = rotateleft(node->left);
  root = rotateright(node);
  return root;
}
/**
---------rotaterightleft-----------------
*         5                   5                   25
*       /  \      RL"40"    /   \      RR"5"     /   \
*      1   40  ------->   1     25  ----------> 5     40
*          /                    / \            /  \   /
*        25                    20 40          1   20  35
*       /  \                     /
*      20   35                  35
*
**/
Node *rotaterightleft(Node *node){
  Node *root;
  node->right = rotateright(node->right);
  root = rotateleft(node);
  return root;
}

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
    node->balanceFactor = -1;
    child->balanceFactor = 1;
  }
  *rootPtr = rotateright(*rootPtr);
  return 0;
}

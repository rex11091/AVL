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

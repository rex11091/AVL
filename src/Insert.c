#include "Insert.h"
#include "stdlib.h"
#include "stdio.h"
#include "node.h"
//get balanceFactor
int getbalanceFactor(Node *Node)
{
    if (Node == NULL)
        return 0;
    return Node->balanceFactor;
}

/* GiveNewNode function that allocates a new node with the given data and
    NULL left and right pointers. */
Node *GiveNewNode(int data)
{
    Node  *root = (Node *)malloc(sizeof(Node));
    root->data   = data;
    root->left   = NULL;
    root->right  = NULL;
    root->balanceFactor = 0;  // new node is initially added at leaf
    return(root);
}
//insert new node
Node *insert(Node **rootPtr, Node *nodeToAdd)
{

    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
        return *rootPtr;
      }
    else{
      if (nodeToAdd->data < (*rootPtr)->data)
      {
        (*rootPtr)->left = insert(&(*rootPtr)->left,nodeToAdd);
      }
      else if (nodeToAdd->data > (*rootPtr)->data)
      {
        (*rootPtr)->right = insert(&(*rootPtr)->right,nodeToAdd);
      }
      else
        return *rootPtr;
      }

        return *rootPtr;

 }

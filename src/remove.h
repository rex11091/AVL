#ifndef _REMOVE_H
#define _REMOVE_H
#include "node.h"
#include "rotate.h"

#endif // _REMOVE_H
 Node *findnearest(Node *rootPtr);
 Node *findnearest1(Node *rootPtr, int *heightchange);

 Node *avlRemove(Node **rootPtr, int data);
 Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange);
 int deleteNode(Node **root, int nodeToRemove);

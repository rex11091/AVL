#ifndef _REMOVE_H
#define _REMOVE_H
#include "node.h"
#include "rotate.h"

#define CHANGED 1
#define UNCHANGE 0

Node *findnearest(Node **rootPtr, int *heightchange);
Node *avlRemove(Node **rootPtr, int data);
Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange);



#endif // _REMOVE_H

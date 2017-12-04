#ifndef _REMOVE_H
#define _REMOVE_H
#include "node.h"
#include "rotate.h"
#include "avlAddInteger.h"

#define CHANGED 1
#define UNCHANGE 0


typedef int(*Compare)(void *remove , Node *refNode);

Node *findnearest(Node **rootPtr, int *heightchange);
Node *avlRemove(Node **rootPtr, int data,Compare IntegerCompare);
Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange,Compare IntegerCompare);


#endif // _REMOVE_H

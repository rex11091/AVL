#ifndef _INSERT_H
#define _INSERT_H
#include "node.h"
#include "rotate.h"
#include "avlAddInteger.h"

typedef int(*Compare)(void *add , Node *refNode);

int avlAdd(Node **rootPtr, Node *nodeToAdd,Compare IntegerCompare);


#endif // _INSERT_H

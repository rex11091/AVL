#ifndef _INSERT_H
#define _INSERT_H
#include "node.h"
#include "rotate.h"

int insert(Node **rootPtr, Node *nodeToAdd);
int avlBalanceRightTree(Node **rootPtr);
int avlBalanceLeftTree(Node **rootPtr);

#endif // _INSERT_H

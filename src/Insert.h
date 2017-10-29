#ifndef _INSERT_H
#define _INSERT_H
#include "node.h"

Node *GiveNewNode(int data);
int getbalanceFactor(Node *Node);
Node *insert(Node **rootPtr, Node *nodeToAdd);
#endif // _INSERT_H

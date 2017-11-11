#ifndef _ROTATE_H
#define _ROTATE_H
#include "node.h"

Node *rotateleft(Node *node);
Node *rotateright(Node *node);
Node *rotateleftright(Node *node);
Node *rotaterightleft(Node *node);
int avlBalanceRightTree(Node **rootPtr);
int avlBalanceLeftTree(Node **rootPtr);

#endif // _ROTATE_H

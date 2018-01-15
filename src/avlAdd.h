#ifndef _INSERT_H
#define _INSERT_H
#include "node.h"
#include "rotate.h"
#include "avlAddInteger.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define NODE_ADD_EXIST             90

typedef int(*Compare)(void *add , Node *refNode);

int avlAdd(Node **rootPtr, Node *nodeToAdd,Compare CompareFunc);


#endif // _INSERT_H

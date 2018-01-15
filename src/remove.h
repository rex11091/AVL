#ifndef _REMOVE_H
#define _REMOVE_H
#include "node.h"
#include "rotate.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "avlAddInteger.h"

#define CHANGED 1
#define UNCHANGE 0
#define Data_not_found          91


typedef int(*Compare)(void *remove , Node *refNode);

Node *findnearest(Node **rootPtr, int *heightchange);
Node *avlRemove(Node **rootPtr, int data,Compare CompareFunc);
Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange,Compare CompareFunc);


#endif // _REMOVE_H

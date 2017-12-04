#ifndef _AVLADDINTEGER_H
#define _AVLADDINTEGER_H
#include "node.h"
#include "avlAdd.h"
#include "remove.h"

#define avlAddInteger(rootptr,nodeToAdd)      avlAdd(rootptr,nodeToAdd,(Compare)IntegerCompare);
#define avlRemoveInteger(rootptr,nodeToAdd)      *avlRemove(rootptr,nodeToAdd,(Compare)IntegerCompare);

int IntegerCompare(int data, Node *refNode);


#endif // _AVLADDINTEGER_H

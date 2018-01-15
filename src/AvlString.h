#ifndef _AVLSTRING_H
#define _AVLSTRING_H
#include "node.h"
#include "avlAdd.h"
#include "remove.h"
#include "stdlib.h"
#include "string.h"
#include "AvlString.h"
#include "CException.h"


#define avlAddString(root, nodeToAdd)  avlAdd((Node **)root, (Node *)nodeToAdd,(Compare) StringCompare)
#define avlRemoveString(root,data)     *avlRemove((Node **)root,(char *)data ,(Compare) StringCompare);

int StringCompare(char *data,StringNode *refNode);
#endif // _AVLSTRING_H

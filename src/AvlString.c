#include "AvlString.h"
#include "stdlib.h"
#include "string.h"

int StringCompare(char *data,StringNode *refNode){
  if(strcmp(data,refNode->data)>0)
    return 1;
  else if(strcmp(data,refNode->data)<0)
    return -1;
  else
    return 0;
}

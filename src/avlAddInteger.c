#include "avlAddInteger.h"



int IntegerCompare(int nodedata, Node *refNode)
{
	
	intNode *temp = (intNode *)refNode;
    uintptr_t data1 = (uintptr_t)temp->data;

  if (nodedata < data1)
  {
    return -1;
  }
  else if(nodedata > data1)
  {
    return 1;
  }
  else
    return 0;
}

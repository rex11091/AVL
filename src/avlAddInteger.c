#include "avlAddInteger.h"



int IntegerCompare(int nodedata, Node *refNode)
{

    //int data  = (int)refNode->data;
    int data1 = (int)((uintptr_t)(refNode->data));

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

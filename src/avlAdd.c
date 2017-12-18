#include "avlAdd.h"
#include "stdlib.h"
#include "stdio.h"
#include "node.h"
#include "rotate.h"
#include "avlAddInteger.h"





int avlAdd(Node **rootPtr, Node *nodeToAdd,Compare CompareFunc){
  int m;//heigh
    if (*rootPtr == NULL){
        *rootPtr = nodeToAdd;
        return 1;
      }
    else{
    int compareResult = CompareFunc((void *)nodeToAdd->data,*rootPtr);
      if (compareResult == -1)
      {
      m = avlAdd(&(*rootPtr)->left,nodeToAdd,CompareFunc);   //if adding data will change the heigh,m =1 else m =0;
        if(m==1){
        (*rootPtr)->balanceFactor -= 1;
          if((*rootPtr)->balanceFactor==0)
          m=0;
        }
      else
      (*rootPtr)->balanceFactor =(*rootPtr)->balanceFactor;

      }
      else if (compareResult ==1)
      {
      m = avlAdd(&(*rootPtr)->right,nodeToAdd,CompareFunc);
        if(m==1){
        (*rootPtr)->balanceFactor += 1;
          if((*rootPtr)->balanceFactor==0)
            m=0;;
          }
        else
          (*rootPtr)->balanceFactor =(*rootPtr)->balanceFactor;
      }
    }
    if((*rootPtr)->balanceFactor >= 2)
        avlBalanceRightTree(&(*rootPtr));
    else if((*rootPtr)->balanceFactor <= -2)
        avlBalanceLeftTree(&(*rootPtr));
    else{
       *rootPtr = *rootPtr;
      }
        return m;
 }

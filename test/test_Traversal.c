#include "unity.h"
#include "Traversal.h"
#include "NodePrint.h"
#include <stdio.h>

Node node1 = {NULL, NULL, 1};
Node node3 = {NULL, NULL, 3};
Node node7 = {NULL, NULL, 7};
Node node24 = {NULL, NULL, 24};
Node node28 = {NULL, NULL, 28};
Node node2 = {&node1, &node3, 2};
Node node5 = {NULL, &node7, 5};
Node node15 = {NULL, NULL, 15};
Node node25 = {&node24, &node28, 25};
Node node4 = {&node2, &node5, 4};
Node node20 = {&node15, &node25, 20};
Node node10 = {&node4, &node20, 10};

StringNode nodeAli = {NULL,NULL,"Ali"};
StringNode nodeAbu = {NULL,NULL,"Abu"};
StringNode nodeDavid = {NULL,NULL,"David"};
StringNode nodeSteven = {NULL,NULL,"Steven"};
StringNode nodeAbraham = {&nodeAli,&nodeAbu,"Abraham"};
StringNode nodeNoah = {&nodeDavid,&nodeSteven,"Noah"};
StringNode nodeAdam = {&nodeAbraham,&nodeNoah,"Adam"};

void setUp(void){}

void tearDown(void){}

void test__inOrderTreeTraversal_with_printInteger(void){
  _inOrderTreeTraversal(&node10,printInteger);
}

void test__inOrderTreeTraversal_eith_printDecoratedInteger(void){
  _inOrderTreeTraversal(&node10,printDecoratedInteger);
}

void test__inOrderTreeTraversal_with_printString(void){
  _inOrderTreeTraversal((Node *)&nodeAdam,printString);
}

/*
void test_Traversal_inOrder(void)
{
    inOrderTreeTraversal(&node10);
}
void test_Traversal_preOder(void)
{
    PreOrderTreeTraversal(&node10);
}
void test_Traversal_postOder(void)
{
    PostOrderTreeTraversal(&node10);
}
*/

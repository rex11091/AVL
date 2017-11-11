#include "unity.h"
#include "remove.h"
#include "stdlib.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"
#include "rotate.h"

void setUp(void)
{
  giveInitdata();
}

void tearDown(void)
{
}

/**
---------insert 20 to 30->left & rotate right----------------------
*       40
*      /   \
*   30     80
*   /      / \
*  20    75  90
*        /
*       70
**/
void test_findnearest(void){

    initNode(&node70,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node90,NULL,NULL,0);
    initNode(&node75,&node70,NULL,-1);
    initNode(&node30,&node20,NULL,-1);
    initNode(&node80,&node75,&node90,-1);
    initNode(&node40,&node30,&node80,1);

    Node *root;
    root = findnearest(&node80);
    printf("%d\n",root->data);
}


/**
---------insert 20 to 30->left & rotate right----------------------
*       40
*      /   \
*   30     80
*   / \     / \
*  20  35  75  90
*        /
*      70
**/
void test_remove(void){

    initNode(&node70,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node90,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node75,&node70,NULL,-1);
    initNode(&node30,&node20,&node35,0);
    initNode(&node80,&node75,&node90,-1);
    initNode(&node40,&node30,&node80,1);

    Node *root=&node40;
    RemoveNode(&root,30);

    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
}

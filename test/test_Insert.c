#include "unity.h"
#include "Insert.h"
#include "stdlib.h"
#include "node.h"

Node node1 ,node5, node10,node15, node20, node25, node30, node35, node40;
Node node45, node50, node55;

void initNode (Node *node, Node *left, Node *right, int bf){

  node->left = left;
  node->right = right;
  node->balanceFactor = bf;

}

void setUp(void){
  node1.data = 1 ;
  node5.data = 5 ;
  node10.data = 10 ;
  node15.data = 15 ;
  node20.data = 20 ;
  node25.data = 25 ;
  node30.data = 30 ;
  node35.data = 35 ;
  node40.data = 40 ;
  node45.data = 45 ;
  node50.data = 50 ;
  node55.data = 55 ;

}

void tearDown(void){};

void test_get_balanceFacotr(void)
{
    int m;
    initNode(&node1,NULL,NULL,0);
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,&node25,NULL,-1);
    initNode(&node5,&node1,&node40,1);

    m = getbalanceFactor(&node5);
    TEST_ASSERT_EQUAL(1,m);;
}

/**
---------test_givenewNode-----------------
*
*
*      10     -> + 2     10
*     / \               / \
*    5  20             5  20
*                     /
*                    2

void test_inset_newNode(void)
{   Node *root;
    root = GiveNewNode(100);
    TEST_ASSERT_EQUAL(0,root->balanceFactor);
    TEST_ASSERT_EQUAL_PTR(NULL,root->left);
    TEST_ASSERT_EQUAL_PTR(NULL,root->right);
}
**/
/**
----------------test_insert_right----------
*        10            10
*         \           /   \
*          30  ->    5    30
*
**/
void test_insert_right(void)
{   Node *root = &node10;
    initNode(&node10,NULL,&node30,1);

    insert(&root,&node5);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

}

/**
----------------test_insert_left----------
*        10              10
*       /  \           /   \
*      5       ->    5     30
*
**/
void test_insert_left(void)
{   Node *root = &node10;
    initNode(&node10,&node5,NULL,-1);

    insert(&root,&node30);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

}
/**
----------------test_insert_leftChild_left----------
*        10              10
*       /  \           /   \
*      5    30   ->   5     30
*                    /
*                   1
**/
void test_insert_1_t0_5_leftchild(void)
{   Node *root = &node10;
    initNode(&node10,&node5,&node30,0);
    initNode(&node5,NULL,NULL,0);

    insert(&root,&node1);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);

}

void test_insert_40_t0_30_rightchild(void)
{   Node *root = &node10;
    initNode(&node10,&node5,&node30,0);
    initNode(&node5,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);

    insert(&root,&node40);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);

}

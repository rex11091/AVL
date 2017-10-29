#include "unity.h"
#include "rotate.h"
#include "stdlib.h"

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

void tearDown(void){
  /**
  ---------rotateright-----------------
  *        30         10
  *       /          /   \
  *      10     ->  5     30
  *     / \               /
  *    5  20             20
  *
  ---------rotateleft-----------------
  *        10            30
  *         \           /   \
  *          30  ->    10    40
  *         / \         \
  *        25  40       25
  *
  ---------rotateleftright------------------------------------
  *        45                   45                   30
  *       /  \      RL"10"    /   \      RR"45"     /   \
  *      10   50  ------->  30    50  ----------> 10     45
  *        \               /  \                     \    / \
  *        30             10   40                   25  40 50
  *       /  \              \
  *      25   40             25
  *
  ---------rotaterightleft-------------------------------------
  *         5                   5                   25
  *       /  \      RL"40"    /   \      RR"5"     /   \
  *      1   40  ------->   1     25  ----------> 5     40
  *          /                    / \            /  \   /
  *        25                    20 40          1   20  35
  *       /  \                     /
  *      20   35                  35
  *
  **/
}
void test_rotate_left(void)
{   Node *root;
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node30,&node25,&node40,0);
    initNode(&node10,NULL,&node30,2);

    root =  rotateleft(&node10);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node40,node30.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node10.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);

}
void test_rotate_right(void)
{   Node *root;
    initNode(&node5,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node10,&node5,&node20,0);
    initNode(&node30,&node10,NULL,-2);

    root =  rotateright(&node30);
    TEST_ASSERT_EQUAL_PTR(&node10,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node20,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node5,node10.left);
    TEST_ASSERT_EQUAL_PTR(&node30,node10.right);

}

void test_rotate_leftright(void)
{   Node *root;
    initNode(&node25,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);
    initNode(&node50,NULL,NULL,0);
    initNode(&node30,&node25,&node40,0);
    initNode(&node10,NULL,&node30,2);
    initNode(&node45,&node10,&node50,-2);

    root =  rotateleftright(&node45);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node25.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node50.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node45.left);
    TEST_ASSERT_EQUAL_PTR(&node50,node45.right);
    TEST_ASSERT_EQUAL_PTR(&node10,node30.left);
    TEST_ASSERT_EQUAL_PTR(&node45,node30.right);
    TEST_ASSERT_EQUAL_PTR(&node25,node10.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node10.left);

}

void test_rotate_rightleft(void)
{   Node *root;
    initNode(&node1,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node25,&node20,&node35,0);
    initNode(&node40,&node25,NULL,-2);
    initNode(&node5,&node1,&node40,2);

    root =  rotaterightleft(&node5);
    TEST_ASSERT_EQUAL_PTR(&node25,root);
    TEST_ASSERT_EQUAL_PTR(NULL,node1.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node1.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node20.right);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node35.right);
    TEST_ASSERT_EQUAL_PTR(&node1,node5.left);
    TEST_ASSERT_EQUAL_PTR(&node20,node5.right);
    TEST_ASSERT_EQUAL_PTR(&node40,node25.right);
    TEST_ASSERT_EQUAL_PTR(&node5,node25.left);
    TEST_ASSERT_EQUAL_PTR(&node35,node40.left);
    TEST_ASSERT_EQUAL_PTR(NULL,node40.right);

}

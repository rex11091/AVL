#include "unity.h"
#include "rotate.h"
#include "stdlib.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"

void setUp(void){
giveInitdata();
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

/*      ___________________________________________________________________________________________
 *     |_Current_Node_|__Child_Node_| G.Child_Node |________Action________|_Root_|_Child_|_G.Child_|
 *     |_______+2_____|_(R)__+1_____|______X_______|________Rotate_Left___|___0__|___0___|____X____|
 *     |_______+2_____|_(R)___0_____|______X_______|________Rotate_Left___|___1__|__-1___|____X____|
 *     |_______+2_____|_(R)__-1_____|_____-1_______|___Rotate_RightLeft___|___0__|___1___|____0____|
 *     |_______+2_____|_(R)__-1_____|______0_______|___Rotate_RightLeft___|___0__|___0___|____0____|
 *     |_______+2_____|_(R)__-1_____|_____+1_______|___Rotate_RightLeft___|__-1__|___0___|____0____|
 *     |_______-2_____|_(L)__-1_____|______X_______|________Rotate_right__|___0__|___0___|____X____|
 *     |_______-2_____|_(L)___0_____|______X_______|________Rotate_right__|___1__|__-1___|____X____|
 *     |_______-2_____|_(L)__+1_____|_____+1_______|___Rotate_LeftRight___|___0__|__-1___|____0____|
 *     |_______-2_____|_(L)__+1_____|______0_______|___Rotate_LeftRight___|___0__|___0___|____X____|
 *     |_______-2_____|_(L)__+1_____|_____-1_______|___Rotate_LeftRight___|___1__|___0___|____0____|
 *
 *
 */
 /**
 ---------rotateLeft----------------------
 *        40 (+2)                   50
 *          \                     /   \
 *           50 (+1)   ------->  40    100
 *            \
 *            100
 *
 **/
void test_avlBalanceRightTree_given_40_50_100_expect_balance(void){

     initNode(&node100,NULL,NULL,0);
     initNode(&node50,NULL,&node100,1);
     initNode(&node40,NULL,&node50,2);

     Node *root = &node40;
     avlBalanceRightTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node50,root);
     TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}
/**
---------rotateLeft----------------------
*        40 (+2)                        50
*          \           rotateLeft      /   \
*           50 (0)  ----- ------->  40    100
*           / \                       \
*         45  100                     45
*
**/
void test_avlBalanceRightTree_given_40_50_45_100_expect_balance(void){

     initNode(&node100,NULL,NULL,0);
     initNode(&node45,NULL,NULL,0);
     initNode(&node50,&node45,&node100,0);
     initNode(&node40,NULL,&node50,2);

     Node *root = &node40;
     avlBalanceRightTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node50,root);
     TEST_ASSERT_EQUAL_NODE(&node40,&node100,-1,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);


}
/**
---------rotateRightLeft(1)----------------------
*        20 (+2)                                35 (0)
*       /  \           rotateRightLeft        /     \
*      15   40 (-1)     --------------->    20 (0)   40 (+1)
*           / \                            /  \        \
*    (-1) 35  50                          15   30       50
*        /
*       30
**/
void test_avlBalanceRightTree_given_AVL_need_rotateRightLeft_condition1_expect_balance(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node30,NULL,NULL,0);
     initNode(&node50,NULL,NULL,0);
     initNode(&node35,&node30,NULL,-1);
     initNode(&node40,&node35,&node50,-1);
     initNode(&node20,&node15,&node40,2);

     Node *root = &node20;
     avlBalanceRightTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node35,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node30);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node15);
     TEST_ASSERT_EQUAL_NODE(NULL,&node50,1,&node40);
     TEST_ASSERT_EQUAL_NODE(&node15,&node30,0,&node20);
     TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node35);
}
/**
---------rotateRightLeft(2)----------------------
*        60 (+2)                                70 (0)
*       /  \           rotateRightLeft        /     \
*      40   80 (-1)     --------------->    60 (0)   80 (0)
*           / \                            /  \      /  \
*      (0) 70  100                        40   65   75   100
*         / \
*        65  75
**/
void test_avlBalanceRightTree_given_AVL_need_rotateRightLeft_condition2_expect_balance(void){

     initNode(&node40,NULL,NULL,0);
     initNode(&node65,NULL,NULL,0);
     initNode(&node75,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node70,&node65,&node75,0);
     initNode(&node80,&node70,&node100,-1);
     initNode(&node60,&node40,&node80,2);

     Node *root = &node60;
     avlBalanceRightTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node70,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node40,&node65,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node75,&node100,0,&node80);
     TEST_ASSERT_EQUAL_NODE(&node60,&node80,0,&node70);

}
/**
---------rotateRightLeft(3)----------------------
*        60 (+2)                                70 (0)
*       /  \           rotateRightLeft        /     \
*      40   80 (-1)     --------------->   60 (-1)   80 (0)
*           / \                            /        /  \
*      (+1)70  100                        40      75   100
*           \
*           75
**/
void test_avlBalanceRightTree_given_AVL_need_rotateRightLeft_condition3_expect_balance(void){

     initNode(&node40,NULL,NULL,0);
     initNode(&node65,NULL,NULL,0);
     initNode(&node75,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node70,NULL,&node75,1);
     initNode(&node80,&node70,&node100,-1);
     initNode(&node60,&node40,&node80,2);

     Node *root = &node60;
     avlBalanceRightTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node70,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node40,NULL,-1,&node60);
     TEST_ASSERT_EQUAL_NODE(&node75,&node100,0,&node80);
     TEST_ASSERT_EQUAL_NODE(&node60,&node80,0,&node70);
}

/**
---------rotateRight----------------------
*        40 (-2)                  30 (0)
*        /      rotateRight     /   \
*      30 (-1) ------------->  20    40 (0)
*      /
*     20
*
**/
void test_avlBalanceLeftTree_given_40_30_20_expect_balance(void){

    initNode(&node20,NULL,NULL,0);
    initNode(&node30,&node20,NULL,-1);
    initNode(&node40,&node30,NULL,-2);

    Node *root = &node40;
    avlBalanceLeftTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
    TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
}
/**
---------rotateRight----------------------
*        40 (-2)                  30 (1)
*        /      rotateRight     /   \
*      30 (0) ------------->  20    40 (-1)
*      / \                          /
*     20  35                       35
*
**/
void test_avlBalanceLeftTree_given_40_30_20_35_expect_balance(void){

    initNode(&node20,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node30,&node20,&node35,0);
    initNode(&node40,&node30,NULL,-2);

    Node *root = &node40;
    avlBalanceLeftTree(&root);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
    TEST_ASSERT_EQUAL_NODE(&node20,&node40,1,&node30);
}
/**
---------rotateleftRight(2)----------------------
*        90 (-2)                                60 (0)
*       /  \            rotateLeftRight        /     \
* (1) 50   100      ------------------>      50 (0)   90 (0)
*     / \                                    /  \      /  \
*    45  60 (0)                             45   55   70   100
*       / \
*      55  70
**/
void test_avlBalanceleftRightTree_given_AVL_need_rotateLeftRight_condition2_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node100,-2);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,&node55,&node70,0);

     Node *root = &node90;
     avlBalanceLeftTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node70,&node100,0,&node90);
}
/**
---------rotateleftRight(1)----------------------
*        90 (-2)                                60 (0)
*       /  \            rotateLeftRight        /     \
* (1) 50   100      ------------------>      50 (-1)  90 (0)
*     / \                                    /        /  \
*    45  60 (1)                             45      70   100
*         \
*         70
**/
void test_avlBalanceleftRightTree_given_AVL_need_rotateLeftRight_condition1_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node100,-2);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,NULL,&node70,1);

     Node *root = &node90;
     avlBalanceLeftTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,NULL,-1,&node50);
     TEST_ASSERT_EQUAL_NODE(&node70,&node100,0,&node90);
}
/**
---------rotateleftRight(3)----------------------
*        90 (-2)                                60 (0)
*       /  \            rotateLeftRight        /     \
* (1) 50   100      ------------------>      50 (0)  90 (1)
*     / \                                    /  \        \
*    45  60 (-1)                            45   55        100
*        /
*       55
**/
void test_avlBalanceleftRightTree_given_AVL_need_rotateLeftRight_condition3_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node100,-2);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,&node55,NULL,-1);

     Node *root = &node90;
     avlBalanceLeftTree(&root);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node90);

}
/**
---------insert 30----------------------
*        0      30 (0)
*          --->                       /
*
*
*
*
**/

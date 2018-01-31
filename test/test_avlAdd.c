#include "unity.h"
#include "avlAdd.h"
#include "stdlib.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"
#include "rotate.h"
#include "avlAddInteger.h"
#include "Exception.h"
#include "CException.h"


void setUp(void){
  giveInitdata();
}

void tearDown(void){
}

/**
 *        add same value
 *    50 ---add 50----> error
 */
void test_avlAdd_given_IntegerNode50_add_IntegerNode50_expected_exception_1(void){
  CEXCEPTION_T ex;
  Node *root = &node50;
  initNode(&node50,NULL,NULL,0);
  Try{
  avlAddInteger(&root, &node50);
  TEST_ASSERT_EQUAL(1,ex);
  }Catch(ex){
    dumpException(ex);
  }
    freeException1(ex);
}

void test_avlAdd_given_NULL_avlAdd_30_expect_root_30_nochild(void){
    CEXCEPTION_T ex;
    initNode(&node30,NULL,NULL,0);
    Node *root = NULL;
    Try{
    avlAddInteger(&root,&node30);
    }Catch(ex){
    dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node30);
}
/**
---------avlAdd 20 with root 40----------------------
*        40 (0)   add 20                40 (-1)
*                                      /
*               ------------------>  20
*
*
*
**/
void test_avlAdd_given_40_avlAdd_20_expect_balance(void){

    CEXCEPTION_T ex;
    initNode(&node20,NULL,NULL,0);
    initNode(&node40,NULL,NULL,0);

    Node *root = &node40;
    Try{
    avlAddInteger(&root,&node20);
    }Catch(ex){
      dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node40,root);
    TEST_ASSERT_EQUAL_NODE(&node20,NULL,-1,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
}

/**
---------avlAdd 20 to 30->left & rotate right----------------------
*       40                    40 (-2)                    30 (0)
*       /      add 20        /      rotate    right      /   \
*     30 (0)  ------> (-1) 30 --------------------->  20    40 (0)
*                         /
*                       20
*
**/
void test_avlAdd_given_40_30_avlAdd_20_expect_balance(void){

    CEXCEPTION_T ex;
    initNode(&node30,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node40,&node30,NULL,-1);

    Node *root = &node40;
    Try{
    avlAddInteger(&root,&node20);
    }Catch(ex){
    dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
    TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
}

/**
---------avlAdd   &    rotateleftRight(1)----------------------
*        90(-1)               90 (-2)                                 60 (0)
*       /  \    add 70        /  \            rotateLeftRight        /     \
*     50   100 --------> (1)50   100      ------------------>      50 (-1)  90 (0)
*    /  \                  /  \                                   /         / \
*   45   60              45     60(1)                            45       70 100
*                               \
*                               70
**/
void test_avlAdd_given_90_50_100_45_60_avlAdd_70_expect_balance(void){

     CEXCEPTION_T ex;
     initNode(&node45,NULL,NULL,0);
     initNode(&node60,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node100,-1);
     initNode(&node50,&node45,&node60,0);

     Node *root = &node90;
     Try{
       avlAddInteger(&root,&node70);
      }Catch(ex){
        dumpException(ex);
      }
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
--------------------------------added 55 & rotateleftRight(2)----------------------
*         90 (-1)                    90 (-2)                                60 (0)
*        / \      added 55          /  \            rotateLeftRight        /     \
*  (0) 50   100  --------->   (1) 50   100      ------------------>      50 (0)   90 (1)
*     / \                         / \                                  /  \        \
*   45  60 (0)                 45  60 (-1)                           45   55        100
*                                 /
*                               55
* root -1 child 0 grandchild 0
**/

void test_avlAdd_55_then_rotateLeftRight_in_rotateleftright_condition3_expect_balance(void){
     CEXCEPTION_T ex;
     initNode(&node45,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node60,NULL,NULL,0);
     initNode(&node90,&node50,&node100,-1);
     initNode(&node50,&node45,&node60,0);

     Node *root = &node90;
     Try{
       avlAddInteger(&root,&node55);
      }Catch(ex){
        dumpException(ex);
      }
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node90);

}
/**
---------avlAdd   &    rotateleftRight(1)----------------------
*        90(-1)               90 (-1)
*       /  \    add 60        /  \
*     50   100 --------> (0)50   100
*    /                     /  \
*   45                   45     60
*
*
**/
void test_avlAdd_given_90_50_1pect_balance(void){
     CEXCEPTION_T ex;
     initNode(&node45,NULL,NULL,0);
     initNode(&node60,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node100,-1);
     initNode(&node50,&node45,NULL,-1);

     Node *root = &node90;
     Try{
      avlAddInteger(&root,&node60);
      }Catch(ex){
      dumpException(ex);
      }
     TEST_ASSERT_EQUAL_PTR(&node90,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node60);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node45,&node60,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node50,&node100,-1,&node90);
}
/*
---------------avlAdd 100 &  rotateLeft----------------------
*  40(1)             40 (+2)                           50
*    \               \          rotateLeft           /   \
*    50(0)           50 (+1)   ------------->      40    100
*                     \
*                     100
*
**/
void test_avlAdd_100_thn_rotate_left_expect_balance(void){
    CEXCEPTION_T ex;
    initNode(&node100,NULL,NULL,0);
    initNode(&node50,NULL,NULL,0);
    initNode(&node40,NULL,&node50,1);
    Node *root = &node40;
    Try{
    avlAddInteger(&root,&node100);
    }Catch(ex){
      dumpException(ex);
    }
    TEST_ASSERT_EQUAL_PTR(&node50,root);
    TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
}

/**
-----------------------------add 30 & rotateRightLeft(1)----------------------------
*      20                           20 (+2)                                35 (0)
*     /  \     ADDED 30           /  \           rotateRightLeft        /     \
*   15   40  ----------->       15   40 (-1)     --------------->    20 (0)   40 (+1)
*       / \                         / \                            /  \        \
*      35  50                (-1) 35  50                          15   30       50
*                                /
*                               30
**/
void test_avlAdd_30_rotateRightLeft_condition1_expect_balance(void){
     CEXCEPTION_T ex;
     initNode(&node15,NULL,NULL,0);
     initNode(&node30,NULL,NULL,0);
     initNode(&node50,NULL,NULL,0);
     initNode(&node35,NULL,NULL,0);
     initNode(&node40,&node35,&node50,0);
     initNode(&node20,&node15,&node40,1);

     Node *root = &node20;
     Try{
     avlAddInteger(&root,&node30);
      }Catch(ex){
        dumpException(ex);
      }
     TEST_ASSERT_EQUAL_PTR(&node35,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node30);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node15);
     TEST_ASSERT_EQUAL_NODE(NULL,&node50,1,&node40);
     TEST_ASSERT_EQUAL_NODE(&node15,&node30,0,&node20);
     TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node35);
}
/**
-------------------------added 75 & rotateRightLeft(3)---------------------------------
*        60                        60 (+2)                                70 (0)
*      /  \       added 75        /  \           rotateRightLeft        /     \
*    40    80    ---------->    40   80 (-1)     --------------->   60 (-1)   80 (0)
*         / \                       / \                            /        /  \
*       70 100                (+1)70  100                        40      75   100
*                               \
*                               75
**/
void test_avlAdd_75_given_AVL_need_rotateRightLeft_condition3_expect_balance(void){
     CEXCEPTION_T ex;
     initNode(&node40,NULL,NULL,0);
     initNode(&node75,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node80,&node70,&node100,0);
     initNode(&node60,&node40,&node80,1);

     Node *root = &node60;
      Try{
     avlAddInteger(&root,&node75);
      }Catch(ex){
        dumpException(ex);
      }
     TEST_ASSERT_EQUAL_PTR(&node70,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node65);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node40,NULL,-1,&node60);
     TEST_ASSERT_EQUAL_NODE(&node75,&node100,0,&node80);
     TEST_ASSERT_EQUAL_NODE(&node60,&node80,0,&node70);
}





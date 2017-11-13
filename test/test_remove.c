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
---------find nearest----------------------
*       40
*      /   \
*   30     80
*   /      / \
*  20    75  90
*        /
*       70
**/
void test_findnearest_find_70_expect_70(void){

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
    TEST_ASSERT_EQUAL(70,root->data);
}

/**
-----------------remove 40----------------------
*                   remove 40
*        40 (0) ------------------>  NULL
*
**/
void test_RemoveNode_given_40_remove_expect_NULL(void){


    initNode(&node40,NULL,NULL,0);

    Node *root = &node40;
    deleteNode(&root,40);
    TEST_ASSERT_EQUAL_PTR(NULL,root);
}
/**
---------------------------------remove 30------------------------------
*       40(-1)                        40 (0)
*       /          remove 40
*     30 (0)  --------------->
*
**/
void test_RemoveNode_given_40_with_child_30_delete_30_expect_40_only(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,NULL,-1);

    Node *root = &node40;
    deleteNode(&root,30);
    TEST_ASSERT_EQUAL_PTR(&node40,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
}
/**
---------------------------------remove 50------------------------------
*       40(0)                              40 (-1)
*       / \          remove 50            /
*   30 (0) 50(0)   --------------->     30
*
**/
void test_RemoveNode_given_40_with_child_30_50__delete_50_expect_40_30(void){

    initNode(&node50,NULL,NULL,0);
    initNode(&node30,NULL,NULL,0);
    initNode(&node40,&node30,&node50,0);

    Node *root = &node40;
    deleteNode(&root,50);
    TEST_ASSERT_EQUAL_PTR(&node40,root);
    TEST_ASSERT_EQUAL_NODE(&node30,NULL,-1,&node40);
}

/**
---------------------------------remove 50------------------------------
*       40(-1)                            40 (-2)                                  30 (0)
*       / \          remove 50          /                 rotate right           /  \
*   30 (-1) 50(0)   --------------->   30(-1)            ------------>         20    40 (0)
*   /                                 /
*  20                               20
*
**/
void test_RemoveNode_after_remove_rotate_right(void){

    initNode(&node50,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node30,&node20,NULL,-1);
    initNode(&node40,&node30,&node50,-1);

    Node *root = &node40;
    deleteNode(&root,50);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(&node20,&node40,0,&node30);
}
/**
---------------------------------remove 50------------------------------
*       40(-1)                            40 (-2)                                  30 (1)
*       / \          remove 50          /                 rotate right           /  \
*   30 (0) 50(0)   --------------->   30(0)            ------------>          20     40 (-1)
*   / \                               / \                                            /
*  20  35                           20  35                                          35
*
**/
void test_RemoveNode_after_remove_rotate_right_condition2(void){

    initNode(&node50,NULL,NULL,0);
    initNode(&node35,NULL,NULL,0);
    initNode(&node20,NULL,NULL,0);
    initNode(&node30,&node20,&node35,0);
    initNode(&node40,&node30,&node50,-1);

    Node *root = &node40;
    deleteNode(&root,50);
    TEST_ASSERT_EQUAL_PTR(&node30,root);
    TEST_ASSERT_EQUAL_NODE(&node35,NULL,-1,&node40);
    TEST_ASSERT_EQUAL_NODE(&node20,&node40,1,&node30);
}
/**
---------------------------------remove 100       &           rotateLeftRight--------------------------------
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotateleftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (-1) 50  90 (0)
*      / \     \                            / \                                          /    / \
*  45   60 (1)   100(0)                    45  60 (1)                                   45   70   95
*        \                                       \
*        70                                       70
*
**/
void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition1_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node90,&node50,&node95,-1);
     initNode(&node95,NULL,&node100,1);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,NULL,&node70,1);

     Node *root = &node90;
     deleteNode(&root,100);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node70);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,NULL,-1,&node50);
     TEST_ASSERT_EQUAL_NODE(&node70,&node95,0,&node90);
}
/**
---------------------------------remove 100       &           rotateLeftRight--------------------------------
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotateleftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (0)   50   90 (1)
*      / \     \                            / \                                          / \     \
*  45   60 (-1) 100(0)                    45  60 (-1)                                   45  55    95
*        /                                     /
*       55                                    55
*
**/
void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition2_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node95,NULL,&node100,1);
     initNode(&node90,&node50,&node95,-1);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,&node55,NULL,-1);

     Node *root = &node90;
     deleteNode(&root,100);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
     TEST_ASSERT_EQUAL_NODE(NULL,&node95,1,&node90);

}
/**
---------------------------------remove 100       &           rotateLeftRight--------------------------------
*           90(-1)                            90 (-2)                                        60 (0)
*          / \          remove 100            /  \               rotateleftright           /  \
*       50 (1) 95(1)   --------------->   50(1)   95[0]         ---------------->   (0)   50   90 (0)
*      / \     \                            / \                                          / \   / \
*  45   60 (0) 100(0)                    45  60 (-1)                                   45  55 70 95
*        / \                                 /  \
*       55  70                              55  70
*
**/
void test_remove_given_a_avltree_need_rotateLeftRight_after_remove_condition3_expect_balance(void){

     initNode(&node45,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node70,NULL,NULL,0);
     initNode(&node95,NULL,&node100,1);
     initNode(&node90,&node50,&node95,-1);
     initNode(&node50,&node45,&node60,1);
     initNode(&node60,&node55,&node70,0);

     Node *root = &node90;
     deleteNode(&root,100);
     TEST_ASSERT_EQUAL_PTR(&node60,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node45);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node95);
     TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node45,&node55,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node70,&node95,0,&node90);

}
/**
---------------------------------remove 30 and rotateLeft---------------------------------
*        40 (1)                            40 (+2)                             50
*       /   \           remove 30            \                 rotate left    /   \
*     30     50 (+1)   ---------->            50(1)        -------------->  40    100
*            \                                 \
*            100                               100
*
**/
void test_remove_rotateleft1(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node100,NULL,NULL,0);
    initNode(&node50,NULL,&node100,1);
    initNode(&node40,&node30,&node50,1);

    Node *root = &node40;
    deleteNode(&root,30);
    TEST_ASSERT_EQUAL_PTR(&node50,root);
    TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}

/**
---------------------------------remove 30 and rotateLeft---------------------------------
*        40 (1)                            40 (+2)                             50
*       /   \           remove 30            \                 rotate left    /   \
*     30     50 (0)   ---------->            50(0)        -------------->  40    100
*            /\                              /   \                          \
*          45  100                         45   100                         45
*
**/
void test_remove_rotateleft2(void){

    initNode(&node30,NULL,NULL,0);
    initNode(&node100,NULL,NULL,0);
    initNode(&node45,NULL,NULL,0);
    initNode(&node50,&node45,&node100,0);
    initNode(&node40,&node30,&node50,1);

    Node *root = &node40;
    deleteNode(&root,30);
    TEST_ASSERT_EQUAL_PTR(&node50,root);
    TEST_ASSERT_EQUAL_NODE(&node40,&node100,-1,&node50);
    TEST_ASSERT_EQUAL_NODE(NULL,&node45,1,&node40);
    TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);


}
/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            30 (2)                                   40
*       /   \           remove 15         /  \                 rotateRightleft    /   \
*     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
*    /       /\                              /   \                             / \      \
*  15      40  100                         40   100                          20 35      100
*         /                                /
*       35                               35
*
*
**/

void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition1_(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node35,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,&node35,NULL,-1);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     deleteNode(&root,15);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,&node35,0,&node30);
}
/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            30 (2)                                   40
*       /   \           remove 15         /  \                 rotateRightleft    /   \
*     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
*    /       /\                              /   \                             / \    / \
*  15      40  100                         40   100                          20 35  45    100
*         / \                             / \
*       35  45                           35 45
*
*
**/
void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition2_(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node45,NULL,NULL,0);
     initNode(&node35,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,&node35,&node45,0);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     deleteNode(&root,15);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,&node35,0,&node30);
}
/**
---------------------------------remove 15 and rotateLeft---------------------------------
*        30 (1)                            30 (2)                                   40
*       /   \           remove 15         /  \                 rotateRightleft    /   \
*     20     50 (-1)   ------------>    20    50(-1)        ----------------   30     50
*    /       /\                              /   \                             /     /  \
*  15      40  100                         40   100                          20   45   100
*           \                              \
*           45                              45
*
*
**/
void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition3_(void){

     initNode(&node15,NULL,NULL,0);
     initNode(&node45,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node40,NULL,&node45,1);
     initNode(&node50,&node40,&node100,-1);
     initNode(&node30,&node20,&node50,1);
     initNode(&node20,&node15,NULL,-1);

     Node *root = &node30;
     deleteNode(&root,15);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node20);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
     TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node40);
     TEST_ASSERT_EQUAL_NODE(&node45,&node100,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node20,NULL,-1,&node30);
}
/**
---------------------------------------remove 60----------------------------------------
*        60                        80 (0)
*      /  \       remove 60        /  \
*    40    80    ---------->    40   100
*           \
*          100
*
*
**/

void test_remove_given_Avl_tree_remove_15_then_rotaterightleft_condition3(void){

  initNode(&node60,&node40,&node80,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node80,NULL,&node100,1);
  initNode(&node100,NULL,NULL,0);


  Node *root = &node60;
  deleteNode(&root,60);
  TEST_ASSERT_EQUAL_PTR(&node80,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
  TEST_ASSERT_EQUAL_NODE(&node40,&node100,0,&node80);
}

/**
---------------------------------------remove 60----------------------------------------
*        60                         75 (0)
*      /  \       remove 60        /  \
*    40    90    ---------->    40     90
*   /     /   \                 /      / \
*  10    75    100            10      80  100
*         \
*           80
**/

void test_remove_given_Avl_tree_remove_60(void){

  initNode(&node60,&node40,&node90,1);
  initNode(&node40,&node10,NULL,-1);
  initNode(&node90,&node75,&node100,-1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node75,NULL,&node80,1);
  initNode(&node80,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);


  Node *root = &node60;
  deleteNode(&root,60);
  TEST_ASSERT_EQUAL_PTR(&node75,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node90,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node40);
  TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);

}
/**
---------------------------------------remove 60----------------------------------------
*        60                         75 (1)
*      /  \       remove 60        /  \
*    40    90    ---------->     40    90(1)
*         /   \                         \
*        75    100                     100
*
*


void test_remove_given_Avl_tree_remove_60_test1(void){

  initNode(&node60,&node40,&node90,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node90,&node75,&node100,0);
  initNode(&node75,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);


  Node *root = &node60;
  RemoveNode(&root,60);
  TEST_ASSERT_EQUAL_PTR(&node75,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node90,1,&node75);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node90);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}
**/

/**
---------------------------------------remove 60----------------------------------------
*                  60                           60 (0)
*                /    \       remove 40        /   \
*               40      90    ---------->     30    90(1)
*              /  \    /   \                 / \   /  \
*            20   50  75   100             20  50  75  100
*           / \    \   \                   /   / \   \
*         10   30   55  80               10   35  55  80
*               \
*               35
*
void test_remove_given_Avl_tree_remove_60_test2(void){

  initNode(&node60,&node40,&node90,-1);
  initNode(&node40,&node20,&node50,-1);
  initNode(&node90,&node75,&node100,-1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node50,NULL,&node55,1);
  initNode(&node75,NULL,&node80,1);
  initNode(&node100,NULL,NULL,0);
  initNode(&node30,NULL,&node35,1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node80,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);


  Node *root = &node60;
  RemoveNode(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
  TEST_ASSERT_EQUAL_NODE(&node75,&node100,-1,&node90);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,&node80,1,&node75);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}
**/

/**
-----------------remove 40----------------------
*                   remove 40
*        40 (0) ------------------>  NULL
*
**/
void test_RemoveNode_test1(void){


    initNode(&node40,NULL,NULL,0);

    Node *root = &node40;
    deleteNode(&root,40);
    TEST_ASSERT_EQUAL_PTR(NULL,root);
}

/**
---------------------------------remove 30------------------------------
*       40(-1)                        40 (0)
*       /          remove 30
*     30 (0)  --------------->
*
**/
void test_RemoveNode_test2(void){


  initNode(&node30,NULL,NULL,0);
  initNode(&node40,&node30,NULL,-1);

  Node *root = &node40;
  deleteNode(&root,30);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
}

/**
---------------------------------remove 50------------------------------
*       40(1)                        40 (0)
*         \          remove 50
*          50 (0)  --------------->
*
**/
void test_RemoveNode_test3(void){


  initNode(&node50,NULL,NULL,0);
  initNode(&node40,NULL,&node50,1);

  Node *root = &node40;
  deleteNode(&root,50);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
}

/**
---------------------------------remove 50------------------------------
*       40(0)                         40 (-1)
*       / \          remove 50        /
*    30    50 (0)  ---------------> 30
*
**/
void test_RemoveNode_test4(void){


  initNode(&node30,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);
  initNode(&node40,&node30,&node50,0);


  Node *root = &node40;
  deleteNode(&root,50);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_NODE(&node30,NULL,-1,&node40);
}

/**
---------------------------------remove 30------------------------------
*       40(0)                         40 (1)
*       / \          remove 30         \
*    30    50 (0)  --------------->    50
*
**/
void test_RemoveNode_test5(void){


  initNode(&node30,NULL,NULL,0);
  initNode(&node50,NULL,NULL,0);
  initNode(&node40,&node30,&node50,0);


  Node *root = &node40;
  deleteNode(&root,30);
  TEST_ASSERT_EQUAL_PTR(&node40,root);
  TEST_ASSERT_EQUAL_NODE(NULL,&node50,1,&node40);
}
/**
---------------------------------remove 30------------------------------
*       40(1)                           45 (0)
*       / \          remove 30         /  \
*    30    50 (-1)  --------------->  30    50
*          /
*         45
**/
void test_RemoveNode_test6(void){


  initNode(&node45,NULL,NULL,0);
  initNode(&node30,NULL,NULL,0);
  initNode(&node50,&node45,NULL,-1);
  initNode(&node40,&node30,&node50,1);


  Node *root = &node40;
  deleteNode(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node45,root);
  TEST_ASSERT_EQUAL_NODE(&node30,&node50,0,&node45);
}
/**
---------------------------------------remove 60----------------------------------------
*        60 (1)                           75 (0)
*      /     \           remove 60        /  \
* (-1)40      90 (-1)    ---------->    40     90
*   /       /     \                    /      / \
*  10     75 (1)   100               10      80  100
*           \
*           80
**/

void test_RemoveNode_test7(void){

  initNode(&node60,&node40,&node90,1);
  initNode(&node40,&node10,NULL,-1);
  initNode(&node90,&node75,&node100,-1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node75,NULL,&node80,1);
  initNode(&node80,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);


  Node *root = &node60;
  deleteNode(&root,60);
  TEST_ASSERT_EQUAL_PTR(&node75,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node90,0,&node75);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node40);
  TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);

}
/**
---------------------------------------remove 60----------------------------------------
*        60                         75 (1)
*      /  \       remove 60        /  \
*    40    90    ---------->     40    90(1)
*         /   \                         \
*        75    100                     100
*
*
**/

void test_remove_given_Avl_tree_remove_60_test1(void){

  initNode(&node60,&node40,&node90,1);
  initNode(&node40,NULL,NULL,0);
  initNode(&node90,&node75,&node100,0);
  initNode(&node75,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);


  Node *root = &node60;
  deleteNode(&root,60);
  TEST_ASSERT_EQUAL_PTR(&node75,root);
  TEST_ASSERT_EQUAL_NODE(&node40,&node90,1,&node75);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node40);
  TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node90);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}
/**
---------------------------------------remove 60----------------------------------------
*         60
*      /     \       remove 60
*    40        90    ---------->
*    / \     /   \
*   20  50  75    100
*         \
*           55
**/

void test_remove_test8(void){

  initNode(&node60,&node40,&node90,-1);
  initNode(&node40,&node20,&node50,1);
  initNode(&node90,&node75,&node100,0);
  initNode(&node50,NULL,&node55,1);
  initNode(&node75,NULL,NULL,0);
  initNode(&node20,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);


  Node *root = &node60;
  deleteNode(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node50,&node90,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node20,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node75,&node100,0,&node90);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node75);

}

/**
---------------------------------------remove 60----------------------------------------
*                  60                           60 (0)
*                /    \       remove 40        /   \
*               40      90    ---------->     30    90(1)
*              /  \    /   \                 / \   /  \
*            20   50  75   100             20  50  75  100
*           / \    \   \                   /   / \   \
*         10   30   55  80               10   35  55  80
*               \
*               35
*
**/
void test_remove_given_Avl_tree_remove_60_test2(void){

  initNode(&node60,&node40,&node90,-1);
  initNode(&node40,&node20,&node50,-1);
  initNode(&node90,&node75,&node100,-1);
  initNode(&node20,&node10,&node30,1);
  initNode(&node50,NULL,&node55,1);
  initNode(&node75,NULL,&node80,1);
  initNode(&node100,NULL,NULL,0);
  initNode(&node30,NULL,&node35,1);
  initNode(&node10,NULL,NULL,0);
  initNode(&node55,NULL,NULL,0);
  initNode(&node80,NULL,NULL,0);
  initNode(&node100,NULL,NULL,0);


  Node *root = &node60;
  deleteNode(&root,40);
  TEST_ASSERT_EQUAL_PTR(&node60,root);
  TEST_ASSERT_EQUAL_NODE(&node30,&node90,0,&node60);
  TEST_ASSERT_EQUAL_NODE(&node20,&node50,0,&node30);
  TEST_ASSERT_EQUAL_NODE(&node75,&node100,-1,&node90);
  TEST_ASSERT_EQUAL_NODE(&node35,&node55,0,&node50);
  TEST_ASSERT_EQUAL_NODE(&node10,NULL,-1,&node20);
  TEST_ASSERT_EQUAL_NODE(NULL,&node80,1,&node75);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node10);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node35);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node55);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node80);
  TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);

}

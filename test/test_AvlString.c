#include "unity.h"
#include "avlAdd.h"
#include "remove.h"
#include "stdlib.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"
#include "rotate.h"
#include "AvlString.h"


void setUp(void)
{
  giveInitString();
}

void tearDown(void)
{
}


/**
---------compare----------------------
*        ALI
*       /  \
*   Abu (0)  Amin(0)
*
*
*
**/

void test_AVL_StringAdd_Equal(void){
  initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);

   int m =StringCompare("Ali",&nodeAli);
   TEST_ASSERT_EQUAL(0,m);
}
void test_AVL_StringAdd_lessThan(void){
  initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);

   int m =StringCompare("Abu",&nodeAli);
   TEST_ASSERT_EQUAL(-1,m);
}
void test_AVL_StringAdd_moreThan(void){
  initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);

   int m =StringCompare("Amin",&nodeAli);
   TEST_ASSERT_EQUAL(1,m);
}


 void test_AVL_StringAdd(void){
   initStringNode(&nodeAli,NULL,NULL,0);
   initStringNode(&nodeAmin,NULL,NULL,0);
   StringNode *root = &nodeAli;

   avlAddString(&root,&nodeAmin);
   TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,&nodeAmin,1,&nodeAli);
   avlAddString(&root,&nodeAbu);
   TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(&nodeAbu,&nodeAmin,0,&nodeAli);
}


void test_AVL_StringRemove(void){
  initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);
  StringNode *root = &nodeAli;

  avlRemoveString(&root,"Amin");
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_PTR(&nodeAbu,nodeAli.left);
  TEST_ASSERT_EQUAL_PTR(NULL,nodeAli.right);
//  TEST_ASSERT_EQUAL_NODE(&nodeAbu,NULL,-1,&nodeAli);
  avlRemoveString(&root,"Abu");
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  //TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&nodeAli);
}

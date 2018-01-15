#include "unity.h"
#include "avlAdd.h"
#include "remove.h"
#include "stdlib.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"
#include "rotate.h"
#include "AvlString.h"
#include "CException.h"
#include "Exception.h"

void setUp(void)
{
  giveInitString();
}

void tearDown(void)
{
}

    CEXCEPTION_T ex;

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

/*

                  add Amin          Ali(+1)
    Ali(0)--------------------->     \
                                    Amin(0)
*/
 void test_AVL_StringAdd_Ali_is_root_add_Amin(void){
   initStringNode(&nodeAli,NULL,NULL,0);
   initStringNode(&nodeAmin,NULL,NULL,0);
   StringNode *root = &nodeAli;

   Try{
   avlAddString(&root,&nodeAmin);
    }Catch(ex){
    dumpException(ex);
    }
    
   TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,&nodeAmin,1,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAmin);
}
/*

       Ali(+1)               add Amin                        Ali(0)
        \             ----------------->                  /       \
      Amin(0)                                           Abu(0)    Amin(0)
*/
 void test_AVL_StringAdd_Ali_Amin_In_Avltree_add_Abu(void){
   initStringNode(&nodeAli,NULL,&nodeAmin,1);
   initStringNode(&nodeAmin,NULL,NULL,0);
   initStringNode(&nodeAbu,NULL,NULL,0);
   StringNode *root = &nodeAli;
   Try{
     avlAddString(&root,&nodeAbu);
    }Catch(ex){
    dumpException(ex);
    }
   TEST_ASSERT_EQUAL_STRING_NODE(&nodeAbu,&nodeAmin,0,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAbu);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAmin);
}
/*

       Ali(+1)             add Amin            Ali(1)                  rotateleft               Alirosa(0)
        \             ----------------->          \             ------------------->          /          \
      Alirosa(0)                                 Alirosa(1)                                 Ali(0)        Amin(0)
                                                    \
                                                  Amin(0)
*/
 void test_AVL_StringAdd_Ali_Alirosa_In_Avltree_add_Amin(void){
   initStringNode(&nodeAli,NULL,&nodeAlirosa,1);
   initStringNode(&nodeAmin,NULL,NULL,0);
   initStringNode(&nodeAlirosa,NULL,NULL,0);
   StringNode *root = &nodeAli;
   Try{
     avlAddString(&root,&nodeAmin);
    }Catch(ex){
    dumpException(ex);
    }
   TEST_ASSERT_EQUAL_PTR(root,&nodeAlirosa);
   TEST_ASSERT_EQUAL_STRING_NODE(&nodeAli,&nodeAmin,0,&nodeAlirosa);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAli);
   TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAmin);
}

/*

       Ali(0)                               Ali(-1)
      /   \         ----------------->      /
  Abu(0)  Amin(0)                         Abu(0)
*/
void test_AVL_StringRemove_Ali_Abu_AMin_remove_Amin(void){
  initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);
  StringNode *root = &nodeAli;

  Try{
    avlRemoveString(&root,"Amin");
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_STRING_NODE(&nodeAbu,NULL,-1,&nodeAli);
  TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAbu);
}

/*

       Ali(0)                               Ali(+1)
      /   \         ----------------->      \
  Abu(0)  Amin(0)                           Amin(0)
*/
void test_AVL_StringRemove_Ali_Abu_Amin_remove_Abu(void){
  initStringNode(&nodeAli,&nodeAbu,&nodeAmin,0);
  initStringNode(&nodeAmin,NULL,NULL,0);
  initStringNode(&nodeAbu,NULL,NULL,0);
  StringNode *root = &nodeAli;
  Try{
    avlRemoveString(&root,"Abu");
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_EQUAL_PTR(root,&nodeAli);
  TEST_ASSERT_EQUAL_STRING_NODE(NULL,&nodeAmin,1,&nodeAli);
  TEST_ASSERT_EQUAL_STRING_NODE(NULL,NULL,0,&nodeAmin);
}

/*

       Ali(+1)             add nodeAlirosa
            \   ------------------------------------->exception
            Alirosa
*/
 void test_AVL_StringAdd_Ali_Alirosa_In_Avltree_add_Alirosa_expect_exception(void){
   initStringNode(&nodeAli,NULL,&nodeAlirosa,1);
   initStringNode(&nodeAlirosa,NULL,NULL,0);
   StringNode *root = &nodeAli;
   Try{
   avlAddString(&root,&nodeAlirosa);
   }Catch(ex){
     dumpException(ex);
     TEST_ASSERT_EQUAL_PTR(&nodeAli,root);
   }
     freeException1(ex);
}

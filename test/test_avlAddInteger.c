#include "unity.h"
#include "stdlib.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"
#include "avlAddInteger.h"

void setUp(void)
{
    giveInitdata();
}

void tearDown(void)
{
}


/**
---------compare----------------------
*        40
*       /  \
*   30 (0)  50(0)
*
*
*
**/
void test_compare_lessThan(void){
initNode(&node30,NULL,NULL,0);
initNode(&node50,NULL,NULL,0);
initNode(&node40,&node30,&node50,0);

int m =IntegerCompare(30,&node40);
TEST_ASSERT_EQUAL(-1,m);
}

void test_compare_moreThan(void){
initNode(&node30,NULL,NULL,0);
initNode(&node50,NULL,NULL,0);
initNode(&node40,&node30,&node50,0);

int m =IntegerCompare(50,&node40);
TEST_ASSERT_EQUAL(1,m);
}
void test_compare_Equal(void){
initNode(&node30,NULL,NULL,0);
initNode(&node50,NULL,NULL,0);
initNode(&node40,&node30,&node50,0);

int m =IntegerCompare(40,&node40);
TEST_ASSERT_EQUAL(0,m);
}

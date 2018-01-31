#include "unity.h"
#include "avlAdd.h"
#include "stdlib.h"
#include "nodeHelper.h"
#include "nodeVerifier.h"
#include "rotate.h"
#include "avlAddInteger.h"
#include "Exception.h"
#include "CException.h"
#include "remove.h"

void setUp(void)
{
    giveInitdata();
}

void tearDown(void)
{
}

/**
---adding----------
*      25                        
*     /  \        
*   1   	50  
*       	/ \                     
*        40  55                
*                               
*                               
**/
void test_functional_test1(void){
	 initNode(&node1,NULL,NULL,0);
     initNode(&node25,NULL,NULL,0);
     initNode(&node40,NULL,NULL,0);
     initNode(&node50,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);


     Node *root = NULL;
     avlAddInteger(&root,&node1);
	 avlAddInteger(&root,&node25);
	 avlAddInteger(&root,&node40);
	 avlAddInteger(&root,&node50);
	 avlAddInteger(&root,&node55);
	 
     TEST_ASSERT_EQUAL_PTR(&node25,root);
	 TEST_ASSERT_EQUAL_NODE(&node1,&node50,1,&node25);
     TEST_ASSERT_EQUAL_NODE(&node40,&node55,0,&node50);
}

/**
------------------------------------------------------------remove 25-------------------------------------------
*      25                        			40(1)
*     /  \        					    / \
*   1   	50  ----------->    		   1   50(1)
*       	/ \                     			    \
*        40  55                				55
*                               
*                               
**/
void test_functional_test2(void){
	 initNode(&node1,NULL,NULL,0);
     initNode(&node25,NULL,NULL,0);
     initNode(&node40,NULL,NULL,0);
     initNode(&node50,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);


     Node *root = NULL;
     avlAddInteger(&root,&node1);
	 avlAddInteger(&root,&node25);
	 avlAddInteger(&root,&node40);
	 avlAddInteger(&root,&node50);
	 avlAddInteger(&root,&node55);
	 
	 avlRemoveInteger(&root,25);
     TEST_ASSERT_EQUAL_PTR(&node40,root);
	 TEST_ASSERT_EQUAL_NODE(&node1,&node50,1,&node40);
     TEST_ASSERT_EQUAL_NODE(NULL,&node55,1,&node50);
}




/**
---------------------------------final form after adding-------------------------------
*      					       75
						   /        \'
*    					  /           \ 
						 /		     \
*    					50           	 120   
*    				     / \          	 /   \      
*     				   25    60        90    200 
*                          / \   / \     	/\      / \
*                         1   40 55 65	  80  100   150 250
**/
void test_avlAdd_functional_test3(void){
     initNode(&node1,NULL,NULL,0);
     initNode(&node40,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node65,NULL,NULL,0);
	 initNode(&node80,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node150,NULL,NULL,0);
     initNode(&node250,NULL,NULL,0);
	 initNode(&node25,NULL,NULL,0);
     initNode(&node60,NULL,NULL,0);
     initNode(&node90,NULL,NULL,0);
	 initNode(&node200,NULL,NULL,0);
	 initNode(&node50,NULL,NULL,0);
     initNode(&node120,NULL,NULL,0);
     initNode(&node75,NULL,NULL,0);

	 Node *root = NULL;
     avlAddInteger(&root,&node1);
	 avlAddInteger(&root,&node25);
	 avlAddInteger(&root,&node40);
	 avlAddInteger(&root,&node50);
	 avlAddInteger(&root,&node55);
	 avlAddInteger(&root,&node60);
	 avlAddInteger(&root,&node65);
	 avlAddInteger(&root,&node75);
	 avlAddInteger(&root,&node80);
	 avlAddInteger(&root,&node90);
	 avlAddInteger(&root,&node100);
	 avlAddInteger(&root,&node120);
	 avlAddInteger(&root,&node150);
	 avlAddInteger(&root,&node200);
	 avlAddInteger(&root,&node250);
	 
	 avlRemoveInteger(&root,60);
	 TEST_ASSERT_EQUAL_PTR(&node75,root);
	 TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
	 TEST_ASSERT_EQUAL_NODE(&node25,&node65,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node1,&node40,0,&node25);
	 TEST_ASSERT_EQUAL_NODE(&node55,NULL,-1,&node65);
     TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
     TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
	 TEST_ASSERT_EQUAL_NODE(&node150,&node250,0,&node200);
	 
	 avlRemoveInteger(&root,150);
	 TEST_ASSERT_EQUAL_PTR(&node75,root);
	 TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
	 TEST_ASSERT_EQUAL_NODE(&node25,&node65,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node1,&node40,0,&node25);
	 TEST_ASSERT_EQUAL_NODE(&node55,NULL,-1,&node65);
     TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
     TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
	 TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
	 
     avlRemoveInteger(&root,25);
	 TEST_ASSERT_EQUAL_PTR(&node75,root);
	 TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node75);
	 TEST_ASSERT_EQUAL_NODE(&node40,&node65,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
	 TEST_ASSERT_EQUAL_NODE(&node55,NULL,-1,&node65);
     TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
     TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
	 TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
	 
	 avlRemoveInteger(&root,50);
	 TEST_ASSERT_EQUAL_PTR(&node75,root);
	 TEST_ASSERT_EQUAL_NODE(&node55,&node120,0,&node75);
	 TEST_ASSERT_EQUAL_NODE(&node40,&node65,-1,&node55);
     TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
     TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
     TEST_ASSERT_EQUAL_NODE(&node80,&node100,0,&node90);
	 TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
	 
	 avlRemoveInteger(&root,90);
	 TEST_ASSERT_EQUAL_PTR(&node75,root);
	 TEST_ASSERT_EQUAL_NODE(&node55,&node120,0,&node75);
	 TEST_ASSERT_EQUAL_NODE(&node40,&node65,-1,&node55);
     TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
     TEST_ASSERT_EQUAL_NODE(&node100,&node200,0,&node120);
     TEST_ASSERT_EQUAL_NODE(&node80,NULL,-1,&node100);
	 TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);
	 
	 avlRemoveInteger(&root,75);
	 TEST_ASSERT_EQUAL_PTR(&node80,root);
	 TEST_ASSERT_EQUAL_NODE(&node55,&node120,0,&node80);
	 TEST_ASSERT_EQUAL_NODE(&node40,&node65,-1,&node55);
     TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
     TEST_ASSERT_EQUAL_NODE(&node100,&node200,1,&node120);
     TEST_ASSERT_EQUAL_NODE(NULL,NULL,0,&node100);
	 TEST_ASSERT_EQUAL_NODE(NULL,&node250,1,&node200);

	 avlRemoveInteger(&root,120);
	 TEST_ASSERT_EQUAL_PTR(&node80,root);
	 TEST_ASSERT_EQUAL_NODE(&node55,&node200,-1,&node80);
	 TEST_ASSERT_EQUAL_NODE(&node40,&node65,-1,&node55);
     TEST_ASSERT_EQUAL_NODE(&node1,NULL,-1,&node40);
     TEST_ASSERT_EQUAL_NODE(&node100,&node250,0,&node200);
	 
}

void test_avlAdd_functional_remove_root(void){
     initNode(&node1,NULL,NULL,0);
     initNode(&node40,NULL,NULL,0);
     initNode(&node55,NULL,NULL,0);
     initNode(&node65,NULL,NULL,0);
	 initNode(&node80,NULL,NULL,0);
     initNode(&node100,NULL,NULL,0);
     initNode(&node150,NULL,NULL,0);
     initNode(&node250,NULL,NULL,0);
	 initNode(&node25,NULL,NULL,0);
     initNode(&node60,NULL,NULL,0);
     initNode(&node90,NULL,NULL,0);
	 initNode(&node200,NULL,NULL,0);
	 initNode(&node50,NULL,NULL,0);
     initNode(&node120,NULL,NULL,0);
     initNode(&node75,NULL,NULL,0);

	 Node *root = NULL;
     avlAddInteger(&root,&node1);
	 avlAddInteger(&root,&node25);
	 avlAddInteger(&root,&node40);
	 avlAddInteger(&root,&node50);
	 avlAddInteger(&root,&node55);
	 avlAddInteger(&root,&node60);
	 avlAddInteger(&root,&node65);
	 avlAddInteger(&root,&node75);
	 avlAddInteger(&root,&node80);
	 avlAddInteger(&root,&node90);
	 avlAddInteger(&root,&node100);
	 avlAddInteger(&root,&node120);
	 avlAddInteger(&root,&node150);
	 avlAddInteger(&root,&node200);
	 avlAddInteger(&root,&node250);
	 

	 avlRemoveInteger(&root,75);
	 TEST_ASSERT_EQUAL_PTR(&node80,root);
	 TEST_ASSERT_EQUAL_NODE(&node50,&node120,0,&node80);
	 TEST_ASSERT_EQUAL_NODE(&node25,&node60,0,&node50);
     TEST_ASSERT_EQUAL_NODE(&node1,&node40,0,&node25);
	 TEST_ASSERT_EQUAL_NODE(&node55,&node65,0,&node60);
     TEST_ASSERT_EQUAL_NODE(&node90,&node200,0,&node120);
     TEST_ASSERT_EQUAL_NODE(NULL,&node100,1,&node90);
	 TEST_ASSERT_EQUAL_NODE(&node150,&node250,0,&node200);
}
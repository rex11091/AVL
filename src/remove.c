#include "remove.h"
#include "stdlib.h"
#include "stdio.h"
#include "node.h"
#include "rotate.h"



 Node *findnearest(Node *rootPtr)
 {
	Node *current = rootPtr->left;
     /* loop down to find the leftmost leaf */
	 if(current!=NULL){
       if(current->left != NULL)
          findnearest(rootPtr->left);
	     else{
		   if(current->right !=NULL){
			   rootPtr->left = current->right;
         rootPtr->balanceFactor +=1;
         current->right = NULL;
       }
		   else{
			   rootPtr->left = NULL;
			   rootPtr->balanceFactor +=1;
        }
			   return current;
		   }
	 }
  else
     return rootPtr;
 }

 Node *findnearest1(Node *rootPtr, int *heightchange)
 {
 Node *current = rootPtr->left;
     /* loop down to find the leftmost leaf */
  if(current!=NULL){
       if(current->left != NULL)
          findnearest1(rootPtr->left,heightchange);
      else{
        if(rootPtr->right!=NULL)
        {
          if(current->right !=NULL){
            rootPtr->left = current->right;
            rootPtr->balanceFactor +=1;
            current->right = NULL;
            *heightchange = 1;
          }
          else{
            rootPtr->left = NULL;
            rootPtr->balanceFactor +=1;
            *heightchange = 0;
            }
        return current;
      }
      else{
        if(rootPtr->right!=NULL)
        {
          if(current->right !=NULL){
            rootPtr->left = current->right;
            rootPtr->balanceFactor +=1;
            current->right = NULL;
            *heightchange = 1;
          }
          else{
            rootPtr->left = NULL;
            rootPtr->balanceFactor +=1;
            *heightchange = 1;
            }
        return current;
      }
      }
      }
  }
  else
     *heightchange = 1;
     return rootPtr;
 }
/*
int deleteNode(Node **root, int nodeToRemove){
      int m; // to determine either root's heigh change or unchange
       //standard removing
       // 0 is no height change
       if (*root == NULL)
           return 1; //heigh change

       if(nodeToRemove < (*root)->data ){
         m=deleteNode(&(*root)->left, nodeToRemove);
         if(m==1)
            (*root)->balanceFactor +=1;
            if((*root)->balanceFactor != 0)
            m = 0;
       }
       else if(nodeToRemove > (*root)->data ){
         m=deleteNode(&(*root)->right, nodeToRemove);
         if(m==1)
            (*root)->balanceFactor -=1;
            if((*root)->balanceFactor != 0)
            m = 0;
       }
       else if(nodeToRemove == (*root)->data ){
           // node with only one child or no child
         if( ( (*root)->left == NULL) || ( (*root)->right == NULL) )
         {
             Node *temp = (*root)->left ?  (*root)->left : (*root)->right;

             // No child case
             if (temp == NULL)
             {
                 temp = *root;
                 *root = NULL;
                 m=1; //heigh change
             }
             else // One child case
             {
              *root = temp; // Copy the contents of the non-empty child
              m=1; // height change
             }
        }
        else
        {
            // node with two children case
            //find the nearest in removenode->right->most left
            Node* temp1 = findnearest((*root)->right);
            //deleteNode(&(*root)->right, temp1->data);
            // Copy the nearest's data to this node
            //if(m == 1)
            (*root)->balanceFactor -=1;
            if(temp1->right!=NULL){
              temp1->balanceFactor = ((*root)->balanceFactor);
              temp1->left = (*root)->left;
              (*root) = temp1;
            }
            else{
            temp1->balanceFactor = ((*root)->balanceFactor);
            temp1->left = (*root)->left;
            temp1->right= (*root)->right;
            (*root) = temp1;
            }
			       m=1;
             if(*root==NULL){
               return m;
             }
			       if((*root)->balanceFactor >= 2)
                avlBalanceRightTree(&(*root));
             else if((*root)->balanceFactor <= -2)
                 avlBalanceLeftTree(&(*root));
             else{
                *root = *root;
               }
            return m;
        }
    }
    if(*root==NULL){
          return m;
        }
    if((*root)->balanceFactor >= 2)
          avlBalanceRightTree(&(*root));
    else if((*root)->balanceFactor <= -2)
          avlBalanceLeftTree(&(*root));
    else{
          *root = *root;
        }
    return m;
}
*/

Node *avlRemove(Node **rootPtr, int data){
    int heightchange;
    Node *avlRemove = _avlRemove(rootPtr, data, &heightchange);
    if(avlRemove == NULL){
        printf("deleted value doesn't exist!");
    }
    return avlRemove;
}




Node *_avlRemove(Node **root, int nodeToRemove ,int *heightchange){

        Node *temp = *root;
        //heightchange to determine either root's heigh change or unchange
       //standard removing
       // 0 is no height change
       if (*root == NULL)
           return NULL; //heigh change

       if(nodeToRemove < (*root)->data ){
         temp=_avlRemove(&(*root)->left, nodeToRemove,heightchange);
         if(*heightchange == 1)
            (*root)->balanceFactor +=1;
            if((*root)->balanceFactor != 0)
            *heightchange = 0;
       }
       else if(nodeToRemove > (*root)->data ){
         temp=_avlRemove(&(*root)->right, nodeToRemove,heightchange);
         if(*heightchange==1)
            (*root)->balanceFactor -=1;
            if((*root)->balanceFactor != 0)
            *heightchange = 0;
       }
       else if(nodeToRemove == (*root)->data ){
           // node with only one child or no child
         if( ( (*root)->left == NULL) || ( (*root)->right == NULL) )
         {
             Node *current = (*root)->left ?  (*root)->left : (*root)->right;

             // No child case
             if (current == NULL)
             {
                 current = *root;
                 *root = NULL;
                 *heightchange=1; //heigh change
             }
             else // One child case
             {
              *root = current; // Copy the contents of the non-empty child
              *heightchange=1; // height change
             }
        }
        else// node with two children case
        {
            //find the nearest in removenode->right->most left
            Node* temp1 = findnearest1((*root)->right,heightchange);
            //checking whether have heightchange ?
            if(*heightchange==1)
            (*root)->balanceFactor -=1;
            else
            (*root)->balanceFactor=(*root)->balanceFactor;
            // Copy the nearest's data to this node
            if(temp1->right!=NULL){
              temp1->balanceFactor = ((*root)->balanceFactor);
              temp1->left = (*root)->left;
              (*root) = temp1;
            }
            else{
            temp1->balanceFactor = ((*root)->balanceFactor);
            temp1->left = (*root)->left;
            temp1->right= (*root)->right;
            (*root) = temp1;
            }
			       *heightchange=1;
             if(*root==NULL){
               return temp;
             }
			       if((*root)->balanceFactor >= 2)
                avlBalanceRightTree(&(*root));
             else if((*root)->balanceFactor <= -2)
                 avlBalanceLeftTree(&(*root));
             else{
                *root = *root;
               }
            return temp;
        }
    }
    if(*root==NULL){
          return temp;
        }
    if((*root)->balanceFactor >= 2)
          avlBalanceRightTree(&(*root));
    else if((*root)->balanceFactor <= -2)
          avlBalanceLeftTree(&(*root));
    else{
          *root = *root;
        }
    return temp;
}

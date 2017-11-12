#include "remove.h"
#include "stdlib.h"
#include "stdio.h"
#include "node.h"
#include "rotate.h"



 Node *findnearest(Node *current)
 {

     /* loop down to find the leftmost leaf */
     if(current->left != NULL)
     current= findnearest(current->left);
     else
     return current ;
 }


//recursive remove node
Node *RemoveNode(Node **root, int nodeToRemove)
 {
    int m;
     //standard removing
     if (*root == NULL)
         return *root;

     // If the nodeToRemove is smaller than the root's data, then it lies on left
     if ( nodeToRemove < (*root)->data ){
         (*root)->left = RemoveNode(&(*root)->left, nodeToRemove);

         (*root)->balanceFactor += 1;
        }
    // if the node To Remove is bigger than root's data then is must be at right tree
     else if ( nodeToRemove > (*root)->data ){
          (*root)->right = RemoveNode(&(*root)->right, nodeToRemove);
          (*root)->balanceFactor -= 1;
        }
     else
     {
         // node with only one child or no child
         if( ( (*root)->left == NULL) || ( (*root)->right == NULL) )
         {
             Node *temp = (*root)->left ?  (*root)->left : (*root)->right;

             // No child case
             if (temp == NULL)
             {
                 temp = *root;
                 *root = NULL;
             }
             else // One child case
              *root = temp; // Copy the contents of the non-empty child
          }
          else
          {
            // node with two children
            //find the nearest 1 in removenode->right->most left
            Node* temp1 = findnearest((*root)->right);
            //delete the node of nearest after store the content to temp
            RemoveNode(&(*root)->right, temp1->data);
            // Copy the nearest's data to this node
            temp1->balanceFactor = ((*root)->balanceFactor);
            temp1->left = (*root)->left;
            temp1->right= (*root)->right;
            (*root) = temp1;

          }
     }
     if (*root == NULL){
     return *root;
    }
     if((*root)->balanceFactor >= 2)
         avlBalanceRightTree(&(*root));
     else if((*root)->balanceFactor <= -2)
         avlBalanceLeftTree(&(*root));
     else{
        *root = *root;
       }
    return *root;
  }

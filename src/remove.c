#include "remove.h"
#include "stdlib.h"
#include "stdio.h"
#include "node.h"
#include "rotate.h"



 Node *findnearest(Node* node)
 {
     Node* current = node;

     /* loop down to find the leftmost leaf */
     while (current->left != NULL)
         current = current->left;

     return current;
 }


//recursive remove node
Node *RemoveNode(Node **root, int nodeToRemove)
 {
     //standard removing
     if (*root == NULL)
         return *root;

     // If the nodeToRemove is smaller than the root's data, then it lies on left
     if ( nodeToRemove < (*root)->data )
         (*root)->left = RemoveNode(&(*root)->left, nodeToRemove);

     else
     {
         // node with only one child or no child
         if( ( (*root)->left == NULL) || ( (*root)->right == NULL) )
         {
             Node *temp = (*root)->left ?  (*root)->left : (*root)->right;

             // No child case
             if (&temp == NULL)
             {
                 temp = *root;
                 *root = NULL;
             }
             else // One child case
              *root = temp; // Copy the contents of
                             // the non-empty child
            // free(temp);
           }
      return *root;
     }
  }

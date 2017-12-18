#include "nodeHelper.h"

extern Node node1 ,node5, node10,node15, node20, node25, node30, node35, node40;
extern Node node45, node50, node55, node60, node65, node70, node75, node80;
extern Node node85, node90, node95, node100;

//string
extern StringNode nodeAli, nodeAbu, nodeAkau, nodeAlirosa,nodeAmin;

void initNode (Node *node, Node *left, Node *right, int bf){

  node->left = left;
  node->right = right;
  node->balanceFactor = bf;

}

void giveInitdata(void){
  node1.data = (int *)1 ;
  node5.data = (int *)5 ;
  node10.data = (int *)10 ;
  node15.data = (int *)15 ;
  node20.data = (int *)20 ;
  node25.data = (int *)25 ;
  node30.data = (int *)30 ;
  node35.data = (int *)35 ;
  node40.data = (int *)40 ;
  node45.data = (int *)45 ;
  node50.data = (int *)50 ;
  node55.data = (int *)55 ;
  node60.data = (int *)60 ;
  node65.data = (int *)65 ;
  node70.data = (int *)70 ;
  node75.data = (int *)75 ;
  node80.data = (int *)80 ;
  node85.data = (int *)85 ;
  node90.data = (int *)90 ;
  node95.data = (int *)95 ;
  node100.data = (int *)100 ;

}

void giveInitString(void){
  nodeAli.data="Ali";
  nodeAbu.data="Abu";
  nodeAkau.data="Akau";
  nodeAlirosa.data="Alirosa";
  nodeAmin.data="Amin";
}

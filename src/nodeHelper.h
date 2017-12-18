#ifndef _NODEHELPER_H
#define _NODEHELPER_H
#include "node.h"

Node node1 ,node5, node10,node15, node20, node25, node30, node35, node40;
Node node45, node50, node55, node60, node65, node70, node75, node80;
Node node85, node90, node95, node100;
StringNode nodeAli, nodeAbu, nodeAkau, nodeAlirosa, nodeAmin;

void initNode (Node *node, Node *left, Node *right, int bf);
void giveInitdata(void);
void giveInitString(void);


#define initStringNode(n,l,r,bf)  initNode((Node *)n,(Node *)l,(Node *)r,bf)



#endif // _NODEHELPER_H

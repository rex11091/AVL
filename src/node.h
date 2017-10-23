#ifndef _NODE_H
#define _NODE_H

#include <stdint.h>

typedef struct Node Node;
struct Node {
  Node *left;
  Node *right;
  int balanceFactor;
  uint32_t data;    // will be change ltr ,no neccessary integer
};

typedef struct StringNode StringNode;
struct StringNode {
  StringNode *left;
  StringNode *right;
  char *data;
};


#endif // _NODE_H

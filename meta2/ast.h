#ifndef AST_FILE
#define AST_FILE

#include "structs.h"

Node createNode(Label, char *);
void addChild(Node, Node);
Node addBrother(Node, Node);
void printTree(Node, int);
void freeTree(Node);
char *labelToString(Label);

Node treeRoot;
Node aux;
Node aux2;

#endif

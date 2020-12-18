#ifndef STRUCTS_FILE
#define STRUCTS_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG 0
#define ERROR -1

typedef enum _label {
	Empty, undef, Program, Declaration, FuncDeclaration, FuncDefinition, ParamList, FuncBody, ParamDeclaration, StatList, If, While, Return, Or, And, Eq, Ne, Lt, Gt, Le, Ge, Add, Sub, Mul, Div, Mod, Not, Minus, Plus, Store, Comma, Call, BitWiseAnd, BitWiseXor, BitWiseOr, Char, ChrLit, Id, Int, Short, IntLit, Double, RealLit, Void, Null
} Label;

typedef struct _al* ArgList;
typedef struct _t1* SymList;
typedef struct _tl* TableList;
typedef struct node_s *Node;

typedef struct node_s
{
  Label label;
  Label type;
  ArgList argList;
  char *value;
  Node child;
  Node brother;
} Node_t;

typedef struct _t1{
	char* name;
	Label label;
  SymList next;
}_SymList;

typedef struct _al{
  char* name;
  Label label;
  ArgList next;
}_argList;

typedef struct _tl{
  SymList tableNode;
  ArgList argList;
  int isDefined;
  TableList next;
}_tableList;

TableList globalTable;
TableList currentTable;
Node treeRoot;

#endif

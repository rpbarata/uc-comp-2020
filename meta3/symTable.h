#ifndef SYMTABLE_FILE
#define SYMTABLE_FILE

#include "structs.h"

# define DEBUG 0

char* getStringForTables(Label);
int handleNode(Node);
void semantic_analysis(Node);
void printTables();
void fullExpand(Node);
TableList findFunctionEntry(char*);
TableList createFunctionEntry(char*, Label, Node, int);
void putType(Node);
Label get_type(Node);
Label resolveType(Label, Label);
char *getLabelString(Label);
ArgList getFunctionArgs(char *);
int insertSymbol(TableList, char*, Label);
SymList findSymbol(TableList, char*);
ArgList findParameter(TableList, char*);

#endif

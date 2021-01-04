#ifndef GENERATOR_FILE
#define GENERATOR_FILE

#include "structs.h"
#include "symTable.h"
#include <stddef.h>

#define ERROR -1

#define LLVM_CHAR "i8"
#define LLVM_SHORT "i16"
#define LLVM_INT "i32"
#define LLVM_DOUBLE "double"
#define LLVM_VOID "VOID"

#define DEFAULT_CHAR_VALUE "0"
#define DEFAULT_SHORT_VALUE "0"
#define DEFAULT_INT_VALUE "0"
#define DEFAULT_DOUBLE_VALUE "0.000000e+00"
#define DEFAULT_VOID_VALUE ""

void generateCode(Node node);
char *getLlvmType(Label label);
char *getLlvmDefaultValue(Label label);
char *getVariable(char* value);
int evalInt(Node node);
double evalDouble(Node node);
char *handleConstant(Label type, char *value, char *aux_str);

#endif

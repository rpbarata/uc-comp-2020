#include  "generator.h"

int returnFound = 0;
int varCount = 1;
int ifLevel = 1;
int andOrCount = 1;
char* currentFunction = NULL;

void generateCode(Node node) {
   char aux_str[1024];
  switch (node->label) {
    case Program: {
      printf("########################## Program ##########################\n");
      printf("declare i32 @putchar(i32)\n");
      printf("declare i32 @getchar()\n");

      Node childNode = node->child;
      while(childNode != NULL) {
        generateCode(childNode);
        childNode = childNode->brother;
      }
      break;
    }

    case FuncDefinition: {
      printf("########################## FuncDefinition ##########################\n");
      varCount = 1;
      Node typeSpec = node->child;
      Node id = typeSpec->brother;
      Node paramList = id->brother;
      currentFunction = id->value;

      Node param = paramList->child;
      char paramString[1024];
      char auxString[1024];

      // Function declaration
      while(param != NULL) {
        auxString[0] = '\0';
        if(paramString[0] == '\0')
          sprintf(auxString, "%s %%%s", getLlvmType(param->child->label), param->child->brother->value);
        else
          sprintf(auxString, ", %s %%%s", getLlvmType(param->child->label), param->child->brother->value);

        strcat(paramString, auxString);
        param = param->brother;
      }
      printf("define %s @%s(%s){\n", getLlvmType(typeSpec->label), id->value, paramString);

      //Function Body
      param = paramList->child;
      generateCode(param);
      param = paramList->brother->child;
      while(param != NULL) {
        returnFound = 0;
        generateCode(param);
        if(returnFound)
          break;
        param = param->brother;
      }

      currentFunction = NULL;

      //Function return
      printf("\tret %s %s\n", getLlvmType(typeSpec->label), getLlvmDefaultValue(typeSpec->label));
      break;
    }

    case FuncDeclaration:
      break;

    case ParamDeclaration: {
      Node typeSpec = node->child;
      Node id = typeSpec->brother;

      if(typeSpec->label != Void) {
        printf("\t%%%d = alloca %s\n", varCount++, getLlvmType(typeSpec->label));
        printf("\tstore %s %%%s, %s* %%%d\n", getLlvmType(typeSpec->label), id->value, getLlvmType(typeSpec->label), varCount - 1);
        TableList table = findFunctionEntry(currentFunction);
        ArgList arg = findParameter(table, id->value);
        arg->varValue = varCount - 1;
      }
      if(node->brother != NULL)
        generateCode(node->brother);
      break;
    }

    case Declaration: {
      Node typeSpec = node->child;
      Node id = typeSpec->brother;
      Node aux = id->brother;

      if(currentFunction != NULL) {
        findSymbol(findFunctionEntry(currentFunction), id->value)->active = 1;
        printf("\t%s = alloca %s\n", getVariable(id->value), getLlvmType(typeSpec->label));

        if(aux != NULL) {
          generateCode(aux);
          printf("\tstore %s %%%d, %s* %%%s\n", getLlvmType(typeSpec->label), varCount - 1, getLlvmType(typeSpec->label), id->value);
        }
      }
      else {
        if(aux != NULL) {
          if (typeSpec->label != Double)
            printf("%s = common global %s %d\n", getVariable(id->value), getLlvmType(typeSpec->label), evalInt(aux));
          else
            printf("%s = common global %s %.16E\n", getVariable(id->value), getLlvmType(typeSpec->label), evalDouble(aux));
        }
        else
          printf("%s = common global %s %s\n", getVariable(id->value), getLlvmType(typeSpec->label), getLlvmDefaultValue(typeSpec->label));
      }
      break;
    }

    case StatList: {
      Node aux = node->child;
      while(aux != NULL){
        returnFound = 0;
        generateCode(aux);
        if(returnFound) break;
        aux = aux->brother;
      }
      break;
    }

    case RealLit:
      printf("\t%%%d = fadd double %s, %s\n", varCount++, getLlvmDefaultValue(Double), handleConstant(Double, node->value, aux_str));
      break;

    case IntLit:
      printf("\t%%%d = add i32 %s, %s\n", varCount++, getLlvmDefaultValue(Int), handleConstant(Int, node->value, aux_str));
      break;

    case ChrLit:
      printf("\t%%%d = add i32 %s, %s\n", varCount++, getLlvmDefaultValue(Char), handleConstant(Char, node->value, aux_str));
      break;

    case Id: {
      TableList table = findFunctionEntry(currentFunction);
      ArgList arg = findParameter(table, node->value);
      SymList sym = findSymbol(table, node->value);
      SymList globalSym = findSymbol(globalTable, node->value);
      Label label;

      if(globalSym != NULL) label = globalSym->label;
      if(sym != NULL && sym->active == 1) label = sym->label;
      if(arg != NULL) label = arg->label;
      printf("\t%%%d = load %s, %s* %s\n", varCount++, getLlvmType(label), getLlvmType(label), getVariable(node->value));
      break;
    }

    case If:
      break;

    case While:
      break;

    case Return:
      break;

    case Store:
      break;

    case Or:
      break;

    case And:
      break;

    case Eq:
      break;

    case Ne:
      break;

    case Lt:
      break;

    case Gt:
      break;

    case Ge:
      break;

    case Add:
      break;

    case Sub:
      break;

    case Mul:
      break;

    case Div:
      break;

    case Not:
      break;

    case Minus:
      break;

    case Plus:
      break;

    case Comma:
      break;

    case BitWiseAnd:
      break;

    case BitWiseXor:
      break;

    case BitWiseOr:
      break;

    case Call:
      break;

    case Null:
      break;

    default:
      printf("FATAL: defaulted call in code generation %s\n", labelToString(node->label));
      break;
  }
}

char *getLlvmType(Label label) {
  switch (label) {
    case Char:
      return LLVM_CHAR;
    case Short:
      return LLVM_SHORT;
    case Int:
      return LLVM_INT;
    case Double:
      return LLVM_DOUBLE;
    case Void:
      return LLVM_VOID;
    default:
      printf("FATAL: Invalid llvm type %s\n", labelToString(label));
  }
  return NULL;
}

char *getLlvmDefaultValue(Label label) {
  switch (label) {
    case Char:
      return DEFAULT_CHAR_VALUE;
    case Short:
      return DEFAULT_SHORT_VALUE;
    case Int:
      return DEFAULT_INT_VALUE;
    case Double:
      return DEFAULT_DOUBLE_VALUE;
    case Void:
      return DEFAULT_VOID_VALUE;
    default:
      printf("FATAL: Invalid type for default\n");
  }
  return NULL;
}

char *getVariable(char* value) {
  char *variable = (char *)malloc(sizeof(char) * 1024);
  if(currentFunction == NULL) {
    sprintf(variable, "@%s", value);
    return variable;
  }
  TableList entry = findFunctionEntry(currentFunction);
  ArgList argument = findParameter(entry, value);
  if (argument == NULL) {
    SymList symbol = findSymbol(entry, value);
    if (symbol != NULL && symbol->active == 1)
      sprintf(variable, "%%%s", value);
    else
      sprintf(variable, "@%s", value);
  }
  else
      sprintf(variable, "%%%d", argument->varValue);
  return variable;
}

int evalInt(Node node)
{
  char aux_str[1024];
  int aux_int;
  switch (node->label)
  {
  case Or:
    return evalInt(node->child) || evalInt(node->child->brother);
  case And:
    return evalInt(node->child) && evalInt(node->child->brother);
  case Eq:
    return evalInt(node->child) == evalInt(node->child->brother);
  case Ne:
    return evalInt(node->child) != evalInt(node->child->brother);
  case Lt:
    return evalInt(node->child) < evalInt(node->child->brother);
  case Le:
    return evalInt(node->child) <= evalInt(node->child->brother);
  case Gt:
    return evalInt(node->child) > evalInt(node->child->brother);
  case Ge:
    return evalInt(node->child) >= evalInt(node->child->brother);
  case Mod:
    return evalInt(node->child) % evalInt(node->child->brother);
  case Comma:
    break;
  case Add:
    return evalInt(node->child) + evalInt(node->child->brother);
  case Sub:
    return evalInt(node->child) - evalInt(node->child->brother);
  case Mul:
    return evalInt(node->child) * evalInt(node->child->brother);
  case Div:
    return evalInt(node->child) / evalInt(node->child->brother);
  case BitWiseAnd:
    return evalInt(node->child) & evalInt(node->child->brother);
  case BitWiseXor:
    return evalInt(node->child) ^ evalInt(node->child->brother);
  case BitWiseOr:
    return evalInt(node->child) | evalInt(node->child->brother);
  case Store:
    break;
  case Not:
    return !evalInt(node->child);
  case Minus:
    return -evalInt(node->child);
  case Plus:
    return +evalInt(node->child);
  case IntLit:
    sscanf(handleConstant(Int, node->value, aux_str), "%d", &aux_int);
    return aux_int;
    break;
  case ChrLit:
    sscanf(handleConstant(Char, node->value, aux_str), "%d", &aux_int);
    return aux_int;
    break;
  default:
    printf("FATAL: error in evalInt\n");
    return ERROR;
  }
  return ERROR;
}

double evalDouble(Node node)
{
  char aux_str[1024];
  int aux_int;
  double aux_double;
  switch (node->label)
  {
  case Or:
    return evalDouble(node->child) || evalDouble(node->child->brother);
  case And:
    return evalDouble(node->child) && evalDouble(node->child->brother);
  case Eq:
    return evalDouble(node->child) == evalDouble(node->child->brother);
  case Ne:
    return evalDouble(node->child) != evalDouble(node->child->brother);
  case Lt:
    return evalDouble(node->child) < evalDouble(node->child->brother);
  case Le:
    return evalDouble(node->child) <= evalDouble(node->child->brother);
  case Gt:
    return evalDouble(node->child) > evalDouble(node->child->brother);
  case Ge:
    return evalDouble(node->child) >= evalDouble(node->child->brother);
  case Comma:
    //Pensar amanha depois de beber um cafe
    break;
  case Add:
    return evalDouble(node->child) + evalDouble(node->child->brother);
  case Sub:
    return evalDouble(node->child) - evalDouble(node->child->brother);
  case Mul:
    return evalDouble(node->child) * evalDouble(node->child->brother);
  case Div:
    return evalDouble(node->child) / evalDouble(node->child->brother);
  case Store:
    //Pensar amanha depois de beber um cafe
    break;
  case Not:
    return !evalDouble(node->child);
  case Minus:
    return -evalDouble(node->child);
  case Plus:
    return +evalDouble(node->child);
  case IntLit:
    sscanf(handleConstant(Int, node->value, aux_str), "%d", &aux_int);
    return aux_int;
    break;
  case ChrLit:
    sscanf(handleConstant(Char, node->value, aux_str), "%d", &aux_int);
    return aux_int;
    break;
  case RealLit:
    sscanf(node->value, "%lf", &aux_double);
    return aux_double;
    break;

  default:
    printf("FATAL: error in evalDouble %s\n", labelToString(node->label));
    return ERROR;
  }
  return ERROR;
}

char *handleConstant(Label type, char *value, char *aux_str)
{
  switch (type)
  {
  case Double:
  {
    double aux_double;
    //printf("value %s\n", value);
    sscanf(value, "%lf", &aux_double);
    //printf("aux_double %lf\n", aux_double);
    sprintf(aux_str, "%.16E", aux_double); //verificar quantas casas devem ser
    //printf("aux_str %s\n", aux_str);
    break;
  }
  case Short:
    /*
    while(value[i] != '\0'){
      if(value[i] == 'e' || value[i] == "E"){
        exponential_flag = 1;
      }
    }
    if(exponential_flag){
      double aux;
      sscanf(value, "%lf", &aux);
    }
    */
    aux_str = value;
    break;
  case Int:
    if (value[0] == '0')
    {
      int aux_int;
      sscanf(value, "%o", &aux_int);
      sprintf(aux_str, "%d", aux_int);
    }
    else
    {
      aux_str = value;
    }
    break;
  case Char:
  {
    char aux_char = '\0';
    //TODO: Temos de fazer um caso especial para os caracteres \t \n e assim
    //printf("value %s\n", value);
    if (value[1] == '\\')
    {
      if (value[2] == 'n')
      {
        aux_char = '\n';
      }
      else if (value[2] == 't')
      {
        aux_char = '\t';
      }
      else if (value[2] == '\\')
      {
        aux_char = '\\';
      }
      else if (value[2] == '\'')
      {
        aux_char = '\'';
      }
      else if (value[2] == '"')
      {
        aux_char = '"';
      }
      else{
        value = value + 2;
        int aux_int = 0;
        for (; value[aux_int]!='\''; aux_int++){}
        value[aux_int] = '\0';
        sscanf(value, "%o", &aux_int);
        aux_char = (char) aux_int;
      }
    }
    else
    {
      aux_char = value[1];
    }
    //printf("aux_char %c\n", aux_char);
    sprintf(aux_str, "%d", aux_char);
    //printf("aux_str %s\n", aux_str);
    break;
  }
  case Void:
    sprintf(aux_str, "");
    break;
  default:
    printf("FATAL: Invalid constant type\n");
  }
  return aux_str;
}

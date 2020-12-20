#include "symTable.h"

void printTables() {
  printf("===== Global Symbol Table =====\n");
  TableList entry = globalTable;
  SymList symbolEntry = globalTable->tableNode->next;
  while (symbolEntry != NULL) {
    char *s = labelToStringForTable(symbolEntry->label);
    ArgList auxArgs = getFunctionArgs(symbolEntry->name);
    if (auxArgs == NULL)
      printf("%s\t%s\n", symbolEntry->name, s);
    else {
      printf("%s\t%s(", symbolEntry->name, s);
      while (auxArgs != NULL) {
        printf("%s", labelToStringForTable(auxArgs->label));
        auxArgs = auxArgs->next;
        if (auxArgs != NULL)
          printf(",");
      }
      printf(")\n");
    }
    symbolEntry = symbolEntry->next;
  }
  entry = entry->next;
  printf("\n");
  entry = globalTable;
  entry = entry->next;
  while (entry != NULL) {
    if (entry->isDefined) {
      printf("===== Function %s Symbol Table =====\n", entry->tableNode->name);
      SymList node = entry->tableNode;
      printf("%s\t%s\n", "return", labelToStringForTable(entry->tableNode->label));
      ArgList auxArgs = entry->argList;
      while (auxArgs != NULL) {
        if (auxArgs->label != Void && auxArgs->name != NULL)
          printf("%s\t%s\tparam\n", auxArgs->name, labelToStringForTable(auxArgs->label));
        auxArgs = auxArgs->next;
      }
      node = node->next;
      while (node != NULL) {
        char *s = labelToStringForTable(node->label);
        printf("%s\t%s\n", node->name, s);
        node = node->next;
      }
      printf("\n");
    }
    entry = entry->next;
  }
}

int handleNode(Node node) {
  switch (node->label) {
  case Program: {
    globalTable = (TableList)malloc(sizeof(_tableList));
    SymList newNode = (SymList)malloc(sizeof(_SymList));
    newNode->name = "Global";
    newNode->label = -1;
    newNode->next = NULL;
    globalTable->tableNode = newNode;
    globalTable->next = NULL;

    currentTable = globalTable;

    Node param = (Node)malloc(sizeof(Node_t));
    param->child = (Node)malloc(sizeof(Node_t));
    param->child->brother = NULL;
    Node typeSpec = (Node)malloc(sizeof(Node_t));
    typeSpec->label = Int;
    param->child->child = typeSpec;
    typeSpec->brother = NULL;
    createFunctionEntry("putchar", Int, param, 0);

    typeSpec->label = Void;
    createFunctionEntry("getchar", Int, param, 0);

    free(typeSpec);
    free(param->child);
    free(param);

    fullExpand(node);
    break;
  }

  case FuncDefinition: {
    Node typeSpec = node->child;
    Node id = typeSpec->brother;
    Node param = id->brother;

    currentTable = findFunctionEntry(id->value);
    if (currentTable == NULL) {
      currentTable = createFunctionEntry(id->value, typeSpec->label, param, 1);
    }
    else {
      ArgList arg = currentTable->argList;
      Node paramDec = param->child;
      while (paramDec != NULL) {
        Node typeSpec = paramDec->child;
        Node id = typeSpec->brother;

        if (arg == NULL)
          break;
        else if (typeSpec->label == arg->label && id != NULL) {
          arg->name = id->value;
        }

        paramDec = paramDec->brother;
        arg = arg->next;
      }

      currentTable->isDefined = 1;
    }

    handleNode(param->brother);

    currentTable = globalTable;

    if (node->brother != NULL)
      handleNode(node->brother);

    break;
  }

  case FuncDeclaration: {
    Node typeSpec = node->child;
    Node id = typeSpec->brother;
    Node param = id->brother;

    if (findFunctionEntry(id->value) == NULL)
      createFunctionEntry(id->value, typeSpec->label, param, 0);

    if (node->brother != NULL)
      handleNode(node->brother);

    break;
  }

  case Declaration: {
    Node typeSpec = node->child;
    Node id = typeSpec->brother;
    Node param = id->brother;

    insertSymbol(currentTable, id->value, typeSpec->label);
    while(param != NULL) {
      putType(param);
      param = param->brother;
    }
    fullExpand(node);
    break;
  }

  case RealLit: {
    node->type = Double;
    fullExpand(node);
    break;
  }

  case IntLit: {
    node->type = Int;
    fullExpand(node);
    break;
  }

  case ChrLit: {
    node->type = Int;
    fullExpand(node);
    break;
  }

  case Or:
  case And:
  case Eq:
  case Ne:
  case Lt:
  case Le:
  case Gt:
  case Ge:

  case Mod: {
    handleNode(node->child);
    putType(node->child);
    putType(node->child->brother);
    node->type = Int;

    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }

  case Comma: {
    handleNode(node->child);
    putType(node->child);
    putType(node->child->brother);

    if(node->child->type == undef)
      node->type = undef;
    else
      node->type = node->child->brother->type;

    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }

  case Add:
  case Sub:
  case Mul:
  case Div:
  case BitWiseAnd:
  case BitWiseXor:

  case BitWiseOr: {
    handleNode(node->child);
    putType(node->child);
    putType(node->child->brother);
    node->type = resolveType(node->child->type, node->child->brother->type);
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }

  case Store: {
    handleNode(node->child);
    putType(node->child);
    putType(node->child->brother);
    node->type = node->child->type;
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }

  case Not: {
    handleNode(node->child);
    putType(node->child);
    node->type = Int;
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }

  case Minus:

  case Plus: {
    handleNode(node->child);
    putType(node->child);
    node->type = node->child->type;
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }

  case While:
  case Return:

  case If: {
    handleNode(node->child);
    putType(node->child);
    Node aux = node->child->brother;

    while (aux != NULL) {
      putType(aux);
      aux = aux->brother;
    }
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }

  case Call: {
    handleNode(node->child);
    putType(node->child);
    Node aux = node->child->brother;
    while (aux != NULL) {
      putType(aux);
      aux = aux->brother;
    }
    node->type = node->child->type;
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }

  case FuncBody: {
    Node children = node->child;
    while(children != NULL){
      if(children->label == Id)
        putType(children);
      children = children->brother;
    }
    fullExpand(node);
  }

  default:
    fullExpand(node);
    break;
  }
  return 1;
}

void fullExpand(Node node) {
  if (node->child != NULL)
    handleNode(node->child);
  if (node->brother != NULL)
    handleNode(node->brother);
}

char *labelToStringForTable(Label label) {
  char *s;
  switch (label) {
  case Char:
    s = "char";
    break;
  case Int:
    s = "int";
    break;
  case Short:
    s = "short";
    break;
  case Double:
    s = "double";
    break;
  case Void:
    s = "void";
    break;
  case undef:
    s = "undef";
    break;
  default:
    s = labelToString(label);
    break;
  }
  return s;
}

TableList findFunctionEntry(char *name) {
  if (name == NULL)
    return NULL;

  TableList entry = globalTable;
  while (entry != NULL) {
    if (strcmp(entry->tableNode->name, name) == 0)
      return entry;
    entry = entry->next;
  }
  return NULL;
}

TableList createFunctionEntry(char *name, Label label, Node paramList, int isDefinition) {
  TableList entry = globalTable;
  while (entry->next != NULL)
    entry = entry->next;

  TableList newNode = (TableList)malloc(sizeof(_tableList));
  newNode->next = NULL;
  newNode->isDefined = isDefinition;

  SymList newList = (SymList)malloc(sizeof(_SymList));
  newList->label = label;
  newList->name = name;
  newNode->tableNode = newList;

  Node paramDec = paramList->child;
  Node typeSpec = paramDec->child;
  Node id = typeSpec->brother;
  ArgList args = (ArgList)malloc(sizeof(_argList));
  args->label = typeSpec->label;

  if (id != NULL)
    args->name = id->value;
  else
    args->name = NULL;

  args->next = NULL;
  newNode->argList = args;
  paramDec = paramDec->brother;

  while (paramDec != NULL) {
    typeSpec = paramDec->child;
    id = typeSpec->brother;

    ArgList newArg = (ArgList)malloc(sizeof(_argList));
    newArg->label = typeSpec->label;

    if (id != NULL && isDefinition)
      newArg->name = id->value;
    else
      newArg->name = NULL;

    newArg->next = NULL;
    args->next = newArg;
    args = newArg;
    paramDec = paramDec->brother;
  }

  entry->next = newNode;
  insertSymbol(globalTable, name, label);

  return newNode;
}

Label resolveType(Label label1, Label label2) {
  if (label1 == undef || label2 == undef)
    return undef;
  else if (label1 == Double || label2 == Double)
    return Double;
  else if (label1 == Int || label2 == Int)
    return Int;
  else if (label1 == Short || label2 == Short)
    return Short;
  else if (label1 == Char || label2 == Char)
    return Char;
  return Char;
}

void putType(Node node) {
  switch (node->label) {
    case Id: {
      ArgList argList = findParameter(currentTable, node->value);
      if (argList != NULL) {
        node->type = argList->label;
        return;
      }
      else {
        SymList symbolEntry = findSymbol(currentTable, node->value);
        if (symbolEntry != NULL)
          node->type = symbolEntry->label;
        else {
          symbolEntry = findSymbol(globalTable, node->value);
          if (symbolEntry != NULL) {
            node->type = symbolEntry->label;
            TableList entry = findFunctionEntry(node->value);
            if (entry != NULL)
              node->argList = entry->argList;
          }
        }
        if(symbolEntry == NULL) {
          node->type = undef;
        }
      }
      break;
    }

    case Void:
    case Char:
    case Double:
    case Int:

    case Short:
      node->type = node->label;
      break;

    default: {
      if (node->type == Empty)
        node->type = Empty;
      break;
    }
  }
}

char *labelToString(Label label) {
  switch (label) {
  case Empty:
    return "Empty";
  case undef:
    return "undef";
  case Program:
    return "Program";
  case Declaration:
    return "Declaration";
  case FuncDeclaration:
    return "FuncDeclaration";
  case FuncDefinition:
    return "FuncDefinition";
  case ParamList:
    return "ParamList";
  case FuncBody:
    return "FuncBody";
  case ParamDeclaration:
    return "ParamDeclaration";
  case StatList:
    return "StatList";
  case If:
    return "If";
  case While:
    return "While";
  case Return:
    return "Return";
  case Or:
    return "Or";
  case And:
    return "And";
  case Eq:
    return "Eq";
  case Ne:
    return "Ne";
  case Lt:
    return "Lt";
  case Gt:
    return "Gt";
  case Le:
    return "Le";
  case Ge:
    return "Ge";
  case Add:
    return "Add";
  case Sub:
    return "Sub";
  case Mul:
    return "Mul";
  case Div:
    return "Div";
  case Mod:
    return "Mod";
  case Not:
    return "Not";
  case Minus:
    return "Minus";
  case Plus:
    return "Plus";
  case Store:
    return "Store";
  case Comma:
    return "Comma";
  case Call:
    return "Call";
  case BitWiseAnd:
    return "BitWiseAnd";
  case BitWiseXor:
    return "BitWiseXor";
  case BitWiseOr:
    return "BitWiseOr";
  case Char:
    return "Char";
  case ChrLit:
    return "ChrLit";
  case Id:
    return "Id";
  case Int:
    return "Int";
  case Short:
    return "Short";
  case IntLit:
    return "IntLit";
  case Double:
    return "Double";
  case RealLit:
    return "RealLit";
  case Void:
    return "Void";
  case Null:
    return "Null";
  }
}

ArgList getFunctionArgs(char *name) {
  TableList entry = globalTable;
  while (entry != NULL) {
    if (strcmp(entry->tableNode->name, name) == 0)
      return entry->argList;
    entry = entry->next;
  }
  return NULL;
}

int insertSymbol(TableList table, char* name, Label label){
  SymList symList = table->tableNode;
  ArgList argList = table->argList;

  while(argList != NULL) {
    if(argList->name != NULL) {
      if(strcmp(argList->name, name) == 0) {
        return -1;
      }
    }
    argList = argList->next;
  }
  while(symList->next != NULL) {
    symList = symList->next;
    if(strcmp(symList->name, name) == 0) {
      return -1;
    }
  }

  SymList newNode = (SymList)malloc(sizeof(_SymList));
  newNode->name = name;
  newNode->label = label;
  newNode->next = NULL;
  symList->next = newNode;
  return 1;
}

SymList findSymbol(TableList tableList, char* name){
  SymList entry = tableList->tableNode->next;
  while(entry != NULL) {
    if(strcmp(entry->name, name) == 0) {
      return entry;
    }
    entry = entry->next;
  }
  return NULL;
}

ArgList findParameter(TableList tableList, char* name){
  ArgList entry = tableList->argList;
  while(entry != NULL) {
    if(entry->name != NULL)
      if(strcmp(entry->name, name) == 0) {
        return entry;
      }
    entry = entry->next;
  }
  return NULL;
}

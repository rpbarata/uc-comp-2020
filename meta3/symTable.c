#include "symTable.h"

void printTables() {
  printf("===== Global Symbol Table =====\n");
  TableList aux = globalTable;
  SymList globalAux = globalTable->tableNode->next;
  while (globalAux != NULL)
  {
    char *s = labelToStringForTable(globalAux->label);
    ArgList auxArgs = getFunctionArgs(globalAux->name);
    if (auxArgs == NULL)
    {
      printf("%s\t%s\n", globalAux->name, s);
    }
    else
    {
      printf("%s\t%s(", globalAux->name, s);
      while (auxArgs != NULL)
      {
        printf("%s", labelToStringForTable(auxArgs->label));
        auxArgs = auxArgs->next;
        if (auxArgs != NULL)
          printf(",");
      }
      printf(")\n");
    }
    globalAux = globalAux->next;
  }
  aux = aux->next;
  printf("\n");
  aux = globalTable;
  aux = aux->next;
  while (aux != NULL)
  {
    if (aux->isDefined)
    {
      printf("===== Function %s Symbol Table =====\n", aux->tableNode->name);
      SymList auxNode = aux->tableNode;
      printf("%s\t%s\n", "return", labelToStringForTable(aux->tableNode->label));
      ArgList auxArgs = aux->argList;
      while (auxArgs != NULL)
      {
        if (auxArgs->label != Void && auxArgs->name != NULL)
          printf("%s\t%s\tparam\n", auxArgs->name, labelToStringForTable(auxArgs->label));
        auxArgs = auxArgs->next;
      }
      auxNode = auxNode->next;
      while (auxNode != NULL)
      {
        char *s = labelToStringForTable(auxNode->label);
        printf("%s\t%s\n", auxNode->name, s);
        auxNode = auxNode->next;
      }
      printf("\n");
    }
    aux = aux->next;
  }
}

int handleNode(Node node)
{
  switch (node->label)
  {
  case Program:
  {
    globalTable = (TableList)malloc(sizeof(_tableList));
    SymList newNode = (SymList)malloc(sizeof(_SymList));
    newNode->name = "Global";
    newNode->label = -1;
    newNode->next = NULL;
    globalTable->tableNode = newNode;
    globalTable->next = NULL;

    currentTable = globalTable;

    Node aux = (Node)malloc(sizeof(Node_t));   //paramlist
    aux->child = (Node)malloc(sizeof(Node_t)); //ParamDeclaration
    aux->child->brother = NULL;
    Node typeSpec = (Node)malloc(sizeof(Node_t));
    typeSpec->label = Int;
    aux->child->child = typeSpec;
    typeSpec->brother = NULL;
    createFunctionEntry("putchar", Int, aux, 0);

    typeSpec->label = Void;
    createFunctionEntry("getchar", Int, aux, 0);

    free(typeSpec);
    free(aux->child);
    free(aux);

    fullExpand(node);
    break;
  }

  case FuncDefinition:
  {
    Node typeSpec = node->child;
    Node id = typeSpec->brother;
    Node paramList = id->brother;

    currentTable = findFunctionEntry(id->value);
    if (currentTable == NULL)
    {
      currentTable = createFunctionEntry(id->value, typeSpec->label, paramList, 1);
    }
    else
    {
      // Ja foi declarada, temos que verificar parametros
      ArgList aux = currentTable->argList;
      Node paramDec = paramList->child;
      while (paramDec != NULL)
      {
        Node typeSpec = paramDec->child;
        Node id = typeSpec->brother;

        if (aux == NULL)
        {
          break;
        }
        if (typeSpec->label == aux->label)
        {
          if (id != NULL)
            aux->name = id->value;
        }

        paramDec = paramDec->brother;
        aux = aux->next;
      }

      currentTable->isDefined = 1;
    }

    handleNode(paramList->brother); //FuncBody

    currentTable = globalTable;

    if (node->brother != NULL)
      handleNode(node->brother);

    break;
  }

  case FuncDeclaration:
  {
    Node typeSpec = node->child;
    Node id = typeSpec->brother;
    Node paramList = id->brother;

    // TODO: We'll need to do something about re-declaring (else)
    if (findFunctionEntry(id->value) == NULL)
      createFunctionEntry(id->value, typeSpec->label, paramList, 0);

    if (node->brother != NULL)
      handleNode(node->brother);

    break;
  }

  case Declaration:
  {
    Node typeSpec = node->child;
    Node id = typeSpec->brother;
    Node aux = id->brother;
    insertSymbol(currentTable, id->value, typeSpec->label);
    while(aux != NULL){
      putType(aux);
      aux = aux->brother;
    }
    fullExpand(node);
    break;
  }

  case RealLit:
  {
    node->type = Double;
    fullExpand(node);
    break;
  }

  case IntLit:
  {
    node->type = Int;
    fullExpand(node);
    break;
  }

  case ChrLit:
  {
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
  case Mod:
  {
    handleNode(node->child);
    putType(node->child);
    putType(node->child->brother);
    node->type = Int;

    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }
  case Comma:
  {
    handleNode(node->child);
    putType(node->child);
    putType(node->child->brother);
    if(node->child->type == undef){
      node->type = undef;
    }
    else{
      node->type = node->child->brother->type;
    }
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
  case BitWiseOr:
  {
    handleNode(node->child);
    putType(node->child);
    putType(node->child->brother);
    node->type = resolveType(node->child->type, node->child->brother->type);
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }
  case Store:
  {
    handleNode(node->child);
    putType(node->child);
    putType(node->child->brother);
    node->type = node->child->type;
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }
  case Not:
  {
    handleNode(node->child);
    putType(node->child);
    node->type = Int;
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }
  case Minus:
  case Plus:
  {
    handleNode(node->child);
    putType(node->child);
    node->type = node->child->type;
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }
  case While:
  case Return:
  case If:
  {
    handleNode(node->child);
    putType(node->child);
    Node aux = node->child->brother;
    while (aux != NULL)
    {
      putType(aux);
      aux = aux->brother;
    }
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }
  case Call:
  {
    handleNode(node->child);
    putType(node->child);
    Node aux = node->child->brother;
    while (aux != NULL)
    {
      putType(aux);
      aux = aux->brother;
    }
    node->type = node->child->type;
    if (node->brother != NULL)
      handleNode(node->brother);
    break;
  }
  case FuncBody:
  {
    Node children = node->child;
    while(children != NULL){
      if(children->label == Id)
        putType(children);
      children = children->brother;
    }
    fullExpand(node);
  }

  /* All operators, terminals and Null are defaulted for now */
  /* ParamList and ParamDeclaration are also defaulted, but they should never occur*/
  default:
    fullExpand(node);
    break;
  }
  return 1;
}

void fullExpand(Node node)
{
  if (node->child != NULL)
    handleNode(node->child);
  if (node->brother != NULL)
    handleNode(node->brother);
}

char *labelToStringForTable(Label label)
{
  char *s;
  switch (label)
  {
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
    //printf("\n\n\nTHIS SHOULD NEVER HAPPEN!\n\n\n");
    break;
  }
  return s;
}

TableList findFunctionEntry(char *name)
{
  if (name == NULL)
    return NULL;

  TableList aux = globalTable;
  while (aux != NULL)
  {
    if (strcmp(aux->tableNode->name, name) == 0)
    {
      return aux;
    }
    aux = aux->next;
  }
  return NULL;
}

TableList createFunctionEntry(char *name, Label label, Node paramList, int isDefinition)
{
  // Assumes it's not already on the table
  TableList aux = globalTable;
  while (aux->next != NULL)
    aux = aux->next;

  TableList newNode = (TableList)malloc(sizeof(_tableList));
  newNode->next = NULL;
  newNode->isDefined = isDefinition;

  SymList newList = (SymList)malloc(sizeof(_SymList));
  newList->label = label;
  newList->name = name;
  newNode->tableNode = newList;

  // A bit messy, but it adds all the arguments at once, if there are any
  // Might refactor later, but I think it works anyway
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

  while (paramDec != NULL)
  {
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

  aux->next = newNode;
  insertSymbol(globalTable, name, label);

  return newNode;
}

Label resolveType(Label label1, Label label2)
{
  if (label1 == undef || label2 == undef)
  {
    return undef;
  }
  if (label1 == Double || label2 == Double)
  {
    return Double;
  }
  if (label1 == Int || label2 == Int)
  {
    return Int;
  }
  if (label1 == Short || label2 == Short)
  {
    return Short;
  }
  if (label1 == Char || label2 == Char)
  {
    return Char;
  }
  return Char;
}

void putType(Node node)
{
  switch (node->label)
  {
  case Id:
  {
    ArgList argList = findParameter(currentTable, node->value);
    if (argList != NULL)
    {
      node->type = argList->label;
      return;
    }
    else
    {
      SymList symbolEntry = findSymbol(currentTable, node->value);
      if (symbolEntry != NULL)
      {
        node->type = symbolEntry->label;
      }
      else
      {
        symbolEntry = findSymbol(globalTable, node->value);
        if (symbolEntry != NULL)
        {
          node->type = symbolEntry->label;
          TableList aux = findFunctionEntry(node->value);
          if (aux != NULL)
          {
            node->argList = aux->argList;
          }
        }
      }
      if(symbolEntry == NULL){
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
    default:
    {
      if (node->type == Empty)
      {
        /*THIS IS A HACK, O HOMEM DOS KEBABS SABERA COMO FAZER ISTO DECENTEMENTE
      printf("Putting type for %s\n", labelToString(node->label));
      printf("---\nThis should never happen\n---\n");
      SE ELE NAO SOUBER VAMOS TENTAR FAZER ISTO EM HORAS MAIS NORMAIS*/
        node->type = Empty;
      }
      break;
    }
    }
}

char *labelToString(Label label)
{
  char *s;
  switch (label)
  {
  case Empty:
    s = "Empty";
    break;
  case undef:
    s = "undef";
    break;
  case Program:
    s = "Program";
    break;
  case Declaration:
    s = "Declaration";
    break;
  case FuncDeclaration:
    s = "FuncDeclaration";
    break;
  case FuncDefinition:
    s = "FuncDefinition";
    break;
  case ParamList:
    s = "ParamList";
    break;
  case FuncBody:
    s = "FuncBody";
    break;
  case ParamDeclaration:
    s = "ParamDeclaration";
    break;
  case StatList:
    s = "StatList";
    break;
  case If:
    s = "If";
    break;
  case While:
    s = "While";
    break;
  case Return:
    s = "Return";
    break;
  case Or:
    s = "Or";
    break;
  case And:
    s = "And";
    break;
  case Eq:
    s = "Eq";
    break;
  case Ne:
    s = "Ne";
    break;
  case Lt:
    s = "Lt";
    break;
  case Gt:
    s = "Gt";
    break;
  case Le:
    s = "Le";
    break;
  case Ge:
    s = "Ge";
    break;
  case Add:
    s = "Add";
    break;
  case Sub:
    s = "Sub";
    break;
  case Mul:
    s = "Mul";
    break;
  case Div:
    s = "Div";
    break;
  case Mod:
    s = "Mod";
    break;
  case Not:
    s = "Not";
    break;
  case Minus:
    s = "Minus";
    break;
  case Plus:
    s = "Plus";
    break;
  case Store:
    s = "Store";
    break;
  case Comma:
    s = "Comma";
    break;
  case Call:
    s = "Call";
    break;
  case BitWiseAnd:
    s = "BitWiseAnd";
    break;
  case BitWiseXor:
    s = "BitWiseXor";
    break;
  case BitWiseOr:
    s = "BitWiseOr";
    break;
  case Char:
    s = "Char";
    break;
  case ChrLit:
    s = "ChrLit";
    break;
  case Id:
    s = "Id";
    break;
  case Int:
    s = "Int";
    break;
  case Short:
    s = "Short";
    break;
  case IntLit:
    s = "IntLit";
    break;
  case Double:
    s = "Double";
    break;
  case RealLit:
    s = "RealLit";
    break;
  case Void:
    s = "Void";
    break;
  case Null:
    s = "Null";
    break;
  }
  return s;
}

ArgList getFunctionArgs(char *name)
{
  TableList aux = globalTable;
  while (aux != NULL)
  {
    if (strcmp(aux->tableNode->name, name) == 0)
    {
      return aux->argList;
    }
    aux = aux->next;
  }
  return NULL;
}

int insertSymbol(TableList table, char* name, Label label){
  //Nao protegido para table == null
  SymList symList = table->tableNode;
  ArgList argList = table->argList;

  while(argList != NULL){
    if(argList->name != NULL){
      if(strcmp(argList->name, name) == 0){
        //-1 means error
        return -1;
      }
    }
    argList = argList->next;
  }
  while(symList->next != NULL){
    symList = symList->next;
    if(strcmp(symList->name, name) == 0){
      //-1 means error
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
  SymList aux = tableList->tableNode->next;
  while(aux != NULL){
    //Isto nao esta protegido para segfault mas acho que nao e preciso
    if(strcmp(aux->name, name) == 0){
      return aux;
    }
    aux = aux->next;
  }
  return NULL;
}

ArgList findParameter(TableList tableList, char* name){
  ArgList aux = tableList->argList;
  while(aux != NULL){
    //Isto nao esta protegido para segfault mas acho que nao e preciso
    if(aux->name != NULL)
      if(strcmp(aux->name, name) == 0){
        return aux;
      }
    aux = aux->next;
  }
  return NULL;
}

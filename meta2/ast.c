#include "ast.h"

Node createNode(Label label, char *value){
	Node newNode = malloc(sizeof(Node_t));

	newNode->label = label;
	newNode->type = Empty;
	newNode->arg_list = NULL;

	newNode->value = value; //value is either NULL or comes from yylval.value which was strduped

	newNode->child = NULL;
	newNode->brother = NULL;

	return newNode;
}

void addChild(Node father, Node child){
	father->child = child;
}

Node addBrother(Node older, Node newer){
	if(older == NULL) {
		return newer;
	}
	if(newer == NULL) {
		return older;
	}
	Node aux = older;
	while(aux->brother != NULL)
		aux = aux->brother;

	aux->brother = newer;
	return older;
}

void printTree(Node current, int depth){
	int i;
	for(i=0; i<depth; i++)
		printf("..");
	printf("%s", labelToString(current->label));
	if(current->value!=NULL){
		printf("(%s)", current->value);
	}
	if(current->type != Empty){
		printf(" - %s",labelToString(current->type));
		if(current->arg_list != NULL){
			Arg_list aux_arg = current->arg_list;
			printf("(");
			while(aux_arg != NULL){
				printf("%s", labelToString(aux_arg->label));
				aux_arg= aux_arg->next;
				if(aux_arg != NULL)
					printf(",");
			}
			printf(")");
		}
	}
	printf("\n");

	if(current->child != NULL) printTree(current->child, depth+1);
	if(current->brother != NULL) printTree(current->brother, depth);
}


void freeTree(Node current){
	if(current->child != NULL) freeTree(current->child);
	if(current->brother != NULL) freeTree(current->brother);

	free(current->value);
	free(current);
}

char *labelToString(Label label){
  switch (label) {
  case Empty:
    return "Empty";
    break;
  case undef:
    return "undef";
    break;
  case Program:
    return "Program";
    break;
  case Declaration:
    return "Declaration";
    break;
  case FuncDeclaration:
    return "FuncDeclaration";
    break;
  case FuncDefinition:
    return "FuncDefinition";
    break;
  case ParamList:
    return "ParamList";
    break;
  case FuncBody:
    return "FuncBody";
    break;
  case ParamDeclaration:
    return "ParamDeclaration";
    break;
  case StatList:
    return "StatList";
    break;
  case If:
    return "If";
    break;
  case While:
    return "While";
    break;
  case Return:
    return "Return";
    break;
  case Or:
    return "Or";
    break;
  case And:
    return "And";
    break;
  case Eq:
    return "Eq";
    break;
  case Ne:
    return "Ne";
    break;
  case Lt:
    return "Lt";
    break;
  case Gt:
    return "Gt";
    break;
  case Le:
    return "Le";
    break;
  case Ge:
    return "Ge";
    break;
  case Add:
    return "Add";
    break;
  case Sub:
    return "Sub";
    break;
  case Mul:
    return "Mul";
    break;
  case Div:
    return "Div";
    break;
  case Mod:
    return "Mod";
    break;
  case Not:
    return "Not";
    break;
  case Minus:
    return "Minus";
    break;
  case Plus:
    return "Plus";
    break;
  case Store:
    return "Store";
    break;
  case Comma:
    return "Comma";
    break;
  case Call:
    return "Call";
    break;
  case BitWiseAnd:
    return "BitWiseAnd";
    break;
  case BitWiseXor:
    return "BitWiseXor";
    break;
  case BitWiseOr:
    return "BitWiseOr";
    break;
  case Char:
    return "Char";
    break;
  case ChrLit:
    return "ChrLit";
    break;
  case Id:
    return "Id";
    break;
  case Int:
    return "Int";
    break;
  case Short:
    return "Short";
    break;
  case IntLit:
    return "IntLit";
    break;
  case Double:
    return "Double";
    break;
  case RealLit:
    return "RealLit";
    break;
  case Void:
    return "Void";
    break;
  case Null:
    return "Null";
    break;
  }
}

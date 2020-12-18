#include "ast.h"
#include "symTable.h"


Node createNode(Label label, char *value){
	Node newNode = malloc(sizeof(Node_t));

	newNode->label = label;
	newNode->type = Empty;
	newNode->argList = NULL;

	newNode->value = value; //value is either NULL or comes from yylval.value which was strduped

	newNode->child = NULL;
	newNode->brother = NULL;

	return newNode;
}

void addChild(Node father, Node child){
	father->child = child;
}

Node addBrother(Node older, Node newer){
	if(older==NULL){
		return newer;
	}
	if(newer==NULL){
		return older;
	}
	Node aux = older;
	while(aux->brother!=NULL)
		aux = aux->brother;

	aux->brother = newer;
	return older;
}

void printTree(Node current, int depth){
	int i;
	for(i=0; i<depth; i++)
		printf("..");
	printf("%s", getLabelString(current->label));
	if(current->value!=NULL){
		printf("(%s)", current->value);
	}
	if(current->type != Empty){
		printf(" - %s",getStringForTables(current->type));
		if(current->argList != NULL){
			ArgList auxArg = current->argList;
			printf("(");
			while(auxArg != NULL){
				printf("%s", getStringForTables(auxArg->label));
				auxArg= auxArg->next;
				if(auxArg != NULL)
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

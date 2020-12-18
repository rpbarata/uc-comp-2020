#include "ast.h"
#include "symTable.h"


Node createNode(Label label, char *value) {
	Node newNode = malloc(sizeof(Node_t));

	newNode->label = label;
	newNode->type = Empty;
	newNode->argList = NULL;

	newNode->value = value;

	newNode->child = NULL;
	newNode->brother = NULL;

	return newNode;
}

void addChild(Node father, Node child) {
	father->child = child;
}

Node addBrother(Node older, Node newer) {
	if(older == NULL) {
		return newer;
	}
	else if(newer == NULL) {
		return older;
	}

	Node node = older;
	while(node->brother != NULL)
		node = node->brother;

	node->brother = newer;
	return older;
}

void printTree(Node current, int depth) {
	for(int i = 0; i < depth; i++)
		printf("..");

	printf("%s", labelToString(current->label));

	if(current->value!=NULL) {
		printf("(%s)", current->value);
	}

	if(current->type != Empty) {
		printf(" - %s", labelToStringForTable(current->type));
		if(current->argList != NULL) {
			ArgList arg = current->argList;
			printf("(");
			while(arg != NULL) {
				printf("%s", labelToStringForTable(arg->label));
				arg = arg->next;
				if(arg != NULL)
					printf(",");
			}
			printf(")");
		}
	}
	printf("\n");

	if(current->child != NULL)
		printTree(current->child, depth+1);
	if(current->brother != NULL)
		printTree(current->brother, depth);
}

void freeTree(Node current) {
	if(current->child != NULL)
		freeTree(current->child);
	if(current->brother != NULL)
		freeTree(current->brother);

	free(current->value);
	free(current);
}

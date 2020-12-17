#include "stack.h"
#include "tree.h"

Position pop(Stackpos head) {
	if (head->next == NULL)
		return NULL;

	Stackpos tempP = head->next;
	Position temp = tempP->sDir;

	head->next = tempP->next;

	free(tempP);
	tempP = NULL;

	return temp;
}

int getRandom(int lower, int upper)
{
	return  (rand() %
		(upper - lower + 1)) + lower;
}

int push(Position where, Position what) {
	what->next = where->next;
	where->next = what;
	return 0;
}

Position createNode(int k) {

	Position el = NULL;

	el = (Position)malloc(sizeof(Node));

	if (NULL == el) {
		printf("Memory allocation failed!\r\n");
		return NULL;
	}

	el->coef = k;
	el->next = NULL;

	return el;
}

int printList(Position head) {

	if (head->next != NULL) {
		printf("\r\n\rLIST CONTENT:\r\n");

		foreach(p, head->next) {
			printf(" %d ", p->coef);
			if (p->next != NULL)
				printf(",");
		}
	}

	else {
		printf("\r\n\rLIST IS EMPTY.\r\n");
	}

	puts("\n");

	return 0;
}
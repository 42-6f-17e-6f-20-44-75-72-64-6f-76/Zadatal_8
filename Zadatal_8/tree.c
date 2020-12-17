#include "tree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


Position newDir(char* dirname) {
	Position temp = NULL;
	temp = (Position*)malloc(sizeof(Dir));
	if (temp == NULL)
	{
		puts("Memory allocation fault.");
		return NULL;
	}
	temp->child = NULL;
	temp->next = NULL;
	strcpy(temp->dir, dirname);
	return temp;
}

void printDir(Position p,char* format) {

	if (p == NULL)
		return;

	printf("%s%s\n", format,p->dir);
	printDir(p->next,"\n");
	printDir(p->child,"\t");

}

int insertDir(Position q, Position what) {

	if (q->child == NULL)
	{
		what->next = q->child;
		q->child = what;
		return 0;
	}


	foreach(p, q->child)
		if (p->next != NULL && strcmp(p->next->dir, what->dir) > 0)
		{
			insertAfterBrother(p, what);
			return 1;
		}
		else if (p->next == NULL) {
			insertAfterBrother(p, what);
			return 1;
		}

	return 1;
}

 int insertAfterBrother(Position where, Position what) {
	what->next = where->next;
	where->next = what;
	return 0;
}

Position findDir(Position q, char* dirname) {
	for (Position p = q->child; p != NULL; p = p->next)
		if (strcmp(p->dir, dirname) == 0)
			return p;

	return NULL;
}

void delete(Position p) {
	if (p == NULL)
		return;

	delete(p->next);
	delete(p->child);

	free(p);
}
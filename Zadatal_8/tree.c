#include "tree.h"

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

void printDir(Position p) {

	if (p == NULL)
		return;

	printf("%s\n", p->dir);
	printDir(p->next);
	printDir(p->child);

}

int insertDir(Position q, Position what) {

	foreach(p, q)
		if (p->next != NULL && strcmp(p->next->dir, what->dir) > 0)
		{
			insertAfter(p, what);
			break;
		}
		else if (p->next == NULL) {
			insertAfter(p, what);
			break;
		}
}

int insertAfter(Position where, Position what) {
	what->next = where->next;
	where->next = what;
	return 0;
}

Position findDir(Position q, char* dirname) {
	for (Position p = q; p != NULL; p = p->next)
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
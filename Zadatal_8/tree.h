#pragma once

#define DIR_NAME_LEN 1024
#define foreach(p,head) \
	for (Position p = head; p != NULL; p = p->next) 

#include <stdio.h>
#include <stdlib.h>


struct _dir;
typedef struct _dir* Position;
typedef struct _dir {
	char dir[DIR_NAME_LEN];
	Position next;
	Position child;
}Dir;


Position newDir(char*);
Position findDir(Position, char*);

int insertDir(Position, Position);
int insertAfter(Position, Position);

void printDir(Position);
void delete(Position);
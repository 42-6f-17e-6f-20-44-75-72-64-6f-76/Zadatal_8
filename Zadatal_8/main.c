#include "main.h"
#include "tree.h"
#include "stack.h"







int main(void) {

	Position current = NULL;
	Position temp = NULL;
	current = newDir("C:\\");

	char inputBuff[COMMAND_LEN]={ '\0' };

		printf("Welcome to DOS simualtor!\nAllowed commands: \n\t\tmd [dir]\n\t\tcd [dir]\n\t\tcd ..\n\t\tdir \n\t\texit\n\n");


	do {
		


		printf("%s>", current->dir);
		scanf(" %s", inputBuff);

		if (strcmp(inputBuff, "md") == 0) {

			scanf(" %s", inputBuff);

			insertDir(current, newDir(inputBuff));
		}
		else if (strcmp(inputBuff, "cd") == 0) {
			scanf(" %s", inputBuff);

			temp = findDir(current, inputBuff);

			if (temp == NULL) {
				printf("The system cannot find the path specified.\n");

			}
			else
			{
				current = temp;
			}
			

		}
		else if (strcmp(inputBuff, "cd ..") == 0) {


		}
		else if (strcmp(inputBuff, "dir") == 0) {

			printDir(current);

		}
		else if (strcmp(inputBuff, "cls") == 0) {

			system("cls");

		}
		else if (strcmp(inputBuff, "exit") != 0) {

			printf("'%s' is not recognized as an internal or external command,\noperable program or batch file.\n",inputBuff);

		}

	} while (strcmp(inputBuff, "exit") != 0);



	system("pause");
	return EXIT_SUCCESS;
}
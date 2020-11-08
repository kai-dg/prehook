#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "help.h"
/**
 * main - Entry point
 */
int main(int argc, char *argv[])
{
	switch(argc)
	{
		case 1:
			help_all();
			break;
		case 3:
			if (strcmp(argv[1], "set") == 0)
				set(argv[2]);
			else
				list(argv[2]);
			break;
		case 2:
			if (strcmp(argv[1], "list") == 0)
				list(argv[1]);
			break;
		default:
			printf("%s is not a command.\n", argv[1]);
	}
	return 0;
}

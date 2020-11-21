#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"
#include "utils.h"
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
		case 2:
			if (strcmp(argv[1], "list") == 0)
				list(argv[1]);
			break;
		case 3:
			if (strcmp(argv[1], "set") == 0)
				set(argv[2]);
			else if (strcmp(argv[1], "unset") == 0)
				unset(argv[2]);
			else
				printf("%s: %s%s is not a command.%s\n",
					TITLE_C, RED_C, argv[1], NC_C);
			break;
		default:
			printf("%s: %s%s is not a command.%s\n",
				TITLE_C, RED_C, argv[1], NC_C);
	}
	return 0;
}

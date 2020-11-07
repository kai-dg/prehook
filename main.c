#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "help.h"
/**
 * main - Entry point
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		help_all();
		return 1;
	}

	if (strcmp(argv[1], "set") == 0)
	{
		set(argv[2]);
	}
	else if (strcmp(argv[1], "list") == 0)
	{
		if (argc == 3)
			list(argv[2]);
		list(argv[1]);
	}
	else
	{
		printf("%s is not a command.\n", argv[1]);
	}
}

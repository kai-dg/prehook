#include <stdio.h>
#include "utils.h"
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

	int path_check = path_validate(argv[1]);
	if (path_check == 0)
		printf("is path\n");
	else
		printf("is not path\n");
	return 0;
}

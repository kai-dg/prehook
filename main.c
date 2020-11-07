#include <stdio.h>
#include "utils.h"
/**
 * main - Entry point
 */
int main(int argc, char *argv[])
{
	if (path_validate(argv[1]) == 0)
		printf("is path");
	else
		printf("is not path");
	return 0;
}

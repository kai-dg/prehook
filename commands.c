#include <stdio.h>
#include <string.h>
#include "utils.h"

int set(const char* path)
{
	int path_check = path_validate(path);
	printf("%s\n", path);
	if (path_check == 0)
		printf("is path\n");
	else
		printf("is not path\n");
	return 0;
}

int list(const char* path)
{
	if (strcmp(path, "list") == 0)
		printf("listing\n");
	return 0;
}

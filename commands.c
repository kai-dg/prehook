#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
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
	char* statusenv = getenv("PREHOOK_STATUS");
	char* pwd = getenv("PWD");
	char* to_match = "/home/harukai/00_development/prehook:/home/harukai/00_development/otherstuff";
	char* pwd2 = "hello";
	char* result = strstr(to_match, pwd);
	char* result1 = strstr(to_match, pwd2);
	if (strcmp(path, "list") == 0)
	{
		if (result1 == NULL)
			printf("no match");
			printf("%d\n", result1);
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "utils.h"
#include "commands.h"

int set(const char *path)
{
	FILE *cnf;
	int path_check;
	char command[] = "source ~/.prehook/scripts/append_conn.sh ";
	char *prehook_path = getenv("PREHOOK_PATH");
	char *path_copy;
	int duplicate;

	if (strcmp(path, ".") == 0)
		path = getenv("PWD");

	path_check = path_validate(path);
	path_copy = strdup(path);
	duplicate = exact_path_match(path_copy, prehook_path);
	if (duplicate == 0)
	{
		printf("Prehook: This directory is already hooked.\n");
		exit(1);
	}

	if (path_check == 0)
	{
		strcat(command, path);
		system(command);
		strcat(path_copy, "/prehook_cnf");
		cnf = fopen(path_copy, "r");
		if (cnf != NULL)
			fclose(cnf);
		else
		{
			cnf = fopen(path_copy, "w");
			fclose(cnf);
		}
	}
	else
	{
		printf("Prehook: Please enter a valid path\n");
		exit(1);
	}
	exit(0);
}

int unset(const char *path)
{
	FILE *cnf;
	int path_check;
	char *prehook_path = getenv("PREHOOK_PATH");
	char command[] = "source ~/.prehook/scripts/remove_conn.sh ";
	char *path_copy;
	int duplicate;

	if (strcmp(path, ".") == 0)
		path = getenv("PWD");

	path_check = path_validate(path);
	path_copy = strdup(path);
	duplicate = exact_path_match(path_copy, prehook_path);
	if (duplicate == 1)
	{
		printf("Prehook: This directory is not hooked.\n");
		exit(1);
	}
	
	if (path_check == 0)
	{
		strcat(command, path);
		system(command);
		strcat(path_copy, "/prehook_cnf");
		cnf = fopen(path_copy, "r");
		if (cnf != NULL)
			remove(path_copy);
	}
	else
	{
		printf("Prehook: Please enter a valid path\n");
		exit(1);
	}
	return 0;
}

int list(const char *path)
{
	char *prehook_path = getenv("PREHOOK_PATH");
	if (strcmp(path, "list") == 0)
	{
		printf("%s", prehook_path);
	}
	return 0;
}

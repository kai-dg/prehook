#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "utils.h"
#include "commands.h"

/* set - Sets a path to prehook path and adds a cnf file
 */
int set(const char *path)
{
	FILE *cnf;
	int path_check;
	char command[] = "sh ~/.prehook/scripts/append_conn.sh ";
	char *prehook_path = getenv("PREHOOK_PATH");
	char *path_copy;
	char *duplicate;

	if (strcmp(path, ".") == 0)
		path = getenv("PWD");

	path_check = path_validate(path);
	path_copy = strdup(path);
	duplicate = exact_path_match(path_copy, prehook_path);
	if (duplicate != NULL)
	{
		printf("%s: %sThis directory is already hooked%s\n",
			TITLE_C, YEL_C, NC_C);
		exit(1);
	}

	if (path_check == 0)
	{
		strcat(path_copy, "/prehook_cnf");
		cnf = fopen(path_copy, "r");
		if (cnf != NULL)
			fclose(cnf);
		else
		{
			cnf = fopen(path_copy, "w");
			printf("%s: %sCreated prehook_cnf file%s\n",
				TITLE_C, GRE_C, NC_C);
			fclose(cnf);
		}
		strcat(command, path);
		system(command);
	}
	else
	{
		printf("%s: %sPlease enter a valid path%s\n",
			TITLE_C, YEL_C, NC_C);
		exit(1);
	}
	exit(0);
}

/* unset - Unsets a prehook path and removes cnf file
 */
int unset(const char *path)
{
	FILE *cnf;
	int path_check;
	char *prehook_path = getenv("PREHOOK_PATH");
	char command[] = "sh ~/.prehook/scripts/remove_conn.sh ";
	char *path_copy;
	char *duplicate;

	if (strcmp(path, ".") == 0)
		path = getenv("PWD");

	path_check = path_validate(path);
	path_copy = strdup(path);
	duplicate = exact_path_match(path_copy, prehook_path);
	if (duplicate == NULL)
	{
		printf("%s: %sThis directory is not hooked%s\n",
			TITLE_C, YEL_C, NC_C);
		exit(1);
	}
	
	if (path_check == 0 && duplicate != NULL)
	{
		strcat(path_copy, "/prehook_cnf");
		cnf = fopen(path_copy, "r");
		if (cnf != NULL)
		{
			remove(path_copy);
			printf("%s: %sRemoving prehook_cnf...%s\n", TITLE_C, RED_C, NC_C);
		}
		strcat(command, path);
		system(command);
	}
	else
	{
		printf("%s: %sPlease enter a valid path%s\n",
			TITLE_C, YEL_C, NC_C);
		exit(1);
	}
	exit(0);
}

/* list - Lists all prehook set paths
 * TODO print paths nicely
 */
int list(const char *arg)
{
	char *prehook_path = getenv("PREHOOK_PATH");
	char *token, *pathenv, *tofree;
	if (*prehook_path == '\0')
	{
		printf("%s: %sNo directories have been set.%s\n", TITLE_C, YEL_C, NC_C);
		return 0;
	}
	printf("%s: Directories with prehook:\n", TITLE_C);
	tofree = pathenv = strdup(prehook_path);
	while ((token = strsep(&pathenv, ":")))
	{
		if (*token != '\0')
			printf("  > %s%s%s\n", GRE_C, token, NC_C);
	}
	free(tofree);
	return 0;
}

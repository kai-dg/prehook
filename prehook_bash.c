#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"

/* Btw, all printf will be eval'd to bash commands. */
char *parse_tag(const char *tag)
{
	if (strcmp("venv", tag) == 0)
		printf("echo 'this is venv';");
	else if (strcmp("env", tag) == 0)
		printf("echo 'this is env';");
	else if (strcmp("gitadd", tag) == 0)
		printf("echo 'this is gitadd';");
	else
		printf("%s is not a tag\n", tag);
	return NULL;
}

/* parse_cnf - Checks for prehook_cnf in pwd and parses it
 * path: pwd
 * Return: 0 if success, exit 1 if failed to find prehook_cnf
 */
int parse_cnf(const char *path)
{
	FILE *cnf;
	ssize_t read;
	size_t len = 0;
	char *line = NULL;
	char *inp;
	int is_tag = 0;
	cnf = fopen("prehook_cnf", "r");
	if (cnf == NULL)
	{
		printf("Could not find %s/prehook_cnf", path);
		exit(1);
	}
	chdir(path);
	while ((read = getline(&line, &len, cnf)) != -1)
	{
		/* TODO switch case for tags */
		while ((inp = strsep(&line, ":")) != NULL)
		{
			if (is_tag == 0)
			{
				parse_tag(inp);
				is_tag = 1;
				
			}
			else
			{
				printf("%s;", inp);
				is_tag = 0;
			}
		}
	}
	fclose(cnf);
	if (line)
		free(line);
	return 0;
}

/* main - Entry point for prehook analyzer + cnf parser
*/
int main(void)
{
	char *statusenv = getenv("PREHOOK_STATUS");
	char *prehook_path = getenv("PREHOOK_PATH");
	char *pwd = getenv("PWD");
	int in_dir = exact_path_match(pwd, prehook_path);
	if (in_dir == 0)
	{
		/* In directory */
		if (statusenv == NULL || strcmp("1", statusenv) == 0)
		{
			parse_cnf(pwd);
			printf("source $HOME/00_development/prehook/scripts/status.sh;");
			printf("echo 'Prehook: loading venv...';");
			/*
			printf(".~/.prehook/scripts/venv_activate.sh");
			*/
		}
	}
	else
	{
		/* Not in directory */
		if (strcmp("0", statusenv) == 0)
		{
			/*
			printf(".~/.prehook/scripts/venv_deactivate.sh");
			*/
			printf("echo 'Prehook: exiting venv...';");
			printf("source $HOME/00_development/prehook/scripts/status.sh;");
		}
	}
	return 0;
}

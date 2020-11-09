#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"
#include "tags.h"

/* Btw, all printf will be eval'd to bash commands. */
/* parse_tag - Directs the tag to correct function
 * tag: read from prehook_cnf
 * command: read from prehook_cnf
 */
char *parse_tag(const char *tag, const char *command)
{
	if (strcmp("venv", tag) == 0)
	{
		tag_venv(command);
	}
	else if (strcmp("env", tag) == 0)
	{
		tag_env(command);
	}
	else if (strcmp("gitadd", tag) == 0)
	{
		tag_gitadd(command);
	}
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
	char *inp = NULL;
	char *tag;
	int is_tag = 0;

	chdir(path);
	cnf = fopen("prehook_cnf", "r");
	if (cnf == NULL)
	{
		printf("Could not find %s/prehook_cnf", path);
		exit(1);
	}
	while ((read = getline(&line, &len, cnf)) != -1)
	{
		while ((inp = strsep(&line, ":")) != NULL)
		{
			if (is_tag == 0)
			{
				tag = inp;
				is_tag = 1;
			}
			else
			{
				parse_tag(tag, inp);
				printf("tag: %s, command: %s\n", tag, inp);
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
 * This gets eval'd from scripts/prehook_bash's function
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
			exit(0);
			printf("source ~/.prehook/scripts/status.sh;");
		}
	}
	else
	{
		/* Not in directory */
		if (strcmp("0", statusenv) == 0)
		{
			printf("source ~/.prehook/scripts/status.sh;");
			exit(0);
		}
	}
	return 0;
}

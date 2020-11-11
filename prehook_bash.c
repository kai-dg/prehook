#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"
#include "tags.h"

/* Btw, all printf will be eval'd to bash commands. */
/* check_envs - All tag functions need to reverse/unset their env vars
 * Running a C program runs in another process, not in current shell process
 * This function reverses/unsets envs as it is eval'd from bash script
 */
int check_envs(void)
{
	/* tag.c - tag_venv */
	const char *venv = getenv("PREHOOK_VENV");
	const char *venv_path = getenv("PREHOOK_VENV_PATH");
	const char *pwd = getenv("PWD");
	if (strcmp(venv, "0") == 0)
	{
		/* case of entering another folder within venv dir */
		if (strcmp(venv_path, pwd) != 0)
		{
			printf("deactivate;");
			printf("unset PREHOOK_VENV;");
			printf("echo 'Prehook: Exiting venv...';");
		}
	}
	return 0;
}
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
		printf("echo 'Prehook: %s is not a tag';", tag);
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
		printf("echo 'Prehook: Could not find %s/prehook_cnf';", path);
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
	setenv("PREHOOK_VENV_PATH", strdup(pwd), 1);
	if (in_dir == 0)
	{
		/* In directory */
		if (statusenv == NULL)
		{
			printf("export PREHOOK_STATUS=0;");
			parse_cnf(pwd);
			exit(0);
		}
	}
	else
	{
		/* Not in directory */
		if (strcmp("0", statusenv) == 0)
		{
			printf("source ~/.prehook/scripts/refresh_path.sh;");
			printf("unset PREHOOK_STATUS;");
			check_envs();
			exit(0);
		}
	}
	return 0;
}

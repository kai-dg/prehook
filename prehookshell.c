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
	const char *script = getenv("PREHOOK_SCRIPT");
	if (venv != NULL)
	{
		printf("deactivate;");
		printf("unset PREHOOK_VENV;");
		printf("echo -e '%s: %sExiting venv...%s';", TITLE, RED, NC);
	}
	if (script != NULL)
		printf("unset PREHOOK_SCRIPT;");
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
	else if (strcmp("script", tag) == 0)
	{
		tag_script(command);
	}
	else
		printf("echo -e '%s: %s%s is not a tag%s';",
			TITLE, RED, tag, NC);
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
		printf("echo -e '%s: %sCould not find %s/prehook_cnf%s';",
			TITLE, RED, path, NC);
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
	char *in_dir = exact_path_match(pwd, prehook_path);
	if (in_dir != NULL)
	{
		/* In directory */
		if (statusenv == NULL)
		{
			printf("export PREHOOK_STATUS=0;");
			printf("export PREHOOK_ROOT_DIR=%s;", pwd);
			parse_cnf(pwd);
		}
	}
	else
	{
		/* Not in directory */
		char *rootdir = getenv("PREHOOK_ROOT_DIR");
		char *is_sub;
		if (statusenv != NULL)
			is_sub = strstr(pwd, rootdir);
		/* Not in directory AND not a subdirectory */
		if (statusenv != NULL && is_sub == NULL)
		{
			unsetenv("PREHOOK_STATUS");
			printf("~/.prehook/scripts/refresh_path.sh;");
			printf("unset PREHOOK_STATUS;");
			printf("unset PREHOOK_ROOT_DIR;");
			check_envs();
		}
	}
	return 0;
}

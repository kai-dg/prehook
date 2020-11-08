/* Btw, all printf will be eval'd to bash commands. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
	cnf = fopen("prehook_cnf", "r");
	if (cnf == NULL)
	{
		printf("Could not find %s/prehook_cnf", path);
		exit(1);
	}
	while ((read = getline(&line, &len, cnf)) != -1)
	{
		/* TODO switch case for tags */
		printf("%s", line);
	}
	fclose(cnf);
	if (line)
		free(line);
	return 0;
}

/* exact_path_match - Delimits paths and matches pwd with paths
 * pwd: substring
 * prehook_path: string
 * Return: substring if found, NULL if not found
 */
char *exact_path_match(char *pwd, char *prehook_path)
{
	char *pp_copy = strdup(prehook_path);
	char *path;
	int cmpresult;
	size_t pwdlen, pathlen;
	pwdlen = strlen(pwd);
	while ((path = strsep(&pp_copy, ":")) != NULL)
	{
		pathlen = strlen(path);
		cmpresult = strncmp(path, pwd, pwdlen);
		if (cmpresult == 0 && pathlen == pwdlen)
			return path;
	}
	return NULL;
}

/* main - Entry point for prehook analyzer + cnf parser
*/
int main(void)
{
	char* statusenv = getenv("PREHOOK_STATUS");
	char* prehook_path = getenv("PREHOOK_PATH");
	char* pwd = getenv("PWD");
	char* in_dir = exact_path_match(pwd, prehook_path);
	if (in_dir != NULL)
	{
		/* In directory */
		if (statusenv == NULL || strcmp("1", statusenv) == 0)
		{
			parse_cnf(pwd);
			/*
			printf(".~/.prehook/scripts/status.sh");
			printf(".~/.prehook/scripts/venv_activate.sh");
			printf("echo 'Prehook: loading venv...'");
			*/
		}
	}
	else
	{
		/* Not in directory */
		if (strcmp("0", statusenv) == 0)
		{
			printf(".~/.prehook/scripts/venv_deactivate.sh");
			printf("echo 'Prehook: exiting venv...'");
			printf(".~/.prehook/scripts/status.sh");
		}
	}
	return 0;
}

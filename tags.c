#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "tags.h"
/* tag_venv - PYTHON: turns virtualenv off or on
 * status: 0 = turn on, null = turn off
 */
int tag_venv(const char *command)
{
	const char *statusvenv = getenv("PREHOOK_VENV");
	if (statusvenv == NULL)
	{
		printf("%s;", command);
		printf("export PREHOOK_VENV=0;");
		printf("echo -e '%s: %sLoading venv...%s';", TITLE, GRE, NC);
	}
	return 0;
}

/* tag_env - Applies env variables from an env script
 * Does it matter if envs are applied twice? I dunno man
 */
int tag_env(const char *command)
{
	const char *envstatus = getenv("PREHOOK_ENV");
	if (envstatus == NULL)
	{
		printf("export PREHOOK_ENV=0;");
		printf("echo -e '%s: %sSetting env variables...%s';", TITLE, GRE, NC);
		printf("%s;", command);
	}
	return 0;
}

/* tag_gitadd - Applies any tests before adding to git commit
 * TODO do a `history 1` parse if this tag is found in cnf
 * It should check for the `command` == `history 1`
 * Figure out a way to handle alias later
 */
int tag_gitadd(const char *command)
{
	const char *gaddenvcnf = getenv("PREHOOK_GADD_CNF");
	const char *gaddenv = getenv("PREHOOK_GADD");
	if (gaddenvcnf == NULL)
	{
		printf("export PREHOOK_GADD_CNF=0;");
		printf("echo -e '%s: %sGit add is being monitored...%s';",
			TITLE, GRE, NC);
	}
	if (gaddenv != NULL)
		printf("source ~/.prehook/scripts/gadd.sh '%s';", command);
	return 0;
}

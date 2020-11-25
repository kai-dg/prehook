#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <libgen.h>
#include <string.h>
#include <stdio.h> /* remove after print error use */
#include "utils.h"

int path_validate(const char* path)
{
	DIR* dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		return 0;
	}
	return 1;
}
/* exact_path_match - Delimits paths and matches pwd with paths
 * pwd: substring
 * prehook_path: string
 * Return: needle if match, NULL if no match
 */
char *exact_path_match(char *needle, char *haystack)
{
	char *pp_copy = strdup(haystack);
	char *path;
	int cmpresult;
	size_t pwdlen, pathlen;
	pwdlen = strlen(needle);
	while ((path = strsep(&pp_copy, ":")) != NULL)
	{
		pathlen = strlen(path);
		cmpresult = strncmp(path, needle, pwdlen);
		if (cmpresult == 0 && pathlen == pwdlen)
			return needle;
	}
	free(pp_copy);
	return NULL;
}
int is_directory(const char *path)
{
	struct stat statbuf;
	if (stat(path, &statbuf) != 0)
		return 0;
	return S_ISDIR(statbuf.st_mode);
}

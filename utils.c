#include <stdlib.h>
#include <dirent.h>
#include <string.h>
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
 * Return: 0 if match, 1 if no match
 */
int exact_path_match(char *needle, char *haystack)
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
			return 0;
	}
	free(pp_copy);
	return 1;
}


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
	printf("echo 'path: %s';", path);
	if (stat(path, &statbuf) != 0)
		return 0;
	return S_ISDIR(statbuf.st_mode);
}
/* find_subdirectory - Finds if given path is a subdirectory of given dir
 * Primarily for prehook_bash, as args will be env vars
 * directory: Directory to search in
 * path: subdirectory in question
 * Return: 0 if match, 1 if no match
 */
int find_subdirectory(const char *root, const char *path)
{
	struct dirent* dent;
	char *pathcopy = strdup(path);
	char *basefolder = basename(pathcopy);
	DIR* srcdir = opendir(root);
	if (srcdir == NULL)
	{
		perror("opendir");
		return -1;
	}
	while((dent = readdir(srcdir)) != NULL)
	{
		struct stat st;
		if(strcmp(dent->d_name, ".") == 0 || strcmp(dent->d_name, "..") == 0)
			continue;
		if (fstatat(dirfd(srcdir), dent->d_name, &st, 0) < 0)
		{
			perror(dent->d_name);
			continue;
		}
		if (S_ISDIR(st.st_mode))
		{
			if (strcmp(basefolder, dent->d_name) == 0)
				return 0;
		}
	}
	closedir(srcdir);
	return 1;
}

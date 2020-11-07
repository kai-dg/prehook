#include <dirent.h>
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

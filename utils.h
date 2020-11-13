#ifndef UTILS_H
#define UTILS_H

int path_validate(const char* path);
char *exact_path_match(char *needle, char *haystack);
int find_subdirectory(const char *directory, const char *path);

#endif /* UTILS_H */

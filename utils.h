#ifndef UTILS_H
#define UTILS_H

int path_validate(const char* path);
char *exact_path_match(char *needle, char *haystack);
int find_subdirectory(const char *directory, const char *path);

/* Bash Text Colors */
#define RED ((const unsigned char *)"\\033[1;31m")
#define GRE ((const unsigned char *)"\\033[1;32m")
#define YEL ((const unsigned char *)"\\033[1;33m")
#define NC ((const unsigned char *)"\\033[0m")
#define TITLE ((const unsigned char *)"\\033[1;36m > Prehook\\033[0m")

/* C Text Colors */
#define RED_C ((const unsigned char *)"\x1b[31m")
#define GRE_C ((const unsigned char *)"\x1b[32m")
#define YEL_C ((const unsigned char *)"\x1b[33m")
#define NC_C ((const unsigned char *)"\x1b[0m")
#define TITLE_C ((const unsigned char *)"\x1b[36m > Prehook\x1b[0m")

#endif /* UTILS_H */

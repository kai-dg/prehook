#include <stdio.h>
#include "help.h"

void help_usage()
{
	printf("Usage: prehook <command> FOLDER_PATH*\n");
	printf("Try 'prehook -h <command>' for more information.\n");
	return;
}

void help_set()
{
	printf("set FOLDER_PATH\n");
	return;
}

void help_list()
{
	printf("list FOLDER_PATH*\n");
	return;
}

void help_all()
{
	help_usage();
	printf("\nAll commands:\n");
	printf("\tset FOLDER_PATH\t\tSets a prehook in the folder. Modify prehook_cnf to add commands.\n");
	printf("\tlist FOLDER_PATH*\tFOLDER_PATH is optional. Lists all set prehooks.\n");
	return;
}

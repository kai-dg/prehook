CC=gcc

setup:
	$(CC) -Wall -Werror -pedantic -o prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o prehook_bash prehook_bash.c utils.c
	# ./scripts/setup.sh

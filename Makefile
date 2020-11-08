CC=gcc

setup:
	$(CC) -o prehook prehook.c utils.c commands.c help.c
	$(CC) -o prehook_bash prehook_bash.c
	# ./scripts/setup.sh

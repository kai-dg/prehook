CC=gcc

setup:
	mkdir -p ~/.prehook/bin

install:
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/prehook_bash prehook_bash.c tags.c utils.c
	# ./scripts/setup.sh

test:
	$(CC) -Wall -Werror -pedantic -o prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o prehook_bash prehook_bash.c tags.c utils.c

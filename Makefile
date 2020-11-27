CC=gcc

install:
	mkdir -p ~/.prehook/bin
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/bin/prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/prehookshell prehookshell.c tags.c utils.c
	./scripts/setup.sh

uninstall:
	rm ~/.prehook/prehookshell
	rm ~/.prehook/bin/prehook
	./scripts/uninstall.sh

update:
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/bin/prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/prehookshell prehookshell.c tags.c utils.c

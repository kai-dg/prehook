CC=gcc

install:
	mkdir -p ~/.prehook/bin
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/bin/prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/prehook_bash prehook_bash.c tags.c utils.c
	./scripts/setup.sh

uninstall:
	. ~/.prehook/scripts/uninstall.sh
	rm -rf ~/.prehook
	. ~/.bashrc
	exec $$SHELL

test:
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/bin/prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/prehook_bash prehook_bash.c tags.c utils.c

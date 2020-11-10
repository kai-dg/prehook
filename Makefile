CC=gcc

install:
	mkdir -p ~/.prehook/bin
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/bin/prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o ~/.prehook/prehook_bash prehook_bash.c tags.c utils.c
	./scripts/setup.sh

uninstall:
	rm ~/.prehook/bin/prehook
	rm ~/.prehook/prehook_bash
	rm ~/.prehook/connections/prehook_path
	rm ~/.prehook/scripts/append_conn.sh
	rm ~/.prehook/scripts/remove_conn.sh
	rm ~/.prehook/scripts/prehook_bash
	rm ~/.prehook/scripts/setup.sh
	rm ~/.prehook/scripts/status.sh
	rm ~/.prehook/scripts/venv_status.sh
	rmdir ~/.prehook/bin
	rmdir ~/.prehook/connections
	source ~/.prehook/scripts/uninstall.sh
	rm ~/.prehook/scripts/uninstall.sh
	rmdir ~/.prehook/scripts
	rmdir ~/.prehook
	source ~/.bashrc

test:
	$(CC) -Wall -Werror -pedantic -o prehook prehook.c utils.c commands.c help.c
	$(CC) -Wall -Werror -pedantic -o prehook_bash prehook_bash.c tags.c utils.c

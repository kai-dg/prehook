CC=gcc

setup:
	$(CC) -o prehook main.c utils.c help.c
	./scripts/setup.sh

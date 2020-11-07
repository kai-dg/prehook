CC=gcc

setup:
	$(CC) -o prehook main.c utils.c
	./scripts/setup.sh

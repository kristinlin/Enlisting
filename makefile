all: skillz.c
	gcc -o "skillz" skillz.c
run: all
	./skillz

all: pipes.c
	gcc pipes.c
run: all
	./a.out

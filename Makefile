main: main.c node.c node.h queue.h queue.c
	zig cc main.c node.c queue.c -o main

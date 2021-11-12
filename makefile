all: myexec
	
myexec: main.o
	gcc main.o -o myexec

main.o: main.c
	gcc -c main.c

run:
	./myexec

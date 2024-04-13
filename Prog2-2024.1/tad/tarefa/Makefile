# Makefile

all: output

output: implement.o main.o
	gcc -o output implement.o main.o -lm

main.o: main.c
	gcc -c main.c

implement.o: implement.c
	gcc -c implement.c

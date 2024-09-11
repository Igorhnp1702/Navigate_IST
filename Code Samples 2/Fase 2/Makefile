############################################# 
# Ficheiro makefile do grupo 137
#
# Autores:
#
# Igor Paruque ist1102901
# Gonçalo Pires ist199947
#############################################

CFLAGS = -Wall -std=c99 -g

tileblaster: main.o solver.o mancha.o matriz.o
	gcc $(CFLAGS) -o tileblaster main.o solver.o mancha.o matriz.o

main.o: main.c 
	gcc $(CFLAGS) -c main.c

solver.o: solver.c solver.h
	gcc $(CFLAGS) -c solver.c
		
mancha.o: mancha.c mancha.h 
	gcc $(CFLAGS) -c mancha.c

matriz.o: matriz.c matriz.h
	gcc $(CFLAGS) -c matriz.c



	
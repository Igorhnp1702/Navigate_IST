############################################# 
# Ficheiro makefile do grupo 137
#
# Autores:
#
# Igor Paruque ist1102901
# Gonçalo Pires ist199947
#############################################

CFLAGS = -Wall -std=c99 -O3

tileblaster: main.o generic.o specific.o 
	gcc $(CFLAGS) -o tileblaster main.o generic.o specific.o 
	
main.o: main.c 
	gcc $(CFLAGS) -c main.c	
		
generic.o: generic.c generic.h 
	gcc $(CFLAGS) -c generic.c

specific.o: specific.c specific.h
	gcc $(CFLAGS) -c specific.c
	
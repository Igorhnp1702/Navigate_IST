############################################# 
# Ficheiro makefile do grupo 
#
# Autores:
#
# Igor Paruque ist1102901
# Mónica Ferreira ist1106520
#############################################

CFLAGS = -Wall -std=c99 -g

navigate: nav_main.o nav_InOut.o nav_matrix.o
	gcc $(CFLAGS) -o navigate nav_main.o nav_InOut.o nav_matrix.o
	
nav_main.o: nav_main.c nav_header.h
	gcc $(CFLAGS) -c nav_main.c	
		
nav_InOut.o: nav_InOut.c nav_InOut.h 
	gcc $(CFLAGS) -c nav_InOut.c

nav_matrix.o: nav_matrix.c nav_matrix.h
	gcc $(CFLAGS) -c nav_matrix.c

nav_paths.o: nav_paths.c structs.h
	gcc $(CFLAGS) -c nav_paths.c structs.h
	
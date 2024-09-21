############################################# 
# Ficheiro makefile do grupo 
#
# Autores:
#
# Igor Paruque ist1102901
# Mónica Ferreira ist1106520
#############################################

CFLAGS = -Wall -std=c99 -g

navigate: main.o IOmodule.o prob_utils.o
	gcc $(CFLAGS) -o navigate main.o IOmodule.o prob_utils.o
	
nav_main.o: main.c structs.h IOmodule.h prob_utils.h 
	gcc $(CFLAGS) -c main.c	
		
IOmodule.o: IOmodule.h structs.h IOmodule.c
	gcc $(CFLAGS) -c IOmodule.c

prob_utils.o: structs.h prob_utils.h prob_utils.c
	gcc $(CFLAGS) -c prob_utils.c

clean:
	make
	rm *.o

valdiff:
	valgrind --leak-check=full ./navigate TestInputs/Simples01/*.1maps
	mv *.sol1maps -t TestOutputs/Nossos/Simples01/
	diff -q TestOutputs/Nossos/Simples01/*.sol1maps TestOutputs/Corretos/Simples01/*.query
	valgrind --leak-check=full ./navigate TestInputs/Simples02/*.1maps
	mv *.sol1maps -t TestOutputs/Nossos/Simples02/
	diff -q TestOutputs/Nossos/Simples02/*.sol1maps TestOutputs/Corretos/Simples02/*.query

val:
	valgrind --leak-check=full ./navigate TestInputs/Simples01/*.1maps
	mv *.sol1maps -t TestOutputs/Nossos/Simples01/
	valgrind --leak-check=full ./navigate TestInputs/Simples02/*.1maps
	mv *.sol1maps -t TestOutputs/Nossos/Simples02/

diff:
	diff -q TestOutputs/Nossos/Simples01/*.sol1maps TestOutputs/Corretos/Simples01/*.query
	diff -q TestOutputs/Nossos/Simples02/*.sol1maps TestOutputs/Corretos/Simples02/*.query

run:
	./navigate TestInputs/Simples01/*.1maps
	mv *.sol1maps -t TestOutputs/Nossos/Simples01/
	./navigate TestInputs/Simples02/*.1maps
	mv *.sol1maps -t TestOutputs/Nossos/Simples02/

rundiff:
	./navigate TestInputs/Simples01/*.1maps
	mv *.sol1maps -t TestOutputs/Nossos/Simples01/
	./navigate TestInputs/Simples02/*.1maps
	mv *.sol1maps -t TestOutputs/Nossos/Simples02/
	diff -q TestOutputs/Nossos/Simples01/*.sol1maps TestOutputs/Corretos/Simples01/*.query
	diff -q TestOutputs/Nossos/Simples02/*.sol1maps TestOutputs/Corretos/Simples02/*.query




 
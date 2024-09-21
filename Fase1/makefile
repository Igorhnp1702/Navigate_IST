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

# INPUTS = t0001.1maps t0002.1maps t0003.1maps t0004.1maps t0005.1maps t0006.1maps t0007.1maps t0008.1maps t0009.1maps
# OUTPUTS = t0001.sol1maps t0002.sol1maps t0003.sol1maps t0004.sol1maps t0005.sol1maps t0006.sol1maps t0007.sol1maps t0008.sol1maps t0009.sol1maps
# SOLS = t0001.query t0002.query t0003.query t0004.query t0005.query t0006.query t0007.query t0008.query t0009.query

PREFIX =t0001 t0002 t0003 t0004  t0005  t0006 t0007 t0008 t0009

valdiff:
	for file in $(PREFIX); do \
		valgrind --leak-check=full ./navigate TestInputs/Simples01/$(PREFIX).1maps
		mv *.sol1maps -t TestOutputs/Nossos/Simples01/
		diff -q TestOutputs/Nossos/Simples01/*.sol1maps TestOutputs/Corretos/Simples01/*.query
		valgrind --leak-check=full ./navigate TestInputs/Simples02/*.1maps
		mv *.sol1maps -t TestOutputs/Nossos/Simples02/
		diff -q TestOutputs/Nossos/Simples02/*.sol1maps TestOutputs/Corretos/Simples02/*.query; \
	done

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




 
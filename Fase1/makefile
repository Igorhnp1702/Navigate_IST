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
	
main.o: main.c structs.h IOmodule.h prob_utils.h 
	gcc $(CFLAGS) -c main.c	
		
IOmodule.o: IOmodule.h structs.h IOmodule.c
	gcc $(CFLAGS) -c IOmodule.c

prob_utils.o: structs.h prob_utils.h prob_utils.c
	gcc $(CFLAGS) -c prob_utils.c

clean:
	make
	rm *.o

# INPUTS = 
# OUTPUTS = t0001.sol1maps t0002.sol1maps t0003.sol1maps t0004.sol1maps t0005.sol1maps t0006.sol1maps t0007.sol1maps t0008.sol1maps t0009.sol1maps
# SOLS = t0001.query t0002.query t0003.query t0004.query t0005.query t0006.query t0007.query t0008.query t0009.query



.PHONY: valdiff
INFILE = $(wildcard ./*.1maps)
OUTFILE = $(wildcard ./*.sol1maps)
SOLFILE = 

INFILE2 = $(wildcard ./TestInputs/Simples02/*.1maps)

print:
	
	 rm ./TestInputs/Simples01/*.sol1maps
	 rm ./TestInputs/Simples02/*.sol1maps


valdiff:  
	mv ./TestInputs/Simples01/*.1maps -t ./
	mv ./TestOutputs/Simples01/*.query -t ./
	$(foreach f, $(INFILE1),  $(shell  valgrind --leak-check=full ./navigate $(f))) 
	diff -q 
		
		
	

	for INF2 in $(INFILE2); do \	
		valgrind --leak-check=full ./navigate $$INF2 ; \
		mv  $(wildcard *.sol1maps) -t TestOutputs/Nossos/Simples01/; \
		diff -q TestOutputs/Nossos/Simples01/$(wildcard *.sol1maps) TestOutputs/Corretos/Simples01/$(wildcard *.sol1maps) ; \
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




 
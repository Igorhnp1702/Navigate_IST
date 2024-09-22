############################################# 
# Ficheiro makefile do grupo 51
#
# Autores:
#
# Igor Paruque ist1102901
# Mónica Ferreira ist1106520
#############################################

CFLAGS = -Wall -std=c99 -g #flags to use

navigate: main.o IOmodule.o prob_utils.o #program compilation
	gcc $(CFLAGS) -o navigate main.o IOmodule.o prob_utils.o
	
main.o: main.c structs.h IOmodule.h prob_utils.h 
	gcc $(CFLAGS) -c main.c	
		
IOmodule.o: IOmodule.h structs.h IOmodule.c
	gcc $(CFLAGS) -c IOmodule.c

prob_utils.o: structs.h prob_utils.h prob_utils.c
	gcc $(CFLAGS) -c prob_utils.c

clean: # clean object files
	make
	rm *.o

valtest: # test a specific file for memory leaks
	valgrind --leak-check=full ./navigate ./TestInputs/$(ARG).1maps
	code ./TestInputs/$(ARG).sol1maps ./TestOutputs/Corretos/$(ARG).query		

difftest: # test a specific file for differences in the solution
	./navigate ./TestInputs/$(ARG).1maps
	diff ./TestInputs/$(ARG).sol1maps ./TestOutputs/Corretos/$(ARG).query
	code ./TestInputs/$(ARG).sol1maps ./TestOutputs/Corretos/$(ARG).query

valall: val move # test all files for memory leaks 

diffall: run diffs move # test all files for differences in the solution

val:
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0001.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0002.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0003.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0004.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0005.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0006.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0007.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0008.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t0009.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1001.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1002.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1003.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1004.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1005.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1006.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1007.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1008.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t1009.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2001.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2002.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2003.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2004.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2005.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2006.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2007.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2008.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples01/t2009.1maps ; \
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples02/t3001.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples02/t3002.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples02/t3003.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples02/t3004.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples02/t3005.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples02/t3006.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples02/t3007.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Simples02/t3008.1maps ; \
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4001.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4002.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4003.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4004.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4005.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4006.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4007.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4008.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4009.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios01/t4010.1maps ; \
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6001.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6002.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6003.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6004.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6005.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6006.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6007.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6008.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6009.1maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Medios02/t6010.1maps 

run:
	./navigate  ./TestInputs/Simples01/t0001.1maps ; \
	./navigate  ./TestInputs/Simples01/t0002.1maps ; \
	./navigate  ./TestInputs/Simples01/t0003.1maps ; \
	./navigate  ./TestInputs/Simples01/t0004.1maps ; \
	./navigate  ./TestInputs/Simples01/t0005.1maps ; \
	./navigate  ./TestInputs/Simples01/t0006.1maps ; \
	./navigate  ./TestInputs/Simples01/t0007.1maps ; \
	./navigate  ./TestInputs/Simples01/t0008.1maps ; \
	./navigate  ./TestInputs/Simples01/t0009.1maps ; \
	./navigate  ./TestInputs/Simples01/t1001.1maps ; \
	./navigate  ./TestInputs/Simples01/t1002.1maps ; \
	./navigate  ./TestInputs/Simples01/t1003.1maps ; \
	./navigate  ./TestInputs/Simples01/t1004.1maps ; \
	./navigate  ./TestInputs/Simples01/t1005.1maps ; \
	./navigate  ./TestInputs/Simples01/t1006.1maps ; \
	./navigate  ./TestInputs/Simples01/t1007.1maps ; \
	./navigate  ./TestInputs/Simples01/t1008.1maps ; \
	./navigate  ./TestInputs/Simples01/t1009.1maps ; \
	./navigate  ./TestInputs/Simples01/t2001.1maps ; \
	./navigate  ./TestInputs/Simples01/t2002.1maps ; \
	./navigate  ./TestInputs/Simples01/t2003.1maps ; \
	./navigate  ./TestInputs/Simples01/t2004.1maps ; \
	./navigate  ./TestInputs/Simples01/t2005.1maps ; \
	./navigate  ./TestInputs/Simples01/t2006.1maps ; \
	./navigate  ./TestInputs/Simples01/t2007.1maps ; \
	./navigate  ./TestInputs/Simples01/t2008.1maps ; \
	./navigate  ./TestInputs/Simples01/t2009.1maps ; \
	\
	./navigate  ./TestInputs/Simples02/t3001.1maps ; \
	./navigate  ./TestInputs/Simples02/t3002.1maps ; \
	./navigate  ./TestInputs/Simples02/t3003.1maps ; \
	./navigate  ./TestInputs/Simples02/t3004.1maps ; \
	./navigate  ./TestInputs/Simples02/t3005.1maps ; \
	./navigate  ./TestInputs/Simples02/t3006.1maps ; \
	./navigate  ./TestInputs/Simples02/t3007.1maps ; \
	./navigate  ./TestInputs/Simples02/t3008.1maps ; \
	\
	./navigate  ./TestInputs/Medios01/t4001.1maps ; \
	./navigate  ./TestInputs/Medios01/t4002.1maps ; \
	./navigate  ./TestInputs/Medios01/t4003.1maps ; \
	./navigate  ./TestInputs/Medios01/t4004.1maps ; \
	./navigate  ./TestInputs/Medios01/t4005.1maps ; \
	./navigate  ./TestInputs/Medios01/t4006.1maps ; \
	./navigate  ./TestInputs/Medios01/t4007.1maps ; \
	./navigate  ./TestInputs/Medios01/t4008.1maps ; \
	./navigate  ./TestInputs/Medios01/t4009.1maps ; \
	./navigate  ./TestInputs/Medios01/t4010.1maps ; \
	\
	./navigate  ./TestInputs/Medios02/t6001.1maps ; \
	./navigate  ./TestInputs/Medios02/t6002.1maps ; \
	./navigate  ./TestInputs/Medios02/t6003.1maps ; \
	./navigate  ./TestInputs/Medios02/t6004.1maps ; \
	./navigate  ./TestInputs/Medios02/t6005.1maps ; \
	./navigate  ./TestInputs/Medios02/t6006.1maps ; \
	./navigate  ./TestInputs/Medios02/t6007.1maps ; \
	./navigate  ./TestInputs/Medios02/t6008.1maps ; \
	./navigate  ./TestInputs/Medios02/t6009.1maps ; \
	./navigate  ./TestInputs/Medios02/t6010.1maps 

move:
	mv ./TestInputs/Simples01/t0*.sol1maps -t ./TestOutputs/Nossos/Simples01/ ;\
	mv ./TestInputs/Simples01/t1*.sol1maps -t ./TestOutputs/Nossos/Simples01/ ;\
	mv ./TestInputs/Simples01/t2*.sol1maps -t ./TestOutputs/Nossos/Simples01/ ;\
	mv ./TestInputs/Simples02/t3*.sol1maps -t ./TestOutputs/Nossos/Simples02/ ;\
	mv ./TestInputs/Medios01/t4*.sol1maps -t ./TestOutputs/Nossos/Medios01/   ;\
	mv ./TestInputs/Medios02/t6*.sol1maps -t .TestOutputs/Nossos/Medios02/	  ;\

diffs:
	diff  ./TestOutputs/Nossos/Simples01/t0001.sol1maps ./TestOutputs/Corretos/Simples01/t0001.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t0002.sol1maps ./TestOutputs/Corretos/Simples01/t0002.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t0003.sol1maps ./TestOutputs/Corretos/Simples01/t0003.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t0004.sol1maps ./TestOutputs/Corretos/Simples01/t0004.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t0005.sol1maps ./TestOutputs/Corretos/Simples01/t0005.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t0006.sol1maps ./TestOutputs/Corretos/Simples01/t0006.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t0007.sol1maps ./TestOutputs/Corretos/Simples01/t0007.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t0008.sol1maps ./TestOutputs/Corretos/Simples01/t0008.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t0009.sol1maps ./TestOutputs/Corretos/Simples01/t0009.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1001.sol1maps ./TestOutputs/Corretos/Simples01/t1001.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1002.sol1maps ./TestOutputs/Corretos/Simples01/t1002.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1003.sol1maps ./TestOutputs/Corretos/Simples01/t1003.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1004.sol1maps ./TestOutputs/Corretos/Simples01/t1004.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1005.sol1maps ./TestOutputs/Corretos/Simples01/t1005.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1006.sol1maps ./TestOutputs/Corretos/Simples01/t1006.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1007.sol1maps ./TestOutputs/Corretos/Simples01/t1007.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1008.sol1maps ./TestOutputs/Corretos/Simples01/t1008.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t1009.sol1maps ./TestOutputs/Corretos/Simples01/t1009.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2001.sol1maps ./TestOutputs/Corretos/Simples01/t2001.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2002.sol1maps ./TestOutputs/Corretos/Simples01/t2002.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2003.sol1maps ./TestOutputs/Corretos/Simples01/t2003.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2004.sol1maps ./TestOutputs/Corretos/Simples01/t2004.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2005.sol1maps ./TestOutputs/Corretos/Simples01/t2005.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2006.sol1maps ./TestOutputs/Corretos/Simples01/t2006.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2007.sol1maps ./TestOutputs/Corretos/Simples01/t2007.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2008.sol1maps ./TestOutputs/Corretos/Simples01/t2008.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t2009.sol1maps ./TestOutputs/Corretos/Simples01/t2009.query ; \
	\
	diff  ./TestOutputs/Nossos/Simples02/t3001.sol1maps ./TestOutputs/Corretos/Simples02/t3001.query ; \
	diff  ./TestOutputs/Nossos/Simples02/t3002.sol1maps ./TestOutputs/Corretos/Simples02/t3002.query ; \
	diff  ./TestOutputs/Nossos/Simples02/t3003.sol1maps ./TestOutputs/Corretos/Simples02/t3003.query ; \
	diff  ./TestOutputs/Nossos/Simples02/t3004.sol1maps ./TestOutputs/Corretos/Simples02/t3004.query ; \
	diff  ./TestOutputs/Nossos/Simples02/t3005.sol1maps ./TestOutputs/Corretos/Simples02/t3005.query ; \
	diff  ./TestOutputs/Nossos/Simples02/t3006.sol1maps ./TestOutputs/Corretos/Simples02/t3006.query ; \
	diff  ./TestOutputs/Nossos/Simples02/t3007.sol1maps ./TestOutputs/Corretos/Simples02/t3007.query ; \
	diff  ./TestOutputs/Nossos/Simples02/t3008.sol1maps ./TestOutputs/Corretos/Simples02/t3008.query ; \
	\
	diff  ./TestOutputs/Nossos/Simples01/t4001.sol1maps ./TestOutputs/Corretos/Simples01/t4001.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4002.sol1maps ./TestOutputs/Corretos/Simples01/t4002.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4003.sol1maps ./TestOutputs/Corretos/Simples01/t4003.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4004.sol1maps ./TestOutputs/Corretos/Simples01/t4004.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4005.sol1maps ./TestOutputs/Corretos/Simples01/t4005.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4006.sol1maps ./TestOutputs/Corretos/Simples01/t4006.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4007.sol1maps ./TestOutputs/Corretos/Simples01/t4007.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4008.sol1maps ./TestOutputs/Corretos/Simples01/t4008.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4009.sol1maps ./TestOutputs/Corretos/Simples01/t4009.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t4010.sol1maps ./TestOutputs/Corretos/Simples01/t4010.query ; \
	\
	diff  ./TestOutputs/Nossos/Simples01/t6001.sol1maps ./TestOutputs/Corretos/Simples01/t6001.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6002.sol1maps ./TestOutputs/Corretos/Simples01/t6002.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6003.sol1maps ./TestOutputs/Corretos/Simples01/t6003.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6004.sol1maps ./TestOutputs/Corretos/Simples01/t6004.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6005.sol1maps ./TestOutputs/Corretos/Simples01/t6005.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6006.sol1maps ./TestOutputs/Corretos/Simples01/t6006.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6007.sol1maps ./TestOutputs/Corretos/Simples01/t6007.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6008.sol1maps ./TestOutputs/Corretos/Simples01/t6008.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6009.sol1maps ./TestOutputs/Corretos/Simples01/t6009.query ; \
	diff  ./TestOutputs/Nossos/Simples01/t6010.sol1maps ./TestOutputs/Corretos/Simples01/t6010.query ; \

	




 
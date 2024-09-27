############################################# 
# Ficheiro makefile do grupo 51
#
# Autores:
#
# Igor Paruque ist1102901
# Mónica Ferreira ist1106520
#############################################

CFLAGS = -Wall -std=c99 -O3 #flags to use

navigate: main.o IOmodule.o prob_utils.o #program compilation
	gcc $(CFLAGS) -o navigate main.o IOmodule.o prob_utils.o
	
main.o: main.c structs.h IOmodule.h prob_utils.h 
	gcc $(CFLAGS) -c main.c	
		
IOmodule.o: IOmodule.h structs.h IOmodule.c
	gcc $(CFLAGS) -c IOmodule.c

prob_utils.o: structs.h prob_utils.h prob_utils.c
	gcc $(CFLAGS) -c prob_utils.c

clean: # clean object files	
	rm *.o

valtest: # test a specific file for memory leaks
	valgrind --leak-check=full ./navigate ./TestInputs/$(ARG).maps 
#code ./TestInputs/$(ARG).sol1maps ./TestOutputs/Corretos/$(ARG).query		

difftest: # test a specific file for differences in the solution
	./navigate ./TestInputs/$(	diff -s ./TestInputs/$(ARG).sol1maps ./TestOutputs/Corretos/$(ARG).query
#code ./TestInputs/$(ARG).sol1maps ./TestOutputs/Corretos/$(ARG).query

valall: val move # test all files for memory leaks 

diffall: run diffs move# test all files for differences in the solution

val:
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/t3001.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t3002.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t3003.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t3004.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t3005.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t3006.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t3007.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t3008.maps ; \
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/t4001.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4002.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4003.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4004.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4005.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4006.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4007.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4008.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4009.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/t4010.maps ; \
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ;\
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/ ; 
	

run:
	./navigate  ./TestInputs/t0001.maps ; \
	./navigate  ./TestInputs/t0002.maps ; \
	./navigate  ./TestInputs/t0003.maps ; \
	./navigate  ./TestInputs/t0004.maps ; \
	./navigate  ./TestInputs/t0005.maps ; \
	./navigate  ./TestInputs/t0006.maps ; \
	./navigate  ./TestInputs/t0007.maps ; \
	./navigate  ./TestInputs/t0008.maps ; \
	./navigate  ./TestInputs/t0009.maps ; \
	./navigate  ./TestInputs/t1001.maps ; \
	./navigate  ./TestInputs/t1002.maps ; \
	./navigate  ./TestInputs/t1003.maps ; \
	./navigate  ./TestInputs/t1004.maps ; \
	./navigate  ./TestInputs/t1005.maps ; \
	./navigate  ./TestInputs/t100
	./navigate  ./TestInputs/t1007.maps ; \
	./navigate  ./TestInputs/t1008.maps ; \
	./navigate  ./TestInputs/t1009.maps ; \
	./navigate  ./TestInputs/t2001.maps ; \
	./navigate  ./TestInputs/t2002.maps ; \
	./navigate  ./TestInputs/t2003.maps ; \
	./navigate  ./TestInputs/t2004.maps ; \
	./navigate  ./TestInputs/t2005.maps ; \
	./navigate  ./TestInputs/t2006.maps ; \
	./navigate  ./TestInputs/t2007.maps ; \
	./navigate  ./TestInputs/t2008.maps ; \
	./navigate  ./TestInputs/t2009.maps ; \
	\
	./navigate  ./TestInputs/t3001.maps ; \
	./navigate  ./TestInputs/t3002.maps ; \
	./navigate  ./TestInputs/t3003.maps ; \
	./navigate  ./TestInputs/t3004.maps ; \
	./navigate  ./TestInputs/t3005.maps ; \
	./navigate  ./TestInputs/t3006.maps ; \
	./navigate  ./TestInputs/t3007.maps ; \
	./navigate  ./TestInputs/t3008.maps ; \
	\
	./navigate  ./TestInputs/t4001.maps ; \
	./navigate  ./TestInputs/t4002.maps ; \
	./navigate  ./TestInputs/t4003.maps ; \
	./navigate  ./TestInputs/t4004.maps ; \
	./navigate  ./TestInputs/t4005.maps ; \
	./navigate  ./TestInputs/t4006.maps ; \
	./navigate  ./TestInputs/t4007.maps ; \
	./navigate  ./TestInputs/t4008.maps ; \
	./navigate  ./TestInputs/t4009.maps ; \
	./navigate  ./TestInputs/t4010.maps ; \
	\
	./navigate  ./TestInputs/t6001.maps ; \
	./navigate  ./TestInputs/t6002.maps ; \
	./navigate  ./TestInputs/t6003.maps ; \
	./navigate  ./TestInputs/t6004.maps ; \
	./navigate  ./TestInputs/t6005.maps ; \
	./navigate  ./TestInputs/t6006.maps ; \
	./navigate  ./TestInputs/t6007.maps ; \
	./navigate  ./TestInputs/t6008.maps ; \
	./navigate  ./TestInputs/t6009.maps ; \
	./navigate  ./TestInputs/t6010.maps ; \
	\
	./navigate  ./TestInputs/t8001.maps ; \
	./navigate  ./TestInputs/t8002.maps ; \
	./navigate  ./TestInputs/t8003.maps ; \
	./navigate  ./TestInputs/t8004.maps ; \
	./navigate  ./TestInputs/t8005.maps ; \
	./navigate  ./TestInputs/t8006.maps ; \
	./navigate  ./TestInputs/t8007.maps ; 

move:
	mv ./TestInputs/t0*.sol1maps -t ./TestOutputs/Nossos/ ;\
	mv ./TestInputs/t1*.sol1maps -t ./TestOutputs/Nossos/ ;\
	mv ./TestInputs/t2*.sol1maps -t ./TestOutputs/Nossos/ ;\
	mv ./TestInputs/t3*.sol1maps -t ./TestOutputs/Nossos/ ;\
	mv ./TestInputs/t4*.sol1maps -t ./TestOutputs/Nossos/   ;\
	mv ./TestInputs/t6*.sol1maps -t ./TestOutputs/Nossos/	  ;\
	mv ./TestInputs/t8*.sol1maps -t ./TestOutputs/Nossos/	 

diffs:
	diff -s ./TestInputs/t0001.sol1maps ./TestOutputs/Corretos/t0001.query ; \
	diff -s ./TestInputs/t0002.sol1maps ./TestOutputs/Corretos/t0002.query ; \
	diff -s ./TestInputs/t0003.sol1maps ./TestOutputs/Corretos/t0003.query ; \
	diff -s ./TestInputs/t0004.sol1maps ./TestOutputs/Corretos/t0004.query ; \
	diff -s ./TestInputs/t0005.sol1maps ./TestOutputs/Corretos/t0005.query ; \
	diff -s ./TestInputs/t0006.sol1maps ./TestOutputs/Corretos/t0006.query ; \
	diff -s ./TestInputs/t0007.sol1maps ./TestOutputs/Corretos/t0007.query ; \
	diff -s ./TestInputs/t0008.sol1maps ./TestOutputs/Corretos/t0008.query ; \
	diff -s ./TestInputs/t0009.sol1maps ./TestOutputs/Corretos/t0009.query ; \
	diff -s ./TestInputs/t1001.sol1maps ./TestOutputs/Corretos/t1001.query ; \
	diff -s ./TestInputs/t1002.sol1maps ./TestOutputs/Corretos/t1002.query ; \
	diff -s ./TestInputs/t1003.sol1maps ./TestOutputs/Corretos/t1003.query ; \
	diff -s ./TestInputs/t1004.sol1maps ./TestOutputs/Corretos/t1004.query ; \
	diff -s ./TestInputs/t1005.sol1maps ./TestOutputs/Corretos/t1005.query ; \
	diff -s ./TestInputs/t1006.sol1maps ./TestOutputs/Corretos/t1006.query ; \
	diff -s ./TestInputs/t1007.sol1maps ./TestOutputs/Corretos/t1007.query ; \
	diff -s ./TestInputs/t1008.sol1maps ./TestOutputs/Corretos/t1008.query ; \
	diff -s ./TestInputs/t1009.sol1maps ./TestOutputs/Corretos/t1009.query ; \
	diff -s ./TestInputs/t2001.sol1maps ./TestOutputs/Corretos/t2001.query ; \
	diff -s ./TestInputs/t2002.sol1maps ./TestOutputs/Corretos/t2002.query ; \
	diff -s ./TestInputs/t2003.sol1maps ./TestOutputs/Corretos/t2003.query ; \
	diff -s ./TestInputs/t2004.sol1maps ./TestOutputs/Corretos/t2004.query ; \
	diff -s ./TestInputs/t2005.sol1maps ./TestOutputs/Corretos/t2005.query ; \
	diff -s ./TestInputs/t2006.sol1maps ./TestOutputs/Corretos/t2006.query ; \
	diff -s ./TestInputs/t2007.sol1maps ./TestOutputs/Corretos/t2007.query ; \
	diff -s ./TestInputs/t2008.sol1maps ./TestOutputs/Corretos/t2008.query ; \
	diff -s ./TestInputs/t2009.sol1maps ./TestOutputs/Corretos/t2009.query ; \
	\
	diff -s ./TestInputs/t3001.sol1maps ./TestOutputs/Corretos/t3001.query ; \
	diff -s ./TestInputs/t3002.sol1maps ./TestOutputs/Corretos/t3002.query ; \
	diff -s ./TestInputs/t3003.sol1maps ./TestOutputs/Corretos/t3003.query ; \
	diff -s ./TestInputs/t3004.sol1maps ./TestOutputs/Corretos/t3004.query ; \
	diff -s ./TestInputs/t3005.sol1maps ./TestOutputs/Corretos/t3005.query ; \
	diff -s ./TestInputs/t3006.sol1maps ./TestOutputs/Corretos/t3006.query ; \
	diff -s ./TestInputs/t3007.sol1maps ./TestOutputs/Corretos/t3007.query ; \
	diff -s ./TestInputs/t3008.sol1maps ./TestOutputs/Corretos/t3008.query ; \
	\
	diff -s ./TestInputs/t4001.sol1maps ./TestOutputs/Corretos/t4001.query ; \
	diff -s ./TestInputs/t4002.sol1maps ./TestOutputs/Corretos/t4002.query ; \
	diff -s ./TestInputs/t4003.sol1maps ./TestOutputs/Corretos/t4003.query ; \
	diff -s ./TestInputs/t4004.sol1maps ./TestOutputs/Corretos/t4004.query ; \
	diff -s ./TestInputs/t4005.sol1maps ./TestOutputs/Corretos/t4005.query ; \
	diff -s ./TestInputs/t4006.sol1maps ./TestOutputs/Corretos/t4006.query ; \
	diff -s ./TestInputs/t4007.sol1maps ./TestOutputs/Corretos/t4007.query ; \
	diff -s ./TestInputs/t4008.sol1maps ./TestOutputs/Corretos/t4008.query ; \
	diff -s ./TestInputs/t4009.sol1maps ./TestOutputs/Corretos/t4009.query ; \
	diff -s ./TestInputs/t4010.sol1maps ./TestOutputs/Corretos/t4010.query ; \
	\
	diff -s ./TestInputs/t6001.sol1maps ./TestOutputs/Corretos/t6001.query ; \
	diff -s ./TestInputs/t6002.sol1maps ./TestOutputs/Corretos/t6002.query ; \
	diff -s ./TestInputs/t6003.sol1maps ./TestOutputs/Corretos/t6003.query ; \
	diff -s ./TestInputs/t6004.sol1maps ./TestOutputs/Corretos/t6004.query ; \
	diff -s ./TestInputs/t6005.sol1maps ./TestOutputs/Corretos/t6005.query ; \
	diff -s ./TestInputs/t6006.sol1maps ./TestOutputs/Corretos/t6006.query ; \
	diff -s ./TestInputs/t6007.sol1maps ./TestOutputs/Corretos/t6007.query ; \
	diff -s ./TestInputs/t6008.sol1maps ./TestOutputs/Corretos/t6008.query ; \
	diff -s ./TestInputs/t6009.sol1maps ./TestOutputs/Corretos/t6009.query ; \
	diff -s ./TestInputs/t6010.sol1maps ./TestOutputs/Corretos/t6010.query ; \
	\
	diff -s ./TestInputs/t8001.sol1maps ./TestOutputs/Corretos/t8001.query ; \
	diff -s ./TestInputs/t8002.sol1maps ./TestOutputs/Corretos/t8002.query ; \
	diff -s ./TestInputs/t8003.sol1maps ./TestOutputs/Corretos/t8003.query ; \
	diff -s ./TestInputs/t8004.sol1maps ./TestOutputs/Corretos/t8004.query ; \
	diff -s ./TestInputs/t8005.sol1maps ./TestOutputs/Corretos/t8005.query ; \
	diff -s ./TestInputs/t8006.sol1maps ./TestOutputs/Corretos/t8006.query ; \
	diff -s ./TestInputs/t8007.sol1maps ./TestOutputs/Corretos/t8007.query  
	

	




 
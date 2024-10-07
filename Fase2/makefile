############################################# 
# Ficheiro makefile do grupo 51
#
# Autores:
#
# Igor Paruque ist1102901
# Mónica Ferreira ist1106520
#############################################

CFLAGS = -std=c99 -g #flags to use

navigate: main.o IOmodule.o problem.o #program compilation
	gcc $(CFLAGS) -o navigate main.o IOmodule.o problem.o
	
main.o: structs.h IOmodule.h problem.h main.c
	gcc $(CFLAGS) -c main.c	
		
problem.o: structs.h IOmodule.h problem.h problem.c
	gcc $(CFLAGS) -c problem.c

IOmodule.o: IOmodule.h IOmodule.c
	gcc $(CFLAGS) -c IOmodule.c

clean: # clean object files	
	rm *.o

valtest: # test a specific file for memory leaks
	valgrind --leak-check=full ./navigate ./TestInputs/$(ARG).maps 
		
difftest: # test a specific file for differences in the solution
	./navigate ./TestInputs/$(ARG).maps ;	diff -s ./TestInputs/$(ARG).solmaps ./TestOutputs/Corretos/$(ARG).query

valall: val move # test all files for memory leaks 

diffall: run diffs move # test all files for differences in the solution

val:
	
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4001.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4002.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4003.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4004.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4005.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4006.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4007.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4008.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4009.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4010.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4011.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4012.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4013.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4014.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4015.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4016.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4017.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4018.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4019.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4020.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4021.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4022.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4023.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4024.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4025.maps ; 
	
	
	

run:
	./Navigate ./TestInputs/Girinos01/t4001.maps ; \
	./Navigate ./TestInputs/Girinos01/t4002.maps ; \
	./Navigate ./TestInputs/Girinos01/t4003.maps ; \
	./Navigate ./TestInputs/Girinos01/t4004.maps ; \
	./Navigate ./TestInputs/Girinos01/t4005.maps ; \
	./Navigate ./TestInputs/Girinos01/t4006.maps ; \
	./Navigate ./TestInputs/Girinos01/t4007.maps ; \
	./Navigate ./TestInputs/Girinos01/t4008.maps ; \
	./Navigate ./TestInputs/Girinos01/t4009.maps ; \
	./Navigate ./TestInputs/Girinos01/t4010.maps ; \
	./Navigate ./TestInputs/Girinos01/t4011.maps ; \
	./Navigate ./TestInputs/Girinos01/t4012.maps ; \
	./Navigate ./TestInputs/Girinos01/t4013.maps ; \
	./Navigate ./TestInputs/Girinos01/t4014.maps ; \
	./Navigate ./TestInputs/Girinos01/t4015.maps ; \
	./Navigate ./TestInputs/Girinos01/t4016.maps ; \
	./Navigate ./TestInputs/Girinos01/t4017.maps ; \
	./Navigate ./TestInputs/Girinos01/t4018.maps ; \
	./Navigate ./TestInputs/Girinos01/t4019.maps ; \
	./Navigate ./TestInputs/Girinos01/t4020.maps ; \
	./Navigate ./TestInputs/Girinos01/t4021.maps ; \
	./Navigate ./TestInputs/Girinos01/t4022.maps ; \
	./Navigate ./TestInputs/Girinos01/t4023.maps ; \
	./Navigate ./TestInputs/Girinos01/t4024.maps ; \
	./Navigate ./TestInputs/Girinos01/t4025.maps ; 

move:
	
	mv ./TestInputs/Girinos01/t4*.sol1maps -t ./TestOutputs/Nossos/Girinos01/ 

diffs:
	
	diff -s ./TestInputs/Girinos01/t4001.sol1maps ./TestOutputs/Corretos/t4001.query ; \
	diff -s ./TestInputs/Girinos01/t4002.sol1maps ./TestOutputs/Corretos/t4002.query ; \
	diff -s ./TestInputs/Girinos01/t4003.sol1maps ./TestOutputs/Corretos/t4003.query ; \
	diff -s ./TestInputs/Girinos01/t4004.sol1maps ./TestOutputs/Corretos/t4004.query ; \
	diff -s ./TestInputs/Girinos01/t4005.sol1maps ./TestOutputs/Corretos/t4005.query ; \
	diff -s ./TestInputs/Girinos01/t4006.sol1maps ./TestOutputs/Corretos/t4006.query ; \
	diff -s ./TestInputs/Girinos01/t4007.sol1maps ./TestOutputs/Corretos/t4007.query ; \
	diff -s ./TestInputs/Girinos01/t4008.sol1maps ./TestOutputs/Corretos/t4008.query ; \
	diff -s ./TestInputs/Girinos01/t4009.sol1maps ./TestOutputs/Corretos/t4009.query ; \
	diff -s ./TestInputs/Girinos01/t4010.sol1maps ./TestOutputs/Corretos/t4010.query ; \
	

	




 
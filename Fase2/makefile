############################################# 
# Ficheiro makefile do grupo 51
#
# Autores:
#
# Igor Paruque ist1102901
# Mónica Ferreira ist1106520
#############################################

CFLAGS = -Wall -std=c99 -g #flags to use

navigate: IOmodule.o Stack.o problem.o main.o    #program compilation
	gcc $(CFLAGS) -o navigate main.o IOmodule.o problem.o Stack.o

IOmodule.o: IOmodule.h IOmodule.c
	gcc $(CFLAGS) -c IOmodule.c

Stack.o: Items.h Stack.h Stack.c
	gcc $(CFLAGS) -c Stack.c
		
problem.o: Items.h Stack.h problem.h problem.c 
	gcc $(CFLAGS) -c problem.c

main.o: structs.h IOmodule.h problem.h main.c
	gcc $(CFLAGS) -c main.c



clean: # clean object files	
	rm *.o

valtest: # test a specific file for memory leaks
	valgrind --leak-check=full ./navigate ./TestInputs/$(ARG).maps 
		
valall: val move # test all files for memory leaks 

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
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos01/t4025.maps ; \
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5001.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5002.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5003.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5004.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5005.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5006.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5007.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5008.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5009.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5010.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5011.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5012.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5013.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5014.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5015.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5016.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5017.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5018.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5019.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5020.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5021.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5022.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5023.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5024.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5025.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5026.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5027.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5028.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Girinos02/5029.maps ; \		
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-01.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-02.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-03.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-04.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-05.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-06.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-07.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-08.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-09.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-10.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-11.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-12.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-13.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-14.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas01/41-53-16-15.maps ; \
	\
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-16.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-17.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-18.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-19.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-20.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-21.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-22.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-23.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-24.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-25.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-26.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-27.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-28.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-29.maps ; \
	valgrind --leak-check=full ./navigate  ./TestInputs/Crisalidas02/41-53-16-30.maps ; \	
	\


			
	
	
	

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
	mv ./TestInputs/Girinos01/t5*.sol1maps -t ./TestOutputs/Nossos/Girinos02/ 
	mv ./TestInputs/Girinos01/t4*.sol1maps -t ./TestOutputs/Nossos/Crisalidas01/ 
	mv ./TestInputs/Girinos01/t4*.sol1maps -t ./TestOutputs/Nossos/Crisalidas02/ 
	mv ./TestInputs/Girinos01/t4*.sol1maps -t ./TestOutputs/Nossos/Girinos01/ 
	mv ./TestInputs/Girinos01/t4*.sol1maps -t ./TestOutputs/Nossos/Girinos01/ 
	
	

	




 
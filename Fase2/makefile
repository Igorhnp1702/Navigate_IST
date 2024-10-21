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
	valgrind --leak-check=full ./navigate ./$(ARG).maps 

checktest:
	./navigate ./$(ARG).maps ; \
	navigateChecker ./$(ARG).maps
		
valall:
#girinos01; girinos02, crisalidas01; crisalidas02; minhocas01; minhocas02
	valgrind --leak-check=full ./navigate  ./Pool/t4001.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4002.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4003.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4004.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4005.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4006.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4007.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4008.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4009.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4010.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4011.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4012.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4013.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4014.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4015.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4016.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4017.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4018.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4019.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4020.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4021.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4022.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4023.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4024.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/t4025.maps ; \
	\
	valgrind --leak-check=full ./navigate  ./Pool/5001.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5002.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5003.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5004.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5005.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5006.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5007.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5008.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5009.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5010.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5011.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5012.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5013.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5014.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5015.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5016.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5017.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5018.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5019.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5020.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5021.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5022.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5023.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5024.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5025.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5026.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5027.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5028.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/5029.maps ; \		
	\
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-01.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-02.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-03.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-04.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-05.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-06.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-07.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-08.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-09.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-10.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-11.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-12.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-13.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-14.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-15.maps ; \
	\
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-16.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-17.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-18.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-19.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-20.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-21.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-22.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-23.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-24.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-25.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-26.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-27.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-28.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-29.maps ; \
	valgrind --leak-check=full ./navigate  ./Pool/41-53-16-30.maps ; \	
	\
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-01.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-02.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-03.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-04.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-05.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-06.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-07.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-08.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-09.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-10.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-11.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-12.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-13.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-14.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-15.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-16.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-17.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-18.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-19.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-20.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-21.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-22.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-23.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-24.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-25.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-26.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-27.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-28.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-29.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-30.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-31.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-32.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-xx.maps ; \
	\
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-50.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-51.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-52.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-53.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-54.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-55.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-56.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-57.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-58.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-59.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-60.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-61.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-62.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-63.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-64.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-65.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-66.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-67.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-68.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-69.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-70.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-71.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-72.maps ; \
	valgrind --leak-check=full ./navigate  ./BigPool/41-53-73.maps ; 
	 					
run:
	./navigate  ./Pool/t4001.maps ; \
	navigateChecker ./Pool/t4001.maps\
	\
	./navigate  ./Pool/t4002.maps ; \
	navigateChecker ./Pool/t4002.maps\
	\
	./navigate  ./Pool/t4003.maps ; \
	navigateChecker ./Pool/t4003.maps\
	\
	./navigate  ./Pool/t4004.maps ; \
	navigateChecker ./Pool/t4004.maps\
	\
	./navigate  ./Pool/t4005.maps ; \
	navigateChecker ./Pool/t4005.maps\
	\
	./navigate  ./Pool/t4006.maps ; \
	navigateChecker ./Pool/t4006.maps\
	\
	./navigate  ./Pool/t4007.maps ; \
	navigateChecker ./Pool/t4007.maps\
	\
	./navigate  ./Pool/t4008.maps ; \
	navigateChecker ./Pool/t4008.maps\
	\
	./navigate  ./Pool/t4009.maps ; \
	navigateChecker ./Pool/t4009.maps\
	\
	./navigate  ./Pool/t4010.maps ; \
	navigateChecker ./Pool/t4010.maps\
	\
	./navigate  ./Pool/t4011.maps ; \
	navigateChecker ./Pool/t4011.maps\
	\
	./navigate  ./Pool/t4012.maps ; \
	navigateChecker ./Pool/t4012.maps\
	\
	./navigate  ./Pool/t4013.maps ; \
	navigateChecker ./Pool/t4013.maps\
	\
	./navigate  ./Pool/t4014.maps ; \
	navigateChecker ./Pool/t4014.maps\
	\
	./navigate  ./Pool/t4015.maps ; \
	navigateChecker ./Pool/t4015.maps\
	\
	./navigate  ./Pool/t4016.maps ; \
	navigateChecker ./Pool/t4016.maps\
	\
	./navigate  ./Pool/t4017.maps ; \
	navigateChecker ./Pool/t4017.maps\
	\
	./navigate  ./Pool/t4018.maps ; \
	navigateChecker ./Pool/t4018.maps\
	\
	./navigate  ./Pool/t4019.maps ; \
	navigateChecker ./Pool/t4019.maps\
	\
	./navigate  ./Pool/t4020.maps ; \
	navigateChecker ./Pool/t4020.maps\
	\
	./navigate  ./Pool/t4021.maps ; \
	navigateChecker ./Pool/t4021.maps\
	\
	./navigate  ./Pool/t4022.maps ; \
	navigateChecker ./Pool/t4022.maps\
	\
	./navigate  ./Pool/t4023.maps ; \
	navigateChecker ./Pool/t4023.maps\
	\
	./navigate  ./Pool/t4024.maps ; \
	navigateChecker ./Pool/t4024.maps\
	\
	./navigate  ./Pool/t4025.maps ; \
	navigateChecker ./Pool/t4025.maps\
	\
	./navigate  ./Pool/t5001.maps ; \
	navigateChecker ./Pool/t5001.maps\
	\
	./navigate  ./Pool/t5002.maps ; \
	navigateChecker ./Pool/t5002.maps\
	\
	./navigate  ./Pool/t5003.maps ; \
	navigateChecker ./Pool/t5003.maps\
	\
	./navigate  ./Pool/t5004.maps ; \
	navigateChecker ./Pool/t5004.maps\
	\
	./navigate  ./Pool/t5005.maps ; \
	navigateChecker ./Pool/t5005.maps\
	\
	./navigate  ./Pool/t5006.maps ; \
	navigateChecker ./Pool/t5006.maps\
	\
	./navigate  ./Pool/t5007.maps ; \
	navigateChecker ./Pool/t5007.maps\
	\
	./navigate  ./Pool/t5008.maps ; \
	navigateChecker ./Pool/t5008.maps\
	\
	./navigate  ./Pool/t5009.maps ; \
	navigateChecker ./Pool/t5009.maps\
	\
	./navigate  ./Pool/t5010.maps ; \
	navigateChecker ./Pool/t5010.maps\
	\
	./navigate  ./Pool/t5011.maps ; \
	navigateChecker ./Pool/t5011.maps\
	\
	./navigate  ./Pool/t5012.maps ; \
	navigateChecker ./Pool/t5012.maps\
	\
	./navigate  ./Pool/t5013.maps ; \
	navigateChecker ./Pool/t5013.maps\
	\
	./navigate  ./Pool/t5014.maps ; \
	navigateChecker ./Pool/t5014.maps\
	\
	./navigate  ./Pool/t5015.maps ; \
	navigateChecker ./Pool/t5015.maps\
	\
	./navigate  ./Pool/t5016.maps ; \
	navigateChecker ./Pool/t5016.maps\
	\
	./navigate  ./Pool/t5017.maps ; \
	navigateChecker ./Pool/t5017.maps\
	\
	./navigate  ./Pool/t5018.maps ; \
	navigateChecker ./Pool/t5018.maps\
	\
	./navigate  ./Pool/t5019.maps ; \
	navigateChecker ./Pool/t5019.maps\
	\
	./navigate  ./Pool/t5020.maps ; \
	navigateChecker ./Pool/t5020.maps\
	\
	./navigate  ./Pool/t5021.maps ; \
	navigateChecker ./Pool/t5021.maps\
	\
	./navigate  ./Pool/t5022.maps ; \
	navigateChecker ./Pool/t5022.maps\
	\
	./navigate  ./Pool/t5023.maps ; \
	navigateChecker ./Pool/t5023.maps\
	\
	./navigate  ./Pool/t5024.maps ; \
	navigateChecker ./Pool/t5024.maps\
	\
	./navigate  ./Pool/t5025.maps ; \
	navigateChecker ./Pool/t5025.maps\
	\
	./navigate  ./Pool/t5026.maps ; \
	navigateChecker ./Pool/t5026.maps\
	\
	./navigate  ./Pool/t5027.maps ; \
	navigateChecker ./Pool/t5027.maps\
	\
	./navigate  ./Pool/t5028.maps ; \
	navigateChecker ./Pool/t5028.maps\
	\
	./navigate  ./Pool/t5029.maps ; \
	navigateChecker ./Pool/t5029.maps\
	\
	./navigate  ./Pool/41-53-16-01.maps ; \
	navigateChecker ./Pool/41-53-16-01.maps\
	\
	./navigate  ./Pool/41-53-16-02.maps ; \
	navigateChecker ./Pool/41-53-16-02.maps\
	\
	./navigate  ./Pool/41-53-16-03.maps ; \
	navigateChecker ./Pool/41-53-16-03.maps\
	\
	./navigate  ./Pool/41-53-16-04.maps ; \
	navigateChecker ./Pool/41-53-16-04.maps\
	\
	./navigate  ./Pool/41-53-16-05.maps ; \
	navigateChecker ./Pool/41-53-16-05.maps\
	\
	./navigate  ./Pool/41-53-16-06.maps ; \
	navigateChecker ./Pool/41-53-16-06.maps\
	\
	./navigate  ./Pool/41-53-16-07.maps ; \
	navigateChecker ./Pool/41-53-16-07.maps\
	\
	./navigate  ./Pool/41-53-16-08.maps ; \
	navigateChecker ./Pool/41-53-16-08.maps\
	\
	./navigate  ./Pool/41-53-16-09.maps ; \
	navigateChecker ./Pool/41-53-16-09.maps\
	\
	./navigate  ./Pool/41-53-16-10.maps ; \
	navigateChecker ./Pool/41-53-16-10.maps\
	\
	./navigate  ./Pool/41-53-16-11.maps ; \
	navigateChecker ./Pool/41-53-16-11.maps\
	\
	./navigate  ./Pool/41-53-16-12.maps ; \
	navigateChecker ./Pool/41-53-16-12.maps\
	\
	./navigate  ./Pool/41-53-16-13.maps ; \
	navigateChecker ./Pool/41-53-16-13.maps\
	\
	./navigate  ./Pool/41-53-16-14.maps ; \
	navigateChecker ./Pool/41-53-16-14.maps\
	\
	./navigate  ./Pool/41-53-16-15.maps ; \
	navigateChecker ./Pool/41-53-16-15.maps\
	\
	./navigate  ./Pool/41-53-16-16.maps ; \
	navigateChecker ./Pool/41-53-16-16.maps\
	\
	./navigate  ./Pool/41-53-16-17.maps ; \
	navigateChecker ./Pool/41-53-16-17.maps\
	\
	./navigate  ./Pool/41-53-16-18.maps ; \
	navigateChecker ./Pool/41-53-16-18.maps\
	\
	./navigate  ./Pool/41-53-16-19.maps ; \
	navigateChecker ./Pool/41-53-16-19.maps\
	\
	./navigate  ./Pool/41-53-16-20.maps ; \
	navigateChecker ./Pool/41-53-16-20.maps\
	\
	./navigate  ./Pool/41-53-16-21.maps ; \
	navigateChecker ./Pool/41-53-16-21.maps\
	\
	./navigate  ./Pool/41-53-16-22.maps ; \
	navigateChecker ./Pool/41-53-16-22.maps\
	\
	./navigate  ./Pool/41-53-16-23.maps ; \
	navigateChecker ./Pool/41-53-16-23.maps\
	\
	./navigate  ./Pool/41-53-16-24.maps ; \
	navigateChecker ./Pool/41-53-16-24.maps\
	\
	./navigate  ./Pool/41-53-16-25.maps ; \
	navigateChecker ./Pool/41-53-16-25.maps\
	\
	./navigate  ./Pool/41-53-16-26.maps ; \
	navigateChecker ./Pool/41-53-16-26.maps\
	\
	./navigate  ./Pool/41-53-16-27.maps ; \
	navigateChecker ./Pool/41-53-16-27.maps\
	\
	./navigate  ./Pool/41-53-16-28.maps ; \
	navigateChecker ./Pool/41-53-16-28.maps\
	\
	./navigate  ./Pool/41-53-16-29.maps ; \
	navigateChecker ./Pool/41-53-16-29.maps\
	\
	./navigate  ./Pool/41-53-16-30.maps ; \
	navigateChecker ./Pool/41-53-16-30.maps\
	\
	./navigate  ./BigPool/41-53-00.maps ; \
	navigateChecker ./BigPool/41-53-00.maps\
	\
	./navigate  ./BigPool/41-53-01.maps ; \
	navigateChecker ./BigPool/41-53-01.maps\
	\
	./navigate  ./BigPool/41-53-02.maps ; \
	navigateChecker ./BigPool/41-53-02.maps\
	\
	./navigate  ./BigPool/41-53-03.maps ; \
	navigateChecker ./BigPool/41-53-03.maps\
	\
	./navigate  ./BigPool/41-53-04.maps ; \
	navigateChecker ./BigPool/41-53-04.maps\
	\
	./navigate  ./BigPool/41-53-05.maps ; \
	navigateChecker ./BigPool/41-53-05.maps\
	\
	./navigate  ./BigPool/41-53-06.maps ; \
	navigateChecker ./BigPool/41-53-06.maps\
	\
	./navigate  ./BigPool/41-53-07.maps ; \
	navigateChecker ./BigPool/41-53-07.maps\
	\
	./navigate  ./BigPool/41-53-08.maps ; \
	navigateChecker ./BigPool/41-53-08.maps\
	\
	./navigate  ./BigPool/41-53-09.maps ; \
	navigateChecker ./BigPool/41-53-09.maps\
	\
	./navigate  ./BigPool/41-53-10.maps ; \
	navigateChecker ./BigPool/41-53-10.maps\
	\
	./navigate  ./BigPool/41-53-11.maps ; \
	navigateChecker ./BigPool/41-53-11.maps\
	\
	./navigate  ./BigPool/41-53-12.maps ; \
	navigateChecker ./BigPool/41-53-12.maps\
	\
	./navigate  ./BigPool/41-53-13.maps ; \
	navigateChecker ./BigPool/41-53-13.maps\
	\
	./navigate  ./BigPool/41-53-14.maps ; \
	navigateChecker ./BigPool/41-53-14.maps\
	\
	./navigate  ./BigPool/41-53-15.maps ; \
	navigateChecker ./BigPool/41-53-15.maps\
	\
	./navigate  ./BigPool/41-53-16.maps ; \
	navigateChecker ./BigPool/41-53-16.maps\
	\
	./navigate  ./BigPool/41-53-17.maps ; \
	navigateChecker ./BigPool/41-53-17.maps\
	\
	./navigate  ./BigPool/41-53-18.maps ; \
	navigateChecker ./BigPool/41-53-18.maps\
	\
	./navigate  ./BigPool/41-53-19.maps ; \
	navigateChecker ./BigPool/41-53-19.maps\
	\
	./navigate  ./BigPool/41-53-20.maps ; \
	navigateChecker ./BigPool/41-53-20.maps\
	\
	./navigate  ./BigPool/41-53-21.maps ; \
	navigateChecker ./BigPool/41-53-21.maps\
	\
	./navigate  ./BigPool/41-53-22.maps ; \
	navigateChecker ./BigPool/41-53-22.maps\
	\
	./navigate  ./BigPool/41-53-23.maps ; \
	navigateChecker ./BigPool/41-53-23.maps\
	\
	./navigate  ./BigPool/41-53-24.maps ; \
	navigateChecker ./BigPool/41-53-24.maps\
	\
	./navigate  ./BigPool/41-53-25.maps ; \
	navigateChecker ./BigPool/41-53-25.maps\
	\
	./navigate  ./BigPool/41-53-26.maps ; \
	navigateChecker ./BigPool/41-53-26.maps\
	\
	./navigate  ./BigPool/41-53-27.maps ; \
	navigateChecker ./BigPool/41-53-27.maps\
	\
	./navigate  ./BigPool/41-53-28.maps ; \
	navigateChecker ./BigPool/41-53-28.maps\
	\
	./navigate  ./BigPool/41-53-29.maps ; \
	navigateChecker ./BigPool/41-53-29.maps\
	\
	./navigate  ./BigPool/41-53-30.maps ; \
	navigateChecker ./BigPool/41-53-30.maps\
	\
	./navigate  ./BigPool/41-53-31.maps ; \
	navigateChecker ./BigPool/41-53-31.maps\
	\
	./navigate  ./BigPool/41-53-32.maps ; \
	navigateChecker ./BigPool/41-53-32.maps\
	\
	./navigate  ./BigPool/41-53-50.maps ; \
	navigateChecker ./BigPool/41-53-50.maps\
	\
	./navigate  ./BigPool/41-53-51.maps ; \
	navigateChecker ./BigPool/41-53-51.maps\
	\
	./navigate  ./BigPool/41-53-52.maps ; \
	navigateChecker ./BigPool/41-53-52.maps\
	\
	./navigate  ./BigPool/41-53-53.maps ; \
	navigateChecker ./BigPool/41-53-53.maps\
	\
	./navigate  ./BigPool/41-53-54.maps ; \
	navigateChecker ./BigPool/41-53-54.maps\
	\
	./navigate  ./BigPool/41-53-55.maps ; \
	navigateChecker ./BigPool/41-53-55.maps\
	\
	./navigate  ./BigPool/41-53-56.maps ; \
	navigateChecker ./BigPool/41-53-56.maps\
	\
	./navigate  ./BigPool/41-53-57.maps ; \
	navigateChecker ./BigPool/41-53-57.maps\
	\
	./navigate  ./BigPool/41-53-58.maps ; \
	navigateChecker ./BigPool/41-53-58.maps\
	\
	./navigate  ./BigPool/41-53-59.maps ; \
	navigateChecker ./BigPool/41-53-59.maps\
	\
	./navigate  ./BigPool/41-53-60.maps ; \
	navigateChecker ./BigPool/41-53-60.maps\
	\
	./navigate  ./BigPool/41-53-61.maps ; \
	navigateChecker ./BigPool/41-53-61.maps\
	\
	./navigate  ./BigPool/41-53-62.maps ; \
	navigateChecker ./BigPool/41-53-62.maps\
	\
	./navigate  ./BigPool/41-53-63.maps ; \
	navigateChecker ./BigPool/41-53-63.maps\
	\
	./navigate  ./BigPool/41-53-64.maps ; \
	navigateChecker ./BigPool/41-53-64.maps\
	\
	./navigate  ./BigPool/41-53-65.maps ; \
	navigateChecker ./BigPool/41-53-65.maps\
	\
	./navigate  ./BigPool/41-53-66.maps ; \
	navigateChecker ./BigPool/41-53-66.maps\
	\
	./navigate  ./BigPool/41-53-67.maps ; \
	navigateChecker ./BigPool/41-53-67.maps\
	\
	./navigate  ./BigPool/41-53-68.maps ; \
	navigateChecker ./BigPool/41-53-68.maps\
	\
	./navigate  ./BigPool/41-53-69.maps ; \
	navigateChecker ./BigPool/41-53-69.maps\
	\
	./navigate  ./BigPool/41-53-70.maps ; \
	navigateChecker ./BigPool/41-53-70.maps\
	\
	./navigate  ./BigPool/41-53-71.maps ; \
	navigateChecker ./BigPool/41-53-71.maps\
	\
	./navigate  ./BigPool/41-53-72.maps ; \
	navigateChecker ./BigPool/41-53-72.maps\
	\
	./navigate  ./BigPool/41-53-73.maps ; \
	navigateChecker ./BigPool/41-53-73.maps\
	\
	./navigate  ./BigPool/41-53-xx.maps ; \
	navigateChecker ./BigPool/41-53-xx.maps
	
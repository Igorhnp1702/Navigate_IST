############################################# 
# Group 51's makefile
#
# Authors:
#
# Igor Paruque ist1102901
# Mónica Ferreira ist1106520
#############################################

CFLAGS = -Wall -std=c99 -O3 #flags to use

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
	valgrind --leak-check=full --show-leak-kinds=all ./navigate $(ARG).maps 

checktest:
	./navigate $(ARG).maps ; \
	navigateChecker $(ARG).maps
		
valall:
#girinos01; girinos02, crisalidas01; crisalidas02; minhocas01; minhocas02
#	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4001.maps ; \
	navigateChecker ./SmallPool/t4001.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4002.maps ; \
	navigateChecker ./SmallPool/t4002.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4003.maps ; \
	navigateChecker ./SmallPool/t4003.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4004.maps ; \
	navigateChecker ./SmallPool/t4004.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4005.maps ; \
	navigateChecker ./SmallPool/t4005.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4006.maps ; \
	navigateChecker ./SmallPool/t4006.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4007.maps ; \
	navigateChecker ./SmallPool/t4007.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4008.maps ; \
	navigateChecker ./SmallPool/t4008.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4009.maps ; \
	navigateChecker ./SmallPool/t4009.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4010.maps ; \
	navigateChecker ./SmallPool/t4010.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4011.maps ; \
	navigateChecker ./SmallPool/t4011.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4012.maps ; \
	navigateChecker ./SmallPool/t4012.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4013.maps ; \
	navigateChecker ./SmallPool/t4013.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4014.maps ; \
	navigateChecker ./SmallPool/t4014.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4015.maps ; \
	navigateChecker ./SmallPool/t4015.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4016.maps ; \
	navigateChecker ./SmallPool/t4016.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4017.maps ; \
	navigateChecker ./SmallPool/t4017.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4018.maps ; \
	navigateChecker ./SmallPool/t4018.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4019.maps ; \
	navigateChecker ./SmallPool/t4019.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4020.maps ; \
	navigateChecker ./SmallPool/t4020.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4021.maps ; \
	navigateChecker ./SmallPool/t4021.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4022.maps ; \
	navigateChecker ./SmallPool/t4022.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4023.maps ; \
	navigateChecker ./SmallPool/t4023.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4024.maps ; \
	navigateChecker ./SmallPool/t4024.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t4025.maps ; \
	navigateChecker ./SmallPool/t4025.maps
#	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5001.maps ; \
	navigateChecker ./SmallPool/t5001.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5002.maps ; \
	navigateChecker ./SmallPool/t5002.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5003.maps ; \
	navigateChecker ./SmallPool/t5003.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5004.maps ; \
	navigateChecker ./SmallPool/t5004.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5005.maps ; \
	navigateChecker ./SmallPool/t5005.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5006.maps ; \
	navigateChecker ./SmallPool/t5006.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5007.maps ; \
	navigateChecker ./SmallPool/t5007.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5008.maps ; \
	navigateChecker ./SmallPool/t5008.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5009.maps ; \
	navigateChecker ./SmallPool/t5009.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5010.maps ; \
	navigateChecker ./SmallPool/t5010.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5011.maps ; \
	navigateChecker ./SmallPool/t5011.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5012.maps ; \
	navigateChecker ./SmallPool/t5012.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5013.maps ; \
	navigateChecker ./SmallPool/t5013.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5014.maps ; \
	navigateChecker ./SmallPool/t5014.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5015.maps ; \
	navigateChecker ./SmallPool/t5015.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5016.maps ; \
	navigateChecker ./SmallPool/t5016.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5017.maps ; \
	navigateChecker ./SmallPool/t5017.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5018.maps ; \
	navigateChecker ./SmallPool/t5018.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5019.maps ; \
	navigateChecker ./SmallPool/t5019.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5020.maps ; \
	navigateChecker ./SmallPool/t5020.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5021.maps ; \
	navigateChecker ./SmallPool/t5021.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5022.maps ; \
	navigateChecker ./SmallPool/t5022.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5023.maps ; \
	navigateChecker ./SmallPool/t5023.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5024.maps ; \
	navigateChecker ./SmallPool/t5024.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5025.maps ; \
	navigateChecker ./SmallPool/t5025.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5026.maps ; \
	navigateChecker ./SmallPool/t5026.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5027.maps ; \
	navigateChecker ./SmallPool/t5027.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5028.maps ; \
	navigateChecker ./SmallPool/t5028.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/t5029.maps ; \
	navigateChecker ./SmallPool/t5029.maps ; 

	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-01.maps ; \
	navigateChecker ./SmallPool/41-53-16-01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-02.maps ; \
	navigateChecker ./SmallPool/41-53-16-02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-03.maps ; \
	navigateChecker ./SmallPool/41-53-16-03.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-04.maps ; \
	navigateChecker ./SmallPool/41-53-16-04.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-05.maps ; \
	navigateChecker ./SmallPool/41-53-16-05.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-06.maps ; \
	navigateChecker ./SmallPool/41-53-16-06.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-07.maps ; \
	navigateChecker ./SmallPool/41-53-16-07.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-08.maps ; \
	navigateChecker ./SmallPool/41-53-16-08.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-09.maps ; \
	navigateChecker ./SmallPool/41-53-16-09.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-10.maps ; \
	navigateChecker ./SmallPool/41-53-16-10.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-11.maps ; \
	navigateChecker ./SmallPool/41-53-16-11.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-12.maps ; \
	navigateChecker ./SmallPool/41-53-16-12.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-13.maps ; \
	navigateChecker ./SmallPool/41-53-16-13.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-14.maps ; \
	navigateChecker ./SmallPool/41-53-16-14.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-15.maps ; \
	navigateChecker ./SmallPool/41-53-16-15.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-16.maps ; \
	navigateChecker ./SmallPool/41-53-16-16.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-17.maps ; \
	navigateChecker ./SmallPool/41-53-16-17.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-18.maps ; \
	navigateChecker ./SmallPool/41-53-16-18.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-19.maps ; \
	navigateChecker ./SmallPool/41-53-16-19.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-20.maps ; \
	navigateChecker ./SmallPool/41-53-16-20.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-21.maps ; \
	navigateChecker ./SmallPool/41-53-16-21.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-22.maps ; \
	navigateChecker ./SmallPool/41-53-16-22.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-23.maps ; \
	navigateChecker ./SmallPool/41-53-16-23.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-24.maps ; \
	navigateChecker ./SmallPool/41-53-16-24.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-25.maps ; \
	navigateChecker ./SmallPool/41-53-16-25.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-26.maps ; \
	navigateChecker ./SmallPool/41-53-16-26.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-27.maps ; \
	navigateChecker ./SmallPool/41-53-16-27.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-28.maps ; \
	navigateChecker ./SmallPool/41-53-16-28.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-29.maps ; \
	navigateChecker ./SmallPool/41-53-16-29.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./SmallPool/41-53-16-30.maps ; \
	navigateChecker ./SmallPool/41-53-16-30.maps ; 
#ddd\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-00.maps ; \
	navigateChecker ./MediumPool/41-53-00.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-01.maps ; \
	navigateChecker ./MediumPool/41-53-01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-02.maps ; \
	navigateChecker ./MediumPool/41-53-02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-03.maps ; \
	navigateChecker ./MediumPool/41-53-03.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-04.maps ; \
	navigateChecker ./MediumPool/41-53-04.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-05.maps ; \
	navigateChecker ./MediumPool/41-53-05.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-06.maps ; \
	navigateChecker ./MediumPool/41-53-06.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-07.maps ; \
	navigateChecker ./MediumPool/41-53-07.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-08.maps ; \
	navigateChecker ./MediumPool/41-53-08.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-09.maps ; \
	navigateChecker ./MediumPool/41-53-09.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-10.maps ; \
	navigateChecker ./MediumPool/41-53-10.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-11.maps ; \
	navigateChecker ./MediumPool/41-53-11.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-12.maps ; \
	navigateChecker ./MediumPool/41-53-12.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-13.maps ; \
	navigateChecker ./MediumPool/41-53-13.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-14.maps ; \
	navigateChecker ./MediumPool/41-53-14.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-15.maps ; \
	navigateChecker ./MediumPool/41-53-15.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-16.maps ; \
	navigateChecker ./MediumPool/41-53-16.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-17.maps ; \
	navigateChecker ./MediumPool/41-53-17.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-18.maps ; \
	navigateChecker ./MediumPool/41-53-18.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-19.maps ; \
	navigateChecker ./MediumPool/41-53-19.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-20.maps ; \
	navigateChecker ./MediumPool/41-53-20.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-21.maps ; \
	navigateChecker ./MediumPool/41-53-21.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-22.maps ; \
	navigateChecker ./MediumPool/41-53-22.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-23.maps ; \
	navigateChecker ./MediumPool/41-53-23.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-24.maps ; \
	navigateChecker ./MediumPool/41-53-24.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-25.maps ; \
	navigateChecker ./MediumPool/41-53-25.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-26.maps ; \
	navigateChecker ./MediumPool/41-53-26.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-27.maps ; \
	navigateChecker ./MediumPool/41-53-27.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-28.maps ; \
	navigateChecker ./MediumPool/41-53-28.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-29.maps ; \
	navigateChecker ./MediumPool/41-53-29.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-30.maps ; \
	navigateChecker ./MediumPool/41-53-30.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-31.maps ; \
	navigateChecker ./MediumPool/41-53-31.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-32.maps ; \
	navigateChecker ./MediumPool/41-53-32.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-50.maps ; \
	navigateChecker ./MediumPool/41-53-50.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-51.maps ; \
	navigateChecker ./MediumPool/41-53-51.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-52.maps ; \
	navigateChecker ./MediumPool/41-53-52.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-53.maps ; \
	navigateChecker ./MediumPool/41-53-53.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-54.maps ; \
	navigateChecker ./MediumPool/41-53-54.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-55.maps ; \
	navigateChecker ./MediumPool/41-53-55.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-56.maps ; \
	navigateChecker ./MediumPool/41-53-56.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-57.maps ; \
	navigateChecker ./MediumPool/41-53-57.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-58.maps ; \
	navigateChecker ./MediumPool/41-53-58.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-59.maps ; \
	navigateChecker ./MediumPool/41-53-59.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-60.maps ; \
	navigateChecker ./MediumPool/41-53-60.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-61.maps ; \
	navigateChecker ./MediumPool/41-53-61.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-62.maps ; \
	navigateChecker ./MediumPool/41-53-62.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-63.maps ; \
	navigateChecker ./MediumPool/41-53-63.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-64.maps ; \
	navigateChecker ./MediumPool/41-53-64.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-65.maps ; \
	navigateChecker ./MediumPool/41-53-65.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-66.maps ; \
	navigateChecker ./MediumPool/41-53-66.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-67.maps ; \
	navigateChecker ./MediumPool/41-53-67.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-68.maps ; \
	navigateChecker ./MediumPool/41-53-68.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-69.maps ; \
	navigateChecker ./MediumPool/41-53-69.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-70.maps ; \
	navigateChecker ./MediumPool/41-53-70.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-71.maps ; \
	navigateChecker ./MediumPool/41-53-71.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-72.maps ; \
	navigateChecker ./MediumPool/41-53-72.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-73.maps ; \
	navigateChecker ./MediumPool/41-53-73.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./MediumPool/41-53-xx.maps ; \
	navigateChecker ./MediumPool/41-53-xx.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_01.maps ; \
	navigateChecker ./BigPool/250-250-30_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_02.maps ; \
	navigateChecker ./BigPool/250-250-30_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_03.maps ; \
	navigateChecker ./BigPool/250-250-30_03.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_04.maps ; \
	navigateChecker ./BigPool/250-250-30_04.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_05.maps ; \
	navigateChecker ./BigPool/250-250-30_05.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_06.maps ; \
	navigateChecker ./BigPool/250-250-30_06.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_07.maps ; \
	navigateChecker ./BigPool/250-250-30_07.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_08.maps ; \
	navigateChecker ./BigPool/250-250-30_08.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-30_09.maps ; \
	navigateChecker ./BigPool/250-250-30_09.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-101_01.maps ; \
	navigateChecker ./BigPool/250-250-101_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-101_02.maps ; \
	navigateChecker ./BigPool/250-250-101_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-121_01.maps ; \
	navigateChecker ./BigPool/250-250-121_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-121_02.maps ; \
	navigateChecker ./BigPool/250-250-121_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-141_01.maps ; \
	navigateChecker ./BigPool/250-250-141_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-141_02.maps ; \
	navigateChecker ./BigPool/250-250-141_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-161_01.maps ; \
	navigateChecker ./BigPool/250-250-161_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-161_02.maps ; \
	navigateChecker ./BigPool/250-250-161_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-181_01.maps ; \
	navigateChecker ./BigPool/250-250-181_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-201_01.maps ; \
	navigateChecker ./BigPool/250-250-201_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-221_01.maps ; \
	navigateChecker ./BigPool/250-250-221_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-221_02.maps ; \
	navigateChecker ./BigPool/250-250-221_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-241_01.maps ; \
	navigateChecker ./BigPool/250-250-241_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-241_02.maps ; \
	navigateChecker ./BigPool/250-250-241_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-261_01.maps ; \
	navigateChecker ./BigPool/250-250-261_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-261_02.maps ; \
	navigateChecker ./BigPool/250-250-261_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-281_01.maps ; \
	navigateChecker ./BigPool/250-250-281_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-301_01.maps ; \
	navigateChecker ./BigPool/250-250-301_01.maps ; \ 
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-301_02.maps ; \
	navigateChecker ./BigPool/250-250-301_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-321_01.maps ; \
	navigateChecker ./BigPool/250-250-321_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-321_02.maps ; \
	navigateChecker ./BigPool/250-250-321_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-341_01.maps ; \
	navigateChecker ./BigPool/250-250-341_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-341_02.maps ; \
	navigateChecker ./BigPool/250-250-341_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-361_01.maps ; \
	navigateChecker ./BigPool/250-250-361_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-361_02.maps ; \
	navigateChecker ./BigPool/250-250-361_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-381_01.maps ; \
	navigateChecker ./BigPool/250-250-381_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-381_02.maps ; \
	navigateChecker ./BigPool/250-250-381_02.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-401_01.maps ; \
	navigateChecker ./BigPool/250-250-401_01.maps ; \
	\
	valgrind --leak-check=full --show-leak-kinds=all ./BigPool/250-250-401_02.maps ; \
	navigateChecker ./BigPool/250-250-401_02.maps ;
	 					
checkall:
#\
	./navigate  ./SmallPool/t4001.maps ; \
	navigateChecker ./SmallPool/t4001.maps ; \
	\
	./navigate  ./SmallPool/t4002.maps ; \
	navigateChecker ./SmallPool/t4002.maps ; \
	\
	./navigate  ./SmallPool/t4003.maps ; \
	navigateChecker ./SmallPool/t4003.maps ; \
	\
	./navigate  ./SmallPool/t4004.maps ; \
	navigateChecker ./SmallPool/t4004.maps ; \
	\
	./navigate  ./SmallPool/t4005.maps ; \
	navigateChecker ./SmallPool/t4005.maps ; \
	\
	./navigate  ./SmallPool/t4006.maps ; \
	navigateChecker ./SmallPool/t4006.maps ; \
	\
	./navigate  ./SmallPool/t4007.maps ; \
	navigateChecker ./SmallPool/t4007.maps ; \
	\
	./navigate  ./SmallPool/t4008.maps ; \
	navigateChecker ./SmallPool/t4008.maps ; \
	\
	./navigate  ./SmallPool/t4009.maps ; \
	navigateChecker ./SmallPool/t4009.maps ; \
	\
	./navigate  ./SmallPool/t4010.maps ; \
	navigateChecker ./SmallPool/t4010.maps ; \
	\
	./navigate  ./SmallPool/t4011.maps ; \
	navigateChecker ./SmallPool/t4011.maps ; \
	\
	./navigate  ./SmallPool/t4012.maps ; \
	navigateChecker ./SmallPool/t4012.maps ; \
	\
	./navigate  ./SmallPool/t4013.maps ; \
	navigateChecker ./SmallPool/t4013.maps ; \
	\
	./navigate  ./SmallPool/t4014.maps ; \
	navigateChecker ./SmallPool/t4014.maps ; \
	\
	./navigate  ./SmallPool/t4015.maps ; \
	navigateChecker ./SmallPool/t4015.maps ; \
	\
	./navigate  ./SmallPool/t4016.maps ; \
	navigateChecker ./SmallPool/t4016.maps ; \
	\
	./navigate  ./SmallPool/t4017.maps ; \
	navigateChecker ./SmallPool/t4017.maps ; \
	\
	./navigate  ./SmallPool/t4018.maps ; \
	navigateChecker ./SmallPool/t4018.maps ; \
	\
	./navigate  ./SmallPool/t4019.maps ; \
	navigateChecker ./SmallPool/t4019.maps ; \
	\
	./navigate  ./SmallPool/t4020.maps ; \
	navigateChecker ./SmallPool/t4020.maps ; \
	\
	./navigate  ./SmallPool/t4021.maps ; \
	navigateChecker ./SmallPool/t4021.maps ; \
	\
	./navigate  ./SmallPool/t4022.maps ; \
	navigateChecker ./SmallPool/t4022.maps ; \
	\
	./navigate  ./SmallPool/t4023.maps ; \
	navigateChecker ./SmallPool/t4023.maps ; \
	\
	./navigate  ./SmallPool/t4024.maps ; \
	navigateChecker ./SmallPool/t4024.maps ; \
	\
	./navigate  ./SmallPool/t4025.maps ; \
	navigateChecker ./SmallPool/t4025.maps ; \
	\
	./navigate  ./SmallPool/t5001.maps ; \
	navigateChecker ./SmallPool/t5001.maps ; \
	\
	./navigate  ./SmallPool/t5002.maps ; \
	navigateChecker ./SmallPool/t5002.maps ; \
	\
	./navigate  ./SmallPool/t5003.maps ; \
	navigateChecker ./SmallPool/t5003.maps ; \
	\
	./navigate  ./SmallPool/t5004.maps ; \
	navigateChecker ./SmallPool/t5004.maps ; \
	\
	./navigate  ./SmallPool/t5005.maps ; \
	navigateChecker ./SmallPool/t5005.maps ; \
	\
	./navigate  ./SmallPool/t5006.maps ; \
	navigateChecker ./SmallPool/t5006.maps ; \
	\
	./navigate  ./SmallPool/t5007.maps ; \
	navigateChecker ./SmallPool/t5007.maps ; \
	\
	./navigate  ./SmallPool/t5008.maps ; \
	navigateChecker ./SmallPool/t5008.maps ; \
	\
	./navigate  ./SmallPool/t5009.maps ; \
	navigateChecker ./SmallPool/t5009.maps ; \
	\
	./navigate  ./SmallPool/t5010.maps ; \
	navigateChecker ./SmallPool/t5010.maps ; \
	\
	./navigate  ./SmallPool/t5011.maps ; \
	navigateChecker ./SmallPool/t5011.maps ; \
	\
	./navigate  ./SmallPool/t5012.maps ; \
	navigateChecker ./SmallPool/t5012.maps ; \
	\
	./navigate  ./SmallPool/t5013.maps ; \
	navigateChecker ./SmallPool/t5013.maps ; \
	\
	./navigate  ./SmallPool/t5014.maps ; \
	navigateChecker ./SmallPool/t5014.maps ; \
	\
	./navigate  ./SmallPool/t5015.maps ; \
	navigateChecker ./SmallPool/t5015.maps ; \
	\
	./navigate  ./SmallPool/t5016.maps ; \
	navigateChecker ./SmallPool/t5016.maps ; \
	\
	./navigate  ./SmallPool/t5017.maps ; \
	navigateChecker ./SmallPool/t5017.maps ; \
	\
	./navigate  ./SmallPool/t5018.maps ; \
	navigateChecker ./SmallPool/t5018.maps ; \
	\
	./navigate  ./SmallPool/t5019.maps ; \
	navigateChecker ./SmallPool/t5019.maps ; \
	\
	./navigate  ./SmallPool/t5020.maps ; \
	navigateChecker ./SmallPool/t5020.maps ; \
	\
	./navigate  ./SmallPool/t5021.maps ; \
	navigateChecker ./SmallPool/t5021.maps ; \
	\
	./navigate  ./SmallPool/t5022.maps ; \
	navigateChecker ./SmallPool/t5022.maps ; \
	\
	./navigate  ./SmallPool/t5023.maps ; \
	navigateChecker ./SmallPool/t5023.maps ; \
	\
	./navigate  ./SmallPool/t5024.maps ; \
	navigateChecker ./SmallPool/t5024.maps ; \
	\
	./navigate  ./SmallPool/t5025.maps ; \
	navigateChecker ./SmallPool/t5025.maps ; \
	\
	./navigate  ./SmallPool/t5026.maps ; \
	navigateChecker ./SmallPool/t5026.maps ; \
	\
	./navigate  ./SmallPool/t5027.maps ; \
	navigateChecker ./SmallPool/t5027.maps ; \
	\
	./navigate  ./SmallPool/t5028.maps ; \
	navigateChecker ./SmallPool/t5028.maps ; \
	\
	./navigate  ./SmallPool/t5029.maps ; \
	navigateChecker ./SmallPool/t5029.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-01.maps ; \
	navigateChecker ./SmallPool/41-53-16-01.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-02.maps ; \
	navigateChecker ./SmallPool/41-53-16-02.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-03.maps ; \
	navigateChecker ./SmallPool/41-53-16-03.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-04.maps ; \
	navigateChecker ./SmallPool/41-53-16-04.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-05.maps ; \
	navigateChecker ./SmallPool/41-53-16-05.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-06.maps ; \
	navigateChecker ./SmallPool/41-53-16-06.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-07.maps ; \
	navigateChecker ./SmallPool/41-53-16-07.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-08.maps ; \
	navigateChecker ./SmallPool/41-53-16-08.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-09.maps ; \
	navigateChecker ./SmallPool/41-53-16-09.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-10.maps ; \
	navigateChecker ./SmallPool/41-53-16-10.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-11.maps ; \
	navigateChecker ./SmallPool/41-53-16-11.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-12.maps ; \
	navigateChecker ./SmallPool/41-53-16-12.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-13.maps ; \
	navigateChecker ./SmallPool/41-53-16-13.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-14.maps ; \
	navigateChecker ./SmallPool/41-53-16-14.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-15.maps ; \
	navigateChecker ./SmallPool/41-53-16-15.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-16.maps ; \
	navigateChecker ./SmallPool/41-53-16-16.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-17.maps ; \
	navigateChecker ./SmallPool/41-53-16-17.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-18.maps ; \
	navigateChecker ./SmallPool/41-53-16-18.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-19.maps ; \
	navigateChecker ./SmallPool/41-53-16-19.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-20.maps ; \
	navigateChecker ./SmallPool/41-53-16-20.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-21.maps ; \
	navigateChecker ./SmallPool/41-53-16-21.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-22.maps ; \
	navigateChecker ./SmallPool/41-53-16-22.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-23.maps ; \
	navigateChecker ./SmallPool/41-53-16-23.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-24.maps ; \
	navigateChecker ./SmallPool/41-53-16-24.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-25.maps ; \
	navigateChecker ./SmallPool/41-53-16-25.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-26.maps ; \
	navigateChecker ./SmallPool/41-53-16-26.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-27.maps ; \
	navigateChecker ./SmallPool/41-53-16-27.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-28.maps ; \
	navigateChecker ./SmallPool/41-53-16-28.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-29.maps ; \
	navigateChecker ./SmallPool/41-53-16-29.maps ; \
	\
	./navigate  ./SmallPool/41-53-16-30.maps ; \
	navigateChecker ./SmallPool/41-53-16-30.maps ;  \
	\
	./navigate  ./MediumPool/41-53-00.maps ; \
	navigateChecker ./MediumPool/41-53-00.maps ; \
	\
	./navigate  ./MediumPool/41-53-01.maps ; \
	navigateChecker ./MediumPool/41-53-01.maps ; \
	\
	./navigate  ./MediumPool/41-53-02.maps ; \
	navigateChecker ./MediumPool/41-53-02.maps ; \
	\
	./navigate  ./MediumPool/41-53-03.maps ; \
	navigateChecker ./MediumPool/41-53-03.maps ; \
	\
	./navigate  ./MediumPool/41-53-04.maps ; \
	navigateChecker ./MediumPool/41-53-04.maps ; \
	\
	./navigate  ./MediumPool/41-53-05.maps ; \
	navigateChecker ./MediumPool/41-53-05.maps ; \
	\
	./navigate  ./MediumPool/41-53-06.maps ; \
	navigateChecker ./MediumPool/41-53-06.maps ; \
	\
	./navigate  ./MediumPool/41-53-07.maps ; \
	navigateChecker ./MediumPool/41-53-07.maps ; \
	\
	./navigate  ./MediumPool/41-53-08.maps ; \
	navigateChecker ./MediumPool/41-53-08.maps ; \
	\
	./navigate  ./MediumPool/41-53-09.maps ; \
	navigateChecker ./MediumPool/41-53-09.maps ; \
	\
	./navigate  ./MediumPool/41-53-10.maps ; \
	navigateChecker ./MediumPool/41-53-10.maps ; \
	\
	./navigate  ./MediumPool/41-53-11.maps ; \
	navigateChecker ./MediumPool/41-53-11.maps ; \
	\
	./navigate  ./MediumPool/41-53-12.maps ; \
	navigateChecker ./MediumPool/41-53-12.maps ; \
	\
	./navigate  ./MediumPool/41-53-13.maps ; \
	navigateChecker ./MediumPool/41-53-13.maps ; \
	\
	./navigate  ./MediumPool/41-53-14.maps ; \
	navigateChecker ./MediumPool/41-53-14.maps ; \
	\
	./navigate  ./MediumPool/41-53-15.maps ; \
	navigateChecker ./MediumPool/41-53-15.maps ; \
	\
	./navigate  ./MediumPool/41-53-16.maps ; \
	navigateChecker ./MediumPool/41-53-16.maps ; \
	\
	./navigate  ./MediumPool/41-53-17.maps ; \
	navigateChecker ./MediumPool/41-53-17.maps ; \
	\
	./navigate  ./MediumPool/41-53-18.maps ; \
	navigateChecker ./MediumPool/41-53-18.maps ; \
	\
	./navigate  ./MediumPool/41-53-19.maps ; \
	navigateChecker ./MediumPool/41-53-19.maps ; \
	\
	./navigate  ./MediumPool/41-53-20.maps ; \
	navigateChecker ./MediumPool/41-53-20.maps ; \
	\
	./navigate  ./MediumPool/41-53-21.maps ; \
	navigateChecker ./MediumPool/41-53-21.maps ; \
	\
	./navigate  ./MediumPool/41-53-22.maps ; \
	navigateChecker ./MediumPool/41-53-22.maps ; \
	\
	./navigate  ./MediumPool/41-53-23.maps ; \
	navigateChecker ./MediumPool/41-53-23.maps ; \
	\
	./navigate  ./MediumPool/41-53-24.maps ; \
	navigateChecker ./MediumPool/41-53-24.maps ; \
	\
	./navigate  ./MediumPool/41-53-25.maps ; \
	navigateChecker ./MediumPool/41-53-25.maps ; \
	\
	./navigate  ./MediumPool/41-53-26.maps ; \
	navigateChecker ./MediumPool/41-53-26.maps ; \
	\
	./navigate  ./MediumPool/41-53-27.maps ; \
	navigateChecker ./MediumPool/41-53-27.maps ; \
	\
	./navigate  ./MediumPool/41-53-28.maps ; \
	navigateChecker ./MediumPool/41-53-28.maps ; \
	\
	./navigate  ./MediumPool/41-53-29.maps ; \
	navigateChecker ./MediumPool/41-53-29.maps ; \
	\
	./navigate  ./MediumPool/41-53-30.maps ; \
	navigateChecker ./MediumPool/41-53-30.maps ; \
	\
	./navigate  ./MediumPool/41-53-31.maps ; \
	navigateChecker ./MediumPool/41-53-31.maps ; \
	\
	./navigate  ./MediumPool/41-53-32.maps ; \
	navigateChecker ./MediumPool/41-53-32.maps ; \
	\
	./navigate  ./MediumPool/41-53-50.maps ; \
	navigateChecker ./MediumPool/41-53-50.maps ; \
	\
	./navigate  ./MediumPool/41-53-51.maps ; \
	navigateChecker ./MediumPool/41-53-51.maps ; \
	\
	./navigate  ./MediumPool/41-53-52.maps ; \
	navigateChecker ./MediumPool/41-53-52.maps ; \
	\
	./navigate  ./MediumPool/41-53-53.maps ; \
	navigateChecker ./MediumPool/41-53-53.maps ; \
	\
	./navigate  ./MediumPool/41-53-54.maps ; \
	navigateChecker ./MediumPool/41-53-54.maps ; \
	\
	./navigate  ./MediumPool/41-53-55.maps ; \
	navigateChecker ./MediumPool/41-53-55.maps ; \
	\
	./navigate  ./MediumPool/41-53-56.maps ; \
	navigateChecker ./MediumPool/41-53-56.maps ; \
	\
	./navigate  ./MediumPool/41-53-57.maps ; \
	navigateChecker ./MediumPool/41-53-57.maps ; \
	\
	./navigate  ./MediumPool/41-53-58.maps ; \
	navigateChecker ./MediumPool/41-53-58.maps ; \
	\
	./navigate  ./MediumPool/41-53-59.maps ; \
	navigateChecker ./MediumPool/41-53-59.maps ; \
	\
	./navigate  ./MediumPool/41-53-60.maps ; \
	navigateChecker ./MediumPool/41-53-60.maps ; \
	\
	./navigate  ./MediumPool/41-53-61.maps ; \
	navigateChecker ./MediumPool/41-53-61.maps ; \
	\
	./navigate  ./MediumPool/41-53-62.maps ; \
	navigateChecker ./MediumPool/41-53-62.maps ; \
	\
	./navigate  ./MediumPool/41-53-63.maps ; \
	navigateChecker ./MediumPool/41-53-63.maps ; \
	\
	./navigate  ./MediumPool/41-53-64.maps ; \
	navigateChecker ./MediumPool/41-53-64.maps ; \
	\
	./navigate  ./MediumPool/41-53-65.maps ; \
	navigateChecker ./MediumPool/41-53-65.maps ; \
	\
	./navigate  ./MediumPool/41-53-66.maps ; \
	navigateChecker ./MediumPool/41-53-66.maps ; \
	\
	./navigate  ./MediumPool/41-53-67.maps ; \
	navigateChecker ./MediumPool/41-53-67.maps ; \
	\
	./navigate  ./MediumPool/41-53-68.maps ; \
	navigateChecker ./MediumPool/41-53-68.maps ; \
	\
	./navigate  ./MediumPool/41-53-69.maps ; \
	navigateChecker ./MediumPool/41-53-69.maps ; \
	\
	./navigate  ./MediumPool/41-53-70.maps ; \
	navigateChecker ./MediumPool/41-53-70.maps ; \
	\
	./navigate  ./MediumPool/41-53-71.maps ; \
	navigateChecker ./MediumPool/41-53-71.maps ; \
	\
	./navigate  ./MediumPool/41-53-72.maps ; \
	navigateChecker ./MediumPool/41-53-72.maps ; \
	\
	./navigate  ./MediumPool/41-53-73.maps ; \
	navigateChecker ./MediumPool/41-53-73.maps ; \
	\
	./navigate  ./MediumPool/41-53-xx.maps ; \
	navigateChecker ./MediumPool/41-53-xx.maps ; \
	\
	./navigate ./BigPool/250-250-30_01.maps ; \
	navigateChecker ./BigPool/250-250-30_01.maps ; \
	\
	./navigate ./BigPool/250-250-30_02.maps ; \
	navigateChecker ./BigPool/250-250-30_02.maps ; \
	\
	./navigate ./BigPool/250-250-30_03.maps ; \
	navigateChecker ./BigPool/250-250-30_03.maps ; \
	\
	./navigate ./BigPool/250-250-30_04.maps ; \
	navigateChecker ./BigPool/250-250-30_04.maps ; \
	\
	./navigate ./BigPool/250-250-30_05.maps ; \
	navigateChecker ./BigPool/250-250-30_05.maps ; \
	\
	./navigate ./BigPool/250-250-30_06.maps ; \
	navigateChecker ./BigPool/250-250-30_06.maps ; \
	\
	./navigate ./BigPool/250-250-30_07.maps ; \
	navigateChecker ./BigPool/250-250-30_07.maps ; \
	\
	./navigate ./BigPool/250-250-30_08.maps ; \
	navigateChecker ./BigPool/250-250-30_08.maps ; \
	\
	./navigate ./BigPool/250-250-30_09.maps ; \
	navigateChecker ./BigPool/250-250-30_09.maps ; \
	\
	./navigate ./BigPool/250-250-101_01.maps ; \
	navigateChecker ./BigPool/250-250-101_01.maps ; \
	\
	./navigate ./BigPool/250-250-101_02.maps ; \
	navigateChecker ./BigPool/250-250-101_02.maps ; \
	\
	./navigate ./BigPool/250-250-121_01.maps ; \
	navigateChecker ./BigPool/250-250-121_01.maps ; \
	\
	./navigate ./BigPool/250-250-121_02.maps ; \
	navigateChecker ./BigPool/250-250-121_02.maps ; \
	\
	./navigate ./BigPool/250-250-141_01.maps ; \
	navigateChecker ./BigPool/250-250-141_01.maps ; \
	\
	./navigate ./BigPool/250-250-141_02.maps ; \
	navigateChecker ./BigPool/250-250-141_02.maps ; \
	\
	./navigate ./BigPool/250-250-161_01.maps ; \
	navigateChecker ./BigPool/250-250-161_01.maps ; \
	\
	./navigate ./BigPool/250-250-161_02.maps ; \
	navigateChecker ./BigPool/250-250-161_02.maps ; \
	\
	./navigate ./BigPool/250-250-181_01.maps ; \
	navigateChecker ./BigPool/250-250-181_01.maps ; \
	\
	./navigate ./BigPool/250-250-201_01.maps ; \
	navigateChecker ./BigPool/250-250-201_01.maps ; \
	\
	./navigate ./BigPool/250-250-221_01.maps ; \
	navigateChecker ./BigPool/250-250-221_01.maps ; \
	\
	./navigate ./BigPool/250-250-221_02.maps ; \
	navigateChecker ./BigPool/250-250-221_02.maps ; \
	\
	./navigate ./BigPool/250-250-241_01.maps ; \
	navigateChecker ./BigPool/250-250-241_01.maps ; \
	\
	./navigate ./BigPool/250-250-241_02.maps ; \
	navigateChecker ./BigPool/250-250-241_02.maps ; \
	\
	./navigate ./BigPool/250-250-261_01.maps ; \
	navigateChecker ./BigPool/250-250-261_01.maps ; \
	\
	./navigate ./BigPool/250-250-261_02.maps ; \
	navigateChecker ./BigPool/250-250-261_02.maps ; \
	\
	./navigate ./BigPool/250-250-281_01.maps ; \
	navigateChecker ./BigPool/250-250-281_01.maps ; \
	\
	./navigate ./BigPool/250-250-301_01.maps ; \
	navigateChecker ./BigPool/250-250-301_01.maps ; \
	\
	./navigate ./BigPool/250-250-301_02.maps ; \
	navigateChecker ./BigPool/250-250-301_02.maps ; \
	\
	./navigate ./BigPool/250-250-321_01.maps ; \
	navigateChecker ./BigPool/250-250-321_01.maps ; \
	\
	./navigate ./BigPool/250-250-321_02.maps ; \
	navigateChecker ./BigPool/250-250-321_02.maps ; \
	\
	./navigate ./BigPool/250-250-341_01.maps ; \
	navigateChecker ./BigPool/250-250-341_01.maps ; \
	\
	./navigate ./BigPool/250-250-341_02.maps ; \
	navigateChecker ./BigPool/250-250-341_02.maps ; \
	\
	./navigate ./BigPool/250-250-361_01.maps ; \
	navigateChecker ./BigPool/250-250-361_01.maps ; \
	\
	./navigate ./BigPool/250-250-361_02.maps ; \
	navigateChecker ./BigPool/250-250-361_02.maps ; \
	\
	./navigate ./BigPool/250-250-381_01.maps ; \
	navigateChecker ./BigPool/250-250-381_01.maps ; \
	\
	./navigate ./BigPool/250-250-381_02.maps ; \
	navigateChecker ./BigPool/250-250-381_02.maps ; \
	\
	./navigate ./BigPool/250-250-401_01.maps ; \
	navigateChecker ./BigPool/250-250-401_01.maps ; \
	\
	./navigate ./BigPool/250-250-401_02.maps ; \
	navigateChecker ./BigPool/250-250-401_02.maps ; 

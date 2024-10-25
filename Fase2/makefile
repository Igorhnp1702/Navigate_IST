############################################# 
# Group 51's makefile
#
# Authors:
#
# Igor Paruque ist1102901
# Mónica Ferreira ist1106520
#############################################

DEBUGFLAGS = -Wall -std=c99 -g 
BESTFLAGS = -Wall -std=c99 -O3 
PROFFLAGS = -Wall -std=c99 -O3 -pg 

FILES = $(shell ls ./MediumPool/*.maps)
VALG = valgrind --leak-check=full -s

navigate: IOmodule.o Stack.o problem.o main.o    # default compilation
	gcc $(BESTFLAGS) -o navigate main.o IOmodule.o problem.o Stack.o

IOmodule.o: IOmodule.h IOmodule.c
	gcc $(BESTFLAGS) -c IOmodule.c

Stack.o: Items.h Stack.h Stack.c
	gcc $(BESTFLAGS) -c Stack.c
		
problem.o: Items.h Stack.h problem.h problem.c 
	gcc $(BESTFLAGS) -c problem.c

main.o: structs.h IOmodule.h problem.h main.c
	gcc $(BESTFLAGS) -c main.c

debugcomp: debugnavigate debugIOmodule debugStack debugproblem debugmain

debugnavigate: debugIOmodule debugStack debugproblem debugmain    #debug compilation
	gcc $(DEBUGFLAGS) -o navigate main.o IOmodule.o problem.o Stack.o

debugIOmodule: IOmodule.h IOmodule.c
	gcc $(DEBUGFLAGS) -c IOmodule.c

debugStack: Items.h Stack.h Stack.c
	gcc $(DEBUGFLAGS) -c Stack.c
		
debugproblem: Items.h Stack.h problem.h problem.c 
	gcc $(DEBUGFLAGS) -c problem.c

debugmain: structs.h IOmodule.h problem.h main.c
	gcc $(DEBUGFLAGS) -c main.c

profcomp: profnavigate profIOmodule profStack profproblem profmain 

profnavigate: profIOmodule profStack profproblem profmain    # profiler compilation
	gcc $(PROFFLAGS) -o navigate main.o IOmodule.o problem.o Stack.o

profIOmodule: IOmodule.h IOmodule.c
	gcc $(PROFFLAGS) -c IOmodule.c

profStack: Items.h Stack.h Stack.c
	gcc $(PROFFLAGS) -c Stack.c
		
profproblem: Items.h Stack.h problem.h problem.c 
	gcc $(PROFFLAGS) -c problem.c

profmain: structs.h IOmodule.h problem.h main.c
	gcc $(PROFFLAGS) -c main.c

checktest:
	./navigate $(ARG).maps ; \
	navigateChecker $(ARG).maps

valtest: 
	valgrind --leak-check=full --show-leak-kinds=all ./navigate $(ARG).maps 

timetest:
	time -p ./navigate $(ARG).maps

prof: profcomp
	./navigate $(ARG).maps ; \
	gprof navigate gmon.out > prof.txt ; \
	code prof.txt ; \
	

runcheck: runall checkall

timecheck: timeall checkall

valall:
	$(foreach F,$(FILES), valgrind --leak-check=full ./navigate $(F); sleep 1;)

checkall:
	$(foreach F,$(FILES), echo $(F) ; navigateChecker $(F);)

runall:
	$(foreach F,$(FILES), ./navigate $(F);)

timeall:
	$(foreach F,$(FILES), echo $(F) ; time  -p ./navigate $(F) ; sleep 0.5 ;)

clean: # clean object files	
	rm *.o

cleanprof:
	rm gmon.out
	rm prof.txt


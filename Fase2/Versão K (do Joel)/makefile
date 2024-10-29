CC = gcc

DEBUGFLAGS = -Wall -std=c99 -g 
BESTFLAGS = -Wall -std=c99 -O3 
PROFFLAGS = -Wall -std=c99 -O3 -pg 

FILES = $(shell ls ./*/*.maps)
VALG = valgrind --leak-check=full -s

navigate: main.o file.o tasks.o
	$(CC) $(BESTFLAGS) -o navigate main.o file.o tasks.o

main.o: main.c file.h tasks.h
	$(CC) $(BESTFLAGS) -c main.c

file.o: file.c file.h tasks.h
	$(CC) $(BESTFLAGS) -c file.c

tasks.o: tasks.c tasks.h
	$(CC) $(BESTFLAGS) -c tasks.c

debugcomp: debugnavigate 

debugnavigate: debugmain debugfile debugtasks
	$(CC) $(DEBUGFLAGS) -o navigate main.o file.o tasks.o

debugmain: main.c file.h tasks.h
	$(CC) $(DEBUGFLAGS) -c main.c

debugfile: file.c file.h tasks.h
	$(CC) $(DEBUGFLAGS) -c file.c

debugtasks: tasks.c tasks.h
	$(CC) $(DEBUGFLAGS) -c tasks.c 

profcomp: profnavigate

profnavigate: profmain proffile proftasks
	$(CC) $(PROFFLAGS) -o navigate main.o file.o tasks.o

profmain: main.c file.h tasks.h
	$(CC) $(PROFFLAGS) -c main.c

proffile: file.c file.h tasks.h
	$(CC) $(PROFFLAGS) -c file.c

proftasks: tasks.c tasks.h
	$(CC) $(PROFFLAGS) -c tasks.c

valtest: 
	valgrind --leak-check=full --show-leak-kinds=all ./navigate $(ARG).maps 

timetest:
	echo ./Minhocas02/41-53-73.maps ; \
	time -p ./navigate ./Minhocas02/41-53-73.maps ; sleep 1 ; \
	echo ./Tarantulas/250-250-241_02.maps ; \
	time -p ./navigate ./Tarantulas/250-250-241_02.maps

prof: profcomp
	./navigate $(ARG).maps ; \
	gprof navigate gmon.out > prof.txt ; \
	code prof.txt 

runcheck: runall checkall

timecheck: timeall checkall

valall:
	$(foreach F,$(FILES), valgrind --leak-check=full ./navigate $(F) ; sleep 1 ; )

checkall:
	$(foreach F,$(FILES), echo $(F) ; navigateChecker $(F) ; ) 

runall:
	$(foreach F,$(FILES), ./navigate $(F) ; )

timeall:
	$(foreach F,$(FILES), echo $(F) ; time  -p ./navigate $(F) ; echo ; sleep 0.5 ; )

clean: # clean object files	
	rm *.o

cleanprof:
	rm gmon.out
	rm prof.txt

compcleanruncheckprof: navigate clean runcheck timetest profcomp # compile, clean run and check
	./navigate ./Minhocas02/41-53-73.maps ; \
	gprof navigate gmon.out > worstMinhocas.txt ; \
	code worstMinhocas.txt ; \
	./navigate ./Tarantulas/250-250-241_02.maps ; \
	gprof navigate gmon.out > worstTarantulas.txt ; \
	code worstTarantulas.txt 
	rm *.o gmon.out navigate



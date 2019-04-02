FLAGS = -g
SRC =  main.cpp readRef.cpp 

all: main

main: main.o readRef.o
	icpc $(FLAGS) $^ -o $@

.cpp.o:
	icpc $(FLAGS) -Wall -c $<

#.c.o:
#	icc $(FLAGS) -Wall -c $<

clean:
	rm -f *.o main

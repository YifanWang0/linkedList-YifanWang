all: enlist_main.o enlist_func.o
	gcc -o program enlist_main.o enlist_func.o

enlist_main.o: enlist_main.c enlist_header.h
	gcc -c enlist_main.c

enlist_func.o: enlist_func.c enlist_header.h
	gcc -c enlist_func.c

run:
	./program

clean:
	rm *.o
	rm *~

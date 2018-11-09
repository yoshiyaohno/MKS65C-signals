all : yahoo.o
	gcc -o yahoo yahoo.o

yahoo.o : yahoo.c
	gcc -c yahoo.c

run :
	./yahoo

clean :
	rm yahoo *.o

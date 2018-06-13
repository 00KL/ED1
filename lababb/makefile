all: lababb

lababb: abb.o cliente.o
	gcc -o lababb abb.o cliente.o && rm -f *.o && rm -f *gch && mv lababb exe && ./exe

abb.o: abb.c
	gcc -c abb.c

cliente.o: cliente.o
	gcc -c cliente.c

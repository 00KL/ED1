all: lababb

lababb: abb.o cliente.o
	gcc -o lababb abb.o cliente.o

abb.o: abb.c
	gcc -c abb.c

cliente.o: cliente.o
	gcc -c cliente.c

clean: 
	rm -rf *.o && rm -rf *gch && mv lababb exe && ./exe

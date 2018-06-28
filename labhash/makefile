all: exe limpa

exe: cliente.o hash.o
	gcc -o exe hash.o cliente.o

cliente.o: cliente.c
	gcc -c cliente.c

hash.o: hash.c
	gcc -c hash.c

limpa:
	rm -f *.o *.h.gch

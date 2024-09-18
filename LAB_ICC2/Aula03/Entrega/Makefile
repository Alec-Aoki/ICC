all: main.o pilhaEncadeada.o item.o
	gcc main.o pilhaEncadeada.o item.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c

pilhaEncadeada.o:
	gcc -c pilhaEncadeada.c

main.o:
	gcc -c main.c

clean:
	rm *.o main
	clear

run:
	./main

zip:
	zip -R entrega.zip . '*.c' '*.h' 'Makefile'

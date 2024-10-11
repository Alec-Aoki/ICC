all: main.o 
	gcc main.o -o main -std=c99 -Wall

main.o:
	gcc -c main.c

clean:
	rm *.o main

run:
	./main

zip:
	zip -R entrega.zip . 'main.c' 'Makefile'
all: queue.o radixsort.o
	gcc queue.o radixsort.o -o radixsort -std=c99 -Wall

queue.o:
	gcc -c queue.c -o queue.o

radixsort.o:
	gcc -c radixsort.c -o radixsort.o

clean:
	-rm *.o radixsort

run:
	./radixsort
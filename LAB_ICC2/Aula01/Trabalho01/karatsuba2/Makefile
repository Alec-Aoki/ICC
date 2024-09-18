all: operacoes.o atividade.o
	gcc atividade.o operacoes.o -std=c99 -o karatsuba -Wall
operacoes.o:
	gcc -c operacoes.c -o operacoes.o
atividade.o:
	gcc -c atividade.c -o atividade.o
clean:
	rm *.o karatsuba
run:
	./karatsuba
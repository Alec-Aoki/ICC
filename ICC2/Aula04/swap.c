#include <stdio.h>
#include <string.h>

typedef struct{
    int chave;
    char valor[10];
}str_t;

void swap(str_t *a, str_t *b);

int main(void){
    str_t a, b;

    a.chave = 2;
    strcpy(a.valor, "aaa");

    b.chave = 3;
    strcpy(b.valor, "bbb");

    swap(&a, &b);

    printf("%d %s\n", a.chave, a.valor);
    printf("%d %s\n", b.chave, b.valor);

    return 0;
}

void swap(str_t *a, str_t *b){
    str_t aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
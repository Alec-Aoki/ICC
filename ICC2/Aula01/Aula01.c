#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*GERANDO UMA LISTA DE NÚMEROS ALEATÓRIOS*/

void printarLista(int *pont_lista, int tam_Lista);


int main(void){
    int *pont_listaNumeros; //ponteiro que aponta para a lista de numeros, alocada dinamicamente
    int tamanho_listaNumeros;

    //gera uma seed a partir do horário (logo, é única)
    srand(time(NULL));

    printf("Digite o tamanho da lista de numeros:\n");
    scanf("%d", &tamanho_listaNumeros);

    pont_listaNumeros = (int *)malloc(tamanho_listaNumeros*sizeof(int));
    if(pont_listaNumeros == NULL) exit(1);

    for(int i=0; i<tamanho_listaNumeros; i++){
        pont_listaNumeros[i] = rand();
    }

    printarLista(pont_listaNumeros, tamanho_listaNumeros);

    free(pont_listaNumeros);
    pont_listaNumeros = NULL;

    return 0;
}

/*FUNÇÕES*/

void printarLista(int *pont_lista, int tam_Lista){
    for(int i=0; i<tam_Lista; i++){
        printf("%d\n", pont_lista[i]);
    }

    return;
}
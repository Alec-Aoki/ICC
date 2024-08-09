/*GERANDO UMA LISTA DE NÚMEROS ALEATÓRIOS*/
/*FAZER OPÇÃO DE GRAVAR EM TEXTO OU BINÁRIO*/

/*BIBLIOTECAS*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*STRUCTS*/
typedef struct{
    int *pont; //ponteiro que aponta para a lista de numeros, alocada dinamicamente
    int tamanho; //quantidade de elementos na lista
}lista;

/*PROTOTIPAGEM DAS FUNÇÕES*/
//void printarLista(int *pont_lista, int tam_Lista);
void escreverArquivo(lista listaAleatoria);

/*MAIN*/
int main(void){
    lista listaAleatoria;

    //gera uma seed a partir do horário (logo, é única)
    srand(time(NULL));

    printf("Digite o tamanho da lista de numeros:\n");
    scanf("%d", &listaAleatoria.tamanho);

    listaAleatoria.pont = (int *)malloc(listaAleatoria.tamanho*sizeof(int));
    if(listaAleatoria.pont == NULL) exit(1);

    for(int i=0; i<listaAleatoria.tamanho; i++){
        listaAleatoria.pont[i] = rand();
    }

    escreverArquivo(listaAleatoria);

    free(listaAleatoria.pont);
    listaAleatoria.pont = NULL;

    return 0;
}

/*FUNÇÕES*/
// void printarLista(int *pont_lista, int tam_Lista){
//     for(int i=0; i<tam_Lista; i++){
//         printf("%d\n", pont_lista[i]);
//     }

//     return;
// }

void escreverArquivo(lista listaAleatoria){
    FILE *fp;
    fp = fopen("arquivoListaAleatoria.bin", "wb");

    if(fp == NULL){
        printf("Erro ao abrir arquivo!\n");
    }

    fwrite(listaAleatoria.pont, sizeof(int), listaAleatoria.tamanho, fp);

    fclose(fp);
    fp = NULL;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ERRO -1;

typedef struct no_ NO;
typedef struct lista_ LISTA;
typedef struct aluno_ ALUNO;

struct no_{
    ALUNO *aluno;
    NO *noSeguinte;
    NO *noParalelo;
};

struct lista_{
    NO *inicio;
    NO *fim;
    int tamanho;
};

struct aluno_{
    char nome[51];
    int aumento;
};

bool lista_inserir(LISTA *lista, ALUNO *aluno);
void lista_imprimir(LISTA *lista);
void lista_remover(LISTA *lista);

//argv[0]    argv[1]    argv[2]
//./main    nomearquivo    k
int main(void){
    char nome_arq[100];
    int k;

    scanf("%s", nome_arq);
    scanf("%d", &k);

    /*criando a lista*/
    LISTA *lista = (LISTA *)malloc(sizeof(lista));
    if(lista == NULL) return ERRO;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    FILE *fp = fopen(nome_arq, "r+");
    if(fp == NULL) return 1;

    char pular[24];
    fscanf(fp, "%s\n", pular);

    /*inserindo o primeiro aluno do arquivo*/
    ALUNO *alunoAux = (ALUNO *)malloc(sizeof(ALUNO));
    float n1, n3;
    fscanf(fp, "%[^,],%f,%f,%f\n", alunoAux->nome, &n1, &n3, &n3);
    alunoAux->nome[strlen(alunoAux->nome)] = '\0';
    alunoAux->aumento = (int)((n3-n1)*100);
    NO *noNovo = (NO *)malloc(sizeof(NO));
    noNovo->aluno = alunoAux;
    noNovo->noSeguinte = NULL;
    noNovo->noParalelo = NULL;
    lista->inicio = noNovo;
    lista->fim = noNovo;
    lista->tamanho++;

    lista_imprimir(lista); printf("Tamanho: %d\n\n", lista->tamanho);

    while(!feof(fp)){
        ALUNO *alunoAux = (ALUNO *)malloc(sizeof(ALUNO));
    
        fscanf(fp, "%[^,],%f,%f,%f\n", alunoAux->nome, &n1, &n3, &n3);
        alunoAux->nome[strlen(alunoAux->nome)] = '\0';
        alunoAux->aumento = (int)((n3-n1)*100);
        
        if((alunoAux->aumento >= lista->fim->aluno->aumento) || (lista->tamanho <= k)){
            lista_inserir(lista, alunoAux);
            if(lista->tamanho > k) lista_remover(lista);
        }

        lista_imprimir(lista); printf("Tamanho: %d\n\n", lista->tamanho);
    }

    fclose(fp);

    lista_imprimir(lista);
    
    return 0;
}

bool lista_inserir(LISTA *lista, ALUNO *aluno){
    if(lista == NULL) return false;

    NO *noNovo = (NO *)malloc(sizeof(NO));
    if(noNovo == NULL) return false;
    noNovo->aluno = aluno;
    noNovo->noSeguinte = NULL;
    noNovo->noParalelo = NULL;

    lista->tamanho++;

    NO *pontAux = lista->inicio;
    NO *pontAux_noAnterior = lista->inicio;

    for(int i=0; i<lista->tamanho-1; i++){
        if(pontAux->aluno->aumento == aluno->aumento){
            lista->tamanho--;
            /*inserindo paralelamente*/
            if(strcmp(noNovo->aluno->nome, pontAux->aluno->nome) < 0){
                if(lista->fim == pontAux) lista->fim = noNovo;
                else if(lista->inicio == pontAux) lista->inicio = noNovo;

                noNovo->noSeguinte = pontAux->noSeguinte;
                noNovo->noParalelo = pontAux;
                pontAux_noAnterior->noSeguinte = noNovo;

                pontAux->noSeguinte = NULL;

                return true;
            }
            else{
                do{
                    pontAux_noAnterior = pontAux;
                    pontAux = pontAux->noParalelo;

                    if(pontAux == NULL){
                        pontAux_noAnterior->noParalelo = noNovo;
                        noNovo->noParalelo = NULL;

                        return true;
                    }
                    else{
                        if(strcmp(noNovo->aluno->nome, pontAux->aluno->nome) < 0){
                            noNovo->noParalelo = pontAux;
                            pontAux_noAnterior->noParalelo = noNovo;

                            return true;
                        }
                    }
                }while(true);

                return true;
            }
        }
        else if(pontAux->aluno->aumento < aluno->aumento){
            if(pontAux == lista->inicio){
                noNovo->noSeguinte = lista->inicio;
                lista->inicio = noNovo;
            }
            else{
                noNovo->noSeguinte = pontAux;
                pontAux_noAnterior->noSeguinte = noNovo;
            }

            return true;
        }
        else if(pontAux->aluno->aumento > aluno->aumento){
            pontAux_noAnterior = pontAux;
            pontAux = pontAux->noSeguinte;
            if(pontAux == NULL) break;
        }
    }

    lista->fim->noSeguinte = noNovo;
    lista->fim = noNovo;

    return true;
}

void lista_remover(LISTA *lista){
    if(lista == NULL) return;

    NO *noAux = lista->fim;
    NO *noAnterior = lista->inicio;
    NO *proximoNo;

    if(noAnterior != noAux){
        while(noAnterior->noSeguinte != noAux){
            noAnterior = noAnterior->noSeguinte;
        }
    }

    while(noAux != NULL){
        proximoNo = noAux->noParalelo;
        free(noAux->aluno);
        free(noAux);
        if(lista->tamanho > 0) lista->tamanho--;
        noAux = proximoNo;
    }

    lista->fim = noAnterior;
    noAnterior->noSeguinte = NULL;

    return;
}

void lista_imprimir(LISTA *lista){
    if(lista == NULL) return;

    NO* pontNo = lista->inicio;
    NO* pontParalelos;

    int i=0;

    while(pontNo != NULL){
        pontParalelos = pontNo->noParalelo;
        printf("Main: %s %d\n", pontNo->aluno->nome, pontNo->aluno->aumento);
        while(pontParalelos != NULL){
            printf("Paralelo: %s %d\n", pontParalelos->aluno->nome, pontParalelos->aluno->aumento);
            pontParalelos = pontParalelos->noParalelo;
        }
        pontNo = pontNo->noSeguinte;
    }
}
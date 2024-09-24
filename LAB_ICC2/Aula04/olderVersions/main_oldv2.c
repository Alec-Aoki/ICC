
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
bool lista_inserirParalelo(LISTA *lista, ALUNO *aluno);
void lista_imprimir(LISTA *lista);
void lista_remover(LISTA *lista);

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

    while(!feof(fp)){
        ALUNO *alunoAux = (ALUNO *)malloc(sizeof(ALUNO));
        float n1, n3;
    
        fscanf(fp, "%[^,],%f,%f,%f\n", alunoAux->nome, &n1, &n3, &n3);
        alunoAux->nome[strlen(alunoAux->nome)] = '\0';
        alunoAux->aumento = (int)((n3-n1)*10);

        if(lista->tamanho == 0){
            lista_inserir(lista, alunoAux);
        }        
        else if(alunoAux->aumento == lista->fim->aluno->aumento){
            lista_inserirParalelo(lista, alunoAux);
        }
        else if(alunoAux->aumento > lista->fim->aluno->aumento){
            lista_inserir(lista, alunoAux);
            if(lista->tamanho > k){
                lista_remover(lista);
            }
        }
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

    if(lista->tamanho == 0){
        lista->inicio = noNovo;
        lista->fim = noNovo;
        lista->tamanho++;
        
        return true;
    }

    lista->tamanho++;

    NO *pontAux = lista->inicio;
    NO *pontAux_noAnterior = lista->inicio;

    for(int i=0; i<lista->tamanho-1; i++){
        if(pontAux->aluno->aumento < aluno->aumento){
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
        else if(pontAux->aluno->aumento == aluno->aumento){
            lista->tamanho--;
            return true;
        }
    }

    lista->fim->noSeguinte = noNovo;
    lista->fim = noNovo;

    return true;
}

bool lista_inserirParalelo(LISTA *lista, ALUNO *aluno){
    if(lista == NULL) return false;

    NO *noNovo = (NO *)malloc(sizeof(NO));
    if(noNovo == NULL) return false;
    noNovo->aluno = aluno;
    noNovo->noSeguinte = NULL;
    noNovo->noParalelo = NULL;

    NO *pontAux = lista->fim;
    NO *pontAux_noAnterior = lista->inicio;

    while(pontAux_noAnterior->noSeguinte != pontAux){
        pontAux_noAnterior = pontAux_noAnterior->noSeguinte;
    }


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

void lista_remover(LISTA *lista){
    if(lista == NULL) return;

    NO *noAux = lista->fim;
    NO *noAnterior = lista->inicio;
    NO *proximoNo;

    while(noAnterior->noSeguinte != noAux){
        noAnterior = noAnterior->noSeguinte;
    }

    while(noAux != NULL){
        //printf("%s\n", noAux->aluno->nome);
        proximoNo = noAux->noParalelo;
        free(noAux->aluno);
        free(noAux);
        noAux = proximoNo;
    }

    lista->fim = noAnterior;
    noAnterior->noSeguinte = NULL;

    lista->tamanho--;

    return;
}

void lista_imprimir(LISTA *lista){
    if(lista == NULL) return;

    NO* pontNo = lista->inicio;
    NO* pontParalelos;

    int i=0;

    while(pontNo != NULL){
        pontParalelos = pontNo->noParalelo;
        printf("Main: %s\n", pontNo->aluno->nome);
        while(pontParalelos != NULL){
            printf("Paralelo: %s\n", pontParalelos->aluno->nome);
            pontParalelos = pontParalelos->noParalelo;
        }
        pontNo = pontNo->noSeguinte;
    }
}
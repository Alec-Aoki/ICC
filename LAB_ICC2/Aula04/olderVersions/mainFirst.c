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
    int k;
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

    /*criando a lista*/
    LISTA *lista = (LISTA *)malloc(sizeof(lista));
    if(lista == NULL) return ERRO;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    scanf("%s", nome_arq);
    scanf("%d", &lista->k);

    FILE *fp = fopen(nome_arq, "r+");
    if(fp == NULL) return 1;

    char pular[24];
    fscanf(fp, "%s\n", pular);

    ALUNO *alunoAux = (ALUNO *)malloc(sizeof(ALUNO));
    float n1, n3;
    fscanf(fp, "%[^,],%f,%f,%f\n", alunoAux->nome, &n1, &n3, &n3);
    alunoAux->nome[strlen(alunoAux->nome)] = '\0';
    alunoAux->aumento = (int)((n3-n1)*100);
    NO *noNovo = (NO *)malloc(sizeof(NO));
    if(noNovo == NULL) return false;
    noNovo->aluno = alunoAux;
    noNovo->noSeguinte = NULL;
    noNovo->noParalelo = NULL;
    lista->inicio = noNovo;
    lista->fim = noNovo;
    lista->tamanho++;

    while(!feof(fp)){
        ALUNO *alunoAux = (ALUNO *)malloc(sizeof(ALUNO));
    
        fscanf(fp, "%[^,],%f,%f,%f\n", alunoAux->nome, &n1, &n3, &n3);
        alunoAux->nome[strlen(alunoAux->nome)] = '\0';
        alunoAux->aumento = (int)((n3-n1)*100);
        
        if((alunoAux->aumento >= lista->fim->aluno->aumento) || (lista->tamanho < lista->k)){
            lista_inserir(lista, alunoAux);
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

    NO *pontAux = lista->inicio;
    NO *pontAux_noAnterior = lista->inicio;

    for(int i=0; i<lista->tamanho; i++){
        if(pontAux->aluno->aumento == aluno->aumento){
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
            }
            if((pontAux != lista->fim) && (lista->tamanho >= lista->k)){
                lista_remover(lista);
            } //PARA AQUI
            return true;
        }
        else if(aluno->aumento > pontAux->aluno->aumento){
            if(pontAux == lista->inicio){
                noNovo->noSeguinte = lista->inicio;
                lista->inicio = noNovo;
            }
            else{
                noNovo->noSeguinte = pontAux;
                pontAux_noAnterior->noSeguinte = noNovo;
            }
            lista->tamanho++;
            lista_remover(lista);
            return true;
        }
        else{
            pontAux_noAnterior = pontAux;
            pontAux = pontAux->noSeguinte;
            if(pontAux == NULL) break;
        }
    }

    /*inserindo no fim*/
    lista->fim->noSeguinte = noNovo;
    lista->fim = noNovo;
    lista->tamanho++;

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
        noAux = proximoNo;
    }
    lista->tamanho--;

    lista->fim = noAnterior;
    noAnterior->noSeguinte = NULL;

    noAux = lista->inicio;
    int i=0;
    while(noAux != NULL){
        i++;
        noAux = noAux->noSeguinte;
    }

    return;
}

void lista_imprimir(LISTA *lista){
    if(lista == NULL) return;

    NO* pontNo = lista->inicio;
    NO* pontParalelos;

    int i=0;

    while(pontNo != NULL){
        pontParalelos = pontNo->noParalelo;
        printf("%s\n", pontNo->aluno->nome);
        while(pontParalelos != NULL){
            printf("%s\n", pontParalelos->aluno->nome);
            pontParalelos = pontParalelos->noParalelo;
        }
        pontNo = pontNo->noSeguinte;
    }
}
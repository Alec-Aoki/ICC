#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*TODO
ordem decrescente OK
void lista_imprimir(LISTA *lista); OK
bool lista_remover(LISTA *lista);
ler arquivo
*/

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


//argv[0]    argv[1]    argv[2]
//./main    nomearquivo    k
int main(int argc, char *argv[]){ 
    int k = atoi(argv[2]);

    /*criando a lista*/
    LISTA *lista = (LISTA *)malloc(sizeof(lista));
    if(lista == NULL) return ERRO;
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    /*criando a inserindo os primeiros k alunos*/
    while(lista->tamanho < k){
    //for(int i=0; i<k; i++){
        ALUNO *alunoAux = (ALUNO *)malloc(sizeof(ALUNO));
        float n1, n3;
        
        scanf(" %50[^,],%f,%f,%f", alunoAux->nome, &n1, &n3, &n3);
        alunoAux->aumento = (int)((n3-n1)*10);

        lista_inserir(lista, alunoAux);
    }

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
            if(i == 0){
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
        }
        else if(pontAux->aluno->aumento == aluno->aumento){ //pontAux->aluno->aumento == aluno->aumento
            lista->tamanho--;
            /*inserindo paralelamente*/
            if(strcmp(noNovo->aluno->nome, pontAux->aluno->nome) < 0){
                if(lista->fim == pontAux) lista->fim = noNovo;
                else if(lista->inicio == pontAux)lista->inicio = noNovo;

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
    }

    lista->fim->noSeguinte = noNovo;
    noNovo->noSeguinte = NULL;
    lista->fim = noNovo;

    return true;
}

void lista_imprimir(LISTA *lista){
    if(lista == NULL) return;

    NO* pontNo = lista->inicio;
    NO* pontParalelos = pontNo->noParalelo;

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

/*
Os k alunos com os maiores aumentos em suas notas seriam premiados com uma estrela
-> lista encadeada ordenada
    -> pont->inicio
    -> pont->fim
    -> tamanho
    -> struct No
        -> no seguinte
        -> no paralelo
        -> pont para struct aluno
            -> struct aluno
                -> nome
                -> aumento
-> ler os primeiros k alunos e adicionar eles na lista
    -> guardar o menor aumento
-> ler o resto dos alunos, checar com o menor aumento
    -> se houver um aumento igual, inserimos ele paralelamente ao nó já inserido
    -> se houver um aumento maior, apagamos o menor e o inserimos


Imprima esses 0 < 𝑘 < 10⁶ alunos
-> k é um inteiro

aluno,nota1,nota2,nota3
Carlinhos,7.0,7.5,7.2
Clarinha,8.0,8.2,8.9
-> <string>,<nota1>,<nota2>,<nota3>\n
-> aumento - 10*(nota3 - nota1);

Os campos aluno nunca terá mais do que 50 caracteres, os campos nota1, nota2 e nota3 têm uma casa decimal e estão entre 0 e 10
Não é necessário interpretar os campos de nota como números de ponto flutuante, se multiplicarmos tudo por 10 o resultado será o mesmo;


aumento como (nota3 − nota2) + (nota2 − nota1) =
nota3 − nota1

Se houver empates no aumento das notas, todos os alunos que tiverem o mesmo aumento que o aluno na última posição dos 𝑘 maiores aumentos devem ser incluídos na saída

Os nomes dos alunos devem ser impressos em ordem lexicográfica (se houver empate)

Evite carregar o arquivo inteiro na memória primária
-> ler linha por linha
*/
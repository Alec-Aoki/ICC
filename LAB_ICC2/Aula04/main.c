#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    NO *noInicio;
    NO *noFim;
    int tamanho;
};

struct aluno_{
    char nome[51];
    int aumento;
};

//argv[0]    argv[1]    argv[2]
//./main    nomearquivo    k
int main(int argc, char *argv[]){ 
    int k = atoi(argv[2]);

    /*criando a lista*/
    LISTA *lista = (LISTA *)malloc(sizeof(lista));
    if(lista == NULL) return ERRO;
    lista->noInicio = NULL;
    lista->noFim = NULL;
    lista->tamanho = k;

    /*criando a inserindo os primeiros k alunos*/
    ALUNO *primeiros_kAlunos[k];
    for(int i=0; i<k; i++){
        ALUNO *alunoAux = (ALUNO *)malloc(sizeof(ALUNO));
        float n1, n2, n3;
        
        scanf(" %50[^,],%f,%f,%f", alunoAux->nome, &n1, &n2, &n3);
        alunoAux->aumento = (int)((n3-n1)*10);

        primeiros_kAlunos[i] = alunoAux;
        printf("%s %d\n", primeiros_kAlunos[i]->nome, primeiros_kAlunos[i]->aumento);
    }
    return 0;
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
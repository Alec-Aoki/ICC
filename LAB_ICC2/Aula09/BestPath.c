#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct no_ NO;

struct no_{
    int chave;
    NO *esq, *dir;
};


typedef struct arvore_{
    NO *raiz;
    int tamanho;
}ARVORE;


// Modularização
NO* inserir(NO *raiz, int chave);
void apagar(NO **raiz);
bool pertence(NO *raiz, int chave);
void caminho(NO *raiz, int chave);

ARVORE *arvore_criar(){
    ARVORE *arvore = (ARVORE*) malloc(sizeof(ARVORE));
    if(arvore != NULL){
        arvore->raiz = NULL;
        arvore->tamanho = 0;
    }

    return arvore;
}

void arvore_apagar(ARVORE **arvore){
    if(*arvore != NULL){
        apagar(&((*arvore)->raiz));
        free(*arvore);
        *arvore = NULL;
    }

    return;
}

void apagar(NO **raiz){
    if(*raiz == NULL)
        return;
   
    apagar(&((*raiz)->esq));
    apagar(&((*raiz)->dir));


    free(*raiz);
    *raiz = NULL;

    return;
}

void arvore_inserir(ARVORE *arvore, int chave){
    if(arvore != NULL)
    {
        arvore->raiz = inserir(arvore->raiz, chave);
        arvore->tamanho++;
    }

    return;
}

NO* inserir(NO *raiz, int chave){
    // Adiciona o no quando o no NULO é encontrado.
    if (raiz == NULL) {
        NO* novo_no = (NO*) malloc(sizeof(NO));
        novo_no->chave = chave;
        novo_no->esq =  NULL;
        novo_no->dir = NULL;
        return novo_no;
    }

    // Percorra a subárvore esquerda se os dados
    // forem menores que o nó atual
    if (chave < raiz->chave) {
        raiz->esq = inserir(raiz->esq, chave);
        return raiz;
    }

    // Percorra a subárvore direita se os dados
    // forem maiores que o nó atual
    else if (chave > raiz->chave) {
        raiz->dir = inserir(raiz->dir, chave);
        return raiz;
    }
    else
        return raiz;
}

// Retorna se esse elemento pertence ao arvore.
bool arvore_pertence(ARVORE *arvore, int chave){
    if(arvore != NULL){
        return pertence(arvore->raiz, chave);
    }

    return false;
}

// Verifica se o elemento está no NO, caso não, verifica-se para os filhos.
bool pertence(NO *raiz, int chave){
    if (raiz == NULL)
        return 0;

    printf("%d ", raiz->chave);
   
    if(raiz->chave == chave)
        return true;


    return pertence(raiz->esq, chave) || pertence(raiz->dir, chave);
}

void menor_caminho(ARVORE *arvore, int chave){
    if(arvore != NULL){
        // Buscar e imprimir caminho
        caminho(arvore->raiz, chave);
    }
   
    return;
}

void caminho(NO *raiz, int chave){
    if(raiz != NULL){
        printf("%d ", raiz->chave);


        if(raiz->chave == chave)
            return;
        else if(raiz->chave < chave)
            caminho(raiz->dir, chave);
        else
            caminho(raiz->esq, chave);
    }
    else printf("%d ", -1);

    return;    
}

int main(void){
    int tamanho_arvore;

    scanf("%d", &tamanho_arvore);

    clock_t start, end;
    double cpu_tempo_ms;

    ARVORE *arvore = arvore_criar();

    for(int i = 0; i < tamanho_arvore; i++){
        int aux;
        scanf("%d", &aux);
        arvore_inserir(arvore, aux);
    }

    int numero_buscado;
    scanf("%d", &numero_buscado);

    start = clock();

    menor_caminho(arvore, numero_buscado);
    //pertence(arvore->raiz, numero_buscado);

    end = clock();

    printf("\nBusca binária\n");
    //printf("\nBusca sequencial\n");

    cpu_tempo_ms = (double) (end - start)/ CLOCKS_PER_SEC *1000;
    printf("\nTempo de execucao: %lfms\n", cpu_tempo_ms);

    arvore_apagar(&arvore);

    return 0;
}
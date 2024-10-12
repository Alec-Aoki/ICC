#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "item.h"
#include "filaDinamica.h"

struct no_{
    ITEM *item;
    //NO *noAnterior;
    NO *noSeguinte;
};

struct fila_{
    int total;
    NO *noInicio;
    NO *noFim;
};

FILA *fila_criar(void){
    FILA *fila = (FILA *)malloc(sizeof(FILA));
    if(fila == NULL) exit(1);
    
    fila->total = 0;
    fila->noInicio = NULL;
    fila->noFim = NULL;

    return fila;
}

bool fila_inserir(FILA *fila, ITEM *item){
    if(fila == NULL) exit(1);
    if(fila_cheia(fila)) return false;

    NO *noNovo = (NO *)malloc(sizeof(NO));
    if(noNovo == NULL) exit(1);

    noNovo->item = item;
    if(fila->total == 0) fila->noInicio = noNovo;
    noNovo->noSeguinte = fila->noFim;

    fila->noFim = noNovo;
    (fila->total)++;

    return true;
}

ITEM *fila_remover(FILA *fila){
    if(fila == NULL) exit(1);
    if(fila_vazia(fila)) return NULL;

    ITEM *itemAux = (fila->noInicio)->item;
    (fila->noInicio)->item = NULL;

    fila->noInicio = fila->noFim;

    for(int i=1; i<(fila->total)-1; i++){
        fila->noInicio = (fila->noInicio)->noSeguinte;
    }

    free((fila->noInicio)->noSeguinte);
    fila->noInicio->noSeguinte = NULL;

    return itemAux;
}

ITEM *fila_frente(FILA *fila){
    if(fila == NULL) exit(1);
    if(fila_vazia(fila)) return NULL;

    return ((fila->noInicio)->item);
}

int fila_tamanho(FILA *fila){
    if(fila == NULL) exit(1);

    return fila->total;
}

bool fila_cheia(FILA *fila){
    if(fila == NULL) exit(1);

    NO* noTemp = (NO *)malloc(sizeof(NO));
    if(noTemp != NULL){
        free(noTemp);
        noTemp = NULL;

        return false;
    }

    return true;
}

bool fila_vazia(FILA *fila){
    if(fila == NULL) exit(1);
    if(fila->total == 0) return true;

    return false;
}

void fila_imprimir(FILA *fila){
    NO *noBusca = fila->noInicio;
    for(int i=0; i<fila->total-1; i++){
        printf("%d ", item_getChave(noBusca->item));
        noBusca = noBusca->noSeguinte;
    }
    if(fila->total != 0) printf("%d\n", item_getChave(fila->noFim->item));

    return;
}
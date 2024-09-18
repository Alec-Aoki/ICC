#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "item.h"

struct item_{
    void *dado;
    int index;
};

ITEM *item_criar(void *dado, int index){
    ITEM *item = (ITEM *)malloc(sizeof(ITEM));
    if(item != NULL){
        item->dado = dado;
        item->index = index;
    }
    
    return item;
}

bool item_apagar(ITEM **item){
    if(*item != NULL){
        free(*item);
        *item = NULL;
        
        return true;
    }
    return false;
}

void *item_getDado(ITEM *item){
    if(item == NULL) return NULL;

    return item->dado;
}

int item_getChave(ITEM *item){
    if(item == NULL) return -1;

    return item->index;
}
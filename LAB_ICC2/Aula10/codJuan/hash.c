#include "hash.h"


#include <stdio.h>
#include <stdlib.h>


struct h {
    ARVORE **tabela;
    int tamanho;
    int fator;
};


int hash_index(hash_t *hash, int chave) {
    return chave % hash->tamanho;
}


int hash2_index(hash_t *hash, int chave) {
    return ((hash->tamanho - 1) - (chave % (hash->tamanho - 1)));
}




hash_t *hash_criar(int tamanho) {
    hash_t *hash = (hash_t*) malloc(sizeof(hash_t));
    if(hash != NULL){
        hash->tabela = (ARVORE**) calloc(tamanho, sizeof(ARVORE*)); // Se for nulo, não há nó.
        if(hash->tabela == NULL) return NULL; /*Não encerra o programa se a memória estiver cheia*/
        hash->tamanho = tamanho;
        hash->fator = 0; // Fator de balanceamento.
        return hash;
    }
    return NULL;
}


void hash_inserir(hash_t *hash, int chave) {
    int ind = hash_index(hash, chave);


    // Verifica se a posição inicial está livre
    if (hash->tabela[ind] == NULL) {
        hash->tabela[ind] = arvore_criar();
        arvore_inserir(hash->tabela[ind], chave);
        hash->fator++;
        return;
    }
   
    // Verifica se a tabela está 80% preenchida para usar double hashing
    if ((float) hash->fator / hash->tamanho >= 0.8) {
        for (int i = 1; i < hash->tamanho; i++) {
            int index = (ind + i * hash2_index(hash, chave)) % hash->tamanho;
            if (hash->tabela[index] == NULL) {
                hash->tabela[index] = arvore_criar();
                arvore_inserir(hash->tabela[index], chave);
                hash->fator++;
                return;
            }
        }
    }


    // Insere na árvore do índice encontrado inicialmente em caso de colisão
    arvore_inserir(hash->tabela[ind], chave);
}


bool hash_busca(hash_t *hash, int chave) {
    if (!hash || !hash->tabela)  // Verifica se a tabela hash existe.
        return false;
       
    for(int i = 0; i < hash->tamanho; i++) {
        int index = (hash_index(hash, chave) +
                    i*hash2_index(hash, chave)) % (hash->tamanho);
                   
        if (index < 0 || index >= hash->tamanho) // Verificar os limites do indice.
             continue;
           
        if(hash->tabela[index] == NULL)
            return false;
           
        // Após garantir o intervalo permitido
        // e que existi tal posição, chama-se a função
        if(arvore_pertence(hash->tabela[index], chave))
            return true;
    }
    return false;
}


void hash_apagar(hash_t **hash){
    if(*hash != NULL){
        for(int i = 0; i < (*hash)->tamanho; i++){
            arvore_apagar(&(((*hash)->tabela)[i]));
        }
        free((*hash)->tabela);
        (*hash)->tabela = NULL;
        free(*hash);
        *hash = NULL;
    }
    return;
}

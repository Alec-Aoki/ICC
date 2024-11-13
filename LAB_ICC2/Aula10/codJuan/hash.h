#ifndef HASH_H
    #define HASH_H


    #include "arvorebinaria.h"


    typedef struct h hash_t;


    hash_t *hash_criar(int tamanho);    
    void hash_inserir(hash_t *hash, int chave);
    bool hash_busca(hash_t *hash, int chave);
    void hash_apagar(hash_t **hash);


#endif
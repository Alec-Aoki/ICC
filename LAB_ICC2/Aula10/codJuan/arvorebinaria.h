#ifndef AB_H
    #define AB_H


    typedef struct arvore_ ARVORE;


    #include<stdbool.h>


    ARVORE *arvore_criar(void);
    void arvore_apagar(ARVORE **arvore);
    void arvore_inserir(ARVORE *arvore, int chave);
    bool arvore_pertence(ARVORE *arvore, int chave);
    int arvore_tamanho(ARVORE *arvore);


#endif
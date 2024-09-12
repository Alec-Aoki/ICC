# Métodos de Ordenação
-> se a busca for feita somente ocasionalmente, não é interessante ter que ordernar o conjunto inteiro (O(n)) <br />
-> se a busca for feita repetidamente, ordenar o conjunto vale a pena, já que terá que ser feita somente uma vez (O(n*log(n)) + O(log(n)))

## Terminologia/Conceitos
- ordenação de registros
    - cada registro é ordenado por sua **chave**!
- ordenação **interna x externa**
    - interna: ordenação utilizando a memória principal
    - externa: ordenação fora da memória principal (em arquivos, por exemplo)
- ordenação **estável**
    - a ordenação mantém, se viável, a ordem original dos elementos
    - ex: 2a 1b 3d 1a -> 1b 1a 2a 3d (1b se manteve antes de 1a pois a ordenação é estável)
- ordenação sobre os próprios registros
    - os registros trocam de posição
- ordenação por endereços
    - utiliza ponteiros que apontam para os registros
    - a ordem de registros se mantém a mesma
    - os ponteiros mudam os endereços para que apontam, de forma que o primeiro ponteiro aponte para a chave 1, o segundo para a chave 2, e assim por diante

```c
#include <stdio.h>
#include <string.h>

typedef struct{
    int chave;
    char valor[10];
}str_t;

void swap(str_t *a, str_t *b);

int main(void){
    str_t a, b;

    a.chave = 2;
    strcpy(a.valor, "aaa");

    b.chave = 3;
    strcpy(b.valor, "bbb");

    swap(&a, &b);

    printf("%d %s\n", a.chave, a.valor);
    printf("%d %s\n", b.chave, b.valor);

    return 0;
}

void swap(str_t *a, str_t *b){
    str_t aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
```
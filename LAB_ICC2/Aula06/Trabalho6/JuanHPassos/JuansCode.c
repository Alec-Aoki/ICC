#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

/*
NOT MY CODE
MADE BY JUAN HENRIQUE PASSOS - github.com/JuanHPassos
*/

typedef struct prato_{
    int prioridade;
    int tempo;
    char *prato;
}PRATO;

// Modularização
PRATO *leitura_dados(int tam);
bool menos_prioritario(PRATO prato1, PRATO prato2);
void desalocacao_memoria(PRATO **vet, int tam);
void heapsort(PRATO *vet, int n);
void swap(PRATO *i, PRATO *j);
void rearranjar_heap(PRATO *vet, int i, int tam_heap);

int main(){
    int quant_pratos;
    PRATO *pratos;
    // Quantidade de pratos;
    scanf("%d", &quant_pratos);

     // Captura o tempo inicial
    clock_t inicio = clock();

    pratos = leitura_dados(quant_pratos);

    heapsort(pratos, quant_pratos);

    // Captura o tempo final
    clock_t fim = clock();

    // Calcula o tempo de execução em milisegundos
    double tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    // Exibe o tempo de execução
    printf("Tempo de execucao: %fms\n", tempo_execucao);


    // for(int i = 0; i < quant_pratos; i++){
    //     printf("%s\n", pratos[i].prato);
    // }

    desalocacao_memoria(&pratos, quant_pratos);

    return(0);
}

// Funcao que le os dados e aloca espaço necessario, sem desperdicio de memoria.
PRATO *leitura_dados(int tam){
    PRATO *pratos = (PRATO*) malloc(tam*sizeof(PRATO));
    if(pratos == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    for(int i = 0; i < tam; i++){
        int prioridade, tempo;
        char leitura[52], *prato;

        scanf("%d %d %s", &prioridade, &tempo, leitura);

        pratos[i].prioridade = prioridade;
        pratos[i].tempo = tempo;
        // Guarda-se exatamente o espaço necessário para guardar nome.
        prato = (char*) malloc((strlen(leitura) + 1)*sizeof(char));
        strcpy(prato, leitura);
        pratos[i].prato = prato;
    }

    return pratos;
}

// Função que analisa se o prato1 tem menos prioridade que o prato2.
bool menos_prioritario(PRATO prato1, PRATO prato2){
    if(prato1.prioridade == prato2.prioridade)
        if(prato1.tempo > prato2.tempo) return true;
        else return false;

    else if(prato1.prioridade > prato2.prioridade) return false;
    else return true; // Prato 1 possui menos prioridade que o prato 2.
}

// Libera memoria armazenada, tanto do campo prato da struct, quanto do vetor do tipo PRATO.
void desalocacao_memoria(PRATO **vet, int tam){
    if(*vet == NULL) return;
    for(int i = 0; i < tam; i++){
        free((*vet)[i].prato);
        (*vet)[i].prato = NULL; // Boa prática
    }
    free(*vet); 
    *vet = NULL;

    return;
}

void swap(PRATO *i, PRATO *j){
    PRATO aux = *i;
    *i = *j;
    *j = aux; 
}

void rearranjar_heap(PRATO *vet, int i, int tam_heap){
    int esq, dir, maior;

    esq = 2*i + 1;
    dir = 2*i + 2;
    maior = i;
    // Busca ajustar o filho da esquerda para ser menor que pai.
    if(esq < tam_heap && menos_prioritario(vet[maior], vet[esq]))
        maior = esq;
    // Filho deve ser menor que o pai.
    if(dir < tam_heap && menos_prioritario(vet[maior], vet[dir]))
        maior = dir;
    // Caso um dos filhos seja maior, sua posição é reposicionada, e busca-se averiguar se ela é a sua posição nessa árvore.
    if(maior != i){
        
        swap(&vet[maior], &vet[i]);

        rearranjar_heap(vet, maior, tam_heap);

    }
}

void heapsort(PRATO *vet, int n){
    int i;
    // Começa em (n/2) - 1, pois a partir disso, são representadas as folhas das arvore binaria.
    for(i = (n / 2) - 1; i >= 0; i--){
        rearranjar_heap(vet, i, n);
    }

    
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {

        swap(&vet[0], &vet[i]);

        rearranjar_heap(vet, 0, i);
    }
}

/*
4
7 30 fish-and-chips
1984 1 poitin
1 20 bubble-and-squeak
42 60 steak-and-ale-pie
*/
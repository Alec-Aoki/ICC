#include <stdio.h>
#include <stdlib.h>

/*DIVISÃO DE MEMÓRIA
-> a memória RAM é separada em Pilha, Heap, Dados e Código
    Código: contém as instruções (todas) do programa
    Dados: onde ficam guardadas as variáveis globais
    Heap: memória livre para alocarmos dinamicamente, maior porção
    Pilha: onde ficam guardadas outras estruturas de dados (como var. locais e parâmetros)
    
ALOCAÇÃO DINÂMICA (doideira)
-> meio pelo qual um programa pode obter memória enquanto ele está em execução, usando a Heap
-> funções:
    calloc(): cria espaço na memória *contíguamente* (um na frente do outro) -> vetores
    malloc(): cria espaço na memória
    realloc(): realoca espaço previamente alocado
    free(): libera espaço criado pelas duas primeiras funções
-> observações:
    NULL: valor nulo
    ponteiro NULL: não aponta pra nada
    ponteiro VOID: aponta para qualquer tipo de dado
    
    
    CALLOC:
    void* calloc(int n, size_t tam);
    //aloca espaço contíguo na memória para "n" elementos, com cada elemento tendo "tam" bytes
    //os bits são inicializados com 0
    //sucesso: retorna um ponteiro void que aponta para o endereço base do espaço alocado
    //falha (não conseguiu alocar a memória na heap: retorna NULL
    
    int *p;
    p = (int *) calloc(2,4); // ou então p=(int *)calloc(2,sizeof(int));, supondo que vamos armazenar ints
    //calloc(2,4) aloca 8 bytes na heap e retorna um ponteiro void para o início dessa memória
    //o cast (int *) transforma esse ponteiro void em ponteiro int
    //p recebe o início da memória
    p[0] = 1;
    p[1] = 2;
    //obs: p[0] não tira o ponteiro p do início da memória!

    MALLOC:
    void* malloc(size_t tam);
    //OBS: malloc NÃO inicializa os espaços de memória! (+ rápido q o calloc)
    int *p;
    p = (int *)malloc(2*sizeof(int)); //tamanho de 8 bytes
    
    MODO CORRETO DE USAR:
    if((p=(int*) malloc(12)) == NULL){
        return 1; //ou então exit(1);, que sai do programa em vez de só sair da função
    }
    //ou
    p = (int *)malloc(12);
    if (p == NULL){
        return 1;
    }

    Diferença entre MALLOC e CALLOC:
    -> em essência, o CALLOC zera os espaços e o MALLOC não, simples assim
    
    FREE:
    void* free(void *ptr);

    int *p;
    p = (int *) malloc(sinzeof(int));
    *p = 10;
    printf("%d\n", *p);
    free(p); //disponibiliza o espaço na memória apontada por esse ponteiro
    p = NULL; //faz o ponteiro p apontar para nada, porque p ainda tá apontando para a memória
    //se você não der free, a memória só vai ser liberada quando o programa terminar
    //OBS: é boa prática dar free sempre que você não for mais usar aquela memória

    REALLOC:
    void* realloc(void *ptr, size_t size);
    //tenta redimensionar o bloco na memória apontado por ptr previamente alocado com calloc() ou malloc()
    //sucesso: retorna um ponteiro void para o endereço base
    //falha: retorna NULL
    int *p;
    p = (int *) malloc(2*sizeof(int));
    p = (int *) realloc(p, (2*sizeof(int)) + (4*sizeof(int))); //é boa prática somar a memória antiga com o que queremos a mais
    //OBS: se der falha, você perde os valores guardados na memória antiga, então pode ser legal usar um *aux
*/

/*EXERCÍCIO
    Fazer um programa que aloca dinamicamente um vetor de doubles com tamanho e elementos determinados pelo usuário

    Leia_Elementos
    Aloque
    Imprima_Valores
*/

double *Aloque(int tam){
    //como vamos retornar um endereço (ponteiro), temos que declarar a função como um ponteiro
    double *vetor_Aloque;
    vetor_Aloque = (double *) calloc(tam, sizeof(double));
    if (vetor_Aloque == NULL){
        printf("Falta de memoria\n");
        exit(1);
    }
    return vetor_Aloque;
}

void Leia_Elementos(double *vetor_Leia, int tam){
    for (int i=0; i<tam; i++){
        scanf(" %lf", &vetor_Leia[i]);
    }
    return;
}

void Imprima_Valores(double *vetor_Imprima, int tam){
    for (int i=0; i<tam; i++){
        printf("%lf ", vetor_Imprima[i]);
    }
    printf("\n");
    return;
}

int main (void){
    double *vetor_main;
    int tam;
    scanf(" %d", &tam);

    vetor_main = Aloque(tam);

    Leia_Elementos(vetor_main, tam);

    /* !!!!!!!
    o ponteiro vetor_main está guardando o endereço das variáveis na heap
    como não queremos mudar o que o vetor_main está guardando, não vamos passar ele por referência, mas por valor
    */

    Imprima_Valores(vetor_main, tam);

    return 0;
}
#include <stdio.h>

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
    p = (int *)calloc(2,4); // ou então p=(int *)calloc(2,sizeof(int));, supondo que vamos armazenar ints
    //calloc(2,4) aloca 8 bytes na heap e retorna um ponteiro void para o início dessa memória
    //o cast (int *) transforma esse ponteiro void em ponteiro int
    //p recebe o início da memória
    p[0] = 1;
    p[1] = 2;
    
    MALLOC:
    void* malloc(size_t tam);
    //OBS: malloc NÃO inicializa os espaços de memória! (+ rápido q o calloc)
    int *p;
    p = (int *)malloc(2*sizeof(int)); //tamanho de 8 bytes
    
    MODO CORRETO DE USAR:
    if((p=(int*)malloc(12)) == NULL){
        return 1; //ou então exit(1);, que sai do programa em vez de só sair da função
    }
    //ou
    p = (int *)malloc(12);
    if (p == NULL){
        return 1;
    }
    
    FREE:
    int *p;
    p = (int *)malloc(sinzeof(int));
    *p = 10;
    printf("%d\n", *p);
    free(p); //disponibiliza o espaço na memória apontada por esse ponteiro
    p = NULL; //faz o ponteiro p apontar para nada

*/

int main (void){
    
    return 0;
}
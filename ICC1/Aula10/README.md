# DIVISÃO DE MEMÓRIA
-> a memória RAM é separada em **Pilha**, **Heap**, **Dados** e **Código** <br />
* Código: contém as instruções (todas) do programa
* Dados: onde ficam guardadas as variáveis globais
* Heap: memória livre para alocarmos dinamicamente, maior porção
* Pilha: onde ficam guardadas outras estruturas de dados (como var. locais e parâmetros)
    
# ALOCAÇÃO DINÂMICA (doideira)
-> meio pelo qual um programa pode obter memória enquanto ele está em execução, usando a Heap <br/>
-> funções:
* calloc(): cria espaço na memória *contíguamente* (um na frente do outro) -> vetores
* malloc(): cria espaço na memória
* realloc(): realoca espaço previamente alocado
* free(): libera espaço criado pelas duas primeiras funções <br />

-> observações:
* NULL: valor nulo
* ponteiro NULL: não aponta pra nada
* ponteiro VOID: aponta para qualquer tipo de dado
    
## CALLOC:
```c
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
```

## MALLOC:
```c
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
```
### Diferença entre MALLOC e CALLOC:
-> em essência, o CALLOC zera os espaços e o MALLOC não, simples assim <br />

## FREE:
```c
    void* free(void *ptr);

    int *p;
    p = (int *) malloc(sinzeof(int));
    *p = 10;
    printf("%d\n", *p);
    free(p); //disponibiliza o espaço na memória apontada por esse ponteiro
    p = NULL; //faz o ponteiro p apontar para nada, porque p ainda tá apontando para a memória
    //se você não der free, a memória só vai ser liberada quando o programa terminar
    //OBS: é boa prática dar free sempre que você não for mais usar aquela memória
```

## REALLOC:
```c
    void* realloc(void *ptr, size_t size);
    //tenta redimensionar o bloco na memória apontado por ptr previamente alocado com calloc() ou malloc()
    //sucesso: retorna um ponteiro void para o endereço base
    //falha: retorna NULL
    int *p;
    p = (int *) malloc(2*sizeof(int));
    p = (int *) realloc(p, (2*sizeof(int)) + (4*sizeof(int))); //é boa prática somar a memória antiga com o que queremos a mais
    //OBS: se der falha, você perde os valores guardados na memória antiga, então pode ser legal usar um *aux
```
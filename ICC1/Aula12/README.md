# TYPEDEF 
-> dá um nome novo a um tipo já existente <br />
-> OBS: NÃO CRIA UM TIPO NOVO

# STRUCT
-> uma variável que armazena outras variáveis <br />

## DECLARAÇÃO DE STRUCTS
-> declaração da struct:
```c
    struct NOME_DA_STRUCT{
        int NOME_DA_VARIAVEL_DENTRO_DA_STRUCT;
    };
```

-> criação de uma variável do tipo daquela struct:
```c
    struct NOME_DA_STRUCT NOME_DA_VARIAVEL;
```

-> acesso de uma variável dentro de uma struct:
```c
    NOME_DA_VARIAVEL.NOME_DA_VARIAVEL_DENTRO_DA_STRUCT = 10;
```

-> podemos usar o TYPEDEF para facilitar a leitura do código:
```c
    typedef struct{
        bla bla bla;
    }NOME_DA_STRUCT;
```

-> aí para criar uma variável dessa struct, basta fazermos:
```c
    NOME_DA_STRUCT NOME_DA_VARIAVEL;
```

## ATRIBUIÇÃO DE VALORES
-> podemos dar valores às variáveis de uma variável do tipo struct usando {} <br />
-> exemplo:
```c
    typedef struct{
        int x;
        int y;
    }ponto;

    ponto p1 = {1, 2};
```
-> OBS: ele vai preencher na ordem em que as variáveis foram declaradas dentro da struct <br />
-> ou então:
```c
    ponto p2 = {
        .y=4, .x=3
        };
```
-> nesse caso, não precisamos preencher na ordem pq estamos especificando q variáveis recebem q valores <br />

-> podemos copiar o valor de uma struct para outra, que nem uma variável normal <br />
-> exemplo:
```c
    Pessoa Joao;
    Pessoa Kevin;
    Joao = Kevin;
    //Joao agr tem o valor de suas variáveis internais iguais as de Kevin
```

## VETOR DE STRUCTS
-> podemos criar um vetor de structs <br />
-> exemplo:
```c
    ponto pontos[10]; //cria um vetor de 10 variáveis do tipo ponto
```
-> para acessar o valor de uma variável de uma dessas variáveis, basta fazer como fazemos normalmente
```c
    pontos[5].x = 0;
    pontos[5].y = 0;
```

## DECLARAÇÃO DE PONTEIROS DENTRO DE STRUCTS
```c
    typedef struct{
        int *vetor;
    }poggers;

    poggers a; //criação de ponteiros que apontam para um inteiro
    poggers b;
    a.vetor = (int *)malloc(3*sizeof(int)); //ponteiros agora apontam para o início de uma memória na heap
    b.vetor = (int *)malloc(3*sizeof(int));
    
    a = b; //OBS: ISSO FAZ a APONTAR PARA O MESMO VETOR QUE b
        //logo, mudando a, vamos mudar b tmb
```

# STRUCTS (v2)
-> uma coleção de variáveis (elementos/campos, que podem ser de tipos diferentes), organizadas em um único conjunto <br />
exemplo:
```c
    struct pessoa{
        char nome[30];
        int idade;
    };

    int main(void){
        struct pessoa Joao;
        strcpy(Joao.nome, "Joao");
        Joao.idade = 18;
        return 0;
    }
```
-> o tamanho de uma variável do tipo da struct é a soma do tamanho das variáveis que a struct tem <br />
-> exemplo usando typedef:
```c
    typedef struct{
        int nome[30];
        int idade;
    }pessoa;

    int main (void){
        pessoa Joao;
        return 0;
    }
```
-> podemos retornar structs (exemplo abaixo) <br />
-> podemos declarar structs dentro de structs <br />
-> exemplo:
```c
    struct ponto{
        int x;
        int y;
    };

    struct linha{
        struct ponto p1;
        struct ponto p2;
    }Linha;

    int main (void){
        Linha.p1.x = 0;
        Linha.p1.y = 0;
        Linha.p2.x = 5;
        Linha.p2.y = 3;
        //P1(0,0)
        //P2(5,3)
        return 0;
    }
```
-> structs podem ser declaradas dentro delas mesmas

## STRUCTS DE PONTEIROS
-> um ponteiro do tipo de uma struct aponta para uma variável do tipo dessa struct <br />
-> exemplo:
```c
    struct ponto *ponteiro_ponto; //ponteiro que aponta para variáveis do tipo "struct ponto"
```
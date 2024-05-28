#include <stdio.h>
#include <string.h>

/*TYPEDEF -> dá um nome novo a um tipo já existente
-> OBS: NÃO CRIA UM TIPO NOVO
*/

/*STRUCT -> uma variável que armazena outras variáveis
DECLARAÇÃO DE STRUCTS
-> declaração da struct:
    struct NOME_DA_STRUCT{
        int NOME_DA_VARIAVEL_DENTRO_DA_STRUCT;
    };
-> criação de uma variável do tipo daquela struct:
    struct NOME_DA_STRUCT NOME_DA_VARIAVEL;
-> acesso de uma variável dentro de uma struct:
    NOME_DA_VARIAVEL.NOME_DA_VARIAVEL_DENTRO_DA_STRUCT = 10;

-> podemos usar o TYPEDEF para facilitar a leitura do código:
    typedef struct{
        bla bla bla;
    }NOME_DA_STRUCT;
-> aí para criar uma variável dessa struct, basta fazermos:
    NOME_DA_STRUCT NOME_DA_VARIAVEL;

ATRIBUIÇÃO DE VALORES
-> podemos dar valores às variáveis de uma variável do tipo struct usando {}
-> exemplo:
    typedef struct{
        int x;
        int y;
    }ponto;
    ponto p1 = {1, 2};
    -> obs: ele vai preencher na ordem em que as variáveis foram declaradas dentro da struct
-> ou então:
    ponto p2 = {
        .y=4, .x=3
        };
    -> nesse caso, não precisamos preencher na ordem pq estamos especificando q variáveis recebem q valores

-> podemos copiar o valor de uma struct para outra, que nem uma variável normal
-> exemplo:
    Pessoa Joao;
    Pessoa Kevin;
    Joao = Kevin;
    //Joao agr tem o valor de suas variáveis internais iguais as de Kevin

VETOR DE STRUCTS
-> podemos criar um vetor de structs
-> exemplo:
    ponto pontos[10]; //cria um vetor de 10 variáveis do tipo ponto
-> para acessar o valor de uma variável de uma dessas variáveis, basta fazer como fazemos normalmente
    pontos[5].x = 0;
    pontos[5].y = 0;

DECLARAÇÃO DE PONTEIROS DENTRO DE STRUCTS
    typedef struct{
        int *vetor;
    }poggers;

    poggers a;
    poggers b;
    a.vetor = (int *)malloc(3*sizeof(int));
    b.vetor = (int *)malloc(3*sizeof(int));
    
    a = b; //OBS: ISSO FAZER a APONTAR PARA O MESMO VETOR QUE b
        //logo, mudando a, vamos mudar b tmb
*/

typedef char letra; //agora posso usar uma variável do tipo letra, que equivale a um char

typedef struct{
    char nome[10];
    long int cpf;
    int idade;
}Pessoa;

int main(void){
    //TYPEDEF
    letra car;
    car = 'a';
    printf("%c\n", car);

    //STRUCT
    Pessoa Joao;
    strcpy(Joao.nome, "Joao");
    Joao.cpf = 123456789;
    Joao.idade = 18;

    printf("%s\n", Joao.nome);
    printf("%ld\n", Joao.cpf);
    printf("%d\n", Joao.idade);

    return 0;
}
#include <stdio.h>
#include <string.h>

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
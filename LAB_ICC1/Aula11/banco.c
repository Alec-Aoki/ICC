#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
Vocˆe ´e um gerente de banco e, a fim de conhecer melhor sua carteira de cr´edito, gostaria de realizar
uma capta¸c˜ao de dados do Banco de Dados e imprimir uma lista de todos os clientes junto a outra lista
que mostrar´a apenas os clientes endividados. Por isso, com os seus conhecimentos sobre computa¸c˜ao,
decide fazer um programa em C para organizar esses dados vindos do banco de dados para futuramente
realizar an´alises sobre os n´umeros.
O programa receber´a como entrada um n´umero inteiro (n) correspondente `a quantidade de dados
fornecidos e, nas pr´oximas n linhas, uma string nome (que dever´a ser alocada apenas o tamanho
necess´ario), um inteiro CPF (que pode ser tratado como char* para ocupar menos espa¸co), um
inteiro idade, um float saldo e um float cr´edito de cada registro, todos separados por v´ırgulas pela
formata¸c˜ao padr˜ao da base de dados. A partir de cada resgistro, obtenha os endividados, printe todos
os registros e, depois, os endividados como no caso teste abaixo.

• Utilize a biblioteca stdlib.h (para alocar) e string.h (para pegar o tamanho das strings).
• Utilize STRUCT para representar as pessoas.
• Em caso de n˜ao ocorrer a presen¸ca de nenhum endividado, deve ser impresso ”Nenhuma pessoa
endividada encontrada.”depois de ”Pessoas endividadas:”
• Só podemos alocar à string nome o tamanho necessário

-> receber número de pessoas
-> receber string nome
-> receber string CPF
-> receber int idade
-> receber float saldo
-> receber float crédito
*/

typedef struct{
    char *nome; //esse ponteiro vai apontar para o início do vetor na heap com o nome da pessoa
    char CPF[12]; //11 numeros e o \0
    int idade;
    float saldo;
    float credito;
    int tamanho_nome;
    bool endividado;
}pessoa;


int main (void){
    int numero_pessoas;
    scanf("%d", &numero_pessoas);

    //vetor da variável do tipo pessoa
    pessoa clientes[numero_pessoas];
    int quant_endividados=0;

    for(int i=0; i<numero_pessoas; i++){
        char nome_temp[31]; //string em que vamos temporariamente armazenar o nome da pessoa
        scanf(" %[^,],", &nome_temp);
        //alocando o nome da pessoa dinamicamente:
        clientes[i].nome = (char *)malloc(sizeof(char)*strlen(nome_temp));
        if (clientes[i].nome == NULL){
            printf("Deu ruim no malloc do nome\n");
        }
        //clientes[i].nome agora aponta para o nome da pessoa, que está heap
        //atribuindo cada caractere de nome_temp para o vetor na heap:
        for (int j=0; j<strlen(nome_temp); j++){
            clientes[i].nome[j] = nome_temp[j];
        }
        clientes[i].tamanho_nome = strlen(nome_temp);
        scanf(" %[^,],", &clientes[i].CPF);
        scanf("%d,", &clientes[i].idade);
        scanf("%f,", &clientes[i].saldo);
        scanf("%f", &clientes[i].credito);

        //checando se o cliente está endividado
        if ((clientes[i].saldo)-(clientes[i].credito)<0){
            //a pessoa está endividada
            clientes[i].endividado = true;
            quant_endividados++;
        }
        else {
            clientes[i].endividado = false;
        }
    }

    //printando todos os registros:
    for(int i=0; i<numero_pessoas; i++){
        printf("Dados da pessoa %d:\n", (i+1));
        printf("Nome: ");
        for (int j=0; j<clientes[i].tamanho_nome; j++){
            printf("%c", clientes[i].nome[j]);
        }
        printf("\n");
        printf("CPF: %s\n", clientes[i].CPF);
        printf("Idade: %d\n", clientes[i].idade);
        printf("Saldo: %.2f\n", clientes[i].saldo);
        printf("Credito: %.2f\n", clientes[i].credito);
        printf("\n");
    }

    //printando as pessoas endividadas:
    int flag_pessoas_endividadas = 0; //enquanto essa flag for zero, signifca q n teremos pessoas endividadas
    printf("Pessoas endividadas:\n");
    for (int i=0; i<numero_pessoas; i++){
        if(clientes[i].endividado){
            flag_pessoas_endividadas++;
            printf("Nome: ");
            for (int j=0; j<clientes[i].tamanho_nome; j++){
                printf("%c", clientes[i].nome[j]);
            }
            printf("\n");
            printf("CPF: %s\n", clientes[i].CPF);
            printf("Divida: %.2f\n", (clientes[i].credito - clientes[i].saldo));
            if (flag_pessoas_endividadas!=quant_endividados){
                printf("\n");
            }
        }
    }
    if (flag_pessoas_endividadas == 0){
        printf("Nenhuma pessoa endividada encontrada.\n");
    }

    for (int i=0; i<numero_pessoas; i++){
        free(clientes[i].nome);
    }
    return 0;
}
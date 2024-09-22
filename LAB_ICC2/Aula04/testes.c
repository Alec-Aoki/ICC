#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[51];
    int nota1;
    int nota2;
    int nota3;
}aluno;

int main(void){
    aluno *aluno1, *aluno2;
    aluno1 = (aluno *)malloc(sizeof(aluno));
    aluno2 = (aluno *)malloc(sizeof(aluno));
    float n1, n2, n3;

    printf("Digite o primeiro aluno:\n");
    scanf(" %50[^,],%f,%f,%f", aluno1->nome, &n1, &n2, &n3);
    aluno1->nota1 = (int)(10*n1);
    aluno1->nota2 = (int)(10*n2);
    aluno1->nota3 = (int)(10*n3);
    printf("Digite o segundo aluno:\n");
    scanf(" %50[^,],%f,%f,%f", aluno2->nome, &n1, &n2, &n3);
    aluno2->nota1 = (int)(10*n1);
    aluno2->nota2 = (int)(10*n2);
    aluno2->nota3 = (int)(10*n3);



    printf("Aluno 1: %s %d %d %d\n", aluno1->nome, aluno1->nota1, aluno1->nota2, aluno1->nota3);
    printf("Aluno 2: %s %d %d %d\n", aluno2->nome, aluno2->nota1, aluno2->nota2, aluno2->nota3);


    return 0;
}
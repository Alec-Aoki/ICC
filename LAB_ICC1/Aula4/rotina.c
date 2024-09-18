#include <stdio.h>
#include <stdbool.h>

int main (void){

    int dia_semana, var_int;
    bool var_bool;

    scanf("%d %d", &dia_semana, &var_int);

    var_bool = var_int;

    if (var_bool==true){
        switch(dia_semana){
        case 1:
            printf("Segunda: Aula de computacao\n");
            break;
        case 2:
            printf("Terca: Treino de volei\n");
            break;
        case 3:
            printf("Quarta: Aula de calculo\n");
            break;
        case 4:
            printf("Quinta: Lista de GA\n");
            break;
        case 5:
            printf("Sexta: Festa da Sacim\n");
            break;
        case 6:
            printf("Sabado: Jantar em familia\n");
            break;
        case 7:
            printf("Domingo: Depressao pos final de semana\n");
            break;
       }
    }
    else {
       switch(dia_semana){
        case 1:
            printf("Segunda: Aula de computacao\n");
        case 2:
            printf("Terca: Treino de volei\n");
        case 3:
            printf("Quarta: Aula de calculo\n");
        case 4:
            printf("Quinta: Lista de GA\n");
        case 5:
            printf("Sexta: Festa da Sacim\n");
        case 6:
            printf("Sabado: Jantar em familia\n");
        case 7:
            printf("Domingo: Depressao pos final de semana\n");
            break;
       }
    }


    return (0);
}


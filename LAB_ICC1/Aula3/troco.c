#include <stdio.h>

int main (void){

    float valor;
    int nota200=0, nota100=0, nota50=0, nota20=0, nota10=0, nota5=0, nota2=0, moeda1=0;

    scanf("%f", &valor);

    while(valor>0){
        if(valor-200>=0){
            nota200++;
            valor = valor - 200;
        }
        else if (valor-100>=0){
            nota100++;
            valor = valor - 100;
        }
        else if (valor-50>=0){
            nota50++;
            valor = valor - 50;
        }
        else if (valor-20>=0){
            nota20++;
            valor = valor - 20;
        }
        else if (valor-10>=0){
            nota10++;
            valor = valor - 10;
        }
        else if (valor-5>=0){
            nota5++;
            valor = valor - 5;
        }
        else if (valor-2>=0){
            nota2++;
            valor = valor - 2;
        }
        else if (valor-1>=0){
            moeda1++;
            valor = valor - 1;
        }
        else {
            break;
        }
    }

    printf("%d nota(s) de R$ 200\n", nota200);
    printf("%d nota(s) de R$ 100\n", nota100);
    printf("%d nota(s) de R$ 50\n", nota50);
    printf("%d nota(s) de R$ 20\n", nota20);
    printf("%d nota(s) de R$ 10\n", nota10);
    printf("%d nota(s) de R$ 5\n", nota5);
    printf("%d nota(s) de R$ 2\n", nota2);
    printf("%d moeda(s) de R$ 1\n", moeda1);

    return 0;
}
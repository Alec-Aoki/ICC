#include <stdio.h>

/*PSEUDOCÓDIGO:

int a, b, menor_primo=0, maior_primo;
ler a e b;

enquanto a<=b:
    conferir todos os valores entre 2 e a:
        se a for divisível por um número: 
            não é primo;
            break;
        senão:
            a é primo;
            if(menor_primo==0): menor_primo = a;
            else: maior_primo = a;
    a++;

*/

int main(void){

    int a, b, menor_primo=0, maior_primo, x=0;

    scanf("%d %d", &a, &b);

    while (a<=b){
        for (int i=1; i<a; i++){
            //printf("i: %d\n", i);
            if(a%i==0 && i!=1){
                x=0;
                break;
                }
            else{
                x=1;
            }
        }
        if (x==1){
            if(menor_primo==0){
                menor_primo=a;
            }
            maior_primo = a;
        }
        a++;
    }

    if (menor_primo==0){
        printf("nenhum primo no intervalo\n");
    }
    else {
        printf("menor primo: %d\n", menor_primo);
        printf("maior primo: %d\n", maior_primo);
    }

    return 0;
}
#include <stdio.h>

/*Converter um número de decimal para binário, recursivamente*/
void decimalToBinary(int n){
    if(n == 1){
        printf("1");
        return;
    }
    decimalToBinary(n/2);
    printf("%d", n%2);
}

/*MDC entre dois inteiros positivos, recursivamente
-> pegar o menor número entre p e q e atribuir a x
-> decrementar x se p%x!=0 OU q%x!=0 
*/
int MDC(int n1, int n2, int mdc){
    int temp;
    if(((n1%mdc) != 0) || ((n2%mdc) != 0)){
        temp = MDC(n1, n2, mdc-1);
        return temp;
    }

    return mdc;
}

int main(void){
    int n1;

    scanf("%d", &n1);

    decimalToBinary(n1);
    printf("\n");

    int n2;
    scanf("%d", &n2);

    if(n1>n2){
        printf("%d\n", MDC(n1, n2, n2));
    }
    else{
        printf("%d\n", MDC(n2, n1, n1));
    }
    return 0;
}
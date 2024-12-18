#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Soma dos n primeiro número naturais
    int Soma(int n){
        //Solução trivial:
        if (n == 1){
            return 1;
        }
        //Caso geral:
        else {
            return (Soma(n-1)+n);
        }
    }
        int n;
        printf("Digite n: ");
        scanf(" %d", &n);
        printf("Soma dos n num. naturais: %d\n", Soma(n));
*/

/*FATORIAL
F(1) = 1! = 1
F(2) = 2! = 2
F(3) = 3! = 3.2
F(4) = 4! = 4.3.2 = 4.F(3)
F(n) = n! = n.F(n-1)

    long int Fatorial(int n){
        if (n == 1 || n == 0){
            return 1;
        }
        else {
            return (n*(Fatorial(n-1)));
        }
    }
        long int n;
        scanf(" %ld", &n);
        printf("%ld\n", Fatorial(n));
*/

/*FIBONNACI
F(0) = 0
F(1) = 1
F(2) = 0 + 1 = F(0) + F(1) = 1
F(3) = 1 + 1 = F(1) + F(2) = 2
F(4) = 1 + 2 = F(2) + F(3) = 3
F(5) = 2 + 3 = F(3) + F(4) = 5
F(n) = F(n-2) + F(n-1)

    int Fibonnaci(int n){
        if (n == 0){
            return 0;
        }
        else if (n == 1){
            return 1;
        }
        else {
            return (Fibonnaci(n-1)+Fibonnaci(n-2));
        }
    }
    int n;
    scanf(" %d", &n);
    for (int i=0; i<=n; i++){
        printf("%d ", Fibonnaci(i));
    }
    printf("\n");
*/

/*Imprima os números naturais positivos anteriores a n em ordem crescente
OBS: printf dentro da função
A(0) = 0
A(1) = A(0), 1
A(2) = A(1), 2
A(n) = A(n-1), n
*/

void Anteriores(int n){
    if (n == 0){
        return;
    }
    Anteriores(n-1);
    printf("%d ", n);
    return;

}

int main (void){
    int n;
    scanf(" %d", &n);
    Anteriores(n);
    printf("\n");
    return 0;
}

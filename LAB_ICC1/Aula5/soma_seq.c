#include <stdio.h>

/*PSEUDOCÓDIGO:

float S = 1, termo=2;
receber N;
enquanto N != 0:
    se termo == par:
        S = S - (1/termo);
    senão:
        S = S + (1/termo);
    termo++;
    N--;
*/

int main (void){

    float S=1;
    int N, termo=2;
    
    scanf("%d", &N);

    if (N==0){
        S = 0;
        printf("%.4f\n", S);
    }

    else {
        while (N>1){
        if (termo%2==0){
            S = S - (1.0/termo);
        }
        else {
            S = S + (1.0/termo);
        }
        termo++;
        N--;
    }
        printf("%.4f\n", S);
    }
    return 0;
}
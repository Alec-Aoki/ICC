#include <stdio.h>
#include <math.h>

int main(void){

    int n1, n2;

    int i=9801;

    for (int i=1000; i<=9999; i++){

        n1 = i/100;
        n2 = i-(n1*100);

        if (sqrt(i)==(n1+n2)){
            printf("%d\n", i);
        }
    }

    return 0;
}
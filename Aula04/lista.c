#include <stdio.h>

int main (void){

    int reit, k=1;

    double S = 1, num, triroot;

    reit = 1000;

    for (int i=1; i<=reit; i++){
        k = k+2;
        if (i%2==0){
            S = S + 1.0/(k*k*k);
        }
        else {
            S = S - 1.0/(k*k*k);
        }
    }

    num = 32*S;

    for (float j=0.00001; j*j*j<=num; j=j+0.00001){
        triroot = j;
    }

    printf("%lf\n", triroot);

    return(0);
}

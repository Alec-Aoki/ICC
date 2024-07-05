#include <stdio.h>

// [0][C][B][A]

int main (void){

    unsigned short int A, B, C;
    long long int num_F=0;
    
    scanf("%hd %hd %hd", &A, &B, &C);

    num_F = C; //[0][0][0][C]

    num_F = num_F<<16; // [0][0][C][0]

    num_F += B; // [0][0][C][B]

    num_F = (num_F<<16); // [0][C][B][0]

    num_F += A; // [0][C][B][A]

    printf("%lld\n", num_F);

    return 0;
}
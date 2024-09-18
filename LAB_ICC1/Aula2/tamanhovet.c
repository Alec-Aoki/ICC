#include <stdio.h>

int main (){

    long int n;

    scanf("%ld", &n);

    int vet_int[n];
    char vet_char[n];
    double vet_double[n];

    printf("char: %ld\nint: %ld\ndouble: %ld\n", sizeof(vet_char), sizeof(vet_int), sizeof(vet_double));

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void){
    int M1, N1, M2, N2;
    scanf("%d %d", &M1, &N1);
    scanf("%d %d", &M2, &N2);

    /*Criação das matrizes*/
    /*Vetor de ponteiros (pont_m), que representa as linhas, com cada ponteiro apontando para uma parte do vetor grandão (v), que representa as colunas*/

    int **pont_m1 = (int **)malloc(M1*sizeof(int *));
    int *v1 = (int *)malloc((M1*N1)*sizeof(int));
    for(int i=0; i<M1; i++){
        pont_m1[i] = &v1[i*N1];
    }

    int **pont_m2 = (int **)malloc(M2*sizeof(int *));
    int *v2 = (int *)malloc((M2*N2)*sizeof(int));
    for (int i=0; i<M2; i++){
        pont_m2[i] = &v2[i*N2];
    }

    /*Leitura das matrizes*/
    for(int i=0; i<M1; i++){
        for(int j=0; j<N1; j++){
            scanf("%d", &pont_m1[i][j]);
        }
    }
    for(int i=0; i<M2; i++){
        for(int j=0; j<N2; j++){
            scanf("%d", &pont_m2[i][j]);
        }
    }

    /*Printando as matrizes*/
    for(int i=0; i<M1; i++){
        for(int j=0; j<N1; j++){
            if(j!=(N1-1)){
                printf("%d ", pont_m1[i][j]);
            }
            else{
                printf("%d\n", pont_m1[i][j]);
            }
        }
    }
    for(int i=0; i<M2; i++){
        for(int j=0; j<N2; j++){
            if(j!=(N2-1)){
                printf("%d ", pont_m2[i][j]);
            }
            else{
                printf("%d\n", pont_m2[i][j]);
            }
        }
    }

    /*Criação da matriz 3*/
    int **pont_m3 = (int **)calloc(M1, sizeof(int *));
    int *v3 = (int *)calloc((M1*N2), sizeof(int));
    for(int i=0; i<M1; i++){
        pont_m3[i] = &v3[i*N2];
    }

    printf("Multiplicando as matrizes...\n");

   for(int i=0; i<M1; i++){
    for(int j=0; j<N2; j++){
        for(int k=0; k<N1; k++){
            pont_m3[i][j] += pont_m1[i][k]*pont_m2[k][j]; 
        }
    }
   }

   for(int i=0; i<M1; i++){
    for(int j=0; j<N2; j++){
        if(j!=(N2-1)){
                printf("%d ", pont_m3[i][j]);
            }
        else{    
            printf("%d\n", pont_m3[i][j]);
        }
    }
   }
    return 0;
}
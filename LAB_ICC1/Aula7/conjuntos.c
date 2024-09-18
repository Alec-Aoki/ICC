#include <stdio.h>

int main(void){

    int n1, n2, k=0, m=0, flag=1;

    scanf ("%d", &n1);
    int vet1[n1];
    for (int i=0; i<n1; i++){
        scanf("%d", &vet1[i]);
    }

    scanf ("%d", &n2);
    int vet2[n2];
    for (int i=0; i<n2; i++){
        scanf("%d", &vet2[i]);
    }

    int intersec[100], menos[100];

    menos[0] = 0;
    intersec[0] = 0;

        for (int i=0; i<n1; i++){
            flag = 1;
            for (int j=0; j<n2; j++){
                if (vet1[i]==vet2[j]){
                    intersec[k] = vet1[i];
                    k++;
                    flag = 0;
                    break;
                }
            } // fim do for interior
            if (flag == 1){
                menos[m] = vet1[i];
                m++;
            }
        }

        printf("intersecao: ");
        if (intersec[0]!=0){
            for (int i=0; i<k; i++){
                printf("%d ", intersec[i]);
            }
        }
        else {
            printf("vazio");
        }
        printf("\n");

        printf("a - b: ");
        if (menos[0]!=0){
            for (int i=0; i<m; i++){
                printf("%d ", menos[i]);
            }
        }
        else {
            printf("vazio");
        }
        printf("\n");
        
    return 0;
}
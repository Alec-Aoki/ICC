#include <stdio.h>

int main(void){

    int v[10], cont=0;

    for (int i=0; i<10; i++){
        scanf("%d", &v[i]);
    }

    for (int i=0; i<10; i++){
        if ((v[i]%2==0) && (v[i]>10)){
            cont++;
        }
    }

    printf("%d\n", cont);

    return 0;
}
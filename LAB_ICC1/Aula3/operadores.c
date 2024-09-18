#include <stdio.h>

int main(void){

    int n1, n2;

    scanf("%d %d", &n1, &n2);

    if (n1>n2 && (n1-n2)%3==0){
        printf("%d", n1+n2);
    }
    else if (n2>n1 && (n1+n2)>400){
        printf("%d", n1+n2);
    }
    else if (n1==n2 && n1%2!=0){
        printf("%d", n1+n2);
    }
    else {
        printf("Nenhuma condicao foi satisfeita\n");
    }

    return 0;
}
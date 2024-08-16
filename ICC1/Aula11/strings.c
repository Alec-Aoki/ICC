#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char str[101];
    char *s;
    s = fgets(str,101,stdin);
    //obs: podemos tirar o s
    printf("\n%s", str);
    printf("%s", s);

    //usando alocação dinâmica
    char *p;
    p = (char *)malloc(101*sizeof(char));
    fgets(p, 101, stdin);
    printf("\n%s", p);
    free(p);
    
    return 0;
}
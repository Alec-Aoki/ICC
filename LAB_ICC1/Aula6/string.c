#include <stdio.h>

int main(void){

    char a[26];
    char *p;

    p = &a[0];
    
    scanf("%[^\n]s", &a);

    while(*p!='\0'){
        printf("%c\n", *p);
        p++;
    }

    return 0;
}
#include <stdio.h>
/*

n1      1A  n2  
n2      2A  n1 
pn1     3A  1A  
pn2     4A  2A  
n3      5A  n1  

*/
int main (void){

    int n1, n2, n3, *pn1, *pn2;

    scanf("%d %d", &n1, &n2);

    pn1 = &n1;
    pn2 = &n2;

    n3 = *pn1;

    *pn1 = *pn2;

    *pn2 = n3;

    printf("%d %d\n", *pn1, *pn2);
    
    return 0;
}
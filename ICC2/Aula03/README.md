# MERGE SORT
-> ordenação por intercalação <br />
-> O(nlog(n)) <br />
-> T(n) = O(1), n = 1 <br />
-> T(n) = 2*T(n/2) + O(n), n>1 <br />
1. quebrar o array na metade até que se obtenha arrays unitários
2. ordernar os dois arrays e uní-los
3. repetir

```
{} indica o meio
                9 3 {1} 4 2 5
    9 {3} 1                     4 {2} 5
    {9} 3       {1}          4 {2}      {5}
 {9}     {3}    {1}       {4}    {2}    {5}
     3 9         1           2 4         5
          1 3 9                   2 4 5
                  1 2 3 4 5 9
```

## Implementação
```c
#include <stdio.h>

void intercala(int esquerda[], int tam_esq, int direita[], int tam_dir, int v[]);
void mergesort(int v[], int tam);

int main(void){
    int v[] = {5, 2, 1, 4, 7, 3, 9};

    mergesort(v, 7);

    for(int i=0; i<7; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

void intercala(int esquerda[], int tam_esq, int direita[], int tam_dir, int v[]){

    int i=0, e=0, d=0;

    /*escrevendo de volta no vetor v*/
    while((e < tam_esq) && (d < tam_dir)){
        if(esquerda[e] < direita[d]){
            v[i] = esquerda[e];
            e++;
        }
        else{
            v[i] = direita[d];
            d++;
        }
        i++;
    }

    /*caso não sobre elementos em um vetor para compararmos*/
    while(e < tam_esq){
        v[i] = esquerda[e];
        e++;
        i++;
    }
    while(d < tam_dir){
        v[i] = direita[d];
        d++;
        i++;
    }

    return;
}

void mergesort(int v[], int tam){
    if(tam == 1){
        return;
    }

    int meio = tam/2;
    int esquerda[meio], direita[tam-meio];

    /*dividindo o vetor v[] em dois (esquerda[] e direita[]), e passando os valores pra cada um*/
    int e=0, d=0;
    for(int i=0; i<tam; i++){
        if(i < meio){
            esquerda[e] = v[i];
            e++;
        }
        else{
            direita[d] = v[i];
            d++;
        }
    }

    mergesort(esquerda, meio); //note que v[] é o vetor esquerda[]!
    mergesort(direita, tam-meio);
    intercala(esquerda, meio, direita, tam-meio, v);

    return;
}
```

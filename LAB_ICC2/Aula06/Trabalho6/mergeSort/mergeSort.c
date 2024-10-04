#include <stdio.h>

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
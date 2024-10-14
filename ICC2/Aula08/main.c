#include <stdio.h>
#include <string.h>

#define tam 8

void contagem_menores(int mainVet[], int tamanho);
void countingSort(int v[], int tamanho);

int main(void){
    int v[] = {12, 92, 33, 25, 86, 57, 37, 48};

    //contagem_menores(v, tam);
    countingSort(v, tam);

    for(int i=0; i<tam; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

void countingSort(int v[], int tamanho){
    int valorMax = -1;

    //passo 1
    for(int i=0; i<tamanho; i++){
        if(v[i] > valorMax) valorMax = v[i];
    }

    //passo 2
    int vetFreq[valorMax + 1];
    memset(vetFreq, 0, sizeof(int)*(valorMax + 1)); 
    //inicializando o vetor vetFreq com 0

    for(int i=0; i<tamanho; i++){
        vetFreq[v[i]]++;
    }

    //passo 3
    for(int i=1; i<valorMax+1; i++){
        vetFreq[i] += vetFreq[i-1];
    }

    //passo 4
    for(int i=valorMax; i>0; i--){
        vetFreq[i] = vetFreq[i-1];
    }
    vetFreq[0] = 0;

    int vAux[tamanho];
    //passo 5
    for(int i=0; i<tamanho; i++){
        vAux[vetFreq[v[i]]] = v[i];
        vetFreq[v[i]]++;
    }
    for(int i=0; i<tamanho; i++){
        v[i] = vAux[i];
    }

    return;
}

void contagem_menores(int mainVet[], int tamanho){
    int auxVet_1[tamanho], auxVet_2[tamanho];

    /*contando os menores*/
    for(int i=0; i<tamanho; i++){
        auxVet_2[i] = mainVet[i];
        //copiando o vetor principal no vet2

        int quantMenores = 0;
        for(int j=0; j<tamanho; j++){
            if(mainVet[j] < mainVet[i]) quantMenores++;
        }
        auxVet_1[i] = quantMenores;
    }

    /*copiando de volta no vetor principal*/
    for(int i=0; i<tamanho; i++){
        mainVet[auxVet_1[i]] = auxVet_2[i];
    }

    return;
}
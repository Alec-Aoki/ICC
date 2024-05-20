#include <stdio.h>

/* ARRAYS/VETORES/ARRANJOS
-> coleção de variáveis (elementos) do mesmo tipo referenciadas por um nome/identificador comum, indiciado
-> ocupam posições contíguas na memória
-> podem ter mais de uma dimensão (em C)

Caso Unidimensional:
    tipo identificador[tamanho];
    OBS: tamanho pode ser qualquer expressão que retorna um inteiro (OBS: 1>=10 retorna 0, então é válido)
    OBS: todo vetor começa no índice 0

Exemplo:
    int vet[5], *p;
    p = vet; // p vai apontar para o endereço base do vetor (endereço do primeiro byte do primeiro índice)

    int v[3] = {1, 2, 3}; // válido


OBS: vet é um ponteiro estático, SEMPRE apontando para o endereço base do vetor
        não dá pra mudar o valor de vet

Exemplo:
    int a[5], b;
    a[0]=100;
    b = a; // a = &a[0]
    printf("%d\n", b); //printa o endereço base do vetor

OBS: C não verifica limites de array, ele compila msm se estiver errado

Exemplo:
    int soma=0, v[1000], *p;

    p = v;

    for (int i=0; i<1000; i++){
        v[i] = i;
        // soma += v[i];
        soma += *p;
        // soma += p[i]; // é válido
        p++;
    }

    printf("%d\n", soma);

    // OBS: um jeito mais otimizado de fazer esse código seria armazenar a soma na posição 0 do vetor

*/

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
#include <stdio.h>

/*
Para facilitar esse registro, vocˆe desenvolver´a um programa em C que te d´a a
coloca¸c˜ao dos competidores na ordem de entrada. O programa receber´a como entrada o n´umero de
atletas (n) e, nas pr´oximas n linhas, a pontua¸c˜ao de cada atleta (1º ... nº). Com base nesses dados,
o programa deve imprimir a lista na mesma ordem em que recebeu, imprimindo o n´umero do atleta,
a quantidade de pontos e sua coloca¸c˜ao

Ordem de entrada do atleta
Sua pontuacao
Sua colocacao

-> receber quantidade de atletas
-> guardar a pontuacao de cada atleta em um vetor A
    -> usaremos o vetor A para printar a ordem e a pontuacao do atleta
-> copiar o vetor A para um vetor B
-> ordernar o vetor B
-> comparar a pontuacao do vetor A com o vetor B
*/

void ordernar_atletas (int quant_atletas){
    int pontuacao_original[quant_atletas], pontuacao_ordenada[quant_atletas], aux, colocacao;

    //recebendo a pontuacao no vetor A e B
    for (int i=0; i<quant_atletas; i++){
        scanf("%d", &pontuacao_original[i]);
        pontuacao_ordenada[i] = pontuacao_original[i];
    }

    //Bubblesort
    for (int i=0; i<quant_atletas; i++){
        for (int j=1; j<quant_atletas; j++){
            if(pontuacao_ordenada[j]>pontuacao_ordenada[j-1]){
                aux = pontuacao_ordenada[j];
                pontuacao_ordenada[j] = pontuacao_ordenada[j-1];
                pontuacao_ordenada[j-1] = aux;
            }
        }
    }

    for (int i=1; i<quant_atletas; i++){
        if (pontuacao_ordenada[i]==pontuacao_ordenada[i-1]){
            pontuacao_ordenada[i] = 0;
        }
    }

    //Bubblesort
    for (int i=0; i<quant_atletas; i++){
        for (int j=1; j<quant_atletas; j++){
            if(pontuacao_ordenada[j]>pontuacao_ordenada[j-1]){
                aux = pontuacao_ordenada[j];
                pontuacao_ordenada[j] = pontuacao_ordenada[j-1];
                pontuacao_ordenada[j-1] = aux;
            }
        }
    }

    //imprimir os atletas
    for (int i=0; i<quant_atletas; i++){

        //achar a colocacao do atleta i comparando os dois vetores
        for (int j=0; j<quant_atletas; j++){
            if (pontuacao_ordenada[j]==pontuacao_original[i] && pontuacao_ordenada[j]!=0){
                colocacao = j+1;
            }
            else if (pontuacao_ordenada[j]==pontuacao_original[i] && pontuacao_ordenada[j]==0) {
                colocacao = j;
            }
        }
        printf("%dº Atleta, %d Pontos, %dº Colocado\n", i+1, pontuacao_original[i], colocacao);
        
    }
}

int main(void){

    int quant_atletas;

    scanf(" %d", &quant_atletas);

    ordernar_atletas(quant_atletas);

    return 0;
}
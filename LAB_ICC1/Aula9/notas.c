#include <stdio.h>

/*
Leia_Matriz
Imprima_Nota_Aluno
Imprima_Media_Exercicio

Para cada aluno, imprima uma linha contendo a m´edia simples (com precis˜ao de 2 casas decimais)
e o status “aprovado” ou “reprovado”, como representado no exemplo de sa´ıda abaixo. Pule uma
linha e, na sequˆencia, imprima em uma ´unica linha as notas m´edias de cada exerc´ıcio, em ordem
decrescente, cada nota com 2 casas de precis˜ao, separada por um espa¸co em branco. Nota: ap´os a
´ultima nota, segue uma quebra de linha, sem espa¸co em branco.
*/

//para a leitura/manipulação de valores da matriz, vamos usar um ponteiro que aponta para sua posicao inicial

void Leia_Matriz(int M, int N, float *ponteiro_Leia){
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            scanf(" %f", ponteiro_Leia);
            ponteiro_Leia++;
        }
    }
    return;
}

void Imprima_Nota_Aluno(int M, int N, float *ponteiro_Nota){
    float nota=0;
    for (int j=0; j<M; j++){
        //leitura de cada linha da matriz na memoria stack, ou seja, cada nota deo aluno j
        for (int i=0; i<N; i++){
            nota = nota + (*ponteiro_Nota);
            ponteiro_Nota++;
        }
        printf("Media do aluno %d = %.2f", j+1, nota/N);
        if (nota/N >= 5.0){
            printf(" : Aprovado\n");
        }
        else {
            printf(" : Reprovado\n");
        }
        nota = 0; //zeramos a nota pois vamos para a proxima linha (proximo aluno)
    }
    return;
}

void Imprima_Media_Exercicio(int M, int N, float matriz[][N]){
    float media=0, vet[N], aux;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            media = media + matriz[j][i];
        }
        vet[i] = media/M;
        media = 0;
    }

    // Bubblesort para ordernar as medias em ordem decrescente
    for (int i=0; i<N; i++){
        for (int j=1; j<N; j++){
            if (vet[j-1]<vet[j]){
                aux = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = aux;
            }
        }
    }

    for (int i=0; i<N; i++){
        if(i!=(N-1)){
            printf("%.2f ", vet[i]);
        }
        else{
            printf("%.2f\n", vet[i]);
        }
    }

    return;
}

int main(void){
    int aluno, trabalho;
    scanf(" %d %d", &aluno, &trabalho);
    float tabela[aluno][trabalho];

    Leia_Matriz(aluno, trabalho, &tabela[0][0]);

    Imprima_Nota_Aluno(aluno, trabalho, &tabela[0][0]);

    printf("\n");

    Imprima_Media_Exercicio(aluno, trabalho, tabela);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
    /*
    Implemente um programa em C que leia 2 vetores (lendo o tamanho do vetor antes), os veto-
    res s˜ao compostos por n´umeros inteiros(positivos e negativos) n˜ao ordenados, os vetores devem ser
    compreendidos como conjuntos A e B.
    O programa DEVE conter uma fun¸c˜ao que retorna o conjunto A uni˜ao B e outra que retorne
    o conjunto (A uni˜ao B) - (A intersec¸c˜ao B), os vetores retornados devem ocupar somente o espa¸co
    estritamente necess´ario. Em seguida, o programa deve imprimir os conjuntos como mostrado no
    exemplo abaixo

    OBRIGAT ´ORIO que as duas fun¸c˜oes especificadas retornem vetores, e que esses vetores
    ocupem somente o espa¸co utilizado.
    • Os elementos dos conjuntos impressos devem estar ordenados.
    • caso o conjunto seja vazio, deve ser impresso ”vazio”.

    main:
    -> ler tamanho dos vetores
    -> receber comeco dos vetores em dois ponteiros diferentes
    -> criar vetor pra uniao e interseccao
    -> ordernar elementos da uniao e interseccao

    Leia_Elementos:
    -> calloc
    -> retorna ponteiro para o inicio desse vetor

    Ordene_Elementos:
    -> bubble sort neles
    -> usar indicies
    -> return nada

    Uniao_AB:
    -> criar vetor Uniao
        -> do tamamho de A
    -> jogar A no vetor Uniao
    -> verificar se o elemento de B ja existe em Uniao
        -> se sim: nada
        -> senao: add um espaço no Uniao e colocar o valor

    Intersec_AB:
    -> criar o vetor Intersec, tamanho 1
    -> comparar A com B
        -> se o elemento for igual: jogar ele no Intersec
        -> senao: nada
    */

int *Leia_Elementos(int tam){
    int *ponteiro_Leia;
    ponteiro_Leia = (int *)calloc(tam, sizeof(int));
    // acabamos de criar o vetor na memória heap
    if (ponteiro_Leia == NULL){
        exit(1);
    }
    //leitura dos elementos do vetor:
    for (int i=0; i<tam; i++){
        scanf(" %d", &ponteiro_Leia[i]);
    }
    //retornando o endereço do começo do vetor na heap:
    return ponteiro_Leia;
}

void Ordene_Elementos(int tam, int *ponteiro_Ordene){
    int aux;
    //Bubblesort
    for (int i=0; i<tam; i++){
        for (int j=1; j<tam; j++){
            if (ponteiro_Ordene[j] < ponteiro_Ordene[j-1]){
                aux = ponteiro_Ordene[j];
                ponteiro_Ordene[j] = ponteiro_Ordene[j-1];
                ponteiro_Ordene[j-1] = aux;
            }
        }
    }
    return;
}

int *Uniao_AB(int *tam_Uniao, int tam_A, int tam_B, int *ponteiro_UA, int *ponteiro_UB){
    int flag = 0, tam_novo=tam_A;
    /*
    -> criar vetor Uniao
        -> do tamamho de A
    -> jogar A no vetor Uniao
    -> verificar se o elemento de B ja existe em Uniao
        -> se sim: fodase
        -> se nao: add um espaço no Uniao e colocar o valor*/
    int *pont_vet_Uniao;
    pont_vet_Uniao = (int *)calloc(tam_A, sizeof(int));

    //jogando os valores de A em Uniao
    for (int i=0; i<tam_A; i++){
        pont_vet_Uniao[i] = ponteiro_UA[i];
    }

    for (int i=0; i<tam_B; i++){
        flag = 0;
        for (int j=0; j<tam_A; j++){
            if (ponteiro_UB[i] == pont_vet_Uniao[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            tam_novo += 1;
            pont_vet_Uniao = (int *)realloc(pont_vet_Uniao, (tam_novo*sizeof(int)));
            pont_vet_Uniao[tam_novo-1] = ponteiro_UB[i];
        }
    }

    *tam_Uniao = tam_novo;

    return pont_vet_Uniao;
}

int *Intersec_AB(int *tam_Intersec, int tam_A, int tam_B, int *ponteiro_UA, int *ponteiro_UB){
    int tam_Intersec_func=0;
    /*
    Intersec_AB:
    -> criar o vetor Intersec, tamanho 1
    -> comparar A com B
        -> se o elemento for igual: jogar ele no Intersec
        -> senao: nada*/
    int *pont_vet_Intersec;

    //verificando cada elemento de B em relacao a A
    for (int i=0; i<tam_B; i++){
        for (int j=0; j<tam_A; j++){
            if (ponteiro_UB[i] == ponteiro_UA[j]) {
                if (i==0){
                    pont_vet_Intersec = (int *)calloc(1, sizeof(int));
                    //não criar Intersec evita colocarmos um zero em seu começo, que é chato de tirar depois
                }
                tam_Intersec_func += 1;
                pont_vet_Intersec = (int *)realloc(pont_vet_Intersec, tam_Intersec_func*sizeof(int));
                pont_vet_Intersec[tam_Intersec_func-1] = ponteiro_UB[i];
            }
        }
    }

    *tam_Intersec = tam_Intersec_func;

    return pont_vet_Intersec;
}

int *Diferenca_UI(int *tam_Diff, int tam_Uniao, int tam_Intersec, int *ponteiro_U, int *ponteiro_I){
    int *ponteiro_Diff;
    int flag = 0, tam_Diff_func=0;

    for (int i=0; i<tam_Uniao; i++){
        flag = 0;
        for (int j=0; j<tam_Intersec; j++){
            if ((ponteiro_U[i] == ponteiro_I[j]) && (ponteiro_U[i] != 0)){
                //obs: temos ponteiro_U[i] != 0 para o caso em que A ou B = vazio
                //temos um numero igual
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            if (i == 0){
                    ponteiro_Diff = (int *)calloc(1, sizeof(int));
            }
            tam_Diff_func += 1;
            ponteiro_Diff = (int *)realloc(ponteiro_Diff, tam_Diff_func*sizeof(int));
            ponteiro_Diff[tam_Diff_func-1] = ponteiro_U[i];
        }
    }

    *tam_Diff = tam_Diff_func;
    return ponteiro_Diff;
}

void Imprima_Resultados(int tam_A, int tam_B, int tam_Uniao, int tam_Diff, int *ponteiro_A, int *ponteiro_B, int *ponteiro_Uniao, int *ponteiro_Diff){
    /*Temos um caso excepcional no código, que é quando A = B
    Devido à forma como a intersecção foi feita, temos que ela sempre terá um zero em seu início
    Para A=B, tam_A = tam_B. Se essa condição for satisfeita, teremos flag_1 = 1
    Caso A!=B, flag_1 = 1
    Assim, temos A = B (Uniao - Intersec = vazio) quando flag_1 = 1 e flag_2 = 0
    */
    int flag_1 = 0, flag_2 = 0;
    if (tam_A == tam_B){
        flag_1 = 1;
        for (int i=0; i<tam_A; i++){
            if (ponteiro_A[i] != ponteiro_B[i]){
                flag_2 = 1;
                break;
            }
        }
    }

    printf("conjunto A: ");
    if (tam_A == 0){
        printf("vazio\n");
    }
    else {
        for (int i=0; i<tam_A; i++){
            if (i!=(tam_A-1)){
                printf("%d ", ponteiro_A[i]);
            }
            else {
                printf("%d\n", ponteiro_A[i]);
            }
        }
    }

    printf("conjunto B: ");
    if (tam_B == 0){
        printf("vazio\n");
    }
    else{
        for (int i=0; i<tam_B; i++){
            if (i!=(tam_B-1)){
                printf("%d ", ponteiro_B[i]);
            }
            else {
                printf("%d\n", ponteiro_B[i]);
            }
        }
    }

    printf("A uniao B: ");
    if ((tam_A == 0) && (tam_B == 0)){
        printf("vazio\n");
    }
    else{
        for (int i=0; i<tam_Uniao; i++){
            if (i!=(tam_Uniao-1)){
                printf("%d ", ponteiro_Uniao[i]);
            }
            else {
                printf("%d\n", ponteiro_Uniao[i]);
            }
        }
    }

    printf("(A uniao B) - (A interseccao B): ");
    if ((tam_A == 0) && (tam_B == 0)){
        printf("vazio\n");
    }
    else if ((flag_1 == 1) && (flag_2 == 0)){
        printf("vazio\n");
    }
    else{
        for (int i=0; i<tam_Diff; i++){
            if (i!=(tam_Diff-1)){
                printf("%d ", ponteiro_Diff[i]);
            }
            else {
                printf("%d\n", ponteiro_Diff[i]);
            }
        }
    }
    return;
}

int main(void){
    int tam_A, tam_B, *ponteiro_A, *ponteiro_B;
    scanf(" %d", &tam_A);
    //ponteiro_A recebe o endereço do começo do vetor na heap
    ponteiro_A = Leia_Elementos(tam_A);
    Ordene_Elementos(tam_A, ponteiro_A);
    scanf(" %d", &tam_B);
    //ponteiro_B recebe o endereço do começo do vetor na heap
    ponteiro_B = Leia_Elementos(tam_B);
    Ordene_Elementos(tam_B, ponteiro_B);

    int *ponteiro_Uniao, *ponteiro_Intersec;
    int tam_Uniao, tam_Intersec;
    //ponteiro_Uniao aponta para o começo do vetor Uniao na heap
    ponteiro_Uniao = Uniao_AB(&tam_Uniao, tam_A, tam_B, ponteiro_A, ponteiro_B);
    //ordenando o vetor Uniao
    Ordene_Elementos(tam_Uniao, ponteiro_Uniao);
    //mesma coisa, so que com o Intersec
    ponteiro_Intersec = Intersec_AB(&tam_Intersec, tam_A, tam_B, ponteiro_A, ponteiro_B);
    Ordene_Elementos(tam_Intersec, ponteiro_Intersec);

    int *ponteiro_Diff;
    int tam_Diff;
    //ponteiro_Diff aponta para o começo do vetor Diff na heap
    ponteiro_Diff = Diferenca_UI(&tam_Diff, tam_Uniao, tam_Intersec, ponteiro_Uniao, ponteiro_Intersec);
    
    Imprima_Resultados(tam_A, tam_B, tam_Uniao, tam_Diff, ponteiro_A, ponteiro_B, ponteiro_Uniao, ponteiro_Diff);

    free(ponteiro_Uniao);
    free(ponteiro_Intersec);
    free(ponteiro_Diff);
    return 0;
}
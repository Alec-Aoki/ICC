#include <stdio.h>
#include <string.h>

int main(void){
    char string_A[131];
    char string_B[131];
    char parametro[21];

    char *pont_parametro;

    scanf(" %[^\n]s", &string_A);
    scanf(" %[^\n]s", &string_B);
    scanf(" %s", &parametro);
    
    string_A[strlen(string_A)] = '\0';
    string_B[strlen(string_B)] = '\0';

    char aux;
    int eh_vazio=1;

    pont_parametro = strstr(string_A, parametro); //strstr() retorna um ponteiro apontando para o início
    //da palavra parametro dentro do vetor string_A
    if (pont_parametro == NULL){
        for(int i=0; i<(strlen(string_A)-1); i++){
            printf("%c", string_A[i]);
        }
        eh_vazio = 0;
    }
    else {
        *pont_parametro = '\0';
        aux = string_A[0];
        if (aux != '\0'){
            eh_vazio = 0;
            pont_parametro--;
            *pont_parametro = '\0';
            printf("%s", string_A);
        }
    }
    
    pont_parametro = strstr(string_B, parametro);
    if (pont_parametro != NULL){
        while(*pont_parametro != ' '){
            pont_parametro++;
        }
        if(eh_vazio){
            pont_parametro++;
        }
        while (*pont_parametro != '\0'){
            printf("%c", *pont_parametro);
            pont_parametro++;
        }
    }
    printf("\n");

    return 0;
}
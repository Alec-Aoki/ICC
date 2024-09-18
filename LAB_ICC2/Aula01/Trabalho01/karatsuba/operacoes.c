#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

// Soma de dois números representados por strings
char* add(char* str1, char* str2) {
    int tam = max(strlen(str1), strlen(str2));
    int carry = 0;
    int sum = 0;

    char* res = calloc(tam + 2, sizeof(char));

    // Adiciona zeros à esquerda para igualar o tamanho das strings
    char* tmp1 = calloc(tam + 1, sizeof(char));
    char* tmp2 = calloc(tam + 1, sizeof(char));
    memset(tmp1, '0', tam);
    memset(tmp2, '0', tam);
    strcpy(tmp1 + (tam - strlen(str1)), str1);
    strcpy(tmp2 + (tam - strlen(str2)), str2);

    for (int i = tam - 1; i >= 0; i--) {
        sum = carry + (tmp1[i] - '0') + (tmp2[i] - '0');
        res[i + 1] = (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) {
        res[0] = carry + '0';
        free(tmp1);
        free(tmp2);
        return res;
    } else {
        free(tmp1);
        free(tmp2);
        return res + 1;
    }
}

// Subtração de dois números representados por strings
char* sub(char* str1, char* str2) {
    int tam1 = strlen(str1);
    int tam2 = strlen(str2);
    int tam = max(tam1, tam2); 

    char* res = calloc((tam + 2), sizeof(char));
    memset(res, '0', tam + 1);

    int empresta = 0, i = tam1 - 1, j = tam2 - 1, k = tam;

    while (i >= 0 || j >= 0 || empresta) {
        int digito1 = (i >= 0) ? str1[i--] - '0' : 0;
        int digito2 = (j >= 0) ? str2[j--] - '0' : 0;
        digito2 += empresta;

        if (digito1 < digito2) {
            digito1 += 10;
            empresta = 1;
        } else {
            empresta = 0;
        }

        res[k--] = (digito1 - digito2) + '0';
    }

    while (*res == '0' && *(res + 1)) res++;

    return res;
}

// Multiplica um número, representado por uma string, por uma potência de 10
char* potencia_de_10(const char* str, int potencia) {
    int tam = strlen(str);
    char* res = calloc(tam + potencia + 1, sizeof(char));

    strcpy(res, str);
    for (int i = 0; i < potencia; i++) {
        res[tam + i] = '0';
    }
    res[tam + potencia] = '\0';

    return res;
}

char* multiplicacao(const char* str1, const char* str2){
    int tam_str1 = strlen(str1); //strlen() já não conta o \0
    int tam_str2 = strlen(str2);

    int tamstrResposta = tam_str1 + tam_str2 + 2; //\0 + 1
    //o maior tamanho possível do produto entre dois números é a soma do tamanho desses dois números + 1

    char *strResposta = (char *)malloc(tamstrResposta*sizeof(char));
    if(strResposta == NULL) exit(1);

    /*preenchendo strResposta com zeros*/
    memset(strResposta, '0', tamstrResposta + 1);
    strResposta[tamstrResposta-1] = '\0';

    for(int i=tam_str2-1; i>=0; i--){

        int contadorResposta = tamstrResposta-2; //-2 pois ignoramos o espaço do \0 e pq o index começa no 0

        int carry = 0;
        int sum = 0; //"quociente"

        for(int j=tam_str1-1; j>=0; j--){ 
            //OBS: - '0' transforma char em int

            int produtoTemporario = (str1[j]-'0')*(str2[i]-'0') + (strResposta[contadorResposta]-'0');
            //+ (strResposta[contadorResposta]-'0') soma ao produto dos dois dígitos o carry do produto anterior, armazenado, durante a iteração anterior, no próximo espaço a ser utilizado no vetor Resposta
            
            sum = produtoTemporario%10;
            strResposta[contadorResposta] = sum+'0';
            //exemplo: 3*6 = 18
            // 18/10 -> carry = 1, sum = 8
            // sum será o dígito armazenado no vetor Resposta

            carry = produtoTemporario/10; //como é um int, automaticamente pega o quociente

            if(strResposta[contadorResposta-1] == '9' && carry == 1){
                strResposta[contadorResposta-1] = '0';
                strResposta[contadorResposta-2] = (strResposta[contadorResposta-2]-'0' + 1)+'0';
            }
            else{
                strResposta[contadorResposta-1] = ((strResposta[contadorResposta-1]-'0') + carry)+'0'; //guarda o carry no próximo espaço do vetor Resposta
            }
            contadorResposta--;
        }
        tamstrResposta--;
    }

    return strResposta;
}
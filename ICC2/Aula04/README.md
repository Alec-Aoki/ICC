# Métodos de Ordenação
-> se a busca for feita somente ocasionalmente, não é interessante ter que ordernar o conjunto inteiro (O(n)) <br />
-> se a busca for feita repetidamente, ordenar o conjunto vale a pena, já que terá que ser feita somente uma vez (O(n*log(n)) + O(log(n)))

## Terminologia/Conceitos
- ordenação de registros
    - cada registro é ordenado por sua **chave**!
    - registros complexos: + de uma informação
    - registros não-complexos: uma só informação
    - métodos de ordenação independem da complexidade do registro
- ordenação **interna x externa**
    - interna: ordenação utilizando a memória principal
    - externa: ordenação fora da memória principal (em arquivos, por exemplo)
- ordenação **estável**
    - a ordenação mantém, se viável, a ordem original dos elementos
    - ex: 2a 1b 3d 1a -> 1b 1a 2a 3d (1b se manteve antes de 1a pois a ordenação é estável)
- ordenação sobre os próprios registros
    - os registros trocam de posição
- ordenação por endereços
    - utiliza ponteiros que apontam para os registros
    - a ordem de registros se mantém a mesma
    - os ponteiros mudam os endereços para que apontam, de forma que o primeiro ponteiro aponte para a chave 1, o segundo para a chave 2, e assim por diante

-> exemplo de ordenação sobre os próprios registros:
```c
#include <stdio.h>
#include <string.h>

typedef struct{
    int chave;
    char valor[10];
}str_t;

void swap(str_t *a, str_t *b);

int main(void){
    str_t a, b;

    a.chave = 2;
    strcpy(a.valor, "aaa");

    b.chave = 3;
    strcpy(b.valor, "bbb");

    swap(&a, &b);

    printf("%d %s\n", a.chave, a.valor);
    printf("%d %s\n", b.chave, b.valor);

    return 0;
}

void swap(str_t *a, str_t *b){
    str_t aux;

    aux = *a;
    *a = *b;
    *b = aux;
}
```

## Bubblesort
-> percorrer o vetor múltiplas vezes e comparar os elementos na posição *i* e *i+1* <br />
-> se o elemento na posição *i* for maior que a posição *i+1*, trocar eles de lugar <br />
-> para um vetor de *n* elementos, são necessárias *n-1* iterações em um passo (o último elemento estará na posição certa) <br />
-> complexidade do melhorado: <br />

$i=0 \rightarrow n-1$ <br />
$i=1 \rightarrow n-2$ <br />
$i=2 \rightarrow n-3$ <br />
$i \rightarrow n-i-1$ <br />
$i=n-2 \rightarrow n-(n-2)-1 = n-n+2-1 = n-n+1 = 1$ <br /> <br />
$\displaystyle T(n) = \frac{ (a_o + a_n) q_n }{ 2 } = \frac{ ((n-1) + 1) (n-1) }{ 2 } =$ <br /> <br />
$\displaystyle = \frac{ n^2 - n }{ 2 } = \frac{ n^2 }{ 2 } = O(n^2)$ <br /> <br />

-> melhor caso do normal (já ordenado): $O(n^2)$ <br />
-> pior caso do normal (inversamente ordenado): $O(n^2)$ <br />

-> melhor caso do aprimorado (já ordenado): $O(n)$ <br />
-> pior caso do aprimorado (inversamente ordenado): $O(n^2)$ <br />

```c
    void bubblesort(int v[], int tam){
        int aux;

        for(int i=0; i<tam; i++){
            for(int j=0; j<tam-1; j++){ //como a cada passo o último elemento já está ordenado, podemos trocar tam-1 por (tam-1)-i
                //int trocas = 0;
                if(v[j] > v[j+1]){
                    //trocas++;
                    aux = v[j+1];
                    v[j+1] = v[j];
                    v[j] = aux;
                }
                /*
                if(trocas == 0) return; // o vetor já está ordenado, não precisamos continuar iterando
                */
            }
        }

        return;
    }

    int main(void){
        int v[] = {4,6,8,1,3,9,-1,7,0};

        bubblesort(v, 9);

        for(int i=0; i<9; i++){
            printf("%d ", v[i]);
        }
        printf("\n");

        return 0;
    }
```
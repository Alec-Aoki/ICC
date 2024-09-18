#include<stdio.h>
#include <time.h>

typedef struct{
    clock_t start;
    clock_t end;
}Timer;
void start_timer(Timer *timer);
double stop_timer(Timer *timer);

int expon(int n,int k);

int main(){
    Timer tempoTimer1, tempoTimer2;
    double tempoExec;

    //n = base, k = expoente.
    int n, k, resposta;
    scanf("%d %d", &n, &k);
    
    /*Versao Recursiva*/
    start_timer(&tempoTimer1);
    resposta = expon(n, k);
    tempoExec = stop_timer(&tempoTimer1);

    printf("\nRecursiva\n%d\n", resposta%10000);
    printf("%lfms\n", tempoExec);


    /*Versao Iterativa*/
    start_timer(&tempoTimer2);
    int aux=1;
    for(int i = 0; i<k; i++){
            aux = aux%10000;
            aux *= n;
        }
    tempoExec = stop_timer(&tempoTimer2);
        
    printf("\nIterativa\n%d\n", aux%10000);
    printf("%lfms\n\n", tempoExec);
    
    return 0;
}

void start_timer(Timer *timer){
    timer->start = clock();
    return;
}

double stop_timer(Timer *timer){
    timer->end = clock();
    return((double)(timer->end - timer->start)) / CLOCKS_PER_SEC;
}

int expon(int n,int k){
    //Pegar os primeiros 4 dígitos.
    n = n%10000;
    //Um numero elevado a 1, é ele mesmo.
    if(k == 1){
        return n%10000;
    }
    //2^8 = 2^4 * 2^4 e 2^9 = 2^4 * 2^4 * 2.
    int aux = expon(n, k/2)%10000;
    if(k%2){
        return ((aux*aux)%10000)*n;
    }
    else{
        return (aux*aux);
    }
}

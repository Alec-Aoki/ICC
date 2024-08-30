# MERGE SORT
-> ordenação por intercalação <br />
-> O(nlog(n)) <br />
1. quebrar o array na metade até que se obtenha arrays unitários
2. ordernar os dois arrays e uní-los
3. repetir

## Implementação
```c
void intercala(int v[], int inicio, int meio, int fim){
    /*TERMINAR!!!!*/
}

void mergesort(int v[], int inicio, int fim){
   if(inicio < fim){
        int meio = (inicio + fim)/2;
        mergesort(v, inicio, meio);
        mergesort(v, meio+1, fim);
        intercala(v, inicio, meio, fim);
    } 
}
```

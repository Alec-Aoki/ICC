# Recursividade
1. Definir o problema de forma recursiva (chamando a si mesmo)
2. Definir a condição de término (básica/trivial)
- Fatorial:
    - F(n) = n! = 1, n = 1 ou n = 0

        n*(n-1)!, n > 1

```c
int fatorial(int n){
    if((n == 1) || (n == 0))
        return 1;
    return (n*fatorial(n-1));
}
```
```
fatorial(3):
3*fatorial(2)

    fatorial(2):
    2*fatorial(1)

        fatorial(1):
        return 1

    2*1
    return 2

3*2
return 6
```
- Fibonacci:
    - F(n) = 1, n < 2

        F(n-1) + F(n-2), n > 2
    - note que temos que calcular várias vezes, repetidamente, o mesmo valor, o que torna essa recursão muito lenta
```c
unsigned long int fibonacci(unsigned long int n){
    if(n < 2)
        return 1;

    return(fibonacci(n-1) + fibonacci(n-2));
}
```

##Recursividade de Cauda
-> quanto a recursividade vem no fim da função, servindo apenas como um loop

-> pode ser facilmente trasnformada em sua versão iterativa

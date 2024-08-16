# Ponteiros
OBS: os tipos do ponteiro e da variável tem que ser os mesmos!!!
```c
    float B;
    int *p;
    B = 3.16
    p = (int *)&B; //transforma &B em um ponteiro inteiro
```
## OPERADORES
- &: endereço: retorna o endereço
```c
    p = &a //(p recebe o endereço de a)
```
- *: derreferência: retorna o conteúdo apontado pelo ponteiro
```c
    q = *p //(q recebe o conteúdo guardado no endereço guardado em p)
    *p = 36 //(o endereço guardado em p recebe 36)
```
    
## EXPRESSÕES
- atribuição: igual a variáveis iguais
```c
    int x=0, *p1, *p2;
    p1 = &x;
    p2 = p1; //(p2 recebe o endereço de x também)
```

## ARITMÉTICA
- incremento/decremento: altera o endereço na quantidade de bytes BASE da memória
    - (supondo que um inteiro tem 2 bytes (base=2 bytes))
```c
    int *p=2000;
    p++; //(*p=2002)
```
- comparação: compara-se os endereços armazenados nos ponteiros, NÃO o valor desses endereços
- adição/subtração:
```c
    int *p=2000;
    p = p+2; //(*p=2004, já que a base é 2 bytes)
```
- OBS: p = p + q não é possível!!! o outro operando além do ponteiro tem que ser inteiro
```c
    int *p, *q, x; //(&p=2008, &q=2016)
    int a=2, b=3;
    p = &a;
    q = &b;
    x = p-q: (x=4) //(a subt. retorna a distância entre eles na base (base=2 bytes))
```

## INDIREÇÃO MÚLTIPLA: ponteiro que aponta para outro ponteiro
```c
    float x=5.7, *p, **q;
    p = &x;
    q = &p;
    printf("%f\n", **q); // 5.7000
```
- OBS: q = &x; estaria ERRADO!! q só pode apontar para outro ponteiro!

## ERROS COMUNS
1) Esquecer de inicializar ponteiro ((p=&x;) ou (int *p=null;))
2) Inicializar ponteiro sem o &
- OBS: i = *&*&j <=> i = j

# RECURSIVIDADE
-> resolução de um problema em partes menores desse mesmo problema, com menos dados <br />
-> chamar uma função dentro dela mesma, mas passando MENOS dados <br />
- solução geral <-> solução trivial
    - toda recursão tem o caminho de volta
    - temos que definir a solução trivial na mão para não entrarmos em um loop <br />
-> obs: a função recursiva exige mais espaço na memória (copia a variável usada) e é mais lento <br />
-> que a versão iterativa

## RECURSÃO DIRETA
-> P chama P (diretamente)

## RECURSÃO INDIRETA
-> P chama Q, que chama P (direta ou indiretamente)

## Exemplo:
```
    -> soma dos n primeiro números naturais:
    -> S(1) = 1
    -> S(2) = S(1) + 2
    -> S(3) = S(2) + 3
    -> S(n) = S(n-1) + n
```

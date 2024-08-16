# FUNÇÕES
A função main vai servir para organizar a executar (chamar) as funções, que vão conter as lógicas/algor. do programa <br />
Quebraremos o problema em partes menores (funções) <br />

Praxe: declar. da função -> def. da função -> main <br />
    - obs: para usarmos uma função, temos que ter definido ela antes. não é obrigatório declarar elas <br />

```c
tipo nome(parâmetros){
    comandos;
}
```

parâmetros: variáveis "de fora pra dentro" da função. todas variáveis declaradas no parâmetro podem ser usadas dentro da função. <br />
    - variáveis declaradas dentro das funções e declaradas no parâmetro só existem dentro dela <br />
tipo: se a função não retornar valores, seu tipo é void. conversões automáticas acontecem no return tmb <br />

obs: só dá pra retornar UMA variável na função <br />

obs: alterar o valor de um parâmetro dentro da função NÃO altera o valor da variável passada como argumento na main <br />

obs: o comando returno sai da função, então só é possível executar ele uma vez <br />

## ARGUMENTOS PARA A MAIN
- char *argc[]: conta quantos parâmetros tem na linha de comando
- int argv: vetor de ponteiros contendo os caracteres de cada parâmetro/argumento
- o primeiro argumento é o nome do programa


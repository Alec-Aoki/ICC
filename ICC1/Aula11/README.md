# STRINGS
-> array de caracteres <br />
-> terminam com o caractere '\0' ou NULL <br />
-> exemplo:
* 'a' é uma constante char, com 1 byte
* "a" é uma constante string, com 2 bytes (2 caracteres, 'a' e '\0')
exemplo:
```c
    char* str;
    str = "abcd"; //str é um ponteiro que recebe o começo da constante "abcd", que está em outro lugar da memória
    printf("%s", str); //funciona
    scanf("%s", str); //não funciona, pq não dá pra gravar coisas em constantes
    //para ler strings, vamos usar string como variáveis
```

## STRING COMO VARIÁVEIS
```c
    char str[101]; //pode armazenar uma palavra de 100 caracteres, e o '\0'
```

## FUNÇÕES PARA MANIPULAR STRINGS
```c
gets(str); //NÃO USAR, não verifica o tamanho da string, então pode invadir memória

```

```c
puts(str); //printf que só funciona pra string, vai imprimindo até achar o \0
```

```c
scanf(" %s", str);
```

```c
print("%s", str);
```

```c
fgets();
```
* usada para leitura de arquivos, já que o buffer do telcado é tecnicamente um arquivo
    ```c
    char *fgets(char *str, int tamanho, FILE *fp);
    ```
    * OBS: lê até (INCLUINDO) o \n, o final do fluxo ou até que o número de caracteres seja n-1 ('\0) (tam. máx.)
        * isso conserta o problema do gets();
    * OBS: ela inclui um '\0' no final
    * OBS: ela lê espaço!!!

## BIBLIOTECA STRING.H
```c
strcpy(s1, s2); //copia o conteudo de s1 pra dentro de s2
```

```c
strcat(s1, s2); //concatena s2 ao final de s1
```

```c
strlen(s1); //retorna o tamanho de s1, SEM contar o \0 (mas conta o \n, eu acho), em um unsigned long int

```

```c
strcmp(s1,s2);
```
* retorna 0 se s1 == s2, um valor < 0 se s1 < s2 e um valor > 0 se s1 > s2
    * ele compara os valores da tabela ASCII (lexicograficamente), caractere por caractere
    * se os caracteres forem diferentes, ele vai usar eles
    * se forem iguais, eles vão pro próximo

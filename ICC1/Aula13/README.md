# ARQUIVOS
-> armazenar quantidades de dados muito grandes <br />
-> armazenar informações de modo permanente

## STREAM (ARQUIVO) DE TEXTO 
-> .txt <br />
-> sequência de caracteres (leitura de byte a byte, ou seja, caractere a caractere) <br />
-> onde a informação começa e termina já é sabido pelo OS

## STREAM (ARQUIVO) BINÁRIA
-> .exe, .mp3., .png etc <br />
-> sequência de bytes <br />
-> onde a informação começa e termina tem que ser determinados
* essa determinação geralmente está no HEADER, que é começo da stream

# ARQUIVOS EM C
-> a associação stream-arquivo é iniciada com a operação de abertura fopen() <br />
    -> permite que operações sejam realizadas no arquivo a partir do programa <br />

-> as informações são gravas no arquivo quando:
- ele é fechado fclose()
- a main() acaba
- a exit() é executada
- a fflush() é executada (evitar)
- ocorre crash
- ocorre abort

-> em C, a stream é a estrutura FILE (biblioteca stdio.h) <br />
    -> usado via ponteiro (geralmente chamado de fp) <br />
    -> exemplo:
```c
    FILE *fp; //esse ponteiro aponta para o arquivo (na verdade é a stream)
```

## MODOS DE ABERTURA DE ARQUIVO:
- r: só leitura
- w: só escrita
    - obs: se não existe, cria; se existe, apaga e cria um novo
- a: escreve no final do arquivo
- rb: abre em modo binário, só leitura
- wb: abre em modo binário, só escrita
- ab: abre em modo binário, escreve no final
- r+: leitura e escrita
    - obs: não começa do final, mas sim no começo
    - obs: se o arquivo já existir, não apaga
    - obs: não cria arquivo se ele não existe !!!!!!!
- w+: leitura e escrita
    - obs: não começa do final, mas sim no começo
    - obs: se o arquivo já existir, não apaga
    - obs: cria arquivo se ele não existe !!!!!!!
- r+b: leitura e escrita em binário

## SINTAXE:
```c
    FILE *fopen("NOME_DO_ARQUIVO", "MODO_DE_ABERTURA");
    fclose (NOME_DO_PONTEIRO);
```

-> exemplo:
```c
    FILE *fp; //cria ponteiro que vai apontar para o começo do arquivo
    fp = fopen("arquivodaora.txt", "r+"); //cria o arquivo "arquivodaora.txt" no modo de ler e escrever
    //fp aponta para o início do arquivo arquivodaora
    if (*fp == NULL){ //erro na abertura do arquivo
        exit(1);
    }
    fclose (fp); //fecha o arquivo apontado por fp, salvando as alterações nele
```
-> OBS: aconselhável fechar um arquivo antes de abrir outro

## FUNÇÕES DE LEITURA E ESCRITA, E OUTRAS
```c
putc(); //escreve um caractere no arquivo
    // sucesso: retorna o caractere escrito
    // falha: retorna EOF
```

```c
fputc(); //igual ao putc
    //OBS: stdout é o arquivo do monitor
        // fput(c, stoud); printa o conteúdo de c direto na tela
```

```c
fprintf(NOME_DO_PONTEIRO, "MÁSCARAS E/OU TEXTO", NOME_DA_VARIÁVEL);
        //igual ao printf, mas tem que colocar o nome do ponteiro antes
```

```c
fscanf(); //igual ao scanf, mas tem que colcoar o nome do ponteiro antes
```

```c
feof(NOME_DO_PONTEIRO); //detecta o fim do arquivo;
```

```c
getc(NOME_DO_PONTEIRO); //pega o caractere apontado pelo ponteiro no arquivo;
    // obs: o fim de um arquivo .txt é denotado pelo caractere 'EOF'
```

```c
fseek(nome_ponteiro, ); //permite a manipulação do ponteiro do arquivo
    //o ponteiro vai passar a apontar para um byte específico
    //OBS: o ponteiro sempre começa no começo do arquivo;
```

# ARQUIVOS BINÁRIOS
## HEADER
-> quant. DEFINIDA de dados no início do arquivo com informações sobre o resto dele

## Lógica para copiar um arq. bin.
-> criar 2 ponteiros para arq. <br />
-> p1 no modo rb, p2 no modo wb <br />
-> ler CARACTERE A CARACTERE do p1 e escrever no p2 (fgetc e fputc, ou fscanf e fprintf) <br />
    -> caractere mesmo (char) pq tem 1 byte, e queremos copiar de byte a byte
    
## OPERAÇÃO COM MAIS DE 1 BYTE
-> se quisermos operar com ints, não poderíamos fazer o mesmo q acima <br />
    -> temos q usar fwrite() e fread() para ler ou escrever mais que 1 byte <br />
    -> fwrite(&nome_variável, sizeof(tipo_da_variável), quant_de_vezes, nome_ponteiro); <br />
    -> fread(&nome_variável, sizeof(tipo_da_variável), quant_de_vezes, nome_ponteiro); <br />
        -> retorna 0 se dá erro
exemplo:
```c
    scanf("%d", &num); //num um int, pont_arq o ponteiro para o arquivo
    fwrite(&num, sizeof(int), 1, pont_arq); //escreve o conteúdo de num 1 vez no arquivo
    fread(&num, sizeof(int), 1, pont_arq); //lê 1 int do arquivo 1 vez e guarda no num
    printf("%d\n", num);
```

## STRUCTS EM ARQUIVO BINÁRIO
-> dá pra printar informação por informação, ou só jogar a struct inteira mesmo <br />
exemplo:
```c
    struct S{
        int num1;
        float num2;
    }y;
    fwrite(&y, sizeof(S), 1, pont_arq);
    fread(&y, sizeof(S), 1, pont_arq);
    printf(...);
```
-> pra vetores de struct é a mesma coisa, só muda o quant_de_vezes <br />
exemplo:
```c
    fwrite(vet, sizeof(S), 3, pont_arq); //coloca as 3 primeiras posição do vetor apontado por vet no arquivo
    fwrite(&vet[0], sizeof(S), 1, pont_arq); //escreve só a primeira posição do vetor ap. por vet no arquivo
    //OBS: escreve depois das outras posições (anteriormente escrita)
    fread(vet2, sizeof(S), 4, pont_arq); //colocar os conteudos do arquivo no vetor vet2
    printf(...);
```
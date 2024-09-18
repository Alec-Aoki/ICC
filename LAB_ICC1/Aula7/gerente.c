#include <stdio.h>

/*
O programa receber´a como entrada o n´umero de produtos negociados no dia. Para
cada produto, o programa registrar´a o pre¸co de compra, o pre¸co de venda, a quantidade adquirida
e a quantidade vendida. Com base nesses dados, o programa deve calcular o lucro total do dia e
determinar o ´ındice do produto que gerou a maior receita junto `a sua pr´opria receita.

- numero de produtos

    para cada produto:
    - preco de compra
    - preco de venda
    - quant. comprada
    - quant. vendida

-> lucro do dia = soma dos lucros
-> lucro relativo do produto
-> indice do produto q gerou mais lucro


3
PC   PV  QC QV
10.0 15.0 5 7
8.0 12.0 10 8
6.0 9.0 4 6

lucro : 101.00
produto : 1 lucro relativo : 55.00
*/

int main(void){

    float preco_compra, preco_venda, lucro_dia=0;

    int quant_compra, quant_venda, melhor_produto=0;

    int numero_produtos;

    scanf("%d", &numero_produtos);

    float lucro_produtos[numero_produtos];

    lucro_produtos[-1] = 0;
    lucro_produtos[0] = 0;

    if (numero_produtos == 0){
        printf("Sem atividades registradas hoje\n");
    }

    else {
        for (int i=0; i<numero_produtos; i++){
            scanf("%f", &preco_compra);
            scanf("%f", &preco_venda);
            scanf("%d", &quant_compra);
            scanf("%d", &quant_venda);

            lucro_produtos[i] = (preco_venda*quant_venda) - (preco_compra*quant_compra);
            lucro_dia = lucro_dia + lucro_produtos[i];

            if (lucro_produtos[i]>lucro_produtos[melhor_produto-1]){
                melhor_produto = i+1;
            }
        }

    if (lucro_dia>0){
        printf("lucro: %.2f\n", lucro_dia);
    }
    else {
        printf("prejuizo: %.2f\n", (-1)*lucro_dia);
    }

    printf("produto: %d ", melhor_produto);
    printf("lucro relativo: %.2f\n", lucro_produtos[melhor_produto-1]);

    }

    return 0;
}
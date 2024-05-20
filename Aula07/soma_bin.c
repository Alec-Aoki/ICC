#include <stdio.h>

int main(void){
    int n, m, n_bin[30], m_bin[30], *pn, *pm, multi=2, n_dec=0, m_dec=0;

    scanf(" %d %d", &n, &m);

    pn = &n_bin;
    pm = &m_bin;

    // preenchimento do vetor n_bin
    for (int i=0; i<n; i++){
        scanf(" %d", pn);
        pn++;
    }
    pn = pn-1;

    // preenchimento do vetor m_bin
    for (int i=0; i<m; i++){
        scanf(" %d", pm);
        pm++;
    }
    pm = pm-1;

    // transf. do bit menos signif. em binario, pq ele eh *1 e o multi vai de 2 em 2
    n_dec = *pn;
    m_dec = *pm;

    //ajuste para comecarmos a multiplicar por 2 o 2o bit
    pn = pn-1;
    pm = pm-1;

    //transf. de n em binario p/ dec
    for (int i=n; i>1; i--){
        n_dec = n_dec + (*pn)*multi;
        multi = multi*2;
        pn--;
    }
    multi = 2;
    //transf. de m em binario p/ dec
    for (int i=m; i>1; i--){
        m_dec = m_dec + (*pm)*multi;
        multi = multi*2;
        pm--;
    }

    printf("%d\n", n_dec+m_dec);

    return 0;
}
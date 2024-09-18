#include <stdio.h>

int main(void){

    int N_corridas, T_corrida;
    float v_A, v_B;

    scanf("%d", &N_corridas);

    for (int i=0; i<N_corridas; i++){
        scanf("%f %f %d", &v_A, &v_B, &T_corrida);

        if (T_corrida == 0){
            printf("A corrida ainda nao comecou\n");
        }

        else if (T_corrida > 0){
            if (v_A==0 && v_B==0){
                printf("Os dois pilotos nao querem competir\n");
            }
            else if (v_A==0 && v_B!=0){
                printf("O piloto A desistiu inesperadamente\n");
            }
            else if (v_B==0 && v_A!=0){
                printf("O piloto B desistiu inesperadamente\n");
            }
            else if (v_A==v_B){
                printf("Os karts empataram, percorrendo cada %.2fkm\n", v_A*T_corrida);
            }
            else if (v_A>v_B){
                printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", (v_A*T_corrida)-(v_B*T_corrida));
            }
            else if (v_B>v_A){
                printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", (v_B*T_corrida)-(v_A*T_corrida));
            }
        }

        else {
            if (v_A==0 && v_B==0){
                printf("Os dois pilotos nao querem competir\n");
            }
            else if (v_A==0 && v_B!=0){
                printf("O piloto A desistiu inesperadamente\n");
            }
            else if (v_B==0 && v_A!=0){
                printf("O piloto B desistiu inesperadamente\n");
            }
            else{
                printf("De alguma forma os pilotos voltaram no tempo\n");
            }
        }
    }

    return 0;
}
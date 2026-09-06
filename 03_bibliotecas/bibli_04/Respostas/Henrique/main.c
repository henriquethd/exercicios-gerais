#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct
{
    int dia, mes, ano;
} tData;


int main(void){
    tData data;

    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);

    if (!verificaDataValida(data.dia, data.mes, data.ano)){
        printf("A data informada eh invalida\n");
        exit(1);
    }

    printf("Data informada: ");
    imprimeDataExtenso(data.dia, data.mes, data.ano);

    if (verificaBissexto(data.ano)){
        printf("O ano informado eh bissexto\n");
    }
    else{
        printf("O ano informado nao eh bissexto\n");
    }

    printf("O mes informado possui %02d dias\n", numeroDiasMes(data.mes, data.ano));

    printf("A data seguinte eh: ");
    imprimeProximaData(data.dia, data.mes, data.ano);
    exit(0);
}
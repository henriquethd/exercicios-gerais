#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct
{
    int dia, mes, ano;
} typedef tData;


int main(void){
    tData data1, data2;
    int comparacao;

    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

    if (!verificaDataValida(data1.dia, data1.mes, data1.ano) || !verificaDataValida(data2.dia, data2.mes, data2.ano)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(1);
    }

    printf("Primeira data: ");
    imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
    printf("Segunda data: ");
    imprimeDataExtenso(data2.dia, data2.mes, data2.ano);

    comparacao = comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano);

    switch (comparacao){
    case -1:
        printf("A segunda data eh mais antiga\n");
        break;
    case 0:
        printf("As datas sao iguais\n");
        break;
    case 1:
        printf("A primeira data eh mais antiga\n");
    default:
        exit(1);
    }

    printf("A diferenca em dias entre as datas eh: ");
    printf("%2d dias\n", &calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.anos));
    exit(0);
}
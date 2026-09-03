#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct
{
    int dia, mes, ano;
} typedef tData;


int main(void){
    tData data1, data2;
    scanf("%d/%d/%d", &data1.dia, &data1.mes, &data1.ano);
    scanf("%d/%d/%d", &data2.dia, &data2.mes, &data2.ano);

    if (!verificaDataValida(data1.dia, data1.mes, data1.ano) || !verificaDataValida(data2.dia, data2.mes, data2.ano)){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(1);
    }

    return 0;
}
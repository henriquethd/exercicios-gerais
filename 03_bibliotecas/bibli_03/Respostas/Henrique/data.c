#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano){
    if (ano < 0){
        return 0;
    }
    if (dia < 1 || dia > 31){
        return 0;
    }
    if (mes < 1 || mes > 12){
        return 0;
    }
    if ((mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11) && (dia == 31)){
        return 0;
    }
    if (dia == 29){
        if (mes == 2){
            if (!verificaBissexto(ano)){
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    return 1;
}

void imprimeMesExtenso(int mes){
    switch (mes){
    case 1: printf("Janeiro"); break;
    case 2: printf("Fevereiro"); break;
    case 3: printf("Marco"); break;
    case 4: printf("Abril"); break;
    case 5: printf("Maio"); break;
    case 6: printf("Junho"); break;
    case 7: printf("Julho"); break;
    case 8: printf("Agosto"); break;
    case 9: printf("Setembro"); break;
    case 10: printf("Outubro"); break;
    case 11: printf("Novembro"); break;
    case 12: printf("Dezembro"); break;
    default: break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d", ano);
    printf("\n");
}

int verificaBissexto(int ano){
    if ((ano % 100) == 0){
        if ((ano % 400) == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if ((ano % 4) == 0){
        return 1;
    }
    return 0;
}

int numeroDiasMes(int mes, int ano){
    if ((mes == 2 || mes == 4 || mes == 6 || mes == 9 || mes == 11)){
        return 30;
    }
    else if (mes == 2){
        if (verificaBissexto(ano)){
            return 29;
        }
        else{
            return 28;
        }
    }
    else{
        return 31;
    }
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if (ano1 > ano2){
        return 1;
    }
    else if (ano1 < ano2){
        return -1;
    }
    else{
        if (mes1 > mes2){
            return 1;
        }
        else if (mes1 < mes2){
            return -1;
        }
        else{
            if (dia1 > dia2){
                return 1;
            }
            else if (dia1 < dia2){
                return -1;
            }
            else{
                return 0;
            }
        }
    }
}

int calculaDiasAteMes(int mes, int ano){
    int mesAtual = 1;
    int soma = 0;

    for (mesAtual = 1; mesAtual < mes; mesAtual++){
        soma += numeroDiasMes(mesAtual, ano);
    }

    return soma;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2);

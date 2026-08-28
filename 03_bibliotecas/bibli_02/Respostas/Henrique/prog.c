#include <stdio.h>

int main(void){
    int opcao;


    do{
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        scanf("%d", &opcao);

        
    } while (1);

    return 0;
}
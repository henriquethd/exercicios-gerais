#include <stdio.h>
#include "string_utils.h"

int main(void){
    char str[1000], copia[1000];
    scanf("%99[^\n]", str);
    int escolha;

    while(1){
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");

        printf("Opcao escolhida: ");
        scanf("%d", &escolha);
        printf("\n");

        switch (escolha){
        case 1:
            printf("Tamanho da string: %d\n", string_length(str));
            break;
        
        case 2:
            string_copy(str, copia);
            printf("String copiada: %s\n", copia);
            break;
        
        case 3:
            string_upper(str);
            printf("String convertida para maiusculas: %s\n", str);
            break;
        
        case 4:
            string_lower(str);
            printf("String convertida para minusculas: %s\n", str);
            break;
        
        case 5:
            string_reverse(str);
            printf("String invertida: %s\n", str);
            break;
        
        case 6:
            exit(0);
            break;

        default:
            exit(1);
        }
    }
    return 0;
}
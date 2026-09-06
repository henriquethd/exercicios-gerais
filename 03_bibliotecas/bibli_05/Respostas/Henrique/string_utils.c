#include "string_utils.h"

int string_length(char *str){
    int tamanho = 0, i;

    for (i = 0; 1; i++){
        if (str[i] == '\0'){
            return tamanho;
        }
        tamanho++;
    }
}

void string_copy(char *src, char *dest){
    int i;
    int tamanho = string_length(src) + 1;

    for (i = 0; i < tamanho; i++){
        dest[i] = src[i];
    }
}

void string_upper(char *str){
    int i;
    int tamanho = string_length(str) + 1;
    char letra;

    for (i = 0; i < tamanho; i++){
        letra = str[i];
        if (letra >= 'a' && letra <= 'z'){
            letra -= 32;
            str[i] = letra;
        }
    }
}

void string_lower(char *str){
    int i;
    int tamanho = string_length(str) + 1;
    char letra;

    for (i = 0; i < tamanho; i++){
        letra = str[i];
        if (letra >= 'A' && letra <= 'Z'){
            letra += 32;
            str[i] = letra;
        }
    }
}

void string_reverse(char *str){
    int i;
    int tamanho = string_length(str) + 1;
    int oposto = tamanho - 2;
    char temp;

    for (i = 0; i < tamanho; i++){
        if (oposto <= i){
            break;
        }
        temp = str[i];
        str[i] = str[oposto];
        str[oposto] = temp;
        oposto--;
    }
}
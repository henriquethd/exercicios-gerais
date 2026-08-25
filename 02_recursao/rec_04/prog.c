#include <stdio.h>
#include <string.h>

int palindromo(char *string, int tamanho){
    if (tamanho <= 1){
        return 1;
    }
    else{
        int i = 0, x = 1;
        int novoTamanho = tamanho - 2;
        char novaString[novoTamanho];

        for (i = 0; i < novoTamanho; i++){
            novaString[i] = string[x];
            x++;
        }

        if (palindromo(novaString, novoTamanho) == 1){
            if (string[0] == string[tamanho-1]){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
}

int main(void){
    char string[50];

    while (scanf("%49s", string) == 1){
        if (palindromo(string, strlen(string)) == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
    }

    return 0;
}
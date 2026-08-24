#include <stdio.h>
// Ola

void ImprimeInvertido(char* string){
    if (string[1] == 0){
        printf("%c", string[0]);
        return;
    }
    else{
        char novaStr[1000];
        int i = 0, x = 1;

        while(1){
            if (string[x] == 0){
                break;
            }

            novaStr[i] = string[x];
            i++;
            x++;
        }
        novaStr[i] = 0;
        ImprimeInvertido(novaStr);
        printf("%c", string[0]);
    }
}

int main(void){
    char frase[1000];
    char string[1000];
    int i = 0, x = 0;

    scanf("%999[^\n]", frase);
    
    while (1){
        x = 0;
        while(frase[i] != ' ' && frase[i] != 0){
            string[x] = frase[i];
            x++;
            i++;
        }

        string[x] = 0;
        ImprimeInvertido(string);  
        printf(" ");

        if (frase[i] == 0){
            break;
        }
        i++;
    }
    

    return 0;
}
#include <stdio.h>

int somaDigitos(int n);

int main(void){
    int n;

    scanf("%d", &n);
    printf("%d\n", somaDigitos(n));

    return 0;
}

int somaDigitos(int n){
    if (n == 0){
        return 0;
    }
    else{
        int soma = 0;
        soma += n%10 + somaDigitos(n/10);

        return soma;
    }
}

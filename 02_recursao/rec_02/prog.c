#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos){
    if (numElementos == 1){
        if (vet[0]%2 == 0){
            return vet[0];
        }
        else{
            return 0;
        }
    }
    else{
        int novoVetor[numElementos-1];
        int soma = 0;
        int i = 0, x = 1;

        for (i = 0; i < numElementos - 1; i++){
            novoVetor[i] = vet[x];
            x++;
        }

        soma += SomaElementosPares(novoVetor, numElementos - 1);

        if (vet[0]%2 == 0){
            soma += vet[0];
        }

        return soma;
    }
}

int main(void){
    int qtdVetores, i, x, qtdElementos, soma;

    scanf("%d", &qtdVetores);

    for (i = 0; i < qtdVetores; i++){
        scanf("%d", &qtdElementos);
        int vet[qtdElementos];

        for (x = 0; x < qtdElementos; x++){
            scanf("%d", &vet[x]);
        }

        soma = SomaElementosPares(vet, qtdElementos);
        printf("%d\n", soma);
    }

    return 0;
}
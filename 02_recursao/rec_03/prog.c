#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado){
    if (numElementos == 0){
        return 0;
    }
    else{
        int novoVet[numElementos-1];
        int i = 1, x = 0, contador = 0;

        for (i = 1; i < numElementos; i++){
            novoVet[x] = vet[i];
            x++;
        }
        if (vet[0] == numeroProcurado){
            contador++;
        }
        contador += ContaOcorrencias(novoVet, numElementos-1, numeroProcurado);
        return contador;
    }

}

int main(void){
    int qtdCasos;
    int numero, qtdElementos, i, x;

    scanf("%d", &qtdCasos);

    for (i = 0; i < qtdCasos; i++){
        scanf("%d %d", &numero, &qtdElementos);
        int vet[qtdElementos];

        for (x = 0; x < qtdElementos; x++){
            scanf("%d", &vet[x]);
        }

        printf("%d\n", ContaOcorrencias(vet, qtdElementos, numero));
    }

    return 0;
}
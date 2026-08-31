#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

void processaOpcao(int opcao, int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2]);

void realizaSoma(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2], int result[row1][col1]);

void realizaSub(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2], int result[row1][col1]);

void realizaMult(int row1, int col1, int matrix1[row1][col1], int row2, int col2, int matrix2[row2][col2], int resultMult[row1][col2]);

void realizaEscalar(int row, int col, int matrix[row][col], int escalar);

void realizaTransposta(int row, int col, int matrix[row][col], int result[col][row]);

int main(void){
    int opcao;

    int row1, col1;
    scanf("%d %d", &row1, &col1);

    int matrix1[row1][col1];
    matrix_read(row1, col1, matrix1);

    int row2, col2;
    scanf("%d %d", &row2, &col2);
    int matrix2[row2][col2];
    matrix_read(row2, col2, matrix2);
    
    do{
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        scanf("%d", &opcao);
        processaOpcao(opcao, row1, col1, row2, col2, matrix1, matrix2);
        
    } while (1);

    return 0;
}

void processaOpcao(int opcao, int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2]){
    int result[row1][col1], resultMult[row1][col2];

    if (opcao == 1){
        realizaSoma(row1, col1, row2, col2, matrix1, matrix2, result);
        matrix_print(row1, col1, result);
        return;
    }
    if (opcao == 2){
        realizaSub(row1, col1, row2, col2, matrix1, matrix2, result);
        matrix_print(row1, col1, result);
        return;
    }
    if (opcao == 3){
        realizaMult(row1, col1, matrix1, row2, col2, matrix2, resultMult);
        matrix_print(row1, col2, resultMult);
        return;
    }
    if (opcao == 4){
        int escalar, n;
        scanf("%d %d", &escalar, &n);

        if (n == 1){
            realizaEscalar(row1, col1, matrix1, escalar);
            matrix_print(row1, col1, matrix1);
        }
        else if (n == 2){
            realizaEscalar(row2, col2, matrix2, escalar);
            matrix_print(row2, col2, matrix2);
        }    
        
        return;
    }
    if (opcao == 5){
        int result1[col1][row1];
        int result2[col2][row2];
        
        realizaTransposta(row1, col1, matrix1, result1);
        realizaTransposta(row1, col2, matrix2, result2);

        matrix_print(row1, col1, result1);
        matrix_print(row2, col2, result2);
    }
    if (opcao == 6){
        exit(0);
    }
}

void realizaSoma(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2], int result[row1][col1]){
    if (possible_matrix_sum(row1, col1, row2, col2) == 0){
        printf("Erro: as dimensoes da matriz nao correspondem \n");
        return;
    }
    else{
        matrix_add(row1, col1, matrix1, row2, col2, matrix2, result);
    }
}

void realizaSub(int row1, int col1, int row2, int col2, int matrix1[row1][col1], int matrix2[row2][col2], int result[row1][col1]){
    if (possible_matrix_sub(row1, col1, row2, col2) == 0){
        printf("Erro: as dimensoes da matriz nao correspondem \n");
        return;
    }
    else{
        matrix_sub(row1, col1, matrix1, row2, col2, matrix2, result);
    }
}

void realizaMult(int row1, int col1, int matrix1[row1][col1], int row2, int col2, int matrix2[row2][col2], int resultMult[row1][col2]){
    if (possible_matrix_multiply(col1, row2) == 0){
        printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz \n");
        return;
    }
    else{
        matrix_multiply(row1, col1, matrix1, row2, col2, matrix2, resultMult);
    }
}

void realizaEscalar(int row, int col, int matrix[row][col], int escalar){
    scalar_multiply(row, col, matrix, escalar);
}

void realizaTransposta(int row, int col, int matrix[row][col], int result[col][row]){
    transpose_matrix(row, col, matrix, result);
}
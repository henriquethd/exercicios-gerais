#include <stdio.h>
#include "matrix_utils.h"

void matrix_read(int rows, int cols, int matrix[rows][cols]){
    int i, j;
    
}

void matrix_print(int rows, int cols, int matrix[rows][cols]);

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2);

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2);

int possible_matrix_multiply(int cols1, int rows2);

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]);

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]);

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar);
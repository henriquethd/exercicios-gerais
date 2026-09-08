#include <stdio.h>
#include "aluno.h"

int main(void){
    int qtdAlunos, i, x;
    
    scanf("%d", &qtdAlunos);
    scanf("%*c");

    tAluno alunos[qtdAlunos];
    tAluno temp;

    for (i = 0; i < qtdAlunos; i++){
        alunos[i] = LeAluno();
    }

    for (i = 0; i < qtdAlunos; i++){
        for (x = i; x < qtdAlunos; x++){
            if (ComparaMatricula(alunos[i], alunos[x]) == 1){
                temp = alunos[i];
                alunos[i] = alunos[x];
                alunos[x] = temp;
            }
        }
    }

    for (i = 0; i < qtdAlunos; i++){
        if (VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
    }
    

    return 0;
}
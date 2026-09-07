#include "candidato.h"
#include <string.h>
#include <stdio.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato candidato;

    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;

    strcpy(candidato.nome, nome);
    strcpy(candidato.partido, partido);

    return candidato;
}

tCandidato LeCandidato(){
    tCandidato candidato;
    int id;
    char cargo;
    char nome[50], partido[50];

    scanf("%*c");
    scanf("%49[^,]", nome);
    scanf(", %49[^,]", partido);
    scanf(", %c", &cargo);
    scanf(", %d", &id);

    candidato = CriaCandidato(nome, partido, cargo, id);
    return candidato;
}

int VerificaIdCandidato(tCandidato candidato, int id){
    return (candidato.id == id);
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    return (candidato1.id == candidato2.id);
}

char ObtemCargo(tCandidato candidato){
    return (candidato.cargo);
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos++;
    return (candidato);
}

int ObtemVotos(tCandidato candidato){
    return (candidato.votos);
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    return (((float)candidato.votos/(float)totalVotos)*100);
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}
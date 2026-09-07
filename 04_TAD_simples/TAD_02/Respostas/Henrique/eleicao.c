#include "candidato.h"
#include "eleitor.h"
#include "eleicao.h"
#include <stdlib.h>
#include <stdio.h>

void AnulaEleicao(){
    printf("ELEICAO ANULADA\n");
    exit(1);
}

tEleicao ApuraEleicao(tEleicao eleicao){
    int i, x = 0, nuloP = 1, nuloG = 1;
    tCandidato candidato;
    
    for (i = 0; i < eleicao.totalEleitores; i++){
        nuloP = 1;
        nuloG = 1;
        for (x = i + 1; x < eleicao.totalEleitores; x++){
            if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[x])){
                AnulaEleicao();
            }
        }

        for (x = 0; x < eleicao.totalPresidentes; x++){
            candidato = eleicao.presidentes[x];
            if (VerificaIdCandidato(candidato, ObtemVotoPresidente(eleicao.eleitores[i]))){
                nuloP = 0;
                eleicao.presidentes[x] = IncrementaVotoCandidato(candidato);
                break;
            }
        }

        for (x = 0; x < eleicao.totalGovernadores; x++){
            candidato = eleicao.governadores[x];
            if (VerificaIdCandidato(candidato, ObtemVotoGovernador(eleicao.eleitores[i]))){
                nuloG = 0;
                eleicao.governadores[x] = IncrementaVotoCandidato(candidato);
                break;
            }
        }
        
        if (ObtemVotoPresidente(eleicao.eleitores[i]) == 0){
            eleicao.votosBrancosPresidente++;
        }
        else if (nuloP){
            eleicao.votosNulosPresidente++;
        }

        if (ObtemVotoGovernador(eleicao.eleitores[i]) == 0){
            eleicao.votosBrancosGovernador++;
        }
        else if (nuloG){
            eleicao.votosNulosGovernador++;
        }
    }

    return eleicao;
}

tEleicao InicializaEleicao(){
    tEleicao eleicao;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;

    tCandidato candidato;

    eleicao.totalGovernadores = 0;
    eleicao.totalPresidentes = 0;

    int qtdCandidatos, i;
    scanf("%d", &qtdCandidatos);

    for (i = 0; i < qtdCandidatos; i++){
        candidato = LeCandidato();
        if (candidato.cargo == 'P'){
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;
        }
        else{
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }

        if ((eleicao.totalGovernadores > MAX_CANDIDATOS_POR_CARGO) || (eleicao.totalPresidentes > MAX_CANDIDATOS_POR_CARGO)){
            AnulaEleicao();
        }
    }

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
    int i;

    scanf("%d", &eleicao.totalEleitores);

    for (i = 0; i < eleicao.totalEleitores; i++){
        eleicao.eleitores[i] = LeEleitor();
    }

    if (eleicao.totalEleitores > 10){
        AnulaEleicao();
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao){
    eleicao = ApuraEleicao(eleicao);
    int i, maiorVoto = 0, empate = 0;
    float percentual;
    tCandidato presidente, governador;

    printf("- PRESIDENTE ELEITO: ");
    for (i = 0; i < eleicao.totalPresidentes; i++){
        if ((ObtemVotos(eleicao.presidentes[i]) == maiorVoto) && (maiorVoto != 0)){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            empate = 1;
            break;
        }
        if (ObtemVotos(eleicao.presidentes[i]) > maiorVoto){
            maiorVoto = ObtemVotos(eleicao.presidentes[i]);
            presidente = eleicao.presidentes[i];
        }
    }

    if (!empate){
        if (maiorVoto > 0){
            if (ObtemVotos(presidente) > (eleicao.votosNulosPresidente + eleicao.votosBrancosPresidente)){
                percentual = CalculaPercentualVotos(presidente, eleicao.totalEleitores);
                ImprimeCandidato(presidente, percentual);
            }
            else{
                printf("SEM DECISAO\n");
            }
        }
        else{
            printf("SEM DECISAO\n");
        }
    }
    
    maiorVoto = 0;
    empate = 0;
    printf("- GOVERNADOR ELEITO: ");
    for (i = 0; i < eleicao.totalGovernadores; i++){
        if ((ObtemVotos(eleicao.governadores[i]) == maiorVoto) && (maiorVoto != 0)){
            printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
            empate = 1;
            break;
        }
        if (ObtemVotos(eleicao.governadores[i]) > maiorVoto){
            maiorVoto = ObtemVotos(eleicao.governadores[i]);
            governador = eleicao.governadores[i];
        }
    }

    if (!empate){
        if (maiorVoto > 0){
            if (ObtemVotos(governador) > (eleicao.votosNulosGovernador+ eleicao.votosBrancosGovernador)){
                percentual = CalculaPercentualVotos(governador, eleicao.totalEleitores);
                ImprimeCandidato(governador, percentual);
            }
            else{
                printf("SEM DECISAO\n");
            }
        }
        else{
            printf("SEM DECISAO\n");
        }
    }
    

    printf("- NULOS E BRANCOS: %d, %d", (eleicao.votosNulosGovernador + eleicao.votosNulosPresidente), (eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente));
}
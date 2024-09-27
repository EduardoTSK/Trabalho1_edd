#ifndef PROCESSOS_H
#define PROCESSOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _registro {
    long long id;
    char numero[30];
    char data_ajuizamento[20];
    char id_classe[50];
    char id_assunto[50];
    int ano_eleicao;
} Registro;

void ordenar_por_id(Registro *registros, int n);
void ordenar_por_data(Registro *registros, int n);
int contar_por_id_classe(Registro *registros, int n, const char *id_classe);
int contar_id_assuntos(Registro *registros, int n);
int dias_em_tramitacao(const char *data_ajuizamento);

#endif
#include "processos.h"

// Função de comparação para qsort (crescente por id)
int comparar_id(const void *a, const void *b) {
    Registro *registroA = (Registro *)a;
    Registro *registroB = (Registro *)b;
    return (registroA->id > registroB->id) - (registroA->id < registroB->id);
}

// Função de comparação para qsort (decrescente por data_ajuizamento)
int comparar_data(const void *a, const void *b) {
    Registro *registroA = (Registro *)a;
    Registro *registroB = (Registro *)b;
    return strcmp(registroB->data_ajuizamento, registroA->data_ajuizamento);
}

void ordenar_por_id(Registro *registros, int n) {
    qsort(registros, n, sizeof(Registro), comparar_id);
}

void ordenar_por_data(Registro *registros, int n) {
    qsort(registros, n, sizeof(Registro), comparar_data);
}

int contar_por_id_classe(Registro *registros, int n, const char *id_classe) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(registros[i].id_classe, id_classe) == 0) {
            contador++;
        }
    }
    return contador;
}

int contar_id_assuntos(Registro *registros, int n) {
    char assuntos[100][50];
    int count = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(registros[i].id_assunto, assuntos[j]) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(assuntos[count], registros[i].id_assunto);
            count++;
        }
    }
    return count;
}

int dias_em_tramitacao(const char *data_ajuizamento) {
    struct tm tm;
    time_t data_inicio, data_atual;

    strptime(data_ajuizamento, "%Y-%m-%d %H:%M:%S", &tm);
    data_inicio = mktime(&tm);
    data_atual = time(NULL);
    
    return difftime(data_atual, data_inicio) / (60 * 60 * 24);
}
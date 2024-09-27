#include "processos.h"

int main() {
    Registro registros[18393];
    int n = 0;
    n = ler_registros (registros);

    ordenar_por_id(registros, n);
    ordenar_por_data(registros, n);
    
    const char *classe_para_contar = "18393";
    int total_por_classe = contar_por_id_classe(registros, n, classe_para_contar);
    printf("Total de processos com id_classe %s: %d\n", classe_para_contar, total_por_classe);

    int total_assuntos = contar_id_assuntos(registros, n);
    printf("Total de id_assuntos distintos: %d\n", total_assuntos);

    for (int i = 0; i < n; i++) {
        int dias = dias_em_tramitacao(registros[i].data_ajuizamento);
        printf("Processo ID %lld está em tramitação há %d dias.\n", registros[i].id, dias);
    }

    return 0;
}
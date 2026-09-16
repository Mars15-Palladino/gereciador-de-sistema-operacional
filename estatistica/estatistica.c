#include "estatistica.h"
#include "../relogio/relogio.h"
#include "../processos/processos.h"
#include"../memoria/memoria.h"
#include "../arquivos/arquivos.h"
#include<stdio.h>

void mostrar_Estatisticas(void){
    double tempo_total = obter_Tempo();
    int processos_criados = proximo_PID - 1;
    int processos_ativos = quantidade_processos_ativos();
    int processos_finalizados = processos_criados-processos_ativos;
    int memoria_utilizada = memoria_Utilizada();
    int quantidade_arquivos = quantidade_Arquivos();


    printf("\n===== ESTATISTICAS DA SIMULACAO =====\n");
    printf("Tempo total: %.2f ms\n", tempo_total);
    printf("Processos criados: %d\n", processos_criados);
    printf("Processos finalizados: %d\n", processos_finalizados);
    printf("Processos ativos: %d\n", processos_ativos);
    printf("Memoria utilizada: %d KB\n", memoria_Utilizada());
    printf("Quantidade de arquivos: %d\n", quantidade_arquivos);
}
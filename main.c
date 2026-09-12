// Inclui as funcoes de entrada e saida, como printf e getchar.
#include <stdio.h>
// Inclui os tipos e as funcoes usadas para gerenciar processos.
#include "processos/processos.h"
#include "escalonador/escalonador.h"
#include "memoria/memoria.h"

// Funcao principal: e o ponto de entrada da execucao do programa.
int main(){
    // Cria a fila que armazenara os PIDs dos processos prontos para executar.
    Fila_escalonador_Prontos fila;
    // Zera os indices e a quantidade de elementos da fila.
    inicializar_fila(&fila);



    // Inicializa todas as posicoes da tabela como livres.
    inicializar_Processos();
    // Inicializa a memoria com um unico bloco livre de 1024 KB.
    inicializar_Memoria();
    // Reserva 200 KB para o processo de PID 1.
    alocar_Memoria(1, 200);
    // Reserva 300 KB para o processo de PID 2.
    alocar_Memoria(2,300);
    alocar_Memoria(3, 500);

    // Exibe os blocos de memoria depois das alocacoes.
    printf("Antes de liberar:\n");
    visualizar_Memoria();
    int resultado = liberar_Memoria(1);

    printf("Resultado da liberacao: %d\n", resultado);

    printf("Depois de liberar:\n");
    visualizar_Memoria();

    resultado = liberar_Memoria(3);

    printf("Resultado da segunda liberacao: %d\n", resultado);

    unir_Blocos_Livres();
    visualizar_Memoria();
   






    // Procura e exibe a primeira posicao livre antes das criacoes.
    verificar_Posicao_livre();
    // Cria um processo com nome, prioridade e tempo total de CPU definidos.
    criar_Processo("Processo 1", 5, 500.0);
    // Cria um segundo processo com os valores informados.
    criar_Processo("Processo 2", 3, 300.0);
    // Cria um terceiro processo com os valores informados.\
    criar_Processo("Processo 3", 8, 700.0);

    printf("Processos ativos: %d\n", quantidade_processos_ativos());

    // Adiciona os processos criados a fila de prontos.
    adicionar_fila(&fila, 1);
    adicionar_fila(&fila, 2);
    adicionar_fila(&fila, 3);

    
    while(quantidade_processos_ativos()>0){
        // Retira o primeiro processo da fila.
        int PID_retirado = remover_fila(&fila);
        // Mostra qual PID foi retirado.
        printf("PID retirado da fila: %d\n", PID_retirado);

        

        // Marca o processo retirado como o processo em execucao.
        atualizar_estado_fila(PID_retirado);
        // Executa o processo durante um quantum do escalonador.
        executar_quantum(PID_retirado);

        printf("Processo terminou? %d\n", processo_terminado(PID_retirado));

        if(processo_terminado(PID_retirado) == 0){
        // Devolve a tarefa para o fim da fila quando ainda ha CPU a utilizar.
        adicionar_fila(&fila, PID_retirado);
        }
    }
    // Exibe todos os processos atualmente ocupados.
    listar_Processos();
    // Procura e exibe a proxima posicao livre depois das criacoes.
    verificar_Posicao_livre();
    // Aguarda uma tecla para que a janela nao seja encerrada imediatamente.
    getchar();
    // Informa ao sistema operacional que o programa terminou com sucesso.
    return 0;
}
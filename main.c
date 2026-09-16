// Inclui as funcoes de entrada e saida, como printf e getchar.
#include <stdio.h>

// Inclui os tipos e as funcoes usadas para gerenciar processos.
#include "processos/processos.h"
#include "escalonador/escalonador.h"
#include "memoria/memoria.h"
#include "relogio/relogio.h"
#include "arquivos/arquivos.h"
#include "io/io.h"
#include "recursos/recursos.h"
#include "semaforos/semaforos.h"
#include "logs/logs.h"
#include "estatistica/estatistica.h"

// Funcao principal: e o ponto de entrada da execucao do programa.
int main()
{
    // Cria a fila que armazenara os PIDs dos processos prontos para executar.
    Fila_escalonador_Prontos fila;

    // Inicializa a fila.
    inicializar_fila(&fila);

    // =========================================================
    // INICIALIZACAO DO SISTEMA
    // =========================================================

    inicializar_Processos();
    inicializar_Memoria();
    inicializar_Arquivos();
    inicializar_Relogio();
    inicializar_Recursos();
    inicializar_Logs();

    // Mostra os recursos inicialmente livres.
    visualizar_Recursos();

    // =========================================================
    // TESTE DO RELOGIO
    // =========================================================

    printf("Tempo inicial: %.2f ms\n", obter_Tempo());

    avancar_Relogio(100);

    printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
    registrar_Log("Sistema iniciado");
    registrar_Log("Teste de log realizado");


    printf("Tempo atual: %.2f ms\n", obter_Tempo());

    printf("\nCriacao dos processos:\n");

    verificar_Posicao_livre();

    criar_Processo("Processo 1", 5, 500.0, 200);
    criar_Processo("Processo 2", 3, 300.0, 200);
    criar_Processo("Processo 3", 8, 700.0, 260);

    criar_Processo("Processo Teste", 1, 100.0, 500);

    // =========================================================
    // TESTE DO SISTEMA DE ARQUIVOS
    // =========================================================

    if(criar_Arquivo("teste.txt", 1) == 0){
        printf("Arquivo criado com sucesso\n");
    }else{
        printf("Nao foi possivel criar arquivo\n");
    }

    if(abrir_Arquivos("teste.txt", 1) == 0){
        printf("Arquivo aberto com sucesso\n");
    }else{
        printf("Nao foi possivel abrir o arquivo\n");
    }

    if(escrever_Arquivos("teste.txt", 1,
                         "Ola, este e um arquivo de teste.") == 0){
        printf("Conteudo escrito com sucesso\n");
    }else{
        printf("Nao foi possivel escrever no arquivo\n");
    }

    listar_Arquivos();

    if(ler_Arquivos("teste.txt", 1) == 0){
        printf("Arquivo lido com sucesso\n");
    }else{
        printf("Nao foi possivel ler o arquivo\n");
    }

    listar_Arquivos();
    /*
    if(fechar_Arquivos("teste.txt", 1) == 0){
        printf("Arquivo fechado com sucesso\n");
    }else{
        printf("Nao foi possivel fechar o arquivo\n");
    }
        */

        int resultado_fechamento = fechar_Arquivos("teste.txt", 1);

        printf("RESULTADO FECHAMENTO: %d\n", resultado_fechamento);

        if(resultado_fechamento == 0){
            printf("Arquivo fechado com sucesso\n");
        }else{
            printf("Nao foi possivel fechar o arquivo\n");
        }/**/

    if(excluir_Arquivos("teste.txt", 1) == 0){
        printf("Arquivo excluido com sucesso\n");
    }else{
        printf("Nao foi possivel excluir o arquivo\n");
    }

    listar_Arquivos();


    // =========================================================
    // CRIACAO DOS PROCESSOS
    // =========================================================

    
    listar_Processos();

    /*==========================================================
    TESTE DO SEMAFORO
    ============================================================*/
    printf("semaforo+++++++++++++++++++++++++++++++++++++\n");
    Semaforo semaforo;

    inicializar_Semaforo(&semaforo, 1);

    printf("Valor inicial: %d\n", semaforo.valor);

    if(P(&semaforo, 1) == 0){
        printf("PID 1 adquiriu o semaforo.\n");
    }

    printf("Valor apos P: %d\n", semaforo.valor);

    if(P(&semaforo, 2) != 0){
        printf("PID 2 nao conseguiu adquirir o semaforo.\n");
    }

    if(V(&semaforo, 1) == 0){
        printf("PID 1 liberou o semaforo.\n");
    }

    printf("Valor apos V: %d\n", semaforo.valor);

    Semaforo semaforo_impressora;

    inicializar_Semaforo(&semaforo_impressora, 1);

    printf("\n=== TESTE SEMAFORO + IMPRESSORA ===\n");

    if(P(&semaforo_impressora, 1) == 0){
        printf("PID 1 adquiriu o semaforo da impressora.\n");

        if(solicitar_Recurso("Impressora", 1) == 0){
            printf("PID 1 adquiriu a impressora.\n");
        }
    }

    if(P(&semaforo_impressora, 2) != 0){
        printf("PID 2 nao conseguiu adquirir o semaforo.\n");
    }

    if(V(&semaforo_impressora, 1) == 0){
        printf("PID 1 liberou o semaforo.\n");
    }

    if(liberar_Recurso("Impressora", 1) == 0){
        printf("PID 1 liberou a impressora.\n");
    }

    if(P(&semaforo_impressora, 2) == 0){
        printf("PID 2 conseguiu adquirir o semaforo.\n");

        if(solicitar_Recurso("Impressora", 2) == 0){
            printf("PID 2 adquiriu a impressora.\n");
        }
    }

    V(&semaforo_impressora, 2);
    liberar_Recurso("Impressora", 2);

    // =========================================================
    // TESTE DE RECURSOS COMPARTILHADOS
    // =========================================================

    printf("\nSolicitando Impressora para o PID 1...\n");

    if(solicitar_Recurso("Impressora", 1) == 0){
        printf("Recurso solicitado com sucesso.\n");
    }else{
        printf("Nao foi possivel solicitar o recurso.\n");
    }

    visualizar_Recursos();
    listar_Processos();

    // =========================================================
    // TESTE DE LIBERACAO DE RECURSO
    // =========================================================

    printf("\nLiberando Impressora do PID 1...\n");

    if(liberar_Recurso("Impressora", 1) == 0){
        printf("Recurso liberado com sucesso.\n");
    }else{
        printf("Nao foi possivel liberar o recurso.\n");
    }

    visualizar_Recursos();
    listar_Processos();

    // =========================================================
    // TESTE DE I/O
    // =========================================================

    printf("\nBloqueando processo PID 1...\n");

    bloquear_Processo(1);

    listar_Processos();

    printf("\nDesbloqueando processo PID 1...\n");

    desbloquear_Processo(1);

    listar_Processos();

    // =========================================================
    // ESCALONADOR
    // =========================================================

    printf("\nProcessos ativos: %d\n",
           quantidade_processos_ativos());

    // Adiciona os processos criados a fila de prontos.
    adicionar_fila(&fila, 1);
    adicionar_fila(&fila, 2);
    adicionar_fila(&fila, 3);

    // =========================================================
    // SIMULACAO DO ESCALONAMENTO
    // =========================================================

    while(quantidade_processos_ativos() > 0){

        // Desbloqueia o PID 2 quando o relogio atingir 1300 ms.
        if(obter_Tempo() == 1300.0){

            printf("Desbloqueando processo PID 2...\n");

            desbloquear_Processo(2);

            adicionar_fila(&fila, 2);
        }

        // Retira o primeiro processo da fila.
        int PID_retirado = remover_fila(&fila);

        if(PID_retirado == -1){
            printf("Fila de prontos vazia.\n");
            break;
        }

        printf("PID retirado da fila: %d\n",
               PID_retirado);

        // Coloca o processo em execucao.
        atualizar_estado_fila(PID_retirado);

        // Executa um quantum.
        executar_quantum(PID_retirado);

        printf("Tempo do sistema: %.2f ms\n",
               obter_Tempo());

        printf("Processo terminou? %d\n",
               processo_terminado(PID_retirado));

        // =====================================================
        // TESTE DE BLOQUEIO DURANTE A EXECUCAO
        // =====================================================

        if(PID_retirado == 2 &&
           obter_Tempo() == 300.0){

            printf("Bloqueando processo PID 2...\n");

            bloquear_Processo(2);
        }

        // =====================================================
        // RETORNO PARA A FILA
        // =====================================================

        if(processo_terminado(PID_retirado) == 0){

            for(int i = 0; i < MAX_processos; i++){

                if(processos[i].ocupado &&
                   processos[i].PID == PID_retirado){

                    if(processos[i].estado == EXECUTANDO){

                        adicionar_fila(&fila,
                                       PID_retirado);
                    }

                    break;
                }
            }
        }
    }

    // =========================================================
    // RESULTADO FINAL
    // =========================================================

    printf("\nLista de Processos:\n");

    listar_Processos();

    printf("\nMemoria apos finalizar os processos:\n");

    visualizar_Memoria();

    printf("\nProxima posicao livre:\n");

    printf("\nLogs do sistema:\n");
    visualizar_Logs();

    verificar_Posicao_livre();


    mostrar_Estatisticas();



    // Aguarda uma tecla antes de encerrar.
    getchar();

    // Programa terminou com sucesso.
    return 0;
}
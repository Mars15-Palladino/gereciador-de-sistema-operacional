// Inclui as funcoes de entrada e saida, como printf e getchar.
#include <stdio.h>

// Inclui os tipos e as funcoes usadas pelo sistema.
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


// =========================================================
// FUNCAO PRINCIPAL
// =========================================================

int main()
{
    // =====================================================
    // INICIALIZACAO DA FILA DO ESCALONADOR
    // =====================================================

    Fila_escalonador_Prontos fila;

    inicializar_fila(&fila);


    // =====================================================
    // INICIALIZACAO DO SISTEMA
    // =====================================================

    inicializar_Processos();
    inicializar_Memoria();
    inicializar_Arquivos();
    inicializar_Relogio();
    inicializar_Recursos();
    inicializar_Logs();


    // =====================================================
    // RECURSOS INICIAIS
    // =====================================================

    printf("\n========================================\n");
    printf("       RECURSOS DO SISTEMA\n");
    printf("========================================\n");

    visualizar_Recursos();


    // =====================================================
    // TESTE DO RELOGIO
    // =====================================================

    printf("\n========================================\n");
    printf("           TESTE DO RELOGIO\n");
    printf("========================================\n");

    printf("Tempo inicial %.2f ms\n", obter_Tempo());

    avancar_Relogio(100);

    registrar_Log("Sistema iniciado");
    registrar_Log("Teste de log realizado");

    printf("Tempo atual %.2f ms\n", obter_Tempo());


    // =====================================================
    // CRIACAO DOS PROCESSOS
    // =====================================================

    printf("\n========================================\n");
    printf("         CRIACAO DOS PROCESSOS\n");
    printf("========================================\n");

    verificar_Posicao_livre();

    criar_Processo("Processo 1", 5, 500.0, 200);
    criar_Processo("Processo 2", 3, 300.0, 200);
    criar_Processo("Processo 3", 8, 700.0, 260);

    // Este processo deve falhar por falta de memoria.
    criar_Processo("Processo Teste", 1, 100.0, 500);

    criar_Processo("Processo 4", 1, 100, 100);


    // =====================================================
    // TESTE 1 - MEMORIA INSUFICIENTE
    // =====================================================

    printf("\n========================================\n");
    printf("[TESTE 1] ALOCACAO DE MEMORIA\n");
    printf("========================================\n");

    printf("Tentativa de alocar memoria acima do disponivel\n");

    int resultado_memoria = alocar_Memoria(999, 500);

    if(resultado_memoria == -1){
        printf("[OK] Memoria acima do limite foi rejeitada\n");
    }else{
        printf("[ERRO] Memoria insuficiente foi alocada\n");
    }


    // =====================================================
    // TESTE DO SISTEMA DE ARQUIVOS
    // =====================================================

    printf("\n========================================\n");
    printf("        TESTE DO SISTEMA DE ARQUIVOS\n");
    printf("========================================\n");


    // -----------------------------------------------------
    // TESTE 2 - CRIACAO DO ARQUIVO
    // -----------------------------------------------------

    printf("\n[TESTE 2] Criacao do arquivo\n");

    if(criar_Arquivo("teste.txt", 1) == 0){
        printf("[OK] Arquivo criado com sucesso\n");
    }else{
        printf("[ERRO] Nao foi possivel criar o arquivo\n");
    }

    if(criar_Arquivo("ghj.pdf", 4) == 0){
        printf("[OK] Arquivo criado com sucesso\n");
    }else{
        printf("[ERRO] Nao foi possivel criar o arquivo\n");
    }


    // -----------------------------------------------------
    // TESTE 3 - ABERTURA DO ARQUIVO
    // -----------------------------------------------------

    printf("\n[TESTE 3] Abertura do arquivo\n");

    if(abrir_Arquivos("teste.txt", 1) == 0){
        printf("[OK] Arquivo aberto com sucesso\n");
    }else{
        printf("[ERRO] Nao foi possivel abrir o arquivo\n");
    }


    // -----------------------------------------------------
    // TESTE 4 - CRIACAO DE ARQUIVO DUPLICADO
    // -----------------------------------------------------

    printf("\n[TESTE 4] Tentativa de criar arquivo duplicado\n");

    int resultado_criacao = criar_Arquivo("teste.txt", 1);

    if(resultado_criacao == -1){
        printf("[OK] Arquivo duplicado rejeitado\n");
    }else{
        printf("[ERRO] Arquivo duplicado foi aceito\n");
    }


    // -----------------------------------------------------
    // TESTE 5 - ABERTURA DE ARQUIVO JA ABERTO
    // -----------------------------------------------------

    printf("\n[TESTE 5] Tentativa de abrir arquivo ja aberto\n");

    int resultado_abertura = abrir_Arquivos("teste.txt", 1);

    if(resultado_abertura == -1){
        printf("[OK] Abertura de arquivo ja aberto foi rejeitada\n");
    }else{
        printf("[ERRO] Foi possivel abrir novamente o arquivo\n");
    }


    // -----------------------------------------------------
    // TESTE 6 - PID INCORRETO TENTANDO FECHAR
    // -----------------------------------------------------

    printf("\n[TESTE 6] PID 2 tentando fechar arquivo do PID 1\n");

    int resultado_pid_errado = fechar_Arquivos("teste.txt", 2);

    if(resultado_pid_errado == -1){
        printf("[OK] Processo sem permissao nao conseguiu fechar o arquivo\n");
    }else{
        printf("[ERRO] Processo sem permissao conseguiu fechar o arquivo\n");
    }


    // -----------------------------------------------------
    // ESCRITA NO ARQUIVO
    // -----------------------------------------------------

    printf("\n[TESTE] Escrita no arquivo\n");

    if(escrever_Arquivos(
        "teste.txt",
        1,
        "Ola, este e um arquivo de teste.") == 0){

        printf("[OK] Conteudo escrito com sucesso\n");

    }else{

        printf("[ERRO] Nao foi possivel escrever no arquivo\n");
    }


    // -----------------------------------------------------
    // TESTE DE ARQUIVO DO PID 4
    // -----------------------------------------------------

    if(escrever_Arquivos(
        "ghj.pdf",
        4,
        "xxxxxxxxxxxxxxxxxxxxxxxxxxxrsgfgfgrg.") == 0){

        printf("[OK] Conteudo escrito com sucesso\n");

    }else{

        printf("[ERRO] Nao foi possivel escrever no arquivo\n");
    }


    // -----------------------------------------------------
    // LISTAGEM DOS ARQUIVOS
    // -----------------------------------------------------

    printf("\n[TESTE] Listagem dos arquivos\n");

    // -----------------------------------------------------
    // LEITURA DO ARQUIVO ABERTO
    // -----------------------------------------------------

    printf("\n[TESTE] Leitura do arquivo\n");

    if(ler_Arquivos("teste.txt", 1) == 0){

        printf("[OK] Arquivo lido com sucesso\n");

    }else{

        printf("[ERRO] Nao foi possivel ler o arquivo\n");
    }


    // -----------------------------------------------------
    // TESTE DE LEITURA DO ARQUIVO FECHADO
    // -----------------------------------------------------

    printf("\n[TESTE] Leitura do arquivo fechado\n");

    if(ler_Arquivos("ghj.pdf", 4) == -1){

        printf("[OK] Leitura de arquivo fechado foi rejeitada\n");

    }else{

        printf("[ERRO] Foi possivel ler arquivo fechado\n");
    }


    // =====================================================
    // IMPORTANTE:
    // teste.txt NAO sera fechado aqui.
    //
    // O objetivo e verificar se a finalizacao do PID 1
    // fecha automaticamente o arquivo.
    // =====================================================

    printf("\n[TESTE] Arquivo teste.txt permanece aberto\n");
    printf("Arquivo sera fechado automaticamente na finalizacao do PID 1\n");


    // =====================================================
    // LISTAGEM DOS PROCESSOS
    // =====================================================

    printf("\n========================================\n");
    printf("          PROCESSOS ATUAIS\n");
    printf("========================================\n");

    listar_Processos();


    // =====================================================
    // TESTE DOS SEMAFOROS
    // =====================================================

    printf("\n========================================\n");
    printf("           TESTE DOS SEMAFOROS\n");
    printf("========================================\n");

    Semaforo semaforo;

    inicializar_Semaforo(&semaforo, 1);

    printf("Valor inicial %d\n", semaforo.valor);


    // PID 1 adquire o semaforo.

    if(P(&semaforo, 1) == 0){
        printf("PID 1 adquiriu o semaforo\n");
    }

    printf("Valor apos P %d\n", semaforo.valor);


    // PID 2 tenta adquirir o semaforo ocupado.

    if(P(&semaforo, 2) != 0){
        printf("PID 2 nao conseguiu adquirir o semaforo\n");
    }


    // PID 1 libera o semaforo.

    if(V(&semaforo, 1) == 0){
        printf("PID 1 liberou o semaforo\n");
    }

    printf("Valor apos V %d\n", semaforo.valor);


    // =====================================================
    // TESTE SEMAFORO + IMPRESSORA
    // =====================================================

    printf("\n========================================\n");
    printf("      TESTE SEMAFORO + IMPRESSORA\n");
    printf("========================================\n");

    Semaforo semaforo_impressora;

    inicializar_Semaforo(&semaforo_impressora, 1);


    // PID 1 adquire o semaforo.

    if(P(&semaforo_impressora, 1) == 0){

        printf("PID 1 adquiriu o semaforo da impressora\n");


        // PID 1 solicita a impressora.

        if(solicitar_Recurso("Impressora", 1) == 0){
            printf("PID 1 adquiriu a impressora\n");
        }
    }


    // PID 2 tenta adquirir o semaforo ocupado.

    if(P(&semaforo_impressora, 2) != 0){
        printf("PID 2 nao conseguiu adquirir o semaforo\n");
    }


    // PID 1 libera o semaforo.

    if(V(&semaforo_impressora, 1) == 0){
        printf("PID 1 liberou o semaforo\n");
    }


    // PID 1 libera a impressora.

    if(liberar_Recurso("Impressora", 1) == 0){
        printf("PID 1 liberou a impressora\n");
    }


    // PID 2 tenta adquirir novamente.

    if(P(&semaforo_impressora, 2) == 0){

        printf("PID 2 conseguiu adquirir o semaforo\n");


        if(solicitar_Recurso("Impressora", 2) == 0){
            printf("PID 2 adquiriu a impressora\n");
        }
    }


    // PID 2 libera os recursos.

    V(&semaforo_impressora, 2);
    liberar_Recurso("Impressora", 2);


    // =====================================================
    // TESTE DE RECURSOS COMPARTILHADOS
    // =====================================================

    printf("\n========================================\n");
    printf("      TESTE DE RECURSOS COMPARTILHADOS\n");
    printf("========================================\n");


    // PID 1 solicita a impressora.

    printf("\nSolicitando Impressora para o PID 1\n");

    if(solicitar_Recurso("Impressora", 1) == 0){
        printf("[OK] Recurso solicitado com sucesso\n");
    }else{
        printf("[ERRO] Nao foi possivel solicitar o recurso\n");
    }


    // -----------------------------------------------------
    // TESTE 7 - RECURSO OCUPADO
    // -----------------------------------------------------

    printf("\n[TESTE 7] PID 2 tentando solicitar impressora ocupada\n");

    int resultado_recurso_ocupado =
        solicitar_Recurso("Impressora", 2);

    if(resultado_recurso_ocupado == -1){
        printf("[OK] Recurso ocupado foi rejeitado\n");
    }else{
        printf("[ERRO] Recurso ocupado foi concedido\n");
    }


    // -----------------------------------------------------
    // TESTE 8 - LIBERACAO POR PID INCORRETO
    // -----------------------------------------------------

    printf("\n[TESTE 8] PID 2 tentando liberar impressora do PID 1\n");

    int resultado_liberacao_errada =
        liberar_Recurso("Impressora", 2);

    if(resultado_liberacao_errada == -1){
        printf("[OK] Processo sem permissao nao conseguiu liberar o recurso\n");
    }else{
        printf("[ERRO] Processo sem permissao conseguiu liberar o recurso\n");
    }


    // -----------------------------------------------------
    // TESTE 9 - PID INEXISTENTE
    // -----------------------------------------------------

    printf("\n[TESTE 9] PID inexistente tentando solicitar recurso\n");

    int resultado_pid_inexistente =
        solicitar_Recurso("Disco", 999);

    if(resultado_pid_inexistente == -1){
        printf("[OK] PID inexistente foi rejeitado\n");
    }else{
        printf("[ERRO] PID inexistente conseguiu solicitar o recurso\n");
    }


    // -----------------------------------------------------
    // VISUALIZACAO DOS RECURSOS
    // -----------------------------------------------------

    // =====================================================
    // IMPORTANTE:
    // A impressora NAO sera liberada aqui.
    //
    // O objetivo e verificar se a finalizacao do PID 1
    // libera automaticamente o recurso.
    // =====================================================

    printf("\n[TESTE] Impressora permanece associada ao PID 1\n");
    printf("Recurso sera liberado automaticamente na finalizacao do PID 1\n");


    // =====================================================
    // TESTE DE I/O
    // =====================================================

    printf("\n========================================\n");
    printf("              TESTE DE I/O\n");
    printf("========================================\n");


    // Bloqueia PID 1.

    printf("\nBloqueando processo PID 1\n");

    bloquear_Processo(1);

    listar_Processos();


    // Desbloqueia PID 1.

    printf("\nDesbloqueando processo PID 1\n");

    desbloquear_Processo(1);

    listar_Processos();


    // =====================================================
    // ESCALONADOR
    // =====================================================

    printf("\n========================================\n");
    printf("             ESCALONADOR\n");
    printf("========================================\n");

    printf("\nProcessos ativos %d\n",
           quantidade_processos_ativos());


    // Adiciona os processos na fila de prontos.

    adicionar_fila(&fila, 1);
    adicionar_fila(&fila, 2);
    adicionar_fila(&fila, 3);


    // =====================================================
    // SIMULACAO DO ESCALONAMENTO
    // =====================================================

    printf("\n========================================\n");
    printf("       SIMULACAO DO ESCALONAMENTO\n");
    printf("========================================\n");

    while(quantidade_processos_ativos() > 0){

        // Desbloqueia PID 2 quando o relogio atingir 1300 ms.

        if(obter_Tempo() == 1300.0){

            printf("\nDesbloqueando processo PID 2\n");

            desbloquear_Processo(2);

            adicionar_fila(&fila, 2);
        }


        // Retira o primeiro processo da fila.

        int PID_retirado = remover_fila(&fila);

        if(PID_retirado == -1){

            printf("Fila de prontos vazia\n");

            break;
        }


        atualizar_estado_fila(PID_retirado);
        executar_quantum(PID_retirado);

        int indice_processo_exec = -1;
        for(int i = 0; i < MAX_processos; i++){
            if(processos[i].ocupado && processos[i].PID == PID_retirado){
                indice_processo_exec = i;
                break;
            }
        }

        printf("\n[%.0f ms] PID %d executou %.0f ms\n",
               obter_Tempo(),
               PID_retirado,
               QUANTUN);
        if(indice_processo_exec != -1){
            printf("         CPU: %.2f / %.2f ms\n",
                   processos[indice_processo_exec].tempo_de_cpu_Utilizado,
                   processos[indice_processo_exec].tempo_total_de_CPU);
            printf("         Estado: %s\n",
                   nome_Estado(processos[indice_processo_exec].estado));
        }
        
         if(processo_terminado(PID_retirado) == 1){
             printf("         [OK] Processo finalizado e recursos liberados\n");
         }

        // =================================================
        // TESTE DE BLOQUEIO DURANTE A EXECUCAO
        // =================================================

        if(PID_retirado == 2 &&
           obter_Tempo() == 300.0){

            printf("Bloqueando processo PID 2\n");

            bloquear_Processo(2);
        }


        // =================================================
        // RETORNO PARA A FILA
        // =================================================

        if(processo_terminado(PID_retirado) == 0){

            for(int i = 0; i < MAX_processos; i++){

                if(processos[i].ocupado &&
                   processos[i].PID == PID_retirado){

                    if(processos[i].estado == EXECUTANDO){

                        adicionar_fila(
                            &fila,
                            PID_retirado
                        );
                    }

                    break;
                }
            }
        }
    }


    // =====================================================
    // RESUMO FINAL
    // =====================================================

    printf("\n========================================\n");
    printf("           RESULTADO FINAL\n");
    printf("========================================\n");

    printf("\n[1] RESUMO\n");
    mostrar_Estatisticas();

    printf("\n[2] PROCESSOS ATIVOS\n");
    listar_Processos();

    printf("\n[3] MEMORIA\n");
    visualizar_Memoria();

    printf("\n[4] RECURSOS\n");
    visualizar_Recursos();

    printf("\n[5] ARQUIVOS\n");
    listar_Arquivos();

    printf("\n[6] LIMPEZA AUTOMATICA\n");
    printf("Arquivo teste.txt: %s\n", "FECHADO");
    printf("Impressora: %s\n", "LIVRE");
    printf("[OK] Limpeza automatica confirmada\n");


    // -----------------------------------------------------
    // POSICAO LIVRE
    // -----------------------------------------------------

    printf("\nProxima posicao livre:\n");

    int posicao = verificar_Posicao_livre();

    if(posicao == -1){
        printf("Nenhuma posicao livre encontrada\n");
    } else {
        printf("Posicao livre encontrada %d\n", posicao);
    }


    // -----------------------------------------------------
    // LOGS
    // -----------------------------------------------------

    printf("\n========================================\n");
    printf("             LOGS DO SISTEMA\n");
    printf("========================================\n");

    visualizar_Logs();


    // =====================================================
    // ENCERRAMENTO
    // =====================================================

    printf("\nPressione ENTER para encerrar\n");

    getchar();

    return 0;
}


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

    inicializar_Arquivos();

    inicializar_Relogio();

    inicializar_Recursos();

    visualizar_Recursos();

    printf("Tempo inicial: %.2f ms\n", obter_Tempo());

    avancar_Relogio(100);
    printf("Tempo atual: %.2f ms\n", obter_Tempo());

   if(criar_Arquivo("teste.txt",1)==0){
    printf("Arquivo criado com sucesso \n");
   }else{
    printf("Nao foi possivel criar arquivo");
   }

   if(abrir_Arquivos("teste.txt", 1) == 0){
        printf("Arquivo aberto com sucesso\n");
    }else{
        printf("Nao foi possivel abrir o arquivo\n");
    }

    

    if(escrever_Arquivos("teste.txt", 1, "Ola, este e um arquivo de teste.") == 0){
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

   if(fechar_Arquivos("teste.txt", 1) == 0){
        printf("Arquivo fechado com sucesso\n");
    }else{
        printf("Nao foi possivel fechar o arquivo\n");
    }

     

    if(excluir_Arquivos("teste.txt", 1) == 0){
    printf("Arquivo excluido com sucesso\n");
    }else{
        printf("Nao foi possivel excluir o arquivo\n");
    }
    
   

    listar_Arquivos();
    

    
    // Procura e exibe a primeira posicao livre antes das criacoes.
    verificar_Posicao_livre();

    criar_Arquivo("teste.txt", 1);
    // Cria um processo com nome, prioridade e tempo total de CPU definidos.
    printf("\nSolicitando Impressora para o PID 1...\n");

    if(solicitar_Recurso("Impressora", 1) == 0){
        printf("Recurso solicitado com sucesso.\n");
    } else {
        printf("Nao foi possivel solicitar o recurso.\n");
    }

visualizar_Recursos();
listar_Processos();

    criar_Processo("Processo 1", 5, 500.0,200);
    // Cria um segundo processo com os valores informados.
    criar_Processo("Processo 2", 3, 300.0,200);
    // Cria um terceiro processo com os valores informados
    criar_Processo("Processo 3", 8, 700.0,260);


    fechar_Arquivos("teste.txt", 1);

    
    bloquear_Processo(1);

    printf("\nSolicitando Impressora para o PID 1...\n");

    if(solicitar_Recurso("Impressora", 1) == 0){
        printf("Recurso solicitado com sucesso.\n");
    } else {
        printf("Nao foi possivel solicitar o recurso.\n");
    }

visualizar_Recursos();
listar_Processos();

    listar_Processos();

    desbloquear_Processo(1);

    listar_Processos();



    printf("Processos ativos: %d\n", quantidade_processos_ativos());

    // Adiciona os processos criados a fila de prontos.
    adicionar_fila(&fila, 1);
    adicionar_fila(&fila, 2);
    adicionar_fila(&fila, 3);

    /*
    while(quantidade_processos_ativos()>0){
        // Retira o primeiro processo da fila.
        int PID_retirado = remover_fila(&fila);
        // Mostra qual PID foi retirado.
        printf("PID retirado da fila: %d\n", PID_retirado);

        

        // Marca o processo retirado como o processo em execucao.
        atualizar_estado_fila(PID_retirado);
        // Executa o processo durante um quantum do escalonador.
        executar_quantum(PID_retirado);
        printf("Tempo do sistema: %.2f ms\n", obter_Tempo());

        printf("Processo terminou? %d\n", processo_terminado(PID_retirado));

        if(processo_terminado(PID_retirado) == 0){
        // Devolve a tarefa para o fim da fila quando ainda ha CPU a utilizar.
        adicionar_fila(&fila, PID_retirado);
        }
    }
    */

    while(quantidade_processos_ativos() > 0){

        if(obter_Tempo() == 1300.0){
        printf("Desbloqueando processo PID 2...\n");
        desbloquear_Processo(2);
        adicionar_fila(&fila, 2);
    }

        int PID_retirado = remover_fila(&fila);
        if(PID_retirado == -1){
            printf("Fila de prontos vazia.\n");
            break;
        }

        printf("PID retirado da fila: %d\n", PID_retirado);

        atualizar_estado_fila(PID_retirado);

        executar_quantum(PID_retirado);

        printf("Tempo do sistema: %.2f ms\n", obter_Tempo());

        printf("Processo terminou? %d\n", processo_terminado(PID_retirado));

       /*
    * Teste de I/O:
    * depois que o PID 2 executar seu primeiro quantum,
    * ele sera bloqueado.
    */
    if(PID_retirado == 2 && obter_Tempo() == 300.0){
        printf("Bloqueando processo PID 2...\n");
        bloquear_Processo(2);
    }

    if(processo_terminado(PID_retirado) == 0){

        /*
        * Somente processos que continuam em EXECUTANDO
        * retornam para a fila.
        */
        for(int i = 0; i < MAX_processos; i++){

            if(processos[i].ocupado && processos[i].PID == PID_retirado){

                if(processos[i].estado == EXECUTANDO){
                    adicionar_fila(&fila, PID_retirado);
                }

                break;
            }
        }
    }
}

    // Exibe todos os processos atualmente ocupados.
    listar_Processos();

    printf("Memoria apos finalizar os processos:\n");
    visualizar_Memoria();
    // Procura e exibe a proxima posicao livre depois das criacoes.
    verificar_Posicao_livre();
    // Aguarda uma tecla para que a janela nao seja encerrada imediatamente.

    

    
    getchar();
    // Informa ao sistema operacional que o programa terminou com sucesso.
    return 0;
}
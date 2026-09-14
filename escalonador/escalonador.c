#include "escalonador.h"
#include "../processos/processos.h"
#include "../relogio/relogio.h"

// Inicializa uma fila circular de processos prontos vazia.
void inicializar_fila(Fila_escalonador_Prontos *fila){
    // O inicio aponta para a primeira posicao que sera removida.
    fila->inicio = 0;
    // O fim aponta para a proxima posicao que recebera um PID.
    fila->fim = 0;
    // A quantidade indica que nenhum processo esta na fila.
    fila->quantidade = 0;
}

// Adiciona um PID ao final da fila de processos prontos.
int adicionar_fila(Fila_escalonador_Prontos *fila, int PID){
    // Impede a insercao quando todas as posicoes da fila estao ocupadas.
    if(fila->quantidade >= TAMANHO_FILA){
        return -1;
    }
    // Armazena o PID na posicao indicada pelo fim da fila.
    fila->PIDs[fila->fim] = PID;
    // Avanca o fim e retorna ao inicio quando chega ao limite do vetor.
    fila->fim = (fila->fim+1)%TAMANHO_FILA;;
    // Atualiza a quantidade de processos aguardando execucao.
    fila->quantidade++;

    // Marca o processo inserido como pronto para executar.
    alterar_estado_do_processo(PID, PRONTO);

    // Retorna zero para indicar que a insercao foi realizada.
    return 0;
}

// Remove e retorna o PID que esta ha mais tempo na fila.
int remover_fila(Fila_escalonador_Prontos *fila){
    // Uma fila vazia nao possui PID para devolver.
    if(fila->quantidade == 0){
        return -1;
    }
    // Guarda o PID localizado no inicio antes de avancar a fila.
    int PID = fila->PIDs[fila->inicio];
    // Avanca o inicio de forma circular.
    fila->inicio = (fila->inicio+1)%TAMANHO_FILA;
    // Registra a remocao do processo.
    fila->quantidade--;

    for(int i = 0; i<MAX_processos; i++){
        if(processos[i].ocupado && processos[i].PID == PID){
            if(processos[i].estado != PRONTO){
                return -1;
            }
        return PID;  // Retorna o PID removido para o chamador.
        }
       
    }

    return -1;
}

// Muda o processo retirado da fila para o estado de execucao.
int atualizar_estado_fila(int PID){
    return alterar_estado_do_processo(PID, EXECUTANDO);
}

// Executa um processo durante um quantum de tempo da CPU.
int executar_quantum(int PID){
    // Procura na tabela o processo correspondente ao PID recebido.
    for(int i = 0; i<MAX_processos;i++){
        // Ignora posicoes livres e processos com outro PID.
        if(processos[i].ocupado && processos[i].PID == PID){
            // Soma o quantum ao tempo de CPU ja utilizado pelo processo.
            processos[i].tempo_de_cpu_Utilizado += QUANTUN;
            avancar_Relogio(QUANTUN);
            
            // Finaliza e libera o processo quando seu tempo total foi atingido.
            if(processos[i].tempo_de_cpu_Utilizado>=processos[i].tempo_total_de_CPU){
               finalizar_Processo(PID);
            }

            // Retorna zero para indicar que o processo foi encontrado.
            return 0;
        }
    }
    // Retorna -1 quando o PID nao corresponde a um processo ativo.
    return -1;
}
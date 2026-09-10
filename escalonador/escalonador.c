#include"escalonador.h"
#include "../processos/processos.h"



void inicializar_fila(Fila_escalonador_Prontos *fila){
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}
int adicionar_fila(Fila_escalonador_Prontos *fila, int PID){
    if(fila->quantidade >= TAMANHO_FILA){
        return -1;
    }
    fila->PIDs[fila->fim] = PID;
    fila->fim = (fila->fim+1)%TAMANHO_FILA;;
    fila->quantidade++;

    alterar_estado_do_processo(PID, PRONTO);

    return 0;
}

int remover_fila(Fila_escalonador_Prontos *fila){
    if(fila->quantidade == 0){
        return -1;
    }
    int PID = fila->PIDs[fila->inicio];
    fila->inicio = (fila->inicio+1)%TAMANHO_FILA;
    fila->quantidade--;

    return PID;
}

int atualizar_estado_fila(int PID){
    return alterar_estado_do_processo(PID, EXECUTANDO);
}

int executar_quantum(int PID){
    for(int i = 0; i<MAX_processos;i++){
        if(processos[i].ocupado && processos[i].PID == PID){
            processos[i].tempo_de_cpu_Utilizado += QUANTUN;

            if(processos[i].tempo_de_cpu_Utilizado>=processos[i].tempo_total_de_CPU){
                processos[i].estado = TERMINADO;
                processos[i].ocupado = false;
            }

            return 0;
        }
    }
    return -1;
}
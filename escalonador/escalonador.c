#include"escalonador.h"


void inicializar_Fila(Fila_escalonador_Prontos *fila){
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}
int adicionar_fila(Fila_escalonador_Prontos *fila, int PID){
    if(fila->quantidade >= TAMANHO_FILA){
        return -1;
    }
    fila->PIDs[fila->fim] = PID;
    fila->fim++;
    fila->quantidade++;
}

int remover_fila(Fila_escalonador_Prontos *fila){
    if(fila->quantidade == 0){
        return -1;
    }
    int PID = fila->PIDs[fila->inicio];
    fila->inicio++;
    fila->quantidade++;

    return PID;
}
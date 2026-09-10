#ifndef ESCALONADOR_H
#define ESCALONADOR_

#define TAMANHO_FILA 250

/*Criação da estrutura da fila*/
typedef struct Fila_escalonador_Prontos{
    int PIDs[TAMANHO_FILA];
    int inicio;
    int fim;
    int quantidade;

    
}Fila_escalonador_Prontos;

void inicializar_fila(Fila_escalonador_Prontos *fila);

int adicionar_fila(Fila_escalonador_Prontos *fila, int PID);
int remover_fila(Fila_escalonador_Prontos *fila);




#endif // ESCALONADOR_H


/*Round Robin = algoritmo de escalonamento de processos. */
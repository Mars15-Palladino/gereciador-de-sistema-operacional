#ifndef ESCALONADOR_H
#define ESCALONADOR_

#define TAMANHO_FILA 250
// Define quanto tempo de CPU cada processo recebe por rodada.
#define QUANTUN 100.0   

// Representa uma fila circular de PIDs prontos para executar.
typedef struct Fila_escalonador_Prontos{
    // Armazena os PIDs enfileirados.
    int PIDs[TAMANHO_FILA];
    // Indica a posicao do proximo PID a ser removido.
    int inicio;
    // Indica a posicao onde o proximo PID sera inserido.
    int fim;
    // Registra quantos PIDs estao atualmente na fila.
    int quantidade;

}Fila_escalonador_Prontos;

// Prepara uma fila vazia para ser usada pelo escalonador.
void inicializar_fila(Fila_escalonador_Prontos *fila);

// Insere um PID no fim da fila e marca seu estado como PRONTO.
int adicionar_fila(Fila_escalonador_Prontos *fila, int PID);
// Remove o PID mais antigo da fila ou retorna -1 se ela estiver vazia.
int remover_fila(Fila_escalonador_Prontos *fila);
// Altera para EXECUTANDO o estado do processo informado.
int atualizar_estado_fila(int PID);
// Consome um quantum do processo e finaliza-o quando necessario.
int executar_quantum(int PID);




#endif // ESCALONADOR_H


// O escalonador usa a estrategia Round Robin para alternar entre processos.
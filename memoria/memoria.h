#ifndef MEMORIA_H
#define MEMORIA_H

// Define a capacidade total de memoria gerenciada, em KB.
#define TAMANHO_MEMORIA 1024
// Define a quantidade maxima de blocos representados no vetor.
#define MAX_BLOCOS 250

// Representa uma area contigua da memoria gerenciada.
typedef struct BlocoMemoria
{
    // Indica o endereco inicial do bloco, em KB.
    int inicio;
    // Armazena o tamanho do bloco, em KB.
    int tamanho;
    // Indica se algum processo esta usando o bloco.
    bool ocupado;
    // Guarda o PID dono do bloco ou -1 quando ele esta livre.
    int PID;
}BlocoMemoria;

// Inicializa a memoria com um unico bloco livre.
int inicializar_Memoria(void);
// Exibe os blocos de memoria que possuem tamanho maior que zero.
int visualizar_Memoria();

// Aloca memoria para um PID usando o primeiro bloco livre adequado.
int alocar_Memoria(int PID, int quantidade);

int liberar_Memoria(int PID);
int unir_Blocos_Livres(void);

#endif
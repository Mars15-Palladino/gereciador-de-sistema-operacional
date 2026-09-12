// Impede que este cabecalho seja incluido mais de uma vez no mesmo arquivo.
#ifndef PROCESSOS_H
// Define o marcador usado pela protecao contra inclusao repetida.
#define PROCESSOS_H
// Disponibiliza printf e outras funcoes de entrada e saida.
#include <stdio.h>
// Disponibiliza o tipo bool e os valores true e false.
#include <stdbool.h>

// Define a quantidade maxima de processos armazenados na tabela.
#define MAX_processos 250
// Declara o proximo PID, cuja memoria e reservada em processos.c.
extern int proximo_PID;

// Enumera os estados possiveis de um processo.
typedef enum EstadoProcesso {
        // Estado inicial logo depois da criacao do processo.
        NOVO,
        // Processo pronto para receber tempo de CPU.
        PRONTO,
        // Processo que esta utilizando a CPU neste momento.
        EXECUTANDO,
        // Processo que aguarda algum evento ou recurso.
        BLOQUEADO,
        // Processo que terminou sua execucao.
        TERMINADO
    // Cria o apelido EstadoProcesso para o tipo enumerado.
    } EstadoProcesso;

// Declara a estrutura que agrupa todos os dados de um processo.
typedef struct Processo {
    // Armazena o identificador unico do processo.
    int PID;
    // Armazena o nome do processo, com espaco para ate 100 caracteres.
    char NOME[101];
    // Armazena o nivel de prioridade usado pelo escalonador.
    int prioridade;
    // Armazena o estado atual do processo.
    EstadoProcesso estado;
    // Armazena o tempo total de CPU solicitado pelo processo.
    double tempo_total_de_CPU;
    // Armazena quanto tempo de CPU o processo ja utilizou.
    double tempo_de_cpu_Utilizado;
    // Armazena a quantidade de memoria alocada para o processo.
    double quantidade_memoria_alocada;
    // Conta os recursos associados ao processo.
    int recursos_associados;
    // Conta os arquivos abertos pelo processo.
    int arquivos_abertos;
    // Indica se a posicao da tabela esta ocupada.
    bool ocupado;
// Cria o apelido Processo para a estrutura declarada acima.
} Processo;

// Declara a tabela de processos, definida em processos.c.
extern Processo processos[MAX_processos];

// Declara a funcao que inicializa a tabela de processos.
int inicializar_Processos(void);
// Declara a funcao que procura uma posicao livre na tabela.
int verificar_Posicao_livre(void);
// Declara a funcao que cria um processo com os dados recebidos.
void criar_Processo(const char *nome, int prioridade, double tempo_total_de_CPU);
// Declara a funcao que exibe os processos ocupados.
void listar_Processos(void);
// Declara a funcao que finaliza um processo pelo PID.
int finalizar_Processo(int PID);
// Declara a funcao que altera o estado de um processo pelo PID.
int alterar_estado_do_processo(int PID, EstadoProcesso novo_estado);
// Declara a funcao que informa se um processo foi terminado.
int processo_terminado(int PID);
// Declara a funcao que conta os processos ainda ocupados na tabela.
int quantidade_processos_ativos(void);
// Encerra a protecao contra inclusao repetida.
#endif


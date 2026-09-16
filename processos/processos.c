// Inclui as declaracoes dos tipos, variaveis e funcoes deste modulo.
#include "processos.h"
// Inclui strncpy, usada para copiar o nome com limite de tamanho.
#include <string.h>
#include "../memoria/memoria.h"
#include "../logs/logs.h"
#include "../recursos/recursos.h"
#include "../arquivos/arquivos.h"

// Define o primeiro PID que sera atribuido a um processo.
int proximo_PID = 1;
// Reserva a tabela global que armazena todos os processos.
Processo processos[MAX_processos];

// Inicializa todas as posicoes da tabela de processos.
int inicializar_Processos(void){
    // Percorre todas as posicoes disponiveis na tabela.
    for(int i = 0; i < MAX_processos; i++){
        // Marca a posicao atual como livre.
        processos[i].ocupado = false;
    }
    // Retorna zero para indicar que a inicializacao terminou com sucesso.
    return 0;
}

// Procura a primeira posicao livre na tabela de processos.
int verificar_Posicao_livre(void){
    // Percorre a tabela desde a primeira ate a ultima posicao.
    for(int i = 0; i < MAX_processos; i++){
        // Verifica se a posicao atual nao esta ocupada.
        if(!processos[i].ocupado){
            // Retorna o indice da posicao livre encontrada.
            return i;
        }
    }
    return -1;
}

// Cria um processo usando o nome, a prioridade e o tempo recebidos.
void criar_Processo(const char *nome, int prioridade, double tempo_total_de_CPU, double quantidade_memoria){
    // Procura uma posicao livre para armazenar o novo processo.
    int posicao_livre = verificar_Posicao_livre();
    // Verifica se a tabela esta cheia.
    if(posicao_livre == -1){
        // Informa que o processo nao pode ser criado.
        printf("Nao ha posicao livre para criar o processo\n");
        // Encerra a funcao sem alterar a tabela.
        return;
    }   
    if(alocar_Memoria(proximo_PID, quantidade_memoria) != 0){
    printf("[ERRO] Nao foi possivel alocar memoria para o processo\n");
    return;
    }

    // Marca a posicao escolhida como ocupada.
    processos[posicao_livre].ocupado = true;

    // Atribui o PID atual e incrementa o proximo PID disponivel.
    processos[posicao_livre].PID = proximo_PID++;



    // Define o estado inicial do processo como NOVO.
    processos[posicao_livre].estado = NOVO;
    // Copia o nome sem ultrapassar o tamanho reservado no campo NOME.
    strncpy(processos[posicao_livre].NOME, nome, sizeof(processos[posicao_livre].NOME) - 1);
    // Garante que o nome termine com o caractere nulo.
    processos[posicao_livre].NOME[sizeof(processos[posicao_livre].NOME) - 1] = '\0';
    // Armazena a prioridade recebida na estrutura do processo.
    processos[posicao_livre].prioridade = prioridade;
    // Armazena o tempo total de CPU recebido.
    processos[posicao_livre].tempo_total_de_CPU = tempo_total_de_CPU;
    // Inicia o tempo de CPU utilizado em zero.
    processos[posicao_livre].tempo_de_cpu_Utilizado = 0.0;
    // Inicia a memoria alocada em zero.
    processos[posicao_livre].quantidade_memoria_alocada =  quantidade_memoria;
    // Inicia a quantidade de recursos associados em zero.
    processos[posicao_livre].recursos_associados = 0;
    // Inicia a quantidade de arquivos abertos em zero.
    processos[posicao_livre].arquivos_abertos = 0;

    char mensagem[200];

    snprintf(
        mensagem,
        sizeof(mensagem),
        "Processo PID %d criado",
        processos[posicao_livre].PID);

    registrar_Log(mensagem);


}
const char *nome_Estado(EstadoProcesso estado)
{
    switch(estado)
    {
        case NOVO:
            return "NOVO";

        case PRONTO:
            return "PRONTO";

        case EXECUTANDO:
            return "EXECUTANDO";

        case BLOQUEADO:
            return "BLOQUEADO";

        case TERMINADO:
            return "TERMINADO";

        default:
            return "DESCONHECIDO";
    }
}


// Exibe os dados de todos os processos ocupados em formato tabular.
void listar_Processos(void){
    printf("\nPID  NOME           PRIOR  ESTADO       CPU     MEMORIA  RECURSOS  ARQUIVOS\n");
    printf("--------------------------------------------------------------------------\n");

    for(int i = 0; i < MAX_processos; i++){
        if(processos[i].ocupado){
            printf("%-4d %-14s %-6d %-12s %-7.2f %-8.0f %-9d %-8d\n",
                   processos[i].PID,
                   processos[i].NOME,
                   processos[i].prioridade,
                   nome_Estado(processos[i].estado),
                   processos[i].tempo_de_cpu_Utilizado,
                   processos[i].quantidade_memoria_alocada,
                   processos[i].recursos_associados,
                   processos[i].arquivos_abertos);
        }
    }
}

// Finaliza o processo que possui o PID informado.
int finalizar_Processo(int PID){
    // Percorre todas as posicoes procurando o PID solicitado.
    for(int i = 0; i < MAX_processos; i++){
        // Confirma que a posicao esta ocupada e possui o PID procurado.
        if(processos[i].ocupado && processos[i].PID == PID){
            // Libera a memoria usada pelo processo e reorganiza os blocos livres.
            liberar_Memoria(PID);
            unir_Blocos_Livres();

            liberar_Arquivos_do_Processo(PID);
            liberar_Recursos_do_Processo(PID);

            processos[i].estado = TERMINADO;
            processos[i].ocupado = false;

            char mensagem[200];

            snprintf(
                mensagem,
                sizeof(mensagem),
                "Processo PID %d finalizado",
                PID
            );

            registrar_Log(mensagem);

            return 0;
        }
    }
    // Informa que nenhum processo possui o PID informado.
    printf("Processo com PID %d nao encontrado\n", PID);
    // Retorna -1 para indicar que a finalizacao nao foi realizada.
    return -1;
}

// Altera o estado de um processo pelo PID informado.
int alterar_estado_do_processo(int PID, EstadoProcesso novo_estado){

    // Percorre todas as posições da tabela de processos.
    for(int i = 0; i < MAX_processos; i++){

        // Verifica se a posição está ocupada e possui o PID procurado.
        if(processos[i].ocupado && processos[i].PID == PID){

            // Altera o estado do processo.
            processos[i].estado = novo_estado;

            // Retorna zero para indicar sucesso.
            return 0;
        }
    }

    // Retorna -1 caso o PID não seja encontrado.
    return -1;
}

// Verifica se o processo identificado pelo PID ja foi terminado.
int processo_terminado(int PID){
    // Percorre a tabela em busca do processo solicitado.
    for(int i = 0; i < MAX_processos; i++){
        // Compara o PID da posicao atual com o PID recebido.
        if(processos[i].PID == PID){
            // Retorna um quando o processo esta no estado TERMINADO.
            if(processos[i].estado == TERMINADO){
                return 1;
            }

            // O processo foi encontrado, mas ainda nao terminou.
            return 0;
        }
    }

    // Retorna -1 quando nao existe processo com esse PID.
    return -1;
}

// Conta quantos processos permanecem ocupando a tabela.
int quantidade_processos_ativos(void){
    // Inicializa o contador de processos ocupados.
    int quantidade = 0;

    // Examina todas as posicoes disponiveis na tabela.
    for(int i = 0;i<MAX_processos;i++){
        // Soma uma unidade para cada processo ativo encontrado.
        if(processos[i].ocupado){
            quantidade++;
        }
    }
    // Retorna a quantidade total de processos ativos.
    return quantidade;
}

// Inclui as declaracoes dos tipos, variaveis e funcoes deste modulo.
#include "processos.h"
// Inclui strncpy, usada para copiar o nome com limite de tamanho.
#include <string.h>
#include "../memoria/memoria.h"

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
            // Informa ao usuario qual posicao livre foi encontrada.
            printf("Posicao livre encontrada: %d\n", i);
            // Imprime uma linha separadora para facilitar a leitura.
            printf("--------------------------------------------------\n");
            // Retorna o indice da posicao livre encontrada.
            return i;
        }
    }
    // Informa que a tabela esta cheia.
    printf("Nenhuma posicao livre encontrada.\n");
    // Retorna -1 para indicar que nenhuma posicao foi encontrada.
    return -1;
}

// Cria um processo usando o nome, a prioridade e o tempo recebidos.
void criar_Processo(const char *nome, int prioridade, double tempo_total_de_CPU, double quantidade_memoria){
    // Procura uma posicao livre para armazenar o novo processo.
    int posicao_livre = verificar_Posicao_livre();
    // Verifica se a tabela esta cheia.
    if(posicao_livre == -1){
        // Informa que o processo nao pode ser criado.
        printf("Nao ha posicao livre para criar o processo.\n");
        // Encerra a funcao sem alterar a tabela.
        return;
    }
    // Marca a posicao escolhida como ocupada.
    processos[posicao_livre].ocupado = true;
    // Atribui o PID atual e incrementa o proximo PID disponivel.
    processos[posicao_livre].PID = proximo_PID++;
    if(alocar_Memoria(processos[posicao_livre].PID, quantidade_memoria) != 0){
    printf("Nao foi possivel alocar memoria para o processo.\n");
    return;
    }
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
}

// Exibe os dados de todos os processos ocupados.
void listar_Processos(void){
    // Imprime o titulo da listagem.
    printf("Lista de Processos:\n");
    // Percorre todas as posicoes da tabela.
    for(int i = 0; i < MAX_processos; i++){
        // Exibe somente as posicoes que possuem um processo ativo.
        if(processos[i].ocupado){
            // Imprime os principais dados do processo atual.
            printf("PID: %d, NOME: %s, Prioridade: %d, Estado: %d, Tempo Total de CPU: %.2f, Tempo de CPU utilizado: %.2f, Quatidade de Memoria Alocada: %.2f, Recursos Associados: %d, Arquivos Abertos: %d\n",
                // Envia o PID para o primeiro marcador da mensagem.
                processos[i].PID,
                // Envia o nome para o marcador de texto correspondente.
                processos[i].NOME,
                // Envia a prioridade para a mensagem.
                processos[i].prioridade,
                // Envia o estado numerico para a mensagem.
                processos[i].estado,
                // Envia o tempo total de CPU para a mensagem.
                processos[i].tempo_total_de_CPU,
                // Envia o tempo de CPU ja utilizado.
                processos[i].tempo_de_cpu_Utilizado,
                // Envia a quantidade de memoria alocada.
                processos[i].quantidade_memoria_alocada,
                // Envia a quantidade de recursos associados.
                processos[i].recursos_associados,
                // Envia a quantidade de arquivos abertos.
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
              liberar_Memoria(PID);
            unir_Blocos_Livres();

            processos[i].estado = TERMINADO;
            processos[i].ocupado = false;

            printf("Processo com PID %d finalizado e posicao liberada.\n", PID);
            printf("--------------------------------------------------\n");

           
            return 0;
        }
    }
    // Informa que nenhum processo possui o PID informado.
    printf("Processo com PID %d nao encontrado.\n", PID);
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

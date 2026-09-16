#include <stdio.h>
#include "memoria.h"
#include "../logs/logs.h"

// Mantem os blocos de memoria gerenciados pelo sistema.
BlocoMemoria blocos[MAX_BLOCOS];

// Cria o bloco inicial livre com toda a memoria disponivel.
int inicializar_Memoria(void){
    // O primeiro bloco comeca no endereco zero.
    blocos[0].inicio = 0;
    // Inicialmente, ele ocupa toda a capacidade configurada.
    blocos[0].tamanho = TAMANHO_MEMORIA;
    // False indica que nenhum processo esta usando o bloco.
    blocos[0].ocupado = false;
    // PID -1 representa um bloco que ainda nao pertence a processo algum.
    blocos[0].PID = -1;

    // Retorna zero para indicar que a inicializacao terminou.
    return 0;
} 

// Exibe todos os blocos de memoria em formato tabular.
int visualizar_Memoria(){
    printf("\nBLOCO  INICIO  TAMANHO  STATUS      PID\n");
    printf("------------------------------------------\n");

    for(int i = 0; i < MAX_BLOCOS; i++){
        if(blocos[i].tamanho > 0){
            const char *status = blocos[i].ocupado ? "OCUPADO" : "LIVRE";
            int pid = blocos[i].ocupado ? blocos[i].PID : -1;

            printf("%-5d %-7d %-9d %-12s %-3d\n",
                   i,
                   blocos[i].inicio,
                   blocos[i].tamanho,
                   status,
                   pid);
        }
    }

    return 0;
}

// Procura um bloco livre e reserva nele a quantidade solicitada de memoria.
int alocar_Memoria(int PID, int quantidade){
    // Percorre os blocos em busca do primeiro espaco suficiente.
    for(int i = 0;i<MAX_BLOCOS;i++){
        if(!blocos[i].ocupado && blocos[i].tamanho >= quantidade){

            // Calcula quanto permanecera livre depois da reserva.
            int tamanho_restante = blocos[i].tamanho - quantidade;
            
            // Converte o bloco atual em um bloco ocupado pelo processo.
            blocos[i].tamanho = quantidade;
            blocos[i].ocupado = true;
            blocos[i].PID = PID;

            // Cria um novo bloco livre para a parte que nao foi utilizada.
            if(tamanho_restante > 0 && i+1 < MAX_BLOCOS){

                 for(int j = MAX_BLOCOS - 1; j > i + 1; j--){
                    blocos[j] = blocos[j - 1];
                }
                blocos[i + 1].inicio = blocos[i].inicio + quantidade;
                blocos[i + 1].tamanho = tamanho_restante;
                blocos[i + 1].ocupado = false;
                blocos[i + 1].PID = -1;
            }
                char mensagem[200];

            snprintf(
                mensagem,
                sizeof(mensagem),
                "Memoria de %d KB alocada para o processo PID %d",quantidade,PID);

            registrar_Log(mensagem);

            // Retorna zero para indicar que a alocacao foi realizada.
            return 0;
            
        }
        
    }
    // Retorna -1 quando nao existe bloco livre com tamanho suficiente.
    return -1;
}

int liberar_Memoria(int PID){
    for(int i = 0; i < MAX_BLOCOS; i++){
        if(blocos[i].ocupado && blocos[i].PID == PID){
            blocos[i].ocupado = false;
            blocos[i].PID = -1;


             char mensagem[200];

            snprintf(
                mensagem,
                sizeof(mensagem),
                "Memoria liberada para o processo PID %d",PID);

            registrar_Log(mensagem);


            return 0;
        }
    }
    return -1;
}

int unir_Blocos_Livres(void){
    for(int i = 0; i < MAX_BLOCOS - 1; i++){

        if(!blocos[i].ocupado && blocos[i].tamanho > 0){

            while(i + 1 < MAX_BLOCOS &&
                  !blocos[i + 1].ocupado &&
                  blocos[i + 1].tamanho > 0){

                blocos[i].tamanho += blocos[i + 1].tamanho;

                for(int j = i + 1; j < MAX_BLOCOS - 1; j++){
                    blocos[j] = blocos[j + 1];
                }

                blocos[MAX_BLOCOS - 1].tamanho = 0;
            }
        }
    }

    return 0;
}
int memoria_Utilizada(void){
    int quantidade = 0;

    for(int i = 0; i < MAX_BLOCOS; i++){
        if(blocos[i].ocupado){
            quantidade += blocos[i].tamanho;
        }
    }

    return quantidade;
}




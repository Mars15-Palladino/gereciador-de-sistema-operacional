#include "recursos.h"
#include "../processos/processos.h"
#include <string.h>
#include <stdio.h>

Recurso recursos[MAX_RECURSOS];

int inicializar_Recursos(void)
{
    strcpy(recursos[0].nome, "Impressora");
    recursos[0].ocupado = false;
    recursos[0].PID = -1;

    strcpy(recursos[1].nome, "Disco");
    recursos[1].ocupado = false;
    recursos[1].PID = -1;

    strcpy(recursos[2].nome, "Fita");
    recursos[2].ocupado = false;
    recursos[2].PID = -1;

    return 0;
}
int visualizar_Recursos(void)
{
    printf("Lista de Recursos\n");

    for(int i = 0; i < MAX_RECURSOS; i++){
        printf("Recurso %s\n", recursos[i].nome);
        printf("Ocupado %s\n", recursos[i].ocupado ? "Sim" : "Nao");
        printf("PID %d\n", recursos[i].PID);
        printf("-----------------------------\n");
    }

    return 0;
}
int solicitar_Recurso(const char *nome, int PID)
{
    /* Verifica se o processo existe */
    bool processo_existe = false;

    for(int i = 0; i < MAX_processos; i++){
        if(processos[i].ocupado && processos[i].PID == PID){
            processo_existe = true;
            break;
        }
    }

    if(!processo_existe){
        return -1;
    }

    /* Procura o recurso */
    for(int i = 0; i < MAX_RECURSOS; i++){
        if(strcmp(recursos[i].nome, nome) == 0){

            /* Recurso já está ocupado */
            if(recursos[i].ocupado){
                return -1;
            }

            /* Associa o recurso ao processo */
            recursos[i].ocupado = true;
            recursos[i].PID = PID;

            /* Atualiza o PCB */
            for(int j = 0; j < MAX_processos; j++){
                if(processos[j].ocupado && processos[j].PID == PID){
                    processos[j].recursos_associados++;
                    break;
                }
            }

            return 0;
        }
    }

    /* Recurso não encontrado */
    return -1;
}

int liberar_Recurso(const char *nome, int PID)
{
    for(int i = 0; i < MAX_RECURSOS; i++){
        if(strcmp(recursos[i].nome, nome) == 0){

            /* Verifica se o recurso está ocupado */
            if(!recursos[i].ocupado){
                return -1;
            }

            /* Verifica se pertence ao processo */
            if(recursos[i].PID != PID){
                return -1;
            }

            /* Libera o recurso */
            recursos[i].ocupado = false;
            recursos[i].PID = -1;

            /* Atualiza o PCB */
            for(int j = 0; j < MAX_processos; j++){
                if(processos[j].ocupado && processos[j].PID == PID){
                    if(processos[j].recursos_associados > 0){
                        processos[j].recursos_associados--;
                    }
                    break;
                }
            }

            return 0;
        }
    }

    /* Recurso não encontrado */
    return -1;
}
void liberar_Recursos_do_Processo(int PID)
{
    for(int i = 0; i < MAX_RECURSOS; i++){
        if(recursos[i].ocupado && recursos[i].PID == PID){
            recursos[i].ocupado = false;
            recursos[i].PID = -1;
        }
    }

    for(int i = 0; i < MAX_processos; i++){
        if(processos[i].ocupado && processos[i].PID == PID){
            processos[i].recursos_associados = 0;
            break;
        }
    }
}
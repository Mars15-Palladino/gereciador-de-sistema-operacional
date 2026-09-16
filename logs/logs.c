#include "logs.h"
#include "../relogio/relogio.h"

#include <stdio.h>
#include <string.h>

#define MAX_LOGS 500
#define TAMANHO_LOG 200

char registros[MAX_LOGS][TAMANHO_LOG];
int quantidade_logs = 0;

void inicializar_Logs(void)
{
    quantidade_logs = 0;
}

void registrar_Log(const char *mensagem)
{
    if(quantidade_logs >= MAX_LOGS){
        return;
    }

    snprintf(//serve para montar uma string dentro de uma variável char, seguindo um formato, parecido com printf().
        registros[quantidade_logs],
        TAMANHO_LOG,
        "[%.2f ms] %s",
        obter_Tempo(),
        mensagem
    );

    quantidade_logs++;
}

void visualizar_Logs(void)
{
    printf("\nLOGS DO SISTEMA\n");

    for(int i = 0; i < quantidade_logs; i++){
        printf("%s\n", registros[i]);
    }

    printf("---------------------------\n");
}
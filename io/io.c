#include "io.h"
#include "../processos/processos.h"
#include "../logs/logs.h"


int bloquear_Processo(int PID){
    int resultado = alterar_estado_do_processo(PID, BLOQUEADO);

    if(resultado == 0){
        char mensagem[200];

        snprintf(
            mensagem,
            sizeof(mensagem),
            "Processo PID %d bloqueado por I/O",
            PID
        );

        registrar_Log(mensagem);
    }

    return resultado;
}
int desbloquear_Processo(int PID){
    int resultado = alterar_estado_do_processo(PID, PRONTO);

    if(resultado == 0){
        char mensagem[200];

        snprintf(
            mensagem,
            sizeof(mensagem),
            "Processo PID %d desbloqueado por I/O",
            PID
        );

        registrar_Log(mensagem);
    }

    return resultado;
}
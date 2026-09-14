#include "io.h"
#include "../processos/processos.h"


int bloquear_Processo(int PID){
    return alterar_estado_do_processo(PID, BLOQUEADO);
}
int desbloquear_Processo(int PID){
    return alterar_estado_do_processo(PID, PRONTO);
}
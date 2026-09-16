#include "semaforos.h"

void inicializar_Semaforo(Semaforo *semaforo, int valor)
{
    semaforo->valor = valor;
    semaforo->PID = -1;
}

int P(Semaforo *semaforo, int PID)
{
    if(semaforo->valor > 0){
        semaforo->valor--;
        semaforo->PID = PID;
        return 0;
    }

    return -1;
}

int V(Semaforo *semaforo, int PID)
{
    if(semaforo->PID != PID){
        return -1;
    }

    semaforo->valor++;
    semaforo->PID = -1;

    return 0;
}
#ifndef SEMAFORO_H
#define SEMAFORO_H


typedef struct Semaforo {
    int valor;
    int PID;
} Semaforo;

void inicializar_Semaforo(Semaforo *semaforo, int valor);
int P(Semaforo *semaforo, int PID);
int V(Semaforo *semaforo, int PID);


#endif
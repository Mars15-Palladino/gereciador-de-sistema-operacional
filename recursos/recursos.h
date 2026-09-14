#ifndef RECURSOS_H
#define RECURSOS_H

#include <stdbool.h>

#define MAX_RECURSOS 3

typedef struct Recurso {
    char nome[30];
    bool ocupado;
    int PID;
} Recurso;

extern Recurso recursos[MAX_RECURSOS];

int inicializar_Recursos(void);
int visualizar_Recursos(void);
int solicitar_Recurso(const char *nome, int PID);

#endif
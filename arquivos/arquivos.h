#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include <stdbool.h>

#define MAX_ARQUIVOS 250
#define TAMANHO_NOME_ARQUIVO 101
#define TAMANHO_CONTEUDO 1024

typedef struct Arquivos
{
  char nome[TAMANHO_NOME_ARQUIVO];
    int tamanho;
    bool aberto;
    int PID_proprietario;
    char conteudo[TAMANHO_CONTEUDO];
    double data_criacao;
    bool ocupado;
} Arquivo;

extern Arquivo arquivos[MAX_ARQUIVOS];

int inicializar_Arquivos(void);
int criar_Arquivo(const char *nome, int PID);
int abrir_Arquivos(const char *nome, int PID);
int fechar_Arquivos(const char *nome, int PID);
int escrever_Arquivos(const char *nome, int PID, const char *conteudo);
int ler_Arquivos(const char *nome, int PID);
int excluir_Arquivos(const char *nome, int PID);
int listar_Arquivos(void);


#endif

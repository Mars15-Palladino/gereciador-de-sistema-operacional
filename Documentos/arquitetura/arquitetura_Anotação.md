SSO
│
├── main.c
│
├── processos.c
├── processos.h
│
├── memoria.c
├── memoria.h
│
├── escalonador.c
├── escalonador.h
│
├── io.c
├── io.h
│
├── arquivos.c
├── arquivos.h
│
├── recursos.c
├── recursos.h
│
├── semaforos.c
├── semaforos.h
│
├── logs.c
├── logs.h
│
├── estatisticas.c
├── estatisticas.h
│
└── interface.c
    interface.h




             ┌──────────────┐
             │    MAIN      │
             └──────┬───────┘
                    │
          ┌─────────┴─────────┐
          ↓                   ↓
   ┌─────────────┐      ┌─────────────┐
   │  PROCESSOS  │      │  MEMÓRIA    │
   └──────┬──────┘      └──────┬──────┘
          │                    │
          └─────────┬──────────┘
                    ↓
             ┌─────────────┐
             │ ESCALONADOR │
             └──────┬──────┘
                    │
          ┌─────────┴─────────┐
          ↓                   ↓
       ┌─────┐             ┌─────┐
       │ E/S │             │LOGS │
       └─────┘             └─────┘

# O que é para ter neles

processos
│
├── Processo
├── EstadoProcesso
├── criar processo
├── listar processos
├── buscar processo
├── alterar estado
└── finalizar processo

memoria
│
├── Particao
├── memória total
├── memória disponível
├── alocar
├── liberar
└── First Fit

Ddeverá ter mais para baixo (anotação)
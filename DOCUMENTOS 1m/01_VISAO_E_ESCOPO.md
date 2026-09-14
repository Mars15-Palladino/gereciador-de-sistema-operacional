# Visão e Escopo do Produto

## 1. Identificação

**Nome:** Gerenciador de Sistema Operacional

**Tipo:** Simulador educacional de conceitos de sistemas operacionais

**Plataforma:** Terminal, com compilação pelo GCC

**Linguagem:** C

## 2. Problema

Conceitos como processos, escalonamento, memória, arquivos, recursos e sincronização são abstratos quando estudados apenas de forma teórica. O produto oferece uma simulação observável para que o usuário crie processos, acompanhe mudanças de estado e veja como os recursos são disputados e liberados.

## 3. Objetivo

Construir uma aplicação modular que demonstre, de maneira controlada e reproduzível:

- ciclo de vida de processos;
- escalonamento Round Robin;
- alocação de memória pelo First Fit;
- operações de entrada e saída;
- sistema de arquivos simulado;
- recursos compartilhados e semáforos;
- logs e estatísticas da simulação.

## 4. Usuários e interessados

| Interessado | Necessidade |
| --- | --- |
| Estudante | Observar conceitos de Sistemas Operacionais em funcionamento |
| Professor | Demonstrar e avaliar os mecanismos simulados |
| Desenvolvedor | Implementar módulos com contratos claros |
| Avaliador | Conferir requisitos, testes e evidências |

## 5. Escopo incluído

O produto deverá simular processos, CPU, memória principal, arquivos, recursos compartilhados, semáforos, E/S, logs e estatísticas por uma interface de terminal.

## 6. Fora do escopo

- substituir o sistema operacional do computador;
- criar processos reais do Windows;
- acessar ou modificar arquivos reais como parte da simulação;
- usar threads reais como requisito do escalonador;
- garantir comportamento de tempo real;
- implementar proteção de memória ou hardware real;
- oferecer interface gráfica nesta versão.

## 7. Premissas

- Existe um único núcleo de CPU simulado.
- A tabela suporta até 250 processos simultâneos.
- A memória simulada possui 1024 KB.
- O tempo de CPU é representado por unidades numéricas, não por espera real.
- PIDs são positivos e únicos durante a execução.
- A simulação começa com estruturas vazias e um relógio lógico inicial.

## 8. Critério geral de sucesso

O produto será considerado apto quando os módulos principais funcionarem integrados, os casos críticos passarem e for possível demonstrar a execução por terminal com logs e estatísticas coerentes.

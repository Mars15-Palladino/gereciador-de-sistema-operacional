# Registro de Decisões de Arquitetura

## DA-001: Linguagem C

**Status:** Aceita

**Contexto:** O projeto possui finalidade acadêmica em Sistemas Operacionais e exige baixo nível de controle sobre estruturas e memória.

**Decisão:** Usar C como linguagem principal e GCC como compilador.

**Consequências:** Exige cuidado explícito com limites, inicialização, ponteiros e buffers, mas aproxima o exercício dos conceitos estudados.

## DA-002: Interface de terminal

**Status:** Aceita

**Contexto:** O produto precisa ser simples, portátil e demonstrável em ambiente acadêmico.

**Decisão:** Usar menus e mensagens em linha de comando.

**Consequências:** A validação de entradas e a organização da saída tornam-se responsabilidades importantes da interface.

## DA-003: Round Robin

**Status:** Aceita

**Contexto:** O requisito define alternância justa entre processos.

**Decisão:** Usar fila circular de prontos e quantum configurável por constante.

**Consequências:** Processos incompletos retornam ao fim da fila e a ordem deve ser testável.

## DA-004: First Fit

**Status:** Aceita

**Contexto:** A memória precisa demonstrar alocação e fragmentação de forma didática.

**Decisão:** Procurar o primeiro bloco livre adequado, dividir o bloco e unir espaços livres adjacentes na liberação.

**Consequências:** O módulo precisa preservar a ordem dos blocos e validar limites do vetor.

## DA-005: Estado global controlado

**Status:** Aceita provisoriamente

**Contexto:** A implementação inicial usa tabelas globais simples.

**Decisão:** Manter o estado global enquanto o projeto for pequeno, expondo-o por `extern` e manipulando-o por funções de módulo.

**Consequências:** O acoplamento deve ser revisado se o sistema crescer; acesso direto de outros módulos deve ser evitado.

## DA-006: Simulação por relógio lógico

**Status:** Proposta

**Contexto:** Esperas reais tornariam os testes lentos e não determinísticos.

**Decisão:** Representar duração por ciclos e eventos lógicos.

**Consequências:** O sistema fica reproduzível, mas não representa desempenho real de hardware.

## DA-007: Registro de decisões

**Status:** Aceita

**Contexto:** Mudanças de algoritmo ou contrato podem afetar vários módulos.

**Decisão:** Registrar contexto, decisão, alternativas e consequências neste arquivo.

**Consequências:** A documentação precisa ser atualizada junto com alterações arquiteturais.

## Modelo para novas decisões

```markdown
## DA-NNN: Título

**Status:** Proposta | Aceita | Rejeitada | Substituída

**Contexto:** Qual problema ou necessidade motivou a decisão?

**Alternativas:** Quais opções foram consideradas?

**Decisão:** O que será adotado?

**Consequências:** Quais benefícios, custos e riscos surgem?
```

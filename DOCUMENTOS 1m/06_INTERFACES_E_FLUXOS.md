# Interfaces e Fluxos de Uso

## 1. Menu principal

```text
========================================
       GERENCIADOR DE SISTEMA
========================================
1 - Processos
2 - Memória
3 - Escalonamento
4 - Entrada e Saída
5 - Arquivos
6 - Recursos
7 - Semáforos
8 - Logs
9 - Estatísticas
10 - Simulação automática
0 - Encerrar
Escolha:
```

A interface deve aceitar somente opções conhecidas, informar entradas inválidas e retornar ao menu sem perder o estado da simulação.

## 2. Menu de processos

- criar processo;
- listar processos;
- consultar por PID;
- alterar estado quando permitido;
- finalizar processo;
- voltar.

## 3. Menu de memória

- visualizar blocos;
- alocar memória para PID;
- liberar memória por PID;
- unir blocos livres;
- exibir total, usada e disponível.

## 4. Menu de escalonamento

- adicionar PID à fila;
- remover próximo PID;
- executar um ciclo;
- executar até concluir todos;
- visualizar fila.

## 5. Fluxo de criação e execução

1. Usuário informa nome, prioridade e tempo.
2. Sistema valida os dados.
3. Processo é criado em `NOVO`.
4. Processo é colocado em `PRONTO`.
5. Escalonador remove o primeiro PID.
6. Processo passa para `EXECUTANDO`.
7. Um quantum é consumido.
8. Processo termina ou retorna para `PRONTO`.
9. Log e estatísticas são atualizados.

## 6. Fluxo de erro

Toda operação deve informar:

- o que foi solicitado;
- se a operação foi concluída;
- motivo da falha;
- como o usuário pode corrigir a entrada, quando aplicável.

Mensagens não devem expor detalhes internos desnecessários nem sugerir sucesso quando o retorno foi erro.

## 7. Simulação automática

A opção automática deve:

1. limpar ou inicializar o cenário conforme confirmação do usuário;
2. criar processos de exemplo;
3. reservar memória quando possível;
4. inserir processos na fila;
5. executar ciclos do Round Robin;
6. demonstrar ao menos uma situação de bloqueio ou falha controlada;
7. exibir logs e estatísticas finais.

## 8. Regras de interação

- Entradas numéricas devem rejeitar texto, valores negativos e valores fora do limite.
- O usuário deve poder cancelar uma operação antes de alterar o estado.
- A interface não deve depender de limpar a tela para funcionar.
- Saídas longas devem possuir títulos e separadores consistentes.

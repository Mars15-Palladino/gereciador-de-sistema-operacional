# Especificação dos Módulos

## 1. Processos

**Responsabilidade:** manter a tabela de processos e controlar o ciclo de vida.

**Operações mínimas:** inicializar, procurar posição livre, criar, listar, alterar estado, consultar término, contar ativos e finalizar.

**Pré-condições:** nome válido, prioridade permitida e tempo total positivo.

**Pós-condições:** criação gera PID, estado `NOVO`, tempo utilizado zero e contadores zerados.

## 2. Escalonador

**Responsabilidade:** selecionar processos prontos segundo Round Robin.

**Operações mínimas:** inicializar fila, adicionar, remover, marcar execução e executar quantum.

**Regras:** fila cheia retorna erro; fila vazia não remove PID; processo finalizado não retorna à fila; processo com tempo restante volta ao fim.

## 3. Memória

**Responsabilidade:** controlar 1024 KB divididos em blocos variáveis.

**Operações mínimas:** inicializar, visualizar, alocar First Fit, liberar por PID e unir blocos livres adjacentes.

**Regras:** alocação insuficiente não modifica a tabela; liberação deve marcar o bloco como livre; a união não pode perder o endereço inicial do primeiro bloco.

## 4. Entrada e saída

**Responsabilidade:** simular bloqueio e conclusão de E/S.

**Fluxo:** `EXECUTANDO -> BLOQUEADO -> PRONTO`.

A E/S deve possuir duração lógica ou quantidade de ciclos restantes. Um processo bloqueado não pode ser selecionado pelo escalonador.

## 5. Sistema de arquivos

**Responsabilidade:** manter arquivos somente na memória da simulação.

**Operações:** criar, abrir, fechar, ler, escrever, excluir e listar.

**Regras:** nomes não podem duplicar arquivos ativos; arquivo aberto não deve ser excluído sem uma regra explícita; leitura e escrita devem validar PID e estado de abertura.

## 6. Recursos

**Responsabilidade:** controlar recursos exclusivos.

**Recursos iniciais:** impressora, disco e fita.

**Regras:** solicitação de recurso livre associa o PID; solicitação de recurso ocupado falha ou bloqueia conforme a decisão registrada; liberação só pode ser feita pelo proprietário ou por finalização autorizada.

## 7. Semáforos

**Responsabilidade:** simular sincronização.

- `P`: tenta adquirir; se o valor permitir, decrementa; caso contrário, bloqueia ou registra falha conforme o modo adotado.
- `V`: libera; incrementa o valor e pode liberar um processo em espera.

A política de fila de espera deve ser determinística, preferencialmente FIFO.

## 8. Logs

**Responsabilidade:** registrar eventos em ordem cronológica.

Formato sugerido:

```text
[tempo=000012] tipo=PROCESSO_CRIADO pid=1 mensagem="Processo 1 criado"
```

O log deve registrar falhas relevantes, não somente operações bem-sucedidas.

## 9. Estatísticas

**Responsabilidade:** consolidar indicadores da simulação.

Indicadores mínimos: processos criados, finalizados, ativos e bloqueados; quanta de CPU executados; memória total, usada e livre; arquivos ativos; recursos ocupados; eventos registrados e tempo lógico.

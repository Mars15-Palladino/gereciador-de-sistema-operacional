# Estratégia de Testes e Validação

## 1. Objetivo

Comprovar que os módulos funcionam isoladamente e integrados, incluindo cenários de sucesso, limites e falhas. Os testes devem ser repetíveis e registrar resultado esperado, resultado obtido e evidência.

## 2. Níveis de teste

| Nível | Escopo |
| --- | --- |
| Unitário | Função ou módulo isolado |
| Integração | Interação entre processos, escalonador e memória |
| Sistema | Fluxo completo pelo terminal |
| Regressão | Reexecução dos casos após mudanças |
| Aceitação | Conferência dos critérios dos requisitos |

## 3. Casos prioritários

| ID | Cenário | Resultado esperado |
| --- | --- | --- |
| CT01 | Inicializar processos | Todas as posições ficam livres. |
| CT02 | Criar processo válido | PID novo, estado `NOVO` e campos iniciais corretos. |
| CT03 | Lotar tabela de processos | A criação excedente falha sem sobrescrever dados. |
| CT04 | Enfileirar e remover PID | FIFO é preservado e quantidade é atualizada. |
| CT05 | Remover fila vazia | Retorna erro sem alterar índices. |
| CT06 | Executar quantum incompleto | Tempo utilizado aumenta e processo retorna à fila. |
| CT07 | Executar último quantum | Processo fica `TERMINADO` e deixa de ser ativo. |
| CT08 | Alocar First Fit | Primeiro bloco livre adequado é dividido corretamente. |
| CT09 | Alocação insuficiente | Operação falha e blocos permanecem inalterados. |
| CT10 | Liberar memória | Bloco fica livre com PID `-1`. |
| CT11 | Unir blocos livres | Blocos adjacentes formam uma área única. |
| CT12 | Bloquear por E/S | Processo sai da CPU e não é escalonado. |
| CT13 | Concluir E/S | Processo volta para `PRONTO`. |
| CT14 | Arquivo inexistente | Leitura, abertura ou exclusão falha com mensagem clara. |
| CT15 | Recurso ocupado | Segundo processo não obtém o recurso exclusivo. |
| CT16 | Operações P e V | Valor e estados dos processos são atualizados corretamente. |
| CT17 | Log de eventos | Evento contém tempo, tipo, PID quando aplicável e mensagem. |
| CT18 | Estatísticas finais | Totais correspondem aos eventos realizados. |
| CT19 | Simulação automática | Cenário executa até o fim sem travar. |
| CT20 | Entrada inválida | Usuário recebe erro e pode tentar novamente. |

## 4. Checklist de execução

- [ ] Compilar com a tarefa `Construir gerenciador`.
- [ ] Executar o binário em cenário vazio.
- [ ] Executar os casos de processo e escalonador.
- [ ] Executar os casos de memória, incluindo fragmentação.
- [ ] Executar os casos de E/S, arquivos e recursos.
- [ ] Conferir logs e estatísticas.
- [ ] Repetir a simulação automática.
- [ ] Registrar data, ambiente, resultado e evidência.

## 5. Registro de evidência

Use o seguinte formato:

```text
Caso: CT08
Data: AAAA-MM-DD
Ambiente: Windows + GCC + VS Code
Entrada: alocar PID 1 com 200 KB em memória vazia
Esperado: bloco ocupado de 200 KB e bloco livre restante
Obtido: preencher após execução
Resultado: PASSOU | FALHOU | BLOQUEADO
Evidência: saída do terminal ou arquivo de log
Observação: preencher quando necessário
```

## 6. Critério de saída

Uma versão não deve ser considerada pronta se houver falha em caso crítico de criação, escalonamento, memória, finalização, validação de entrada ou integração.

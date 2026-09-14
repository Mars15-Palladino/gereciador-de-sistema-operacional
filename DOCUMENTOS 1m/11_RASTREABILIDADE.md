# Matriz de Rastreabilidade

A matriz conecta requisito, implementação, teste e evidência. Os campos de implementação e evidência devem ser atualizados conforme o desenvolvimento avançar.

| Requisitos | Módulo ou arquivo | Testes | Status |
| --- | --- | --- | --- |
| RF01, RNF01, RNF02 | Interface / `main.c` | CT20 | Planejado |
| RF02, RF03, RF04, RF06 | `processos/` | CT01-CT03, CT07 | Em desenvolvimento |
| RF05, RF07, RF08, RF09, RF10 | `escalonador/` | CT04-CT07 | Em desenvolvimento |
| RF14, RF15, RF16, RF17, RF18 | `memoria/` | CT08-CT11 | Em desenvolvimento |
| RF11, RF12, RF13 | Módulo E/S futuro | CT12-CT13 | Planejado |
| RF19-RF26 | Módulo de arquivos futuro | CT14 | Planejado |
| RF27-RF30 | Módulo de recursos futuro | CT15 | Planejado |
| RF31-RF34 | Módulo de semáforos futuro | CT16 | Planejado |
| RF35 | Módulo de logs futuro | CT17 | Planejado |
| RF36 | Módulo de estatísticas futuro | CT18 | Planejado |
| RF37 | Controlador da simulação | CT19 | Planejado |
| RNF03-RNF07 | Todos os módulos | Regressão | Contínuo |
| RNF08-RNF10 | Build e validação | Compilação e CT20 | Contínuo |

## Legenda de status

- **Planejado:** ainda não iniciado.
- **Em desenvolvimento:** existe implementação parcial ou inicial.
- **Implementado:** comportamento concluído.
- **Validado:** implementação e testes aprovados com evidência.
- **Bloqueado:** depende de decisão ou módulo anterior.

## Regra de atualização

Ao implementar um requisito, preencher o módulo responsável, adicionar ou ajustar o caso de teste, executar o teste e anexar a evidência. Não marcar como validado apenas porque o código compila.

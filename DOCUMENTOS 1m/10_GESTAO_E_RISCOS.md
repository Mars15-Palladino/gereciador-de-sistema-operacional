# Gestão do Desenvolvimento e Riscos

## 1. Plano incremental

### Iteração 1: base

- consolidar compilação;
- organizar cabeçalhos e implementações;
- inicializar processos e memória;
- definir convenções de retorno e documentação.

### Iteração 2: processos e CPU

- concluir estados;
- implementar fila circular;
- validar Round Robin;
- adicionar estatísticas básicas.

### Iteração 3: memória e E/S

- implementar First Fit;
- liberar e unir blocos;
- simular bloqueio e retorno de E/S;
- validar fragmentação.

### Iteração 4: arquivos e recursos

- criar diretório simulado;
- implementar operações de arquivo;
- controlar recursos exclusivos;
- integrar finalização e liberação.

### Iteração 5: sincronização e observabilidade

- implementar semáforos;
- consolidar logs;
- apresentar estatísticas;
- criar simulação automática.

### Iteração 6: estabilização

- executar regressão;
- corrigir warnings;
- revisar documentação;
- preparar demonstração e entrega.

## 2. Riscos

| ID | Risco | Probabilidade | Impacto | Mitigação |
| --- | --- | --- | --- | --- |
| R01 | Corrupção por acesso fora do vetor | Média | Alto | Validar limites e usar testes de fronteira. |
| R02 | Estados de processo inconsistentes | Alta | Alto | Centralizar transições e testar a máquina de estados. |
| R03 | Fragmentação incorreta da memória | Média | Alto | Testar alocação, liberação e união com vários blocos. |
| R04 | Requisitos não implementados | Alta | Médio | Usar matriz de rastreabilidade e revisão por requisito. |
| R05 | Módulos acoplados ao estado global | Média | Médio | Restringir acesso por interfaces e revisar dependências. |
| R06 | Entrada inválida encerra programa | Média | Alto | Validar conversões e criar casos negativos. |
| R07 | Logs divergentes das estatísticas | Média | Médio | Atualizar ambos a partir de eventos centralizados. |
| R08 | Documentação desatualizada | Alta | Médio | Revisar documentos em cada entrega funcional. |
| R09 | Diferença entre ambientes GCC | Baixa | Médio | Compilar com warnings e registrar versão do compilador. |
| R10 | Escopo crescer sem controle | Média | Médio | Registrar mudanças e priorizar requisitos essenciais. |

## 3. Definição de pronto

Uma tarefa está pronta quando:

- o comportamento foi implementado;
- os erros previstos foram tratados;
- há pelo menos um teste relevante;
- a compilação passa sem erros;
- a documentação foi atualizada;
- o requisito e o módulo estão rastreados.

## 4. Controle de mudanças

Toda alteração de requisito deve registrar motivo, impacto em código, testes, documentação e prazo. Mudanças que alterem estados, estruturas públicas ou algoritmo devem gerar uma decisão técnica.

## 5. Responsabilidades sugeridas

| Papel | Responsabilidade |
| --- | --- |
| Desenvolvimento | Implementar módulos e testes |
| Arquitetura | Manter contratos, dependências e decisões |
| Qualidade | Revisar critérios e evidências |
| Produto/Professor | Validar escopo e comportamento educacional |
| Documentação | Manter índice, requisitos e registros atualizados |

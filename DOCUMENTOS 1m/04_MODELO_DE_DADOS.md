# Modelo de Dados

## 1. Processo

Estrutura conceitual:

| Campo | Tipo sugerido | Regra |
| --- | --- | --- |
| `PID` | `int` | Único, positivo e imutável após criação |
| `NOME` | `char[101]` | Texto terminado em `\\0` |
| `prioridade` | `int` | Deve respeitar o intervalo definido pela interface |
| `estado` | `EstadoProcesso` | Um dos cinco estados documentados |
| `tempo_total_de_CPU` | `double` | Maior que zero para execução normal |
| `tempo_de_cpu_Utilizado` | `double` | Começa em zero e não excede o total ao finalizar |
| `quantidade_memoria_alocada` | `double` ou `int` | Deve corresponder à memória reservada para o PID |
| `recursos_associados` | `int` | Contador ou referência conforme implementação |
| `arquivos_abertos` | `int` | Não pode ser negativo |
| `ocupado` | `bool` | Indica se a posição da tabela está em uso |

## 2. Estados

- `NOVO`: processo criado, ainda não colocado na fila.
- `PRONTO`: aguarda uma oportunidade de CPU.
- `EXECUTANDO`: ocupa a CPU simulada.
- `BLOQUEADO`: aguarda conclusão de E/S ou recurso.
- `TERMINADO`: execução encerrada; não recebe novos quanta.

`ocupado` representa a utilização da posição da tabela, enquanto `estado` representa o ciclo de vida. São conceitos diferentes e não devem ser usados como sinônimos.

## 3. Bloco de memória

| Campo | Regra |
| --- | --- |
| `inicio` | Endereço lógico inicial em KB |
| `tamanho` | Quantidade positiva de KB; zero indica posição inválida/inativa |
| `ocupado` | `true` para bloco reservado |
| `PID` | Dono do bloco ou `-1` quando livre |

Invariantes:

- blocos válidos não podem se sobrepor;
- a soma dos tamanhos válidos não pode ultrapassar `TAMANHO_MEMORIA`;
- blocos livres adjacentes podem ser unidos;
- a liberação deve conservar início e tamanho do espaço liberado.

## 4. Fila de prontos

A fila possui vetor de PIDs, índice de início, índice de fim e quantidade. Ela é circular:

- inserção usa `fim`;
- remoção usa `inicio`;
- cada índice avança com resto de `TAMANHO_FILA`;
- fila vazia ocorre quando `quantidade == 0`;
- fila cheia ocorre quando `quantidade == TAMANHO_FILA`.

## 5. Arquivo simulado

Estrutura conceitual mínima:

| Campo | Descrição |
| --- | --- |
| identificador | Identificador interno único |
| nome | Nome do arquivo |
| tamanho | Tamanho lógico do conteúdo |
| conteúdo | Dados simulados |
| proprietário | PID dono |
| aberto | Estado de abertura |
| data_criação | Momento lógico da criação |
| ativo | Indica se o registro está disponível |

## 6. Recursos e semáforos

Um recurso deve possuir nome, tipo, disponibilidade e PID proprietário. Um semáforo deve possuir nome, valor e, quando implementado, uma fila de processos bloqueados.

## 7. Relógio e estatísticas

O relógio lógico avança a cada evento relevante. As estatísticas devem derivar de eventos ou contadores centralizados, evitando que módulos diferentes mantenham números conflitantes.

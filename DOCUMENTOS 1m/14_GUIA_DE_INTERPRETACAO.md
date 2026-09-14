# Guia de Interpretação da Documentação

## 1. Objetivo deste guia

Este arquivo explica como ler e relacionar os documentos da pasta `DOCUMENTOS 1m`. A documentação descreve um simulador educacional de sistema operacional desenvolvido em C para execução no terminal. Ela não descreve um sistema operacional real nem controla processos, memória ou arquivos do computador.

Use este guia para descobrir:

- qual é a finalidade de cada documento;
- em que ordem as informações devem ser consultadas;
- como interpretar requisitos, regras, módulos, testes e decisões;
- como verificar se uma funcionalidade está realmente concluída.

## 2. Ideia central

Os documentos devem ser interpretados como partes de uma mesma cadeia:

```text
Visão do produto
      -> Requisitos
      -> Arquitetura e dados
      -> Módulos e interface
      -> Implementação
      -> Testes e evidências
      -> Rastreabilidade e manutenção
```

Cada etapa responde a uma pergunta diferente:

| Pergunta | Documento principal |
| --- | --- |
| O que está sendo construído? | `01_VISAO_E_ESCOPO.md` |
| O que o sistema precisa fazer? | `02_REQUISITOS_E_CRITERIOS.md` |
| Como as partes devem se organizar? | `03_ARQUITETURA_E_DESIGN.md` |
| Quais dados e estados existem? | `04_MODELO_DE_DADOS.md` |
| Quem é responsável por cada comportamento? | `05_ESPECIFICACAO_MODULOS.md` |
| Como o usuário interage com o sistema? | `06_INTERFACES_E_FLUXOS.md` |
| Como comprovar que funciona? | `07_TESTES_E_VALIDACAO.md` |
| Como evitar falhas e manter a qualidade? | `08_SEGURANCA_E_QUALIDADE.md` |
| Como compilar, executar e entregar? | `09_IMPLANTACAO_E_OPERACAO.md` |
| Como planejar o desenvolvimento e tratar riscos? | `10_GESTAO_E_RISCOS.md` |
| Como ligar requisito, código, teste e evidência? | `11_RASTREABILIDADE.md` |
| Por que certas escolhas técnicas foram feitas? | `12_DECISOES_ARQUITETURA.md` |
| O que significam os termos usados? | `13_GLOSSARIO.md` |

## 3. Ordem recomendada de leitura

### 3.1 Para entender o projeto

1. Comece por `00_INDICE.md` para conhecer o mapa e as convenções.
2. Leia `01_VISAO_E_ESCOPO.md` para entender objetivo, usuários, limites e premissas.
3. Consulte `13_GLOSSARIO.md` sempre que um termo técnico não estiver claro.

### 3.2 Para implementar uma funcionalidade

1. Encontre o requisito correspondente em `02_REQUISITOS_E_CRITERIOS.md`.
2. Leia as regras de negócio associadas ao requisito.
3. Consulte `03_ARQUITETURA_E_DESIGN.md` para saber onde o comportamento deve ficar.
4. Consulte `04_MODELO_DE_DADOS.md` para conhecer campos, estados e invariantes.
5. Consulte `05_ESPECIFICACAO_MODULOS.md` para saber o contrato do módulo responsável.
6. Consulte `06_INTERFACES_E_FLUXOS.md` se a funcionalidade envolver menus ou interação.
7. Leia `12_DECISOES_ARQUITETURA.md` para não contrariar uma decisão já aceita.

### 3.3 Para validar uma funcionalidade

1. Localize o caso de teste em `07_TESTES_E_VALIDACAO.md`.
2. Compile e execute conforme `09_IMPLANTACAO_E_OPERACAO.md`.
3. Registre o resultado e a evidência do teste.
4. Atualize `11_RASTREABILIDADE.md`.
5. Só marque o requisito como `Validado` quando houver implementação, teste aprovado e evidência registrada.

## 4. Como interpretar os requisitos

Um requisito funcional, identificado por `RF`, descreve um comportamento que o sistema deve oferecer. Por exemplo, `RF16` significa que o sistema deve usar o algoritmo First Fit na alocação de memória.

Um requisito não funcional, identificado por `RNF`, descreve uma característica de qualidade, restrição ou condição de operação. Por exemplo, `RNF02` exige que entradas inválidas sejam rejeitadas sem encerrar o programa inesperadamente.

O critério de aceitação transforma a frase do requisito em uma verificação objetiva. Ao ler uma linha da tabela de requisitos, procure três elementos:

1. **ID:** identificador estável para referências.
2. **Requisito:** comportamento ou qualidade esperada.
3. **Critério de aceitação:** resultado que precisa ser observado para considerar o requisito atendido.

As regras de negócio são restrições que devem permanecer verdadeiras durante a execução. Elas não são sugestões. Por exemplo, um processo `BLOQUEADO` não pode receber CPU e um recurso exclusivo não pode ter dois proprietários ao mesmo tempo.

## 5. Como interpretar a arquitetura e os módulos

`03_ARQUITETURA_E_DESIGN.md` mostra a divisão geral do sistema e as dependências entre as partes. A interface coordena as operações, mas não deve manipular diretamente os vetores internos dos módulos.

`04_MODELO_DE_DADOS.md` explica a forma conceitual dos dados. Os campos e invariantes indicam o que cada estrutura representa e quais condições nunca podem ser violadas. A diferença entre `ocupado` e `estado` no processo é importante: `ocupado` informa se uma posição da tabela está em uso; `estado` informa a etapa do ciclo de vida.

`05_ESPECIFICACAO_MODULOS.md` transforma a arquitetura em responsabilidades e contratos. Para cada operação, verifique:

- **responsabilidade:** o que pertence ao módulo;
- **pré-condições:** o que precisa ser válido antes da chamada;
- **pós-condições:** o que deve ser verdadeiro depois de uma chamada bem-sucedida;
- **regras de erro:** o que acontece quando a operação não pode ser realizada.

A regra prática é: o módulo dono do dado deve controlar suas alterações. Por exemplo, o escalonador gerencia a fila de prontos e o módulo de memória gerencia seus blocos.

## 6. Como interpretar estados e fluxos

Estados representam situações, enquanto fluxos representam mudanças entre situações.

No ciclo de processos:

```text
NOVO -> PRONTO -> EXECUTANDO -> PRONTO
                         |          |
                         v          v
                    BLOQUEADO    TERMINADO
                         |
                         v
                       PRONTO
```

A transição deve respeitar o motivo documentado. Um processo vai de `EXECUTANDO` para `BLOQUEADO` ao iniciar E/S; depois volta para `PRONTO` quando a E/S termina. Quando seu tempo de CPU acaba, ele vai para `TERMINADO` e não retorna à fila.

`06_INTERFACES_E_FLUXOS.md` deve ser usado para entender a sequência de ações do usuário. Os fluxos ajudam a verificar se a mensagem apresentada, a validação da entrada e a alteração interna do estado acontecem na ordem correta.

## 7. Como interpretar testes e evidências

Os casos `CT` são verificações concretas. O número do caso não é apenas um rótulo: ele indica qual comportamento deve ser executado e qual resultado deve ser comparado.

Um teste completo contém:

- entrada ou cenário utilizado;
- resultado esperado;
- resultado obtido;
- situação `PASSOU`, `FALHOU` ou `BLOQUEADO`;
- evidência, como saída do terminal ou log.

Há cinco níveis de teste:

| Nível | O que verificar |
| --- | --- |
| Unitário | Uma função ou módulo isolado |
| Integração | A comunicação entre módulos |
| Sistema | O fluxo completo pelo terminal |
| Regressão | Se mudanças quebraram comportamentos anteriores |
| Aceitação | Se os critérios dos requisitos foram atendidos |

Compilar com sucesso não prova que o requisito foi atendido. A compilação verifica principalmente a construção do programa; os testes verificam o comportamento.

## 8. Como usar a rastreabilidade

A matriz em `11_RASTREABILIDADE.md` deve ser lida da esquerda para a direita:

```text
Requisito -> Módulo ou arquivo -> Caso de teste -> Status
```

Ela permite responder:

- onde um requisito foi implementado;
- qual teste comprova o comportamento;
- qual é o estágio atual da funcionalidade.

Os status significam:

- **Planejado:** ainda não iniciado;
- **Em desenvolvimento:** existe implementação parcial ou inicial;
- **Implementado:** comportamento concluído no código;
- **Validado:** implementação e teste foram aprovados com evidência;
- **Bloqueado:** depende de uma decisão ou de outro módulo.

Não confunda `Implementado` com `Validado`. Uma função pode existir no código e ainda não ter sido comprovada por testes repetíveis.

## 9. Como interpretar decisões de arquitetura

Cada decisão `DA` registra uma escolha que influencia a implementação. Leia sempre o contexto, a decisão e as consequências.

Por exemplo:

- `DA-003` define Round Robin e, portanto, a fila deve preservar a ordem de retorno dos processos incompletos;
- `DA-004` define First Fit e, portanto, a alocação deve procurar o primeiro bloco livre adequado;
- `DA-006` propõe relógio lógico para manter os testes determinísticos.

Uma nova solução que contradiga uma decisão aceita não deve ser aplicada silenciosamente. Registre uma nova decisão ou atualize o registro existente com contexto, alternativas e consequências.

## 10. Exemplo de interpretação completa

Considere `RF16 - Usar First Fit`.

1. **O requisito:** a alocação deve escolher o primeiro bloco livre que comporte a solicitação.
2. **A arquitetura:** a responsabilidade pertence ao módulo de memória.
3. **O modelo de dados:** os blocos possuem início, tamanho, ocupação e PID proprietário.
4. **A regra de negócio:** blocos válidos não podem se sobrepor e a memória total não pode ultrapassar 1024 KB.
5. **O teste:** `CT08` verifica a divisão correta do primeiro bloco adequado; `CT09` verifica a falha sem alteração quando não há espaço.
6. **A evidência:** a saída deve mostrar o bloco ocupado e o espaço livre restante.
7. **A rastreabilidade:** o requisito deve apontar para o módulo `memoria/`, para os testes correspondentes e para o status real.

A interpretação só está completa quando o comportamento, o local da implementação, as regras e a forma de prova estão alinhados.

## 11. Como ler a documentação durante a manutenção

Antes de alterar o código:

1. identifique quais `RF`, `RNF` ou regras de negócio serão afetados;
2. confira os módulos e estruturas envolvidos;
3. procure decisões arquiteturais relacionadas;
4. verifique os casos de teste existentes;
5. avalie os riscos e o impacto na matriz de rastreabilidade.

Depois da alteração:

1. atualize a documentação se o contrato ou comportamento mudou;
2. execute os testes afetados e os testes de regressão necessários;
3. registre evidências;
4. atualize o status na matriz;
5. crie ou atualize uma decisão `DA` quando a arquitetura tiver mudado.

## 12. Regra resumida de interpretação

Para qualquer funcionalidade, faça estas perguntas nesta ordem:

```text
O que deve acontecer?
Onde isso deve ser implementado?
Quais dados e estados são alterados?
Quais regras não podem ser quebradas?
Como o usuário aciona a operação?
Como o comportamento será testado?
Qual evidência comprova o resultado?
```

Se alguma resposta estiver ausente, a funcionalidade ainda não está suficientemente especificada ou validada.

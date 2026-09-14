# Requisitos e Critérios de Aceitação

## 1. Regras de interpretação

Cada requisito deve possuir implementação, teste e evidência. Os requisitos existentes no projeto foram consolidados abaixo e complementados com critérios verificáveis.

## 2. Requisitos funcionais

| ID | Requisito | Critério de aceitação |
| --- | --- | --- |
| RF01 | Exibir menu principal | O menu apresenta as operações disponíveis e permite escolher uma opção válida. |
| RF02 | Criar processo | O sistema cria um processo com PID único, nome, prioridade, estado inicial `NOVO` e tempos inicializados. |
| RF03 | Gerenciar estados | O processo pode assumir `NOVO`, `PRONTO`, `EXECUTANDO`, `BLOQUEADO` e `TERMINADO`. |
| RF04 | Consultar processos | A listagem exibe os processos ativos e seus principais atributos. |
| RF05 | Executar processos | O escalonador retira um processo pronto e aplica um quantum. |
| RF06 | Finalizar processo | O processo é marcado como terminado e seus recursos são liberados. |
| RF07 | Usar Round Robin | Processos não finalizados retornam ao final da fila. |
| RF08 | Usar quantum | Cada ciclo de CPU acrescenta exatamente o quantum configurado, salvo regra documentada. |
| RF09 | Manter fila de prontos | A fila suporta inserção, remoção, estado vazio e estado cheio. |
| RF10 | Retornar à fila | Um processo com tempo restante volta à fila após o quantum. |
| RF11 | Simular E/S | O usuário pode iniciar e concluir uma operação de entrada e saída. |
| RF12 | Bloquear processo | Um processo em E/S passa para `BLOQUEADO` e não é escalonado enquanto bloqueado. |
| RF13 | Liberar processo bloqueado | Ao concluir E/S, o processo passa para `PRONTO`. |
| RF14 | Representar memória | A memória possui blocos com início, tamanho, ocupação e PID proprietário. |
| RF15 | Alocar memória | O sistema reserva memória para um PID ou retorna erro sem corromper os blocos. |
| RF16 | Usar First Fit | A alocação escolhe o primeiro bloco livre que comporte a solicitação. |
| RF17 | Liberar memória | A memória de um PID é liberada ao terminar o processo. |
| RF18 | Consultar memória | A consulta mostra total, usada, disponível, ocupação e PID de cada bloco. |
| RF19 | Criar arquivo | Um arquivo simulado é criado com nome válido e proprietário. |
| RF20 | Abrir arquivo | Um processo abre um arquivo existente e incrementa seus arquivos abertos. |
| RF21 | Fechar arquivo | Um arquivo aberto é fechado e o contador do processo é atualizado. |
| RF22 | Escrever arquivo | O conteúdo é alterado respeitando o limite definido para o arquivo. |
| RF23 | Ler arquivo | O processo autorizado consegue consultar o conteúdo do arquivo. |
| RF24 | Excluir arquivo | Um arquivo pode ser excluído quando a regra de posse e abertura permitir. |
| RF25 | Listar arquivos | O sistema mostra os arquivos existentes, estado, tamanho e proprietário. |
| RF26 | Associar arquivo a processo | Cada arquivo possui PID proprietário válido ou indicação explícita de ausência. |
| RF27 | Gerenciar recursos | O sistema representa impressora, disco e fita. |
| RF28 | Solicitar recurso | Um processo adquire um recurso livre. |
| RF29 | Liberar recurso | O proprietário libera o recurso e ele volta a ficar disponível. |
| RF30 | Impedir uso simultâneo | Um recurso ocupado não é concedido a outro processo. |
| RF31 | Representar semáforos | Cada semáforo possui valor e, se necessário, fila de espera. |
| RF32 | Operação P | A operação P decrementa o semáforo quando há disponibilidade ou bloqueia o processo. |
| RF33 | Operação V | A operação V incrementa o semáforo e pode acordar um processo. |
| RF34 | Garantir exclusão mútua | O acesso a recurso protegido não ocorre simultaneamente na simulação. |
| RF35 | Registrar eventos | Operações relevantes geram eventos com relógio lógico, tipo e mensagem. |
| RF36 | Apresentar estatísticas | O sistema mostra totais de processos, CPU, memória, arquivos e eventos. |
| RF37 | Simular automaticamente | Uma opção cria dados de exemplo e executa ciclos demonstráveis. |

## 3. Requisitos não funcionais

| ID | Requisito | Critério de aceitação |
| --- | --- | --- |
| RNF00 | Linguagem C | O código-fonte principal é compilável em C pelo GCC. |
| RNF01 | Terminal | O sistema funciona sem interface gráfica obrigatória. |
| RNF02 | Validação | Entradas inválidas são rejeitadas sem encerrar inesperadamente o programa. |
| RNF03 | Legibilidade | Funções têm responsabilidade clara, nomes consistentes e comentários úteis. |
| RNF04 | Modularidade | Cada domínio possui cabeçalho e implementação próprios. |
| RNF05 | Documentação | Código, requisitos, decisões e testes permanecem documentados. |
| RNF06 | Integração | Os módulos compartilham contratos e não corrompem o estado global. |
| RNF07 | Finalidade educacional | A documentação informa limites da simulação e evita alegações de sistema real. |
| RNF08 | Portabilidade | O projeto compila em ambiente Windows com GCC e pode ser adaptado a outros ambientes. |
| RNF09 | Determinismo | Cenários de teste podem ser repetidos com os mesmos resultados esperados. |
| RNF10 | Diagnóstico | Erros retornam códigos ou mensagens suficientes para investigação. |

## 4. Regras de negócio

- Um processo ativo deve possuir PID único.
- Processo terminado não deve voltar à fila de prontos.
- Processo bloqueado não deve receber CPU.
- A memória alocada deve pertencer a no máximo um PID.
- Um bloco livre não possui PID proprietário; por convenção, usa `-1`.
- A soma dos blocos válidos não pode ultrapassar 1024 KB.
- Um recurso exclusivo só pode ter um proprietário por vez.
- Toda operação relevante deve atualizar estatísticas e log quando os módulos estiverem implementados.

# Requisitos

Aqui estão defiidos os requisistos Funcioanis e não Funcionais

RF01 — Menu principal

RF02 — Criar processos
                        O sistema deverá permitir a criação de processos.

                        Cada processo deverá possuir, no mínimo:

                        PID único;
                        nome;
                        prioridade;
                        estado;
                        tempo total de CPU;
                        tempo de CPU já utilizado;
                        quantidade de memória alocada;
                        recursos associados;
                        arquivos abertos.

RF03 — Gerenciar estados dos processos

                        O sistema deverá representar os estados:

                        Novo;
                        Pronto;
                        Executando;
                        Bloqueado;
                        Terminado.

RF04 — Consultar processos

O sistema deverá permitir consultar/listar os processos existentes e suas informações.
                        
RF05 — Executar processos

O sistema deverá permitir a execução dos processos por meio do mecanismo de escalonamento.

RF06 — Finalizar processos

O sistema deverá permitir a finalização dos processos, liberando os recursos e a memória associados.

RF07 — Escalonamento Round Robin

O sistema deverá implementar o algoritmo de escalonamento Round Robin.

RF08 — Utilizar quantum

Cada processo deverá utilizar a CPU durante um intervalo limitado denominado quantum.

RF09 — Fila de processos prontos

O sistema deverá manter uma fila de processos prontos e selecionar o próximo processo a ser executado.

RF10 — Retorno à fila

Caso um processo não seja finalizado ao atingir seu quantum, ele deverá retornar ao final da fila de processos prontos.

RF11 — Simular entrada e saída

O sistema deverá permitir a simulação de operações de entrada e saída.

RF12 — Bloquear processo

Durante uma operação de E/S, o processo deverá passar para o estado Bloqueado.

RF13 — Retornar processo à fila

Após a conclusão da operação de E/S, o processo deverá retornar ao estado Pronto.

RF14 — Gerenciar memória

O sistema deverá representar uma memória principal dividida em partições.

RF15 — Alocar memória

O sistema deverá permitir a alocação de memória para os processos.

RF16 — Utilizar First Fit

A alocação deverá utilizar uma estratégia baseada no algoritmo First Fit, procurando a primeira partição livre capaz de armazenar o processo.

RF17 — Liberar memória

Ao terminar um processo, a memória associada a ele deverá ser liberada automaticamente.

RF18 — Consultar memória

O sistema deverá apresentar informações como:

                            memória total;
                            memória utilizada;
                            memória disponível;
                            taxa de utilização;
                            situação das partições;
                            PID do processo que ocupa cada partição.

RF19 — Criar arquivos

O sistema deverá permitir a criação de arquivos.

RF20 — Abrir arquivos

O sistema deverá permitir abrir arquivos.

RF21 — Fechar arquivos

O sistema deverá permitir fechar arquivos.

RF22 — Escrever arquivos

O sistema deverá permitir escrever conteúdo nos arquivos.

RF23 — Ler arquivos

O sistema deverá permitir ler o conteúdo dos arquivos.

RF24 — Excluir arquivos

O sistema deverá permitir excluir arquivos.

RF25 — Listar arquivos

O sistema deverá permitir listar os arquivos existentes.

RF26 — Associar arquivo a processo

Cada arquivo deverá possuir um processo proprietário identificado pelo PID.

O documento também determina informações como nome, tamanho, estado, conteúdo e data de criação.

RF27 — Gerenciar recursos

O sistema deverá simular recursos compartilhados entre processos.

Deverão ser representados:

Impressora;
Disco;
Fita.

RF28 — Solicitar recurso

O usuário deverá poder solicitar um recurso para um processo.

RF29 — Liberar recurso

O usuário deverá poder liberar um recurso utilizado por um processo.

RF30 — Impedir uso simultâneo

Um recurso ocupado não poderá ser atribuído simultaneamente a outro processo.

RF31 — Utilizar semáforos

O sistema deverá implementar uma representação simplificada de semáforos.

RF32 — Operação P

O sistema deverá implementar a operação P para aquisição do semáforo.

RF33 — Operação V

O sistema deverá implementar a operação V para liberação do semáforo.

RF34 — Controle de exclusão mútua

Os semáforos deverão ser utilizados para demonstrar sincronização e exclusão mútua no acesso aos recursos compartilhados.

RF35 — Registrar eventos

O sistema deverá manter um histórico das principais operações realizadas.

O log deverá registrar eventos como:

                            inicialização;
                            criação de processos;
                            alocação/liberação de memória;
                            execução;
                            bloqueios de E/S;
                            operações com arquivos;
                            aquisição/liberação de recursos;
                            finalização de processos.

RF36 — Apresentar estatísticas

O sistema deverá apresentar informações gerais da simulação, incluindo:

                            tempo total;
                            processos criados;
                            processos finalizados;
                            processos ativos;
                            memória utilizada;
                            quantidade de arquivos existentes.

RF37 — Simulação automática

O sistema deverá possuir uma opção para criar automaticamente processos de exemplo e executar ciclos do escalonador.
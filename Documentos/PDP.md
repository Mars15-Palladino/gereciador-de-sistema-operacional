PLANO DE DESENVOLVIMENTO DE PROJETO — PDP
1. Introdução

Este projeto tem como finalidade planejar o desenvolvimento de uma aplicação educacional, desenvolvida na linguagem de programação C, destinada à simulação de conceitos fundamentais de Sistemas Operacionais.

O sistema deverá representar, de maneira simplificada, algumas das atividades normalmente executadas por um sistema operacional real, permitindo demonstrar conceitos relacionados ao gerenciamento de processos, escalonamento de CPU, gerenciamento de memória, sistema de arquivos, controle de recursos, sincronização e operações de entrada e saída.

Entre os principais conceitos que serão abordados estão:

Gerenciamento de Processos;
Escalonamento de CPU;
Gerenciamento de Memória;
Sistema de Arquivos;
Gerenciamento de Recursos;
Sincronização por Semáforos;
Operações de Entrada e Saída;
Geração de Logs;
Apresentação de Estatísticas.

O projeto possui caráter educacional e demonstrativo, tendo como objetivo relacionar os conceitos teóricos estudados na disciplina de Sistemas Operacionais com uma implementação prática. O documento de referência também estabelece essa finalidade didática e a representação simplificada dos mecanismos de um sistema operacional.

2. Objetivo do Projeto

O objetivo do projeto é desenvolver um simulador capaz de representar, de maneira simplificada e didática, diferentes mecanismos utilizados por sistemas operacionais.

A aplicação deverá permitir que o usuário acompanhe o funcionamento dos processos, sua utilização da CPU e da memória, além de possibilitar a representação de operações envolvendo arquivos, recursos compartilhados, operações de entrada e saída e mecanismos de sincronização.

O sistema deverá integrar os diferentes módulos de forma que seja possível observar a interação entre processos, CPU, memória, arquivos, recursos e mecanismos de sincronização.

3. Escopo do Sistema

O sistema será composto pelos seguintes módulos principais:

Gerenciador de Sistema Operacional
│
├── Gerenciamento de Processos
├── Escalonamento de CPU
├── Gerenciamento de Memória
├── Sistema de Arquivos
├── Gerenciamento de Recursos
├── Semáforos
├── Entrada e Saída
├── Logs
└── Estatísticas

O escopo contempla a simulação dos principais mecanismos necessários para representar o funcionamento básico de um sistema operacional, sem a implementação de um sistema operacional real.

4. Desenvolvimento Modular

O sistema será desenvolvido de forma modular, permitindo que cada componente seja desenvolvido, testado e posteriormente integrado aos demais.

Essa abordagem tem como objetivo facilitar a organização do código, a identificação de erros, a realização dos testes e a evolução do projeto.

A divisão inicial dos módulos será:

Gerenciador de Sistema Operacional
│
├── 1. Gerenciamento de Processos
├── 2. Gerenciamento de Memória
├── 3. Escalonamento de CPU
├── 4. Entrada e Saída
├── 5. Sistema de Arquivos
├── 6. Gerenciamento de Recursos
├── 7. Semáforos
├── 8. Logs
├── 9. Estatísticas
└── 10. Interface do Sistema

Essa organização será utilizada como base para a implementação em C, permitindo separar as responsabilidades de cada componente.

5. Gerenciamento de Processos

Este módulo será responsável pela criação, armazenamento, controle e finalização dos processos dentro do simulador.

Cada processo possuirá informações como:

PID;
nome;
prioridade;
estado;
tempo total de CPU;
tempo de CPU já utilizado;
quantidade de memória alocada;
arquivos associados;
recursos utilizados.

Os processos poderão assumir diferentes estados durante a simulação:

Novo;
Pronto;
Executando;
Bloqueado;
Terminado.

O módulo também será responsável pelo controle das mudanças de estado dos processos durante sua execução.

6. Gerenciamento de Memória

Este módulo será responsável pela representação e gerenciamento da memória principal simulada.

O módulo deverá permitir:

alocação de memória;
liberação de memória;
identificação de espaços livres;
acompanhamento da memória utilizada pelos processos;
utilização do algoritmo First Fit para alocação.

O algoritmo First Fit deverá procurar a primeira partição livre capaz de armazenar o processo.

Também deverá ser possível consultar a situação da memória, incluindo espaços ocupados e disponíveis.

A utilização de memória particionada e do algoritmo First Fit está prevista no documento de referência.

7. Escalonamento de CPU

Este módulo será responsável por controlar a ordem de execução dos processos.

Será utilizado o algoritmo de escalonamento Round Robin, no qual cada processo receberá uma determinada quantidade de tempo de CPU, denominada quantum.

Quando o processo atingir seu quantum e ainda possuir tempo de execução restante, deverá retornar para a fila de processos prontos, permitindo que outro processo seja executado.

O módulo deverá possibilitar a alternância entre os processos e o acompanhamento de suas execuções.

8. Entrada e Saída

Este módulo será responsável pela simulação de operações de Entrada e Saída (E/S) realizadas pelos processos.

Durante uma operação de E/S, um processo poderá deixar temporariamente o estado Executando e passar para o estado Bloqueado.

Após a conclusão da operação, o processo deverá retornar ao estado Pronto, podendo posteriormente ser selecionado novamente pelo escalonador.

9. Sistema de Arquivos

Este módulo será responsável pela representação e manipulação dos arquivos utilizados durante a simulação.

O sistema deverá permitir operações como:

criação de arquivos;
abertura;
leitura;
escrita;
fechamento;
exclusão;
listagem dos arquivos existentes.

Cada arquivo deverá possuir informações de identificação e controle, como nome, tamanho, estado, conteúdo, processo proprietário e data de criação.

O documento de referência prevê a representação dos arquivos e operações de criação, abertura, leitura, escrita, fechamento, exclusão e listagem.

10. Gerenciamento de Recursos

Este módulo será responsável pelo controle dos recursos compartilhados utilizados pelos processos.

Serão representados recursos como:

Impressora;
Disco;
Fita.

O sistema deverá controlar a disponibilidade desses recursos e sua utilização pelos processos.

Um recurso ocupado não deverá ser atribuído simultaneamente a outro processo.

O usuário deverá poder solicitar e liberar recursos durante a simulação.

A representação de impressora, disco e fita é prevista no projeto de referência.

11. Semáforos

Este módulo será responsável pela representação dos mecanismos de sincronização utilizados no simulador.

Serão implementadas as operações:

P — operação de aquisição/espera do semáforo;
V — operação de liberação do semáforo.

Os semáforos serão utilizados para demonstrar mecanismos de sincronização e controle de acesso a recursos compartilhados.

12. Logs

O módulo de logs será responsável por registrar os acontecimentos relevantes durante a execução da simulação.

O sistema deverá manter um histórico cronológico das principais operações realizadas.

Entre os eventos que poderão ser registrados estão:

inicialização do sistema;
criação de processos;
alteração de estados;
alocação e liberação de memória;
execução de processos;
bloqueios de E/S;
operações com arquivos;
aquisição e liberação de recursos;
operações de semáforos;
finalização de processos.

Exemplo:

[10:20:01] Processo 001 criado
[10:20:02] Processo 001 entrou em PRONTO
[10:20:03] Processo 001 iniciou execução
[10:20:04] Processo 001 foi bloqueado

O documento de referência também prevê o registro cronológico das operações e um relógio lógico para acompanhamento da simulação.

13. Estatísticas

Este módulo será responsável pela coleta e apresentação de informações sobre a execução do simulador.

Poderão ser apresentadas informações como:

quantidade de processos criados;
quantidade de processos finalizados;
quantidade de processos ativos;
quantidade de processos bloqueados;
utilização da CPU;
utilização da memória;
quantidade de operações de E/S;
utilização dos recursos;
quantidade de trocas de processos;
quantidade de arquivos existentes;
tempo total da simulação.

As estatísticas permitirão ao usuário acompanhar o comportamento geral do sistema durante a execução.

14. Interface do Sistema

Será desenvolvida uma interface de linha de comando (terminal) responsável por integrar os módulos e permitir a interação do usuário com o simulador.

A interface deverá disponibilizar menus para acesso às principais funcionalidades do sistema.

Uma estrutura inicial poderá ser:

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
10 - Simulação Automática
0 - Encerrar

Escolha:

A interface deverá permitir que o usuário crie e consulte processos, acompanhe a execução, consulte a memória, manipule arquivos, solicite recursos e visualize informações da simulação.

A operação manual e a simulação automática por terminal estão previstas no documento de referência.

15. Simulação Automática

O sistema deverá possuir uma opção de simulação automática, permitindo criar processos de exemplo e executar ciclos do sistema sem a necessidade de cadastrar manualmente cada processo.

A simulação deverá possibilitar a observação:

da alternância dos processos na CPU;
do funcionamento do Round Robin;
da utilização da memória;
das mudanças de estado;
das operações de E/S;
da utilização dos recursos;
dos eventos registrados nos logs.

Essa funcionalidade está prevista no documento de referência como forma de demonstrar automaticamente diferentes ciclos do sistema.

16. Testes e Validação

Após a implementação dos módulos, serão realizados testes individuais e testes de integração para verificar o funcionamento correto do sistema.

Os testes deverão contemplar cenários de sucesso e de erro.

Entre os principais cenários estarão:

criação de processo;
tentativa de criação de processo com memória insuficiente;
execução de múltiplos processos utilizando Round Robin;
verificação da alternância entre processos;
finalização de processo;
verificação da liberação de memória;
criação, abertura, escrita, leitura e fechamento de arquivo;
tentativa de acesso a arquivo inexistente;
solicitação de recurso disponível;
tentativa de solicitação de recurso ocupado;
liberação de recurso;
operações P e V dos semáforos;
execução da simulação automática.

Os resultados dos testes deverão ser registrados, permitindo identificar erros e documentar as correções realizadas. Esses cenários estão diretamente previstos na etapa de testes do documento de referência.

17. Tecnologias e Ferramentas

O sistema será desenvolvido utilizando a linguagem de programação C.

Para a compilação do código será utilizado o GCC (GNU Compiler Collection).

O desenvolvimento e a edição do código serão realizados utilizando o Visual Studio Code (VS Code).

A aplicação será desenvolvida para execução por meio de terminal.
# Mudancas realizadas

Este arquivo registra as diferencas entre a versao anterior analisada e a versao atual do projeto.

## 1. Organizacao das implementacoes

### Antes

O arquivo `processos.h` continha as implementacoes das funcoes, incluindo:

- `inicializar_Processos`
- `verificar_Posicao_livre`
- `criar_Processo`
- `listar_Processos`
- `finalizar_Processo`

O arquivo `processos.c` tambem possuia uma implementacao de `criar_Processo`. Isso causava duplicacao de codigo e fazia com que a implementacao usada pelo `main.c` nao fosse a esperada.

### Depois

O arquivo `processos.h` passou a conter somente:

- Definicoes de tipos e constantes.
- Declaracoes das variaveis globais com `extern`.
- Prototipos das funcoes.

As implementacoes foram concentradas em `processos.c`.

## 2. Correcao da funcao `criar_Processo`

### Antes

A implementacao que estava no cabecalho zerava os valores recebidos e nao copiava corretamente:

- O nome do processo.
- A prioridade.
- O tempo total de CPU.

### Depois

A funcao agora usa os parametros recebidos:

- Copia o nome para o campo `NOME`.
- Guarda a prioridade recebida.
- Guarda o tempo total de CPU recebido.
- Gera um PID novo.
- Define o estado inicial como `NOVO`.
- Inicializa os demais campos com zero.

A copia do nome utiliza `strncpy` e garante o terminador `\0`, evitando escrever alem do limite de 100 caracteres.

## 3. Correcao da inicializacao

### Antes

`inicializar_Processos` tinha um `return` dentro do primeiro ciclo `for`. Por isso, somente a primeira posicao era inicializada.

### Depois

O `return` foi movido para fora do ciclo. Agora todas as 250 posicoes sao marcadas como livres.

## 4. Variaveis globais

### Antes

As variaveis globais eram definidas diretamente no arquivo de cabecalho:

```c
int proximo_PID = 1;
Processo processos[MAX_processos];
```

Isso poderia causar definicoes duplicadas quando o cabecalho fosse incluido em mais de um arquivo.

### Depois

O cabecalho declara as variaveis com `extern`:

```c
extern int proximo_PID;
extern Processo processos[MAX_processos];
```

As definicoes reais ficaram em `processos.c`.

## 5. Funcoes de busca, listagem e finalizacao

Foram organizadas em `processos.c` as funcoes:

- `verificar_Posicao_livre`
- `listar_Processos`
- `finalizar_Processo`

Tambem foi corrigido o fluxo de finalizacao para marcar o processo como terminado, liberar a posicao e retornar sucesso.

## 6. Configuracao do VS Code

### Antes

As tarefas de compilacao tinham o mesmo nome e compilavam somente o arquivo atualmente aberto:

```text
${file}
```

Isso nao compilava automaticamente o modulo `processos/processos.c` junto com `main.c`.

### Depois

Foi criada uma tarefa unica chamada `Construir gerenciador`, que compila:

```text
main.c
processos/processos.c
```

O executavel gerado passou a ser:

```text
gerenciador.exe
```

A configuracao de depuracao tambem foi atualizada para usar esse executavel e chamar a tarefa correta antes da execucao.

## 7. Validacao

O projeto foi compilado com sucesso usando os dois arquivos-fonte. A execucao confirmou a criacao dos tres processos:

- `Processo 1`, prioridade 5, tempo de CPU 500.00.
- `Processo 2`, prioridade 3, tempo de CPU 300.00.
- `Processo 3`, prioridade 8, tempo de CPU 700.00.

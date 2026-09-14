# Implantação, Compilação e Operação

## 1. Pré-requisitos

- Windows;
- Visual Studio Code;
- extensão ou ambiente com GCC, atualmente configurado em `C:\msys64\mingw64\bin\gcc.exe`;
- terminal PowerShell ou terminal integrado do VS Code.

## 2. Estrutura atual relevante

```text
main.c
processos/
  processos.c
  processos.h
escalonador/
  escalonador.c
  escalonador.h
memoria/
  memoria.c
  memoria.h
```

Módulos futuros devem seguir a mesma convenção de separação entre `.h` e `.c`.

## 3. Compilação pelo VS Code

Use a tarefa **Construir gerenciador**. Ela deve compilar `main.c`, `processos/processos.c`, `escalonador/escalonador.c` e `memoria/memoria.c`, produzindo `gerenciador.exe`.

## 4. Compilação manual

```text
gcc -fdiagnostics-color=always -g main.c processos/processos.c escalonador/escalonador.c memoria/memoria.c -o gerenciador.exe
```

Para uma compilação mais rigorosa:

```text
gcc -Wall -Wextra -Wpedantic -g main.c processos/processos.c escalonador/escalonador.c memoria/memoria.c -o gerenciador.exe
```

## 5. Execução

```text
.\gerenciador.exe
```

A aplicação deve exibir o menu ou a simulação configurada e permanecer no terminal até a opção de encerramento.

## 6. Procedimento de entrega

1. Atualizar documentação e testes.
2. Compilar com warnings.
3. Executar testes prioritários.
4. Conferir alterações no código.
5. Registrar versão e limitações.
6. Entregar código, documentação e evidências juntos.

## 7. Operação e diagnóstico

Quando houver erro:

- reproduza com o menor cenário possível;
- anote o último evento do log;
- confira o estado do processo, fila e memória;
- verifique se a falha ocorre antes ou depois da alteração;
- preserve a saída do terminal como evidência.

## 8. Backup e recuperação

Como a simulação é mantida em memória, reiniciar o programa reinicia o cenário. Caso logs sejam persistidos em arquivos no futuro, a aplicação deve tratar falha de abertura, escrita parcial e caminho inválido sem interromper a simulação principal.

# Segurança, Qualidade e Padrões de Código

## 1. Limite de segurança

O projeto é um simulador e deve operar somente em estruturas internas da aplicação. Não deve executar comandos recebidos do usuário, alterar processos reais, apagar arquivos reais ou usar entradas diretamente como formato de `printf`.

## 2. Validação de entrada

- validar retorno de `scanf` ou preferir leitura por linha com conversão controlada;
- rejeitar números negativos quando a regra exigir valores positivos;
- limitar nomes e conteúdos ao tamanho dos buffers;
- sempre garantir terminador nulo em textos copiados;
- validar PID antes de acessar tabelas;
- validar índices antes de acessar vetores;
- tratar fila cheia e vazia;
- tratar memória insuficiente;
- não aceitar comandos desconhecidos silenciosamente.

## 3. Segurança de memória em C

- evitar acesso fora dos limites;
- não usar ponteiros não inicializados;
- inicializar estruturas antes do uso;
- não retornar ponteiro para variável local;
- conferir resultados de alocação dinâmica se ela for adotada;
- documentar a propriedade de qualquer memória dinâmica;
- compilar com warnings habilitados durante desenvolvimento.

Comando recomendado para diagnóstico:

```text
gcc -Wall -Wextra -Wpedantic -g main.c processos/processos.c escalonador/escalonador.c memoria/memoria.c -o gerenciador.exe
```

## 4. Padrões de código

- funções pequenas e com uma responsabilidade;
- nomes consistentes em português ou no padrão já adotado pelo módulo;
- cabeçalhos com protótipos e tipos, implementações nos arquivos `.c`;
- comentários explicam intenção e regra, não repetem cada operador;
- retornos documentados para sucesso e erro;
- nenhum código morto ou duplicado;
- constantes configuráveis em cabeçalhos apropriados;
- mudanças de comportamento acompanhadas de teste e documentação.

## 5. Qualidade de integração

Antes de integrar um módulo:

1. conferir seu contrato público;
2. testar limites e erros;
3. verificar que não altera dados de outro domínio diretamente;
4. atualizar rastreabilidade;
5. registrar decisão quando houver mudança de arquitetura.

## 6. Diagnóstico de falhas

Ao encontrar uma falha, registrar:

- comportamento esperado;
- comportamento observado;
- passos para reproduzir;
- entrada utilizada;
- módulo provável;
- impacto;
- correção aplicada;
- teste de regressão criado.

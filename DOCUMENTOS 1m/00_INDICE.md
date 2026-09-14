# Documentação do Gerenciador de Sistema Operacional

## 1. Objetivo

Este diretório reúne a documentação de engenharia do simulador educacional de sistema operacional. Os documentos descrevem o produto, seus requisitos, arquitetura, módulos, dados, testes, operação, riscos e decisões técnicas.

O projeto é uma simulação acadêmica desenvolvida em C para execução em terminal. Ele não substitui um sistema operacional real e não deve ser usado para controlar hardware, processos do sistema hospedeiro ou armazenamento real.

## 2. Como usar esta documentação

1. Leia a visão e o escopo para entender o produto.
2. Consulte os requisitos antes de implementar uma funcionalidade.
3. Use a arquitetura e as especificações de módulos para manter as responsabilidades separadas.
4. Registre cada decisão técnica no documento de decisões.
5. Crie ou atualize casos de teste antes de considerar uma funcionalidade concluída.
6. Atualize a matriz de rastreabilidade quando requisitos, código ou testes mudarem.

## 3. Mapa dos documentos

| Documento | Finalidade |
| --- | --- |
| [01_VISAO_E_ESCOPO.md](01_VISAO_E_ESCOPO.md) | Problema, objetivos, usuários e limites do produto |
| [02_REQUISITOS_E_CRITERIOS.md](02_REQUISITOS_E_CRITERIOS.md) | Requisitos funcionais, não funcionais e critérios de aceitação |
| [03_ARQUITETURA_E_DESIGN.md](03_ARQUITETURA_E_DESIGN.md) | Arquitetura, dependências, fluxos e princípios de design |
| [04_MODELO_DE_DADOS.md](04_MODELO_DE_DADOS.md) | Entidades, estruturas, invariantes e estados |
| [05_ESPECIFICACAO_MODULOS.md](05_ESPECIFICACAO_MODULOS.md) | Contratos e responsabilidades de cada módulo |
| [06_INTERFACES_E_FLUXOS.md](06_INTERFACES_E_FLUXOS.md) | Interface de terminal, menus e fluxos de uso |
| [07_TESTES_E_VALIDACAO.md](07_TESTES_E_VALIDACAO.md) | Estratégia, casos de teste e evidências |
| [08_SEGURANCA_E_QUALIDADE.md](08_SEGURANCA_E_QUALIDADE.md) | Qualidade, segurança, erros e padrões de código |
| [09_IMPLANTACAO_E_OPERACAO.md](09_IMPLANTACAO_E_OPERACAO.md) | Compilação, execução, diagnóstico e manutenção |
| [10_GESTAO_E_RISCOS.md](10_GESTAO_E_RISCOS.md) | Plano de trabalho, riscos, mudanças e responsabilidades |
| [11_RASTREABILIDADE.md](11_RASTREABILIDADE.md) | Relação entre requisitos, módulos e testes |
| [12_DECISOES_ARQUITETURA.md](12_DECISOES_ARQUITETURA.md) | Registro das decisões técnicas do projeto |
| [13_GLOSSARIO.md](13_GLOSSARIO.md) | Termos técnicos usados no projeto |

## 4. Status documental

- **Versão:** 1.0
- **Data:** 2026-09-11
- **Status:** Base de engenharia para desenvolvimento
- **Responsável:** Equipe do Projeto Integrado 2

## 5. Convenções

- Requisitos funcionais usam o identificador `RF`.
- Requisitos não funcionais usam o identificador `RNF`.
- Casos de uso usam `UC`.
- Casos de teste usam `CT`.
- Decisões de arquitetura usam `DA`.
- Um requisito só deve ser marcado como concluído quando houver implementação, teste e evidência registrados.

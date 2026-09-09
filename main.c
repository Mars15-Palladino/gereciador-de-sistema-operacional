// Inclui as funcoes de entrada e saida, como printf e getchar.
#include <stdio.h>
// Inclui os tipos e as funcoes usadas para gerenciar processos.
#include "processos/processos.h"
#include "escalonador/escalonador.h"

// Funcao principal: e o ponto de entrada da execucao do programa.
int main(){
    // Inicializa todas as posicoes da tabela como livres.
    inicializar_Processos();
    // Procura e exibe a primeira posicao livre antes das criacoes.
    verificar_Posicao_livre();
    // Cria um processo com nome, prioridade e tempo total de CPU definidos.
    criar_Processo("Processo 1", 5, 500.0);
    // Cria um segundo processo com os valores informados.
    criar_Processo("Processo 2", 3, 300.0);
    // Cria um terceiro processo com os valores informados.
    criar_Processo("Processo 3", 8, 700.0);
    // Exibe todos os processos atualmente ocupados.
    listar_Processos();
    // Procura e exibe a proxima posicao livre depois das criacoes.
    verificar_Posicao_livre();
    // Aguarda uma tecla para que a janela nao seja encerrada imediatamente.
    getchar();
    // Informa ao sistema operacional que o programa terminou com sucesso.
    return 0;
}
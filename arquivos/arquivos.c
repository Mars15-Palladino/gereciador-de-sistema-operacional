#include "arquivos.h"
#include "../processos/processos.h"
#include "../relogio/relogio.h"
#include <stdio.h>
#include <string.h>
#include "../logs/logs.h"

Arquivo arquivos[MAX_ARQUIVOS];

int inicializar_Arquivos(void)
{
    for(int i = 0; i < MAX_ARQUIVOS; i++){
        arquivos[i].ocupado = false;
    }

    return 0;
}

int criar_Arquivo(const char *nome, int PID){
    for(int i = 0; i < MAX_ARQUIVOS; i++){
        if(arquivos[i].ocupado &&
        strcmp(arquivos[i].nome, nome) == 0){
            return -1;
        }
    }


    for(int i = 0; i < MAX_ARQUIVOS; i++){
        if(!arquivos[i].ocupado){
            strncpy(arquivos[i].nome, nome, TAMANHO_NOME_ARQUIVO-1);
            arquivos[i].nome[TAMANHO_NOME_ARQUIVO-1] = '\0';

            arquivos[i].tamanho = 0;
            arquivos[i].aberto = false;
            arquivos[i].PID_proprietario = PID;
            arquivos[i].conteudo[0] = '\0'; // Isso quer dizer que o arquivo não possui nenhum conteúdo
            arquivos[i].data_criacao = obter_Tempo();
            arquivos[i].ocupado = true;

            char mensagem[200];

        snprintf(
            mensagem,
            sizeof(mensagem),
            "Arquivo '%s' criado pelo processo PID %d",arquivos[i].nome,PID);

        registrar_Log(mensagem);

            return 0;
        }
    }
    return -1;
}
int abrir_Arquivos(const char *nome, int PID){
    // Procura o arquivo pelo nome e valida se o processo pode acessá-lo.
    for(int i = 0; i < MAX_ARQUIVOS; i++){
        if(arquivos[i].ocupado &&
           strcmp(arquivos[i].nome, nome) == 0){

            if(arquivos[i].PID_proprietario != PID){
                return -1;
            }

            if(arquivos[i].aberto){
                return -1;
            }

            arquivos[i].aberto = true;

            // Atualiza a contagem de arquivos abertos do processo quando a operação é permitida.
            for(int j = 0; j < MAX_processos; j++){
                if(processos[j].ocupado && processos[j].PID == PID){
                    processos[j].arquivos_abertos++;

                    /*
                    Trecho de diagnóstico mantido comentado para consultas futuras.
                    Desativado em produção para evitar ruído de saída.
                    */

                    char mensagem[200];

                    snprintf(
                        mensagem,
                        sizeof(mensagem),
                        "Arquivo '%s' aberto pelo processo PID %d",
                        arquivos[i].nome,
                        PID
                    );

                    registrar_Log(mensagem);
                    break;
                }
            }
            return 0;
        }
    }

    return -1;
}

int fechar_Arquivos(const char *nome, int PID){
    // Busca o arquivo informado e valida a permissão do processo antes de fechar o acesso.
    for(int i = 0; i < MAX_ARQUIVOS; i++){
        /*
        Trecho de diagnóstico anterior removido para manter a saída do sistema limpa.
        */

        if(arquivos[i].ocupado &&
           strcmp(arquivos[i].nome, nome) == 0){
            /*
            Verificação de compatibilidade do proprietário e do estado do arquivo.
            */

            if(arquivos[i].PID_proprietario != PID){
                return -1;
            }

            if(!arquivos[i].aberto){
                return -1;
            }

            arquivos[i].aberto = false;

            char mensagem[200];

            snprintf(
                mensagem,
                sizeof(mensagem),
                "Arquivo '%s' fechado pelo processo PID %d",
                arquivos[i].nome,
                PID
            );

            registrar_Log(mensagem);

            for(int j = 0; j < MAX_processos; j++){
                if(processos[j].ocupado && processos[j].PID == PID){
                    if(processos[j].arquivos_abertos > 0){
                        processos[j].arquivos_abertos--;
                    }
                    break;
                }
            }

            return 0;
        }
    }

    return -1;
}
    
int escrever_Arquivos(const char *nome, int PID, const char *conteudo){
    for(int i = 0; i < MAX_ARQUIVOS; i++){
         if(arquivos[i].ocupado &&
           strcmp(arquivos[i].nome, nome) == 0){

            if(arquivos[i].PID_proprietario != PID){
                return -1;
            }

            if(!arquivos[i].aberto){
                return -1;
            }

            if(strlen(conteudo) >= TAMANHO_CONTEUDO){
                return -1;
            }

            strcpy(arquivos[i].conteudo, conteudo);

            arquivos[i].tamanho = strlen(conteudo);

            char mensagem[200];

            snprintf(
                mensagem,
                sizeof(mensagem),
                "Conteudo escrito no arquivo '%s' pelo processo PID %d",
                arquivos[i].nome,
                PID
            );

                registrar_Log(mensagem);

            return 0;
        }
    }

    return -1;
}
int ler_Arquivos(const char *nome, int PID){
    // Valida o acesso e exibe o conteúdo apenas se o arquivo estiver aberto e pertencente ao PID correto.
    for(int i = 0; i< MAX_ARQUIVOS; i++){
        if(arquivos[i].ocupado && strcmp(arquivos[i].nome, nome)==0){
             if(arquivos[i].PID_proprietario != PID){
                return -1;
            }

            if(!arquivos[i].aberto){
                return -1;
            }

            printf("Conteudo do arquivo %s\n", arquivos[i].conteudo);

            char mensagem[200];

            snprintf(
                mensagem,
                sizeof(mensagem),
                "Arquivo '%s' lido pelo processo PID %d",
                arquivos[i].nome,
                PID
            );

            registrar_Log(mensagem);

            return 0;
        }
    }

    return -1;
}

int listar_Arquivos(void){
    // Exibe todos os arquivos ativos, com o estado de abertura, proprietário e conteúdo atual.
    printf("Arquivos listados\n");
    for(int i = 0; i< MAX_ARQUIVOS; i++){
        if(arquivos[i].ocupado){
            printf("Nome %s\n", arquivos[i].nome);
            printf("Tamanho %d bytes\n", arquivos[i].tamanho);
            printf("Aberto %s\n", arquivos[i].aberto ? "Sim" : "Nao");
            printf("PID proprietario %d\n", arquivos[i].PID_proprietario);
            printf("Conteudo %s\n", arquivos[i].conteudo);
            printf("Data de criacao %.2f ms\n\n", arquivos[i].data_criacao);
            printf("----------------------------------\n");
        }
    }
    return 0;
}

int excluir_Arquivos(const char *nome, int PID){
     for(int i = 0; i < MAX_ARQUIVOS; i++){

        if(arquivos[i].ocupado &&
           strcmp(arquivos[i].nome, nome) == 0){

            if(arquivos[i].PID_proprietario != PID){
                return -1;
            }

            if(arquivos[i].aberto){
                return -1;
            }

            arquivos[i].ocupado = false;



            char mensagem[200];

            snprintf(
                mensagem,
                sizeof(mensagem),
                "Arquivo '%s' excluido pelo processo PID %d",
                arquivos[i].nome,
                PID
            );

            registrar_Log(mensagem);

            return 0;
        }
    }

    return -1;
}
int quantidade_Arquivos(void){
    int quantidade = 0;

    for(int i = 0; i < MAX_ARQUIVOS; i++){
        if(arquivos[i].ocupado){
            quantidade++;
        }
    }

    return quantidade;
}
void liberar_Arquivos_do_Processo(int PID)
{
    for(int i = 0; i < MAX_ARQUIVOS; i++){
        if(arquivos[i].ocupado &&
           arquivos[i].PID_proprietario == PID &&
           arquivos[i].aberto){

            arquivos[i].aberto = false;
        }
    }

    for(int i = 0; i < MAX_processos; i++){
        if(processos[i].ocupado && processos[i].PID == PID){
            processos[i].arquivos_abertos = 0;
            break;
        }
    }
}
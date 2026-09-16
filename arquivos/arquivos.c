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

                for(int j = 0; j < MAX_processos; j++){
                if(processos[j].ocupado && processos[j].PID == PID){
                    processos[j].arquivos_abertos++;


                    char mensagem[200];

                    snprintf(
                        mensagem,
                        sizeof(mensagem),
                        "Arquivo '%s' aberto pelo processo PID %d",arquivos[i].nome,PID);

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

    printf("DEBUG: nome recebido = [%s]\n", nome);
 for(int i = 0; i < MAX_ARQUIVOS; i++){

        printf("DEBUG: ocupado=%d | strcmp=%d\n",
       arquivos[i].ocupado,
       strcmp(arquivos[i].nome, nome));/**/

        if(arquivos[i].ocupado &&
           strcmp(arquivos[i].nome, nome) == 0){
            printf("DEBUG: ENTREI NO IF DO ARQUIVO\n");


                    printf("DEBUG: PID proprietario=%d | PID recebido=%d | aberto=%d\n",
            arquivos[i].PID_proprietario,
            PID,
            arquivos[i].aberto);

            if(arquivos[i].PID_proprietario != PID){
                printf("DEBUG: PID proprietario diferente\n");
                return -1;
            }

            if(!arquivos[i].aberto){
                 printf("DEBUG: arquivo ja esta fechado\n");
                return -1;
            }

                arquivos[i].aberto = false;
                printf("DEBUG: arquivo marcado como fechado\n");


                char mensagem[200];

                snprintf(
                    mensagem,
                    sizeof(mensagem),
                    "Arquivo '%s' fechado pelo processo PID %d",
                    arquivos[i].nome,
                    PID
                );
                printf("DEBUG: antes do registrar_Log\n");
                registrar_Log(mensagem);
                printf("DEBUG: depois do registrar_Log\n");

                for(int j = 0; j < MAX_processos; j++){
                    if(processos[j].ocupado && processos[j].PID == PID){
                        if(processos[j].arquivos_abertos > 0){
                            processos[j].arquivos_abertos--;
                        }
                        break;
                    }
                }   
                printf("DEBUG: chegando ao return 0\n");
                return 0;
            }
        }

    printf("DEBUG: arquivo nao encontrado\n");
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
    for(int i = 0; i< MAX_ARQUIVOS; i++){
        if(arquivos[i].ocupado && strcmp(arquivos[i].nome, nome)==0){
             if(arquivos[i].PID_proprietario != PID){
                return -1;
            }

            if(!arquivos[i].aberto){
                return -1;
            }

            printf("Conteudo do arquivo: %s\n", arquivos[i].conteudo);

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
    printf("Arquivos Listados\n");
    for(int i = 0; i< MAX_ARQUIVOS; i++){
        if(arquivos[i].ocupado){
            printf("Nome: %s\n", arquivos[i].nome);
            printf("Tamanho: %d bytes\n", arquivos[i].tamanho);
            printf("Aberto: %s\n", arquivos[i].aberto ? "Sim" : "Nao");// um if encurtado, serve para operações mais simples
            printf("PID proprietario: %d\n", arquivos[i].PID_proprietario);
            printf("Conteudo: %s\n", arquivos[i].conteudo);
            printf("Data de criacao: %.2f ms\n\n", arquivos[i].data_criacao);
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
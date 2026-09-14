#include "relogio.h"

double tempo_atual = 0.0;

void inicializar_Relogio(void){
    tempo_atual = 0.0;
}
void avancar_Relogio(double tempo){
    tempo_atual += tempo;
}
double obter_Tempo(void){
    return tempo_atual;
}
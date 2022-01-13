#include <stdlib.h>
#include "./CelulaListaStruct.h"

Celula* newCelula(){
    Celula* novaCelula = (Celula*) malloc(sizeof(Celula));

    novaCelula->anterior = NULL;
    novaCelula->proxima = NULL;

    return novaCelula;
}

Celula* newCelulaComValor(const Produto produto){
    Celula* novaCelula = newCelula();
    novaCelula->produto = produto;

    return novaCelula;
}

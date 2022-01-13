#ifndef CELULA_LISTA_H
#define CELULA_LISTA_H

#include "../../Produto/ProdutoStruct.h"

typedef struct Celula Celula;

struct Celula {
    Celula* proxima;
    Celula* anterior;
    Produto produto;
};

Celula* newCelula();
Celula* newCelulaComValor(const Produto produto);

#endif

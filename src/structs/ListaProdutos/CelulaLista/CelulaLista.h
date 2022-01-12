#include "../../Produto/Produto.h"

typedef struct Celula {
    Celula* proxima;
    Celula* anterior;
    Produto produto;
} Celula;

Celula* newCelula();
Celula* newCelulaComValor(const Produto produto);

void setProximaCelula(Celula* celula, Celula* proxima);
void setCelulaAnterior(Celula* celula, Celula* anterior);
void setProduto(Celula* celula, const Produto produto);

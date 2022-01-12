#include "CelulaLista.h"

void setProximaCelula(Celula* celula, Celula* proxima) {
    celula->proxima = proxima;
    return;
}

void setCelulaAnterior(Celula* celula, Celula* anterior) {
    celula->anterior = anterior;
    return;
}

void setProduto(Celula* celula, const Produto produto) {
    celula->produto = produto;
    return;
}

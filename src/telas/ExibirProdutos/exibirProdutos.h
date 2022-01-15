#ifndef EXIBIR_PRODUTOS_H
#define EXIBIR_PRODUTOS_H

#include "../../structs/ListaProdutos/ListaProdutosStruct.h"

void exibirProdutos(const ListaProdutos* lista);

void exibirProdutoMaisCaro(const ListaProdutos* lista);
void exibirProdutoMaisBarato(const ListaProdutos* lista);

#endif

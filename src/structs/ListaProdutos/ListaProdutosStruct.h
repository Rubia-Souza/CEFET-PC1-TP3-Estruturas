#ifndef LISTAPRODUTOS_H
#define LISTAPRODUTOS_H

#include <stdbool.h>

#include "../Produto/ProdutoStruct.h"
#include "./CelulaLista/CelulaListaStruct.h"

typedef struct ListaProdutos {
    unsigned int tamanho;
    Celula* refComeco;
    Celula* refFinal;
} ListaProdutos;

ListaProdutos* newListaProdutos();

void adicionarFim(ListaProdutos* lista, const Produto produto);
void adicionarComeco(ListaProdutos* lista, const Produto produto);
void adicionarAntesProduto(ListaProdutos* lista, const unsigned int codigoProduto, const Produto produto);
void adicionarAntesIndex(ListaProdutos* lista, const unsigned int index, const Produto produto);
void adicionarAposProduto(ListaProdutos* lista, const unsigned int codigoProduto, const Produto produto);
void adicionarAposIndex(ListaProdutos* lista, const unsigned int index, const Produto produto);

void removerPrimeiro(ListaProdutos* lista);
void removerUltimo(ListaProdutos* lista);
void removerEm(ListaProdutos* lista, const unsigned int index);
void removerTodosProdutosComNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);

Produto getProdutoInicial(const ListaProdutos* lista);
Produto getProdutoFinal(const ListaProdutos* lista);
ListaProdutos* getTodosProdutosComNome(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);
Produto getProdutoPorCodigo(ListaProdutos* lista, const unsigned int codigo);
Produto getProdutoPorNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);
Produto getProdutoEm(ListaProdutos* lista, const unsigned int index);

void limpar(ListaProdutos* lista);
void destruir(ListaProdutos* lista);
void ordernar(ListaProdutos* lista);

bool estaVazia(const ListaProdutos* lista);

void renderizarListaProdutos(const ListaProdutos* lista);

#endif

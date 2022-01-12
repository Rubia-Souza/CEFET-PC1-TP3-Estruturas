#include "./CelulaLista/CelulaLista.h"

typedef struct ListaProdutos {
    unsigned int tamanho;
    Celula* comeco;
    Celula* final;
} ListaProdutos;

ListaProdutos* newListaProdutos();

void adicionarFim(ListaProdutos* lista, const Produto produto);
void adicionarComeco(ListaProdutos* lista, const Produto produto);
void adicionarAntesProduto();
void adicionarAntesIndex();
void adicionarAposProduto();
void adicionarAposIndex();

void removerPrimeiro(ListaProdutos* lista);
void removerUltimo(ListaProdutos* lista);
void removerEm(ListaProdutos* lista, const unsigned int index);
void removerProdutoPorNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);

Produto getProdutoPorCodigo(ListaProdutos* lista, const unsigned int codigo);
Produto getProdutoPorNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);
Produto getProdutoEm(ListaProdutos* lista, const unsigned int index);

void limpar(ListaProdutos* lista);
bool estaVazia(ListaProdutos* lista);

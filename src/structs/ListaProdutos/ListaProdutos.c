#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "ListaProdutos.h"

ListaProdutos* getTodasCelulaComNome(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);
ListaProdutos* getTodasCelulaComCodigo(const ListaProdutos* lista, const unsigned int codigo);

Celula* getCelulaPorNome(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);
Celula* getCelulaPorCodigo(const ListaProdutos* lista, const unsigned int codigo);
Celula* getCelulaEm(const ListaProdutos* lista, const unsigned int index);

void removerItem(Celula* alvo);

ListaProdutos* newListaProdutos() {

}

void adicionarFim(ListaProdutos* lista, const Produto produto) {
    Celula* novaCelula = newCelulaComValor(produto);
    Celula* finalAntigo = lista->final;
    
    novaCelula->anterior = finalAntigo;
    novaCelula->proxima = NULL;

    finalAntigo->proxima = novaCelula;
    lista->final = novaCelula;
    lista->tamanho++;

    return;
}

void adicionarComeco(ListaProdutos* lista, const Produto produto) {
    Celula* novaCelula = newCelulaComValor(produto);
    Celula* comecoAntigo = lista->comeco;

    novaCelula->anterior = NULL;
    novaCelula->proxima = comecoAntigo;

    comecoAntigo->anterior = novaCelula;
    lista->comeco = novaCelula;
    lista->tamanho++;

    return;
}

void removerPrimeiro(ListaProdutos* lista) {
    Celula* celulaRemovida = lista->comeco;
    Celula* novoComeco = celulaRemovida->proxima;
    Produto produtoRemovido = celulaRemovida->produto;

    novoComeco->anterior = NULL;
    celulaRemovida->proxima = NULL;
    free(celulaRemovida);

    lista->comeco = novoComeco;
    lista->tamanho--;

    return produtoRemovido; // TODO: Perigo de error
}

void removerUltimo(ListaProdutos* lista) {
    Celula* celulaRemovida = lista->final;
    Celula* novoFim = celulaRemovida->anterior;
    Produto produtoRemovido = celulaRemovida->produto;

    celulaRemovida->anterior = NULL;
    novoFim->proxima = NULL;
    free(celulaRemovida);

    lista->final = novoFim;
    lista->tamanho--;

    return produtoRemovido; // TODO: Perigo de error
}

void removerEm(ListaProdutos* lista, const unsigned int index) {
    if(lista->tamanho <= index) {
        return;
    }

    Celula* celulaRemovida = getProdutoEm(lista, index);
    Celula* alvo;
    for(int i = 0; i < index && i < lista->tamanho; i++) {
        alvo = alvo->proxima;
    }

    Produto produtoRemovido = alvo->produto;
    removerItem(alvo);
    free(alvo);
    lista->tamanho--;

    return produtoRemovido; // TODO: Perigo de error
}

void removerProdutoPorNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    //ListaProdutos produtosRemovidos;
    for(Celula* item = lista->comeco->proxima; item != lista->final; item = item->proxima) {
        bool ehProduto = strcmp(item->produto.nome, nome);
        if(ehProduto) {
            removerItem(item);
            free(item);
            lista->tamanho--;
        }
    }
}

ListaProdutos getTodosProdutosComNome(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);
ListaProdutos getTodosProdutosComCodigo(const ListaProdutos* lista, const unsigned int codigo);

Produto getProdutoPorCodigo(ListaProdutos* lista, const unsigned int codigo){ 
    Celula* alvo = getCelulaPorCodigoProduto(lista, codigo);
    return alvo->produto;
}

Produto getProdutoPorNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    Celula* alvo = getCelulaPorNome(lista, nome);
    return alvo->produto;
}

Produto getProdutoEm(ListaProdutos* lista, const unsigned int index) {
    Celula* alvo = getCelulaEm(lista, index);
    return alvo->produto;
}

void limpar(ListaProdutos* lista) {
    Celula* primeira = lista->comeco;
    Celula* ultima = lista->final;

    for(Celula* item = lista->comeco->proxima; item != lista->final; item = item->proxima->proxima) {
        free(item);
    }

    primeira->anterior = NULL;
    primeira->proxima = ultima;

    ultima->anterior = primeira;
    ultima->proxima = NULL;

    lista->tamanho = 0;

    return;
}

bool estaVazia(const ListaProdutos* lista) {
    Celula* primeira = lista->comeco;
    Celula* ultima = lista->final;

    return (primeira->proxima == ultima && ultima->anterior == primeira);
}

ListaProdutos* getTodasCelulaComNome(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]){
    ListaProdutos* produtos = newListaProdutos();

    for(Celula* item = lista->comeco->proxima; item != lista->final; item = item->proxima) {
        bool ehProduto = strcmp(item->produto.nome, nome);
        if(ehProduto) {
            adicionarFim(produtos, item->produto);
        }
    }

    return produtos;
}

ListaProdutos* getTodasCelulaComCodigo(const ListaProdutos* lista, const unsigned int codigo) {
    ListaProdutos* produtos = newListaProdutos();

    for(Celula* item = lista->comeco->proxima; item != lista->final; item = item->proxima) {
        if(item->produto.codigo == codigo) {
            adicionarFim(produtos, item->produto);
        }
    }

    return produtos;
}

Celula* getCelulaPorNomeProduto(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    for(Celula* item = lista->comeco->proxima; item != lista->final; item = item->proxima) {
        bool ehProduto = strcmp(item->produto.nome, nome);
        if(ehProduto) {
            return item;
        }
    }

    return NULL;
}

Celula* getCelulaPorCodigoProduto(const ListaProdutos* lista, const unsigned int codigo) {
    for(Celula* item = lista->comeco->proxima; item != lista->final; item = item->proxima) {
        if(item->produto.codigo == codigo) {
            return item;
        }
    }

    return NULL;
}

Celula* getCelulaEm(const ListaProdutos* lista, const unsigned int index) {
    if(lista->tamanho <= index) {
        return NULL;
    }

    Celula* alvo;
    for(int i = 0; i < index && i < lista->tamanho; i++) {
        alvo = alvo->proxima;
    }

    return alvo;
}

void removerItem(Celula* alvo) {
    Celula* anterior = alvo->anterior;
    Celula* proxima = alvo->proxima;

    anterior->proxima = proxima;
    proxima->anterior = anterior;

    return;
}

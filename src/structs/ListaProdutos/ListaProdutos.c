#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../Produto/ProdutoStruct.h"
#include "ListaProdutosStruct.h"

void setRefFinal(ListaProdutos* lista, Celula* item);
void setRefInicial(ListaProdutos* lista, Celula* item);

Celula* getCelulaInicial(const ListaProdutos* lista);
Celula* getCelulaFinal(const ListaProdutos* lista);
Celula* getCelulaPorNomeProduto(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);
Celula* getCelulaPorCodigoProduto(const ListaProdutos* lista, const unsigned int codigo);
Celula* getCelulaEm(const ListaProdutos* lista, const unsigned int index);

void removerCelula(Celula* alvo);

ListaProdutos* newListaProdutos() {
    // TODO: Implementar
}

void adicionarFim(ListaProdutos* lista, const Produto produto) {
    Celula* novaCelula = newCelulaComValor(produto);
    
    setRefFinal(lista, novaCelula);
    lista->tamanho++;

    return;
}

void adicionarComeco(ListaProdutos* lista, const Produto produto) {
    Celula* novaCelula = newCelulaComValor(produto);
    
    setRefInicial(lista, novaCelula);
    lista->tamanho++;

    return;
}

void adicionarAntesProduto(ListaProdutos* lista, const unsigned int codigoProduto) {

}

void adicionarAntesIndex(ListaProdutos* lista, const unsigned int index) {

}

void adicionarAposProduto(ListaProdutos* lista, const unsigned int codigoProduto) {

}

void adicionarAposIndex(ListaProdutos* lista, const unsigned int index) {

}

void removerPrimeiro(ListaProdutos* lista) {
    Celula* celulaRemovida = getCelulaInicial(lista);
    Celula* novoComeco = celulaRemovida->proxima;
    
    setRefInicial(lista, novoComeco);
    free(celulaRemovida);
    lista->tamanho--;

    return;
}

void removerUltimo(ListaProdutos* lista) {
    Celula* celulaRemovida = getCelulaFinal(lista);
    Celula* novoFim = celulaRemovida->anterior;

    setRefFinal(lista, celulaRemovida);
    free(celulaRemovida);
    lista->tamanho--;

    return;
}

void removerEm(ListaProdutos* lista, const unsigned int index) {
    if(lista->tamanho <= index) {
        return;
    }

    Celula* celulaRemovida = getCelulaEm(lista, index);

    removerCelula(celulaRemovida);
    lista->tamanho--;

    return;
}

void removerTodosProdutosComNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
        bool produtoTemNomeIgual = strcmp(item->produto.nome, nome);
        if(produtoTemNomeIgual) {
            removerCelula(item);
            lista->tamanho--;
        }
    }
}

Produto getProdutoInicial(const ListaProdutos* lista) {
    Celula* primeiroValor = getCelulaInicial(lista);
    return primeiroValor->produto;
}

Produto getProdutoFinal(const ListaProdutos* lista) {
    Celula* ultimoValor = getCelulaFinal(lista);
    return ultimoValor->produto;
}

ListaProdutos* getTodosProdutosComNome(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    ListaProdutos* produtos = newListaProdutos();

    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
        bool produtoTemNomeIgual = strcmp(item->produto.nome, nome);
        if(produtoTemNomeIgual) {
            adicionarFim(produtos, item->produto);
        }
    }

    return produtos;
}

ListaProdutos* getTodosProdutosComCodigo(const ListaProdutos* lista, const unsigned int codigo) {
    ListaProdutos* produtos = newListaProdutos();

    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
        if(item->produto.codigo == codigo) {
            adicionarFim(produtos, item->produto);
        }
    }

    return produtos;
}

Produto getProdutoPorCodigo(ListaProdutos* lista, const unsigned int codigo){ 
    Celula* alvo = getCelulaPorCodigoProduto(lista, codigo);
    return alvo->produto;
}

Produto getProdutoPorNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    Celula* alvo = getCelulaPorNomeProduto(lista, nome);
    return alvo->produto;
}

Produto getProdutoEm(ListaProdutos* lista, const unsigned int index) {
    Celula* alvo = getCelulaEm(lista, index);
    return alvo->produto;
}

void limpar(ListaProdutos* lista) {
    Celula* refComeco = lista->refComeco;
    Celula* refFinal = lista->refFinal;

    Celula* refProximoItem;
    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = refProximoItem) {
        refProximoItem = item->proxima;
        free(item);
    }

    refComeco->anterior = NULL;
    refComeco->proxima = refFinal;

    refFinal->anterior = refComeco;
    refFinal->proxima = NULL;

    lista->tamanho = 0;

    return;
}

bool estaVazia(const ListaProdutos* lista) {
    Celula* refComeco = lista->refComeco;
    Celula* refFinal = lista->refFinal;

    return (refComeco->proxima == refFinal && refFinal->anterior == refComeco);
}

void setRefFinal(ListaProdutos* lista, Celula* item) {
    if(item == NULL) {
        return;
    }

    Celula* finalAnterior = getCelulaFinal(lista);
    finalAnterior->proxima = item;

    item->anterior = finalAnterior;
    item->proxima = lista->refFinal;

    lista->refFinal->anterior = item;
    return;
}

void setRefInicial(ListaProdutos* lista, Celula* item) {
    if(item == NULL) {
        return;
    }

    Celula* comecoAnteriror = getCelulaInicial(lista);
    comecoAnteriror->anterior = item;

    item->proxima = comecoAnteriror;
    item->anterior = lista->refComeco;

    lista->refComeco->proxima = item;
    return;
}

Celula* getCelulaInicial(const ListaProdutos* lista) {
    return lista->refComeco->proxima;
}

Celula* getCelulaFinal(const ListaProdutos* lista) {
    return lista->refFinal->anterior;
}

Celula* getCelulaPorNomeProduto(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
        bool produtoTemNomeIgual = strcmp(item->produto.nome, nome);
        if(produtoTemNomeIgual) {
            return item;
        }
    }

    return NULL;
}

Celula* getCelulaPorCodigoProduto(const ListaProdutos* lista, const unsigned int codigo) {
    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
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

    Celula* alvo = NULL;
    for(int i = 0; i < index && i < lista->tamanho; i++) {
        alvo = alvo->proxima;
    }

    return alvo;
}

void removerCelula(Celula* alvo) {
    Celula* anteriorAoAlvo = alvo->anterior;
    Celula* proximaAoAlvo = alvo->proxima;

    anteriorAoAlvo->proxima = proximaAoAlvo;
    proximaAoAlvo->anterior = anteriorAoAlvo;

    free(alvo);
    return;
}

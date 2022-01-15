#include <stdio.h>

#include "../../structs/Produto/ProdutoStruct.h"
#include "../../structs/ListaProdutos/CelulaLista/CelulaListaStruct.h"
#include "../../structs/ListaProdutos/ListaProdutosStruct.h"

void exibirProdutos(const ListaProdutos* lista) {
    if(estaVazia(lista)) {
        printf("\nNão há nenhum produto cadastrado");
        return;
    }

    printf("\n---- Lista de todos produtos cadastrados:\n");
    renderizarListaProdutos(lista);

    return;
}

void exibirProdutoMaisCaro(const ListaProdutos* lista) {
    if(estaVazia(lista)) {
        printf("\nNão há nenhum produto cadastrado");
        return;
    }

    Produto produtoCaro = getProdutoInicial(lista);

    for(Celula* item = lista->refComeco->proxima->proxima; item != lista->refFinal; item = item->proxima) {
        Produto produtoAtual = item->produto;
        if(produtoCaro.preco < produtoAtual.preco) {
            produtoCaro = produtoAtual;
        }
    }

    printf("\n---- Produto mais caro:\n");
    printf("%s", produtoAsString(produtoCaro));
    return;
}

void exibirProdutoMaisBarato(const ListaProdutos* lista) {
    if(estaVazia(lista)) {
        printf("\nNão há nenhum produto cadastrado");
        return;
    }

    Produto produtoBarato = getProdutoInicial(lista);

    for(Celula* item = lista->refComeco->proxima->proxima; item != lista->refFinal; item = item->proxima) {
        Produto produtoAtual = item->produto;
        if(produtoBarato.preco > produtoAtual.preco) {
            produtoBarato = produtoAtual;
        }
    }

    printf("\n---- Produto mais barato:\n");
    printf("%s", produtoAsString(produtoBarato));
    return;
}

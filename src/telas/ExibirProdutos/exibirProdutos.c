#include <stdio.h>

#include "../../structs/Produto/ProdutoStruct.h"
#include "../../structs/ListaProdutos/CelulaLista/CelulaListaStruct.h"
#include "../../structs/ListaProdutos/ListaProdutosStruct.h"

void renderizarListaProdutos(const ListaProdutos* lista) {
    if(estaVazia(lista)) {
        printf("\nNão há nenhum produto cadastrado");
        return;
    }

    printf("\n---- Lista de todos produtos cadastrados:\n");

    int contador = 1;
    for(Celula* item = lista->refComeco->proxima; item != lista->refFinal; item = item->proxima) {
        Produto produto = item->produto;
        printf("[%d] %s\n", contador, produtoAsString(produto));
        contador++;
    }

    return;
}

void exibirProdutoMaisCaro(const ListaProdutos* lista) {
    if(estaVazia(lista)) {
        printf("\nNão há nenhum produto cadastrado");
        return;
    }

    Produto produtoCaro = buildProdutoVazio();

    for(Celula* item = lista->refComeco->proxima; item != lista->refFinal; item = item->proxima) {
        Produto produtoAtual = item->produto;
        if(produtoCaro.preco < produtoAtual.preco) {
            produtoCaro = produtoAtual;
        }
    }

    printf("\n---- Produto mais caro:\n");
    printf("%s", produtoAsString(produtoCaro));
    return;
}

void exibirProdutoMaisBarato(const ListaProdutos* lista) { // TODO: Erro produto vazio preço zero
    if(estaVazia(lista)) {
        printf("\nNão há nenhum produto cadastrado");
        return;
    }

    Produto produtoBarato = buildProdutoVazio();

    for(Celula* item = lista->refComeco->proxima; item != lista->refFinal; item = item->proxima) {
        Produto produtoAtual = item->produto;
        if(produtoBarato.preco > produtoAtual.preco) {
            produtoBarato = produtoAtual;
        }
    }

    printf("\n---- Produto mais barato:\n");
    printf("%s", produtoAsString(produtoBarato));
    return;
}

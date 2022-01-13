#include <stdio.h>

#include "../../structs/Produto/ProdutoStruct.h"
#include "../../structs/ListaProdutos/CelulaLista/CelulaListaStruct.h"
#include "../../structs/ListaProdutos/ListaProdutosStruct.h"

void renderizarListaProdutos(const ListaProdutos* lista) {
    printf("\n---- Lista de todos produtos cadastrados: ");

    int contador = 1;
    for(Celula* item = lista->refComeco->proxima; item != lista->refFinal; item = item->proxima) {
        Produto produto = item->produto;
        printf("[%d] %s\n", contador, produtoAsString(produto));
        contador++;
    }

    return;
}

void exibirProdutoMaisCaro(const ListaProdutos* lista) {
    Produto produtoCaro = buildProdutoVazio();

    for(Celula* item = lista->refComeco->proxima; item != lista->refFinal; item = item->proxima) {
        Produto produtoAtual = item->produto;
        if(produtoCaro.preco < produtoAtual.preco) {
            produtoCaro = produtoAtual;
        }
    }

    printf("\nProduto mais caro:\n");
    printf("%s", produtoAsString(produtoCaro));
    return;
}

void exibirProdutoMaisBarato(const ListaProdutos* lista) {
    Produto produtoBarato = buildProdutoVazio();

    for(Celula* item = lista->refComeco->proxima; item != lista->refFinal; item = item->proxima) {
        Produto produtoAtual = item->produto;
        if(produtoBarato.preco > produtoAtual.preco) {
            produtoBarato = produtoAtual;
        }
    }

    printf("\nProduto mais barato:\n");
    printf("%s", produtoAsString(produtoBarato));
    return;
}

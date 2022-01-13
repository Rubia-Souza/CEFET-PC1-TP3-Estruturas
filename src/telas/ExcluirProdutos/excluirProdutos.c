#include <stdio.h>
#include <stdlib.h>

#include "../ExibirProdutos/exibirProdutos.h"
#include "../../structs/Produto/ProdutoStruct.h"
#include "../../structs/ListaProdutos/ListaProdutosStruct.h"

char* getNomeProdutosAlvo();

void excluirProdutos(ListaProdutos* lista) {
    char* nome = getNomeProdutosAlvo();

    ListaProdutos* produtosDevemSerExcluidos = getTodosProdutosComNome(lista, nome);
    if(estaVazia(produtosDevemSerExcluidos)) {
        printf("\nNenhum produto encontrado com o nome fornecido.");
        return;
    }

    removerTodosProdutosComNome(lista, nome);
    printf("\nProdutos que foram excluidos:\n");
    renderizarListaProdutos(produtosDevemSerExcluidos); // TODO: Possível erro

    destruir(produtosDevemSerExcluidos);
    return;
}

char* getNomeProdutosAlvo() {
    char* nomeProduto = (char*) malloc(TAMANHO_NOME_PRODUTO * sizeof(char));

    printf("\nInforme o nome do(s) produto(s) que será(ão) excluido(s): ");
    scanf("%49s", nomeProduto);
    fflush(stdin);

    return nomeProduto;
}

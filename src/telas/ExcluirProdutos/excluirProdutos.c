#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../structs/Produto/ProdutoStruct.h"
#include "../../structs/ListaProdutos/ListaProdutosStruct.h"

char* getNomeProdutosAlvo();

void excluirProdutos(ListaProdutos* lista) {
    if(estaVazia(lista)) {
        printf("\nNão há nenhum produto cadastrado");
        return;
    }

    char* nome = getNomeProdutosAlvo();

    ListaProdutos* produtosDevemSerExcluidos = getTodosProdutosComNome(lista, nome);
    if(estaVazia(produtosDevemSerExcluidos)) {
        printf("\nNenhum produto encontrado com o nome fornecido.");
        return;
    }

    removerTodosProdutosComNome(lista, nome);
    printf("\n---- Produtos que foram excluidos:\n");
    renderizarListaProdutos(produtosDevemSerExcluidos);

    destruir(produtosDevemSerExcluidos);
    return;
}

char* getNomeProdutosAlvo() {
    char* nomeProduto = (char*) malloc(TAMANHO_NOME_PRODUTO * sizeof(char));

    printf("\nInforme o nome do(s) produto(s) que será(ão) excluido(s): ");
    fgets(nomeProduto, TAMANHO_NOME_PRODUTO, stdin);
    fflush(stdin);
    nomeProduto[strcspn(nomeProduto, "\n")] = '\000';

    return nomeProduto;
}

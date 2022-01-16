#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./structs/ListaProdutos/ListaProdutosStruct.h"
#include "./structs/Produto/ProdutoStruct.h"

#include "./telas/CadastrarProduto/cadastrarProduto.h"
#include "./telas/ExcluirProdutos/excluirProdutos.h"
#include "./telas/ExibirProdutos/exibirProdutos.h"
#include "./telas/Menu/menu.h"

#include "./mocks/produtos/mockProdutos.h"

void casoAdicionar(ListaProdutos* lista);
void casoExibirTodosProdutos(const ListaProdutos* lista);
void casoExibirProdutoCaro(const ListaProdutos* lista);
void casoExibirProdutoBarato(const ListaProdutos* lista);
void casoExcluirProduto(ListaProdutos* lista);
void casoOrdenarProdutos(ListaProdutos* lista);
void liberarMemoria(ListaProdutos* lista);

#define MAXIMO_PRODUTOS 100

int main() {
    unsigned int opcaoEscolhida = 0;
    ListaProdutos* produtos = getProdutosMock();

    while (opcaoEscolhida != 7) {
        opcaoEscolhida = renderizarMenu();

        switch (opcaoEscolhida) {
            case ADICIONAR:
                casoAdicionar(produtos);
            break;
            
            case EXIBIR_TODOS_PRODUTOS:
                casoExibirTodosProdutos(produtos);
            break;

            case EXIBIR_PRODUTO_CARO:
                casoExibirProdutoCaro(produtos);
            break;
            
            case EXIBIR_PRODUTO_BRARATO:
                casoExibirProdutoBarato(produtos);
            break;

            case EXCLUIR_PRODUTO:
                casoExcluirProduto(produtos);
            break;
            
            case ORDENAR_PRODUTOS:
                casoOrdenarProdutos(produtos);
            break;

            case SAIR:
                liberarMemoria(produtos);
                opcaoEscolhida = SAIR;
            break;
        }
    }

    return 0;
}

void casoAdicionar(ListaProdutos* lista) {
    if(lista->tamanho >= MAXIMO_PRODUTOS) {
        printf("\nA quantidade máxima de produtos já foi cadastrada\n");
        return;
    }

    Produto novo = renderizarCadastroProduto();
    adicionarFim(lista, novo);

    return;
}

void casoExibirTodosProdutos(const ListaProdutos* lista) {
    exibirProdutos(lista);
    return;
}

void casoExibirProdutoCaro(const ListaProdutos* lista) {
    exibirProdutoMaisCaro(lista);
    return;
}

void casoExibirProdutoBarato(const ListaProdutos* lista) {
    exibirProdutoMaisBarato(lista);
    return;
}

void casoExcluirProduto(ListaProdutos* lista) {
    excluirProdutos(lista);
    return;
}

void casoOrdenarProdutos(ListaProdutos* lista) {
    ordernar(lista);
    renderizarListaProdutos(lista);
    return;
}

void liberarMemoria(ListaProdutos* lista) {
    destruir(lista);
    return;
}

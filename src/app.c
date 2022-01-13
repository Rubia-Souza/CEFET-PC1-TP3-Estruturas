#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./structs/ListaProdutos/ListaProdutosStruct.h"
#include "./structs/Produto/ProdutoStruct.h"

#include "./telas/CadastrarProduto/cadastrarProduto.h"
#include "./telas/ExcluirProdutos/excluirProdutos.h"
#include "./telas/ExibirProdutos/exibirProdutos.h"
#include "./telas/Menu/menu.h"

//TODO: Remover mock
void addTest(ListaProdutos* listinha);

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
    ListaProdutos* produtos = newListaProdutos();
    addTest(produtos);

    while (opcaoEscolhida != 7) {
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
    renderizarListaProdutos(lista);
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
    // TODO: Implementar
}

// TODO: Remover mock
void addTest(ListaProdutos* listinha) {
    for(int i = 0; i < 5; i++) {
        Produto teste3;
        setCodigo(&teste3, i);
        setNome(&teste3, "teste");
        setPreco(&teste3, 50+i);
        Data dataTeste3;
        setDia(&dataTeste3, 10+i);
        setMes(&dataTeste3, 7+i);
        setAno(&dataTeste3, 2005+i);
        setValidade(&teste3, dataTeste3);

        if(i%2 == 0) {
            adicionarAntesIndex(listinha, 0, teste3);
        }
        else {
            adicionarAposIndex(listinha, listinha->tamanho - 1, teste3);
        }
    }
}

void liberarMemoria(ListaProdutos* lista) {
    destruir(lista);
    return;
}

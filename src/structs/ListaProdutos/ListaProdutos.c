#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "../Produto/ProdutoStruct.h"
#include "../../utils/utils.h"
#include "ListaProdutosStruct.h"

void setRefFinal(ListaProdutos* lista, Celula* item);
void setRefInicial(ListaProdutos* lista, Celula* item);

Celula* getCelulaInicial(const ListaProdutos* lista);
Celula* getCelulaFinal(const ListaProdutos* lista);
Celula* getCelulaPorNomeProduto(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]);
Celula* getCelulaPorCodigoProduto(const ListaProdutos* lista, const unsigned int codigo);
Celula* getCelulaEm(const ListaProdutos* lista, const unsigned int index);

void removerCelula(Celula* alvo);

void getProdutoPrioritario(Produto* prioritario, Produto* minoritario);
void getProdutoPrioritarioPorNome(Produto* prioritario, Produto* minoritario);
void getProdutoPrioritarioPorData(Produto* prioritario, Produto* minoritario);
void getProdutoPrioritarioPorPreco(Produto* prioritario, Produto* minoritario);

ListaProdutos* newListaProdutos() {
    ListaProdutos* lista = (ListaProdutos*) malloc(sizeof(ListaProdutos));

    lista->refComeco = newCelula();
    lista->refFinal = newCelula();

    lista->refComeco->proxima = lista->refFinal;
    lista->refFinal->anterior = lista->refComeco;

    lista->tamanho = 0;

    return lista;
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

void adicionarAntesProduto(ListaProdutos* lista, const unsigned int codigoProduto, const Produto produto) {
    if(estaVazia(lista)) {
        return;
    }

    Celula* novaCelula = newCelula(produto);
    Celula* produtoReferencia = getCelulaPorCodigoProduto(lista, codigoProduto);

    Celula* anteriorAReferencia = produtoReferencia->anterior;

    novaCelula->anterior = anteriorAReferencia;
    anteriorAReferencia->proxima = novaCelula;

    novaCelula->proxima = produtoReferencia;
    produtoReferencia->anterior = novaCelula;
    
    lista->tamanho++;
    return;
}

void adicionarAntesIndex(ListaProdutos* lista, const unsigned int index, const Produto produto) {
    if(estaVazia(lista)) {
        return;
    }
    
    Celula* novaCelula = newCelulaComValor(produto);
    Celula* produtoReferencia = getCelulaEm(lista, index);

    Celula* anteriorAReferencia = produtoReferencia->anterior;

    novaCelula->anterior = anteriorAReferencia;
    anteriorAReferencia->proxima = novaCelula;

    novaCelula->proxima = produtoReferencia;
    produtoReferencia->anterior = novaCelula;

    lista->tamanho++;
    return;
}

void adicionarAposProduto(ListaProdutos* lista, const unsigned int codigoProduto, const Produto produto) {
    if(estaVazia(lista)) {
        return;
    }

    Celula* novaCelula = newCelulaComValor(produto);
    Celula* produtoReferencia = getCelulaPorCodigoProduto(lista, codigoProduto);

    Celula* posteriorReferencia = produtoReferencia->proxima;

    novaCelula->proxima = posteriorReferencia;
    posteriorReferencia->anterior = novaCelula;

    novaCelula->anterior = produtoReferencia;
    produtoReferencia->proxima = novaCelula;

    lista->tamanho++;
    return;
}

void adicionarAposIndex(ListaProdutos* lista, const unsigned int index, const Produto produto) {
    if(estaVazia(lista)) {
        return;
    }

    Celula* novaCelula = newCelulaComValor(produto);
    Celula* produtoReferencia = getCelulaEm(lista, index);

    Celula* posteriorReferencia = produtoReferencia->proxima;

    novaCelula->proxima = posteriorReferencia;
    posteriorReferencia->anterior = novaCelula;

    novaCelula->anterior = produtoReferencia;
    produtoReferencia->proxima = novaCelula;

    lista->tamanho++;
    return;
}

void removerPrimeiro(ListaProdutos* lista) {
    if(estaVazia(lista)) {
        return;
    }

    Celula* celulaRemovida = getCelulaInicial(lista);

    Celula* novoComeco = celulaRemovida->proxima;
    novoComeco->anterior = lista->refComeco;
    lista->refComeco->proxima = novoComeco;
    
    free(celulaRemovida);
    lista->tamanho--;

    return;
}

void removerUltimo(ListaProdutos* lista) {
    if(estaVazia(lista)) {
        return;
    }

    Celula* celulaRemovida = getCelulaFinal(lista);

    Celula* novoFim = celulaRemovida->anterior;
    novoFim->proxima = lista->refFinal;
    lista->refFinal->anterior = novoFim;

    free(celulaRemovida);
    lista->tamanho--;

    return;
}

void removerEm(ListaProdutos* lista, const unsigned int index) {
    if(estaVazia(lista) || index >= lista->tamanho) {
        return;
    }

    Celula* celulaRemovida = getCelulaEm(lista, index);
    removerCelula(celulaRemovida);

    lista->tamanho--;

    return;
}

void removerTodosProdutosComNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    if(estaVazia(lista)) {
        return;
    }
    char nomeReferencia[TAMANHO_NOME_PRODUTO];
    strcpy(nomeReferencia, nome);
    toLower(nomeReferencia);

    Celula* iterator = getCelulaInicial(lista);
    for(Celula* item = iterator; item != lista->refFinal; item = iterator) {
        iterator = item->proxima;
        char nomeProduto[TAMANHO_NOME_PRODUTO];
        strcpy(nomeProduto, item->produto.nome);
        toLower(nomeProduto);

        bool produtoTemNomeIgual = !strcmp(nomeProduto, nomeReferencia);

        if(produtoTemNomeIgual) {
            removerCelula(item);
            lista->tamanho--;
        }
    }

    return;
}

Produto getProdutoInicial(const ListaProdutos* lista) {
    if(estaVazia(lista)) {
        return buildProdutoVazio();
    }

    Celula* primeiroValor = getCelulaInicial(lista);
    return primeiroValor->produto;
}

Produto getProdutoFinal(const ListaProdutos* lista) {
    if(estaVazia(lista)) {
        return buildProdutoVazio();
    }

    Celula* ultimoValor = getCelulaFinal(lista);
    return ultimoValor->produto;
}

ListaProdutos* getTodosProdutosComNome(const ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    ListaProdutos* produtos = newListaProdutos();
    if(estaVazia(lista)) {
        return produtos;
    }
    char nomeReferencia[TAMANHO_NOME_PRODUTO];
    strcpy(nomeReferencia, nome);
    toLower(nomeReferencia);

    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
        char nomeProduto[TAMANHO_NOME_PRODUTO];
        strcpy(nomeProduto, item->produto.nome);
        toLower(nomeProduto);
        bool produtoTemNomeIgual = !strcmp(nomeProduto, nomeReferencia);

        if(produtoTemNomeIgual) {
            adicionarFim(produtos, item->produto);
        }
    }

    return produtos;
}

Produto getProdutoPorCodigo(ListaProdutos* lista, const unsigned int codigo){
    if(estaVazia(lista)) {
        return buildProdutoVazio();
    }

    Celula* alvo = getCelulaPorCodigoProduto(lista, codigo);
    if(alvo == NULL) {
        return buildProdutoVazio();
    }

    return alvo->produto;
}

Produto getProdutoPorNome(ListaProdutos* lista, const char nome[TAMANHO_NOME_PRODUTO]) {
    if(estaVazia(lista)) {
        return buildProdutoVazio();
    }

    Celula* alvo = getCelulaPorNomeProduto(lista, nome);
    if(alvo == NULL) {
        return buildProdutoVazio();
    }

    return alvo->produto;
}

Produto getProdutoEm(ListaProdutos* lista, const unsigned int index) {
    if(estaVazia(lista) || index >= lista->tamanho) {
        return buildProdutoVazio();
    }

    Celula* alvo = getCelulaEm(lista, index);
    if(alvo == NULL) {
        return buildProdutoVazio();
    }

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

void destruir(ListaProdutos* lista) {
    limpar(lista);

    free(lista->refComeco);
    free(lista->refFinal);
    free(lista);

    return;
}

void ordernar(ListaProdutos* lista) {
    if(estaVazia(lista)) {
        return;
    }

    for(Celula* atual = getCelulaInicial(lista); atual != lista->refFinal; atual = atual->proxima) {
        for(Celula* iterador = atual->proxima; iterador != lista->refFinal; iterador = iterador->proxima) {
            getProdutoPrioritario(&atual->produto, &iterador->produto);
        }
    }

    return;
}

void getProdutoPrioritario(Produto* prioritario, Produto* minoritario) {
    getProdutoPrioritarioPorNome(prioritario, minoritario);
    return;
}

void getProdutoPrioritarioPorNome(Produto* prioritario, Produto* minoritario) {
    int nomeEhMenorAlfabeticamente = strcmp(prioritario->nome, minoritario->nome);
    if(nomeEhMenorAlfabeticamente < 0) {
        return;
    }
    else if(nomeEhMenorAlfabeticamente > 0) {
        Produto maior = *prioritario;
        *prioritario = *minoritario;
        *minoritario = maior;
        return;
    }
    
    getProdutoPrioritarioPorData(prioritario, minoritario);
    return;
}

void getProdutoPrioritarioPorData(Produto* prioritario, Produto* minoritario) {
    time_t tempoPrioritario = dataAsTimeT(prioritario->validade);
    time_t tempoMinoritario = dataAsTimeT(minoritario->validade);

    time_t tempoAtual = time(NULL);
    
    double tempoPrioritarioAteHoje = abs(difftime(tempoPrioritario, tempoAtual));
    double tempoMinoritarioAteHoje = abs(difftime(tempoMinoritario, tempoAtual));

    if(tempoMinoritarioAteHoje > tempoPrioritarioAteHoje) {
        return;
    }
    else if(tempoMinoritarioAteHoje < tempoPrioritarioAteHoje) {
        Produto produtoValidadeProxima = *prioritario;
        *prioritario = *minoritario;
        *minoritario = produtoValidadeProxima;
        return;
    }

    getProdutoPrioritarioPorPreco(prioritario, minoritario);
    return;
}

void getProdutoPrioritarioPorPreco(Produto* prioritario, Produto* minoritario) {
    if(prioritario->preco < minoritario->preco) {
        Produto produtoPrecoMenor = *prioritario;
        *prioritario = *minoritario;
        *minoritario = produtoPrecoMenor;
    }

    return;
}

bool estaVazia(const ListaProdutos* lista) {
    Celula* refComeco = lista->refComeco;
    Celula* refFinal = lista->refFinal;

    return (refComeco->proxima == refFinal && refFinal->anterior == refComeco);
}

void renderizarListaProdutos(const ListaProdutos* lista) {
    unsigned int contador = 1;

    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
        Produto produto = item->produto;
        printf("[%d] %s\n", contador, produtoAsString(produto));
        contador++;
    }

    return;
}

void setRefFinal(ListaProdutos* lista, Celula* item) {
    if(item == NULL) {
        return;
    }

    Celula* finalAnterior = getCelulaFinal(lista);

    item->anterior = finalAnterior;
    item->proxima = lista->refFinal;
    
    finalAnterior->proxima = item;
    lista->refFinal->anterior = item;

    return;
}

void setRefInicial(ListaProdutos* lista, Celula* item) {
    if(item == NULL) {
        return;
    }

    Celula* comecoAnteriror = getCelulaInicial(lista);

    item->proxima = comecoAnteriror;
    item->anterior = lista->refComeco;

    comecoAnteriror->anterior = item;
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
    if(estaVazia(lista)) {
        return NULL;
    }
    char nomeReferencia[TAMANHO_NOME_PRODUTO];
    strcpy(nomeReferencia, nome);
    toLower(nomeReferencia);

    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
        char nomeProduto[TAMANHO_NOME_PRODUTO];
        strcpy(nomeProduto, item->produto.nome);
        toLower(nomeProduto);

        bool produtoTemNomeIgual = !strcmp(nomeProduto, nomeReferencia);
        if(produtoTemNomeIgual) {
            return item;
        }
    }

    return NULL;
}

Celula* getCelulaPorCodigoProduto(const ListaProdutos* lista, const unsigned int codigo) {
    if(estaVazia(lista)) {
        return NULL;
    }

    for(Celula* item = getCelulaInicial(lista); item != lista->refFinal; item = item->proxima) {
        if(item->produto.codigo == codigo) {
            return item;
        }
    }

    return NULL;
}

Celula* getCelulaEm(const ListaProdutos* lista, const unsigned int index) {
    if(index < 0 || index >= lista->tamanho) {
        return NULL;
    }

    Celula* alvo = getCelulaInicial(lista);
    for(int i = 0; i < index && i < lista->tamanho; i++) {
        alvo = alvo->proxima;
    }

    return alvo;
}

void removerCelula(Celula* alvo) {
    if(alvo == NULL) {
        return;
    }

    Celula* anteriorAoAlvo = alvo->anterior;
    Celula* proximaAoAlvo = alvo->proxima;

    anteriorAoAlvo->proxima = proximaAoAlvo;
    proximaAoAlvo->anterior = anteriorAoAlvo;

    free(alvo);
    return;
}

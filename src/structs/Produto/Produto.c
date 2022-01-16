#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Data/DataStruct.h"
#include "./ProdutoStruct.h"

void setCodigo(Produto* produto, const unsigned int codigo) {
    produto->codigo = codigo;
    return;
}

void setNome(Produto* produto, const char nome[TAMANHO_NOME_PRODUTO]) {
    strcpy(produto->nome, nome);
    return;
}

void setPreco(Produto* produto, const float preco) {
    produto->preco = preco;
    return;
}

void setValidade(Produto* produto, const Data validade) {
    setDia(&produto->validade, validade.dia);
    setMes(&produto->validade, validade.mes);
    setAno(&produto->validade, validade.ano);
}

Produto buildProduto(const unsigned int codigo, const char nome[TAMANHO_NOME_PRODUTO], const float preco, const Data valdiade) {
    Produto novoProduto;
    setCodigo(&novoProduto, codigo);
    setNome(&novoProduto, nome);
    setPreco(&novoProduto, preco);
    setValidade(&novoProduto, valdiade);

    return novoProduto;
}

Produto buildProdutoVazio() {
    Produto vazio = buildProduto(0, "", 0.0, buildDataVazia());
    return vazio;
}

char* produtoAsString(const Produto produto) {
    const char template[] = "Produto: %s, com código: %d. Preço: %.2fR$ - Validade: %s.";
    const size_t tamanho = sizeof(template) + sizeof(produto);

    char* produtoString = (char*) malloc(tamanho * sizeof(char));
    sprintf(produtoString, template, produto.nome, produto.codigo, produto.preco, dataAsString(produto.validade));
    
    return produtoString;
}

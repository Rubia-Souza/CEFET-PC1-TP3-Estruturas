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
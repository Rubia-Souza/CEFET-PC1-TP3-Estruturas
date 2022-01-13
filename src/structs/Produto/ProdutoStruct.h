#ifndef PRODUTO_H
#define PRODUTO_H

#include "../Data/DataStruct.h"

#define TAMANHO_NOME_PRODUTO 50

typedef struct Produto {
    unsigned int codigo;
    char nome[TAMANHO_NOME_PRODUTO];
    float preco;
    Data validade;
} Produto;

void setCodigo(Produto* produto, const unsigned int codigo);
void setNome(Produto* produto, const char nome[TAMANHO_NOME_PRODUTO]);
void setPreco(Produto* produto, const float preco);
void setValidade(Produto* produto, const Data validade);

Produto buildProdutoVazio();
char* produtoAsString(const Produto produto);

#endif

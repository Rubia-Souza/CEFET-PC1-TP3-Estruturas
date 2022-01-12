#include <stdio.h>
#include <stdlib.h>

#include "./structs/Produto/Produto.h"

int main() {

    Produto teste;
    setCodigo(&teste, 1);
    setNome(&teste, "Rubia");
    setPreco(&teste, 1000);
    Data validade;
    setDia(&validade, 2);
    setMes(&validade, 3);
    setAno(&validade, 2001);
    setValidade(&teste, validade);

    printf("Codigo: %d", teste.codigo);
    printf("Nome: %s\n", teste.nome);
    printf("Preco: %f\n", teste.preco);
    printf("Dia: %d\n", teste.validade.dia);
    printf("Mes: %d\n", teste.validade.mes);
    printf("Ano: %d\n", teste.validade.ano);

    return 0;
}

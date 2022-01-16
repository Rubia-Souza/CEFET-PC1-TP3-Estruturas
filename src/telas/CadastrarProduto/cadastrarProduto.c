#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "../../structs/Produto/ProdutoStruct.h"

unsigned int getCodigoProduto();
char* getNomeProduto();
float getPreco();
Data getValidade();
unsigned int getDia();
unsigned int getMes();
unsigned int getAno();

Produto renderizarCadastroProduto(){
    printf("\n--- Dados do produto que será cadastrado\n");

    Produto produto;
    produto.codigo = getCodigoProduto();
    strcpy(produto.nome, getNomeProduto());
    produto.preco = getPreco();
    produto.validade = getValidade();

    printf("\nProduto cadastrado:\n");
    printf("%s", produtoAsString(produto));
    return produto;
}

unsigned int getCodigoProduto() {
    unsigned int numeroProduto = 0;
    bool inputErrado = false;

    printf("\nInforme o código do produto: ");
    do {
        scanf("%d", &numeroProduto);
        fflush(stdin);

        inputErrado = numeroProduto < 1;
        if(inputErrado) {
            printf("\nPor favor informe um valor válido: ");
        }
    } while(inputErrado);

    return numeroProduto;
}

char* getNomeProduto() {
    char* nomeProduto = (char*) malloc(TAMANHO_NOME_PRODUTO * sizeof(char));

    printf("\nInforme o nome do produto: ");
    fgets(nomeProduto, TAMANHO_NOME_PRODUTO, stdin);
    fflush(stdin);
    nomeProduto[strcspn(nomeProduto, "\n")] = '\000';

    return nomeProduto;
}

float getPreco() {
    float preco = 0;
    bool inputErrado = false;

    printf("\nInforme o preço do produto: ");
    do {
        scanf("%f", &preco);
        fflush(stdin);

        inputErrado = preco < 0;
        if(inputErrado) {
            printf("\nPor favor, informe um preço válido: ");
        }
    } while(inputErrado);

    return preco;
}

Data getValidade() {
    Data validade;
    validade.dia = getDia();
    validade.mes = getMes();
    validade.ano = getAno();

    return validade;
}

unsigned int getDia() {
    int dia = 0;
    bool inputErrado = false;

    printf("\nInforme o dia da validade do produto: ");
    do {
        scanf("%d", &dia);
        fflush(stdin);

        inputErrado = !diaEhValido(dia);
        if(inputErrado) {
            printf("\nPor favor, informe um dia válido (entre 1 e 31): ");
        }
    } while(inputErrado);
    
    return dia;
}

unsigned int getMes() {
    int mes = 0;
    bool inputErrado = false;

    printf("\nInforme o mes da validade do produto: ");
    do {
        scanf("%d", &mes);
        fflush(stdin);

        inputErrado = !mesEhValido(mes);
        if(inputErrado) {
            printf("\nPor favor, informe um mes válido (entre 1 e 12): ");
        }
    } while(inputErrado);
    
    return mes;
}

unsigned int getAno() {
    int ano = 0;
    bool inputErrado = false;

    printf("\nInforme o ano da validade do produto: ");
    do {
        scanf("%d", &ano);
        fflush(stdin);

        inputErrado = !anoEhValido(ano);
        if(inputErrado) {
            printf("\nPor favor, informe um ano válido, sendo o mínimo %d: ", ANO_MINIMO);
        }
    } while(inputErrado);
    
    return ano;
}

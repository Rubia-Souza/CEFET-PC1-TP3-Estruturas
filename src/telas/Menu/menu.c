#include <stdio.h>
#include <stdbool.h>

#include "./menu.h"

#define OPCAO_MENU_MINIMA 1
#define OPCAO_MENU_MAXIMA 7

void renderizarOpcoes();
unsigned int getOpcao();

unsigned int renderizarMenu() {
    printf("\n===== Rúbia Alice - Produtos =====\n\n");
    
    renderizarOpcoes();
    unsigned int escolha = getOpcao();

    return escolha;
}

void renderizarOpcoes() {
    printf("[1] Adicionar produto\n");
    printf("[2] Exibir produtos\n");
    printf("[3] Exibir produto mais caro\n");
    printf("[4] Exibir produto mais barato\n");
    printf("[5] Excluir produto\n");
    printf("[6] Ordernar produtos\n");
    printf("[7] Sair\n");

    return;
}

unsigned int getOpcao() {
    unsigned int opcao = 0;
    bool inputErrado = false;

    printf("\nEscolha uma das opções acima: ");
    do {
        scanf("%d", &opcao);
        fflush(stdin);

        inputErrado = opcao < OPCAO_MENU_MINIMA || opcao > OPCAO_MENU_MAXIMA;
        if(inputErrado) {
            printf("\nPor favor, escolha uma opção válida (de %d a %d): ", OPCAO_MENU_MINIMA, OPCAO_MENU_MAXIMA);
        }
    } while(inputErrado);
    
    return opcao;
}

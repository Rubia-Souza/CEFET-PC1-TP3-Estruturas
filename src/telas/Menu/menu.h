#ifndef MENU_H
#define MENU_H

typedef enum OpcoesMenu {
    ADICIONAR = 1,
    EXIBIR_TODOS_PRODUTOS = 2,
    EXIBIR_PRODUTO_CARO = 3,
    EXIBIR_PRODUTO_BRARATO = 4,
    EXCLUIR_PRODUTO = 5,
    ORDENAR_PRODUTOS = 6,
    SAIR = 7,
} OpcoesMenu;

unsigned int renderizarMenu();

#endif

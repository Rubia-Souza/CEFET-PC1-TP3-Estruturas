#include "../../structs/Data/DataStruct.h"
#include "../../structs/Produto/ProdutoStruct.h"
#include "../../structs/ListaProdutos/ListaProdutosStruct.h"

ListaProdutos* getProdutosMock() {
    ListaProdutos* mocks = newListaProdutos();

    adicionarComeco(mocks, buildProduto(
        123,
        "Destiny 2",
        120.0,
        buildData(
            28,
            9,
            2017
        )
    ));

    adicionarComeco(mocks, buildProduto(
        990099,
        "Elder Ring",
        785.90,
        buildData(
            12,
            11,
            2022
        )
    ));

    adicionarComeco(mocks, buildProduto(
        7263,
        "Cross Code",
        24.0,
        buildData(
            15,
            4,
            2015
        )
    ));

    adicionarComeco(mocks, buildProduto(
        788,
        "A Bird History",
        24.0,
        buildData(
            5,
            11,
            2014
        )
    ));

    adicionarComeco(mocks, buildProduto(
        89,
        "To The Moon",
        24.0,
        buildData(
            1,
            11,
            2011
        )
    ));

    adicionarComeco(mocks, buildProduto(
        5,
        "God of War 2018",
        200.0,
        buildData(
            20,
            4,
            2018
        )
    ));

    adicionarComeco(mocks, buildProduto(
        3,
        "Dark Souls III",
        120.0,
        buildData(
            24,
            3,
            2016
        )
    ));

    adicionarComeco(mocks, buildProduto(
        283,
        "Bloodborn",
        200.0,
        buildData(
            24,
            3,
            2015
        )
    ));

    adicionarComeco(mocks, buildProduto(
        90,
        "To The Moon",
        24.0,
        buildData(
            5,
            12,
            2018
        )
    ));

    adicionarComeco(mocks, buildProduto(
        123874,
        "Horizon Forbidden West",
        200.1,
        buildData(
            18,
            2,
            2022
        )
    ));

    adicionarComeco(mocks, buildProduto(
        790,
        "A Bird History",
        24.0,
        buildData(
            10,
            12,
            2015
        )
    ));
    
    adicionarComeco(mocks, buildProduto(
        555,
        "Dark Souls",
        350.0,
        buildData(
            24,
            5,
            2018
        )
    ));

    adicionarComeco(mocks, buildProduto(
        7274,
        "Cross Code",
        30.0,
        buildData(
            20,
            2,
            2022
        )
    ));

    adicionarComeco(mocks, buildProduto(
        589,
        "Dark Souls",
        250.0,
        buildData(
            24,
            5,
            2018
        )
    ));

    adicionarComeco(mocks, buildProduto(
        11278,
        "One Shot",
        250.0,
        buildData(
            2,
            3,
            2011
        )
    ));

    adicionarComeco(mocks, buildProduto(
        777,
        "Finding Paradise",
        777.7,
        buildData(
            7,
            7,
            2777
        )
    ));

    adicionarComeco(mocks, buildProduto(
        7,
        "Dark Souls III",
        120.0,
        buildData(
            24,
            3,
            2016
        )
    ));

    adicionarComeco(mocks, buildProduto(
        791,
        "A Bird History",
        24.0,
        buildData(
            11,
            12,
            2015
        )
    ));

    adicionarComeco(mocks, buildProduto(
        9845,
        "Impostor Factory",
        450.87,
        buildData(
            22,
            2,
            2022
        )
    ));

    adicionarComeco(mocks, buildProduto(
        4,
        "God of War 2018",
        150.0,
        buildData(
            20,
            4,
            2018
        )
    ));

    adicionarComeco(mocks, buildProduto(
        880088,
        "Elder Ring",
        785.90,
        buildData(
            11,
            10,
            2022
        )
    ));

    adicionarComeco(mocks, buildProduto(
        124325315,
        "Horizon Forbidden West",
        9802.1,
        buildData(
            18,
            2,
            2022
        )
    ));

    

    return mocks;
}

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "./utils.h"

void toLower(char* referencia) {
    const size_t tamanho = strlen(referencia);
    char* lowerString = (char*) malloc((tamanho + 1) * sizeof(char));

    int i = 0;
    for(i = 0; i < tamanho; i++) {
        lowerString[i] = tolower(referencia[i]);
    }
    lowerString[i] = '\000';

    strcpy(referencia, lowerString);
}

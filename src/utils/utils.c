#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "./utils.h"

char* toLower(const char referencia[]) {
    const int tamanho = strlen(referencia);
    char* lowerString = (char*) malloc(tamanho * sizeof(char));

    for(int i = 0; i < tamanho; i++) {
        lowerString[i] = tolower(referencia[i]);
    }

    return lowerString;
}

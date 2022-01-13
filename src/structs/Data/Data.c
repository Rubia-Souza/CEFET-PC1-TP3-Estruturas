#include <stdio.h>
#include <stdlib.h>
#include "DataStruct.h"

void setDia(Data* data, const unsigned int dia) {
    data->dia = dia;
    return;
}

void setMes(Data* data, const unsigned int mes) {
    data->mes = mes;
    return;
}

void setAno(Data* data, const unsigned int ano) {
    data->ano = ano;
    return;
}

Data buildDataVazia() {
    Data vazia;
    setAno(&vazia, 0);
    setMes(&vazia, 0);
    setDia(&vazia, 0);

    return vazia;
}

char* dataAsString(const Data data) {
    const char template[] = "%d/%d/%d";
    const int tamanho = sizeof(template);

    char* dataString = (char*) malloc(tamanho * sizeof(char));

    sprintf(dataString, template, data.dia, data.mes, data.ano);
    return dataString;
}

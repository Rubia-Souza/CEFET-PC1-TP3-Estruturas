#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    const size_t tamanho = sizeof(template) + sizeof(Data);

    char* dataString = (char*) malloc(tamanho * sizeof(char));

    sprintf(dataString, template, data.dia, data.mes, data.ano);
    return dataString;
}

bool dataEhValida(const Data data) {
    return (diaEhValido(data.dia) && mesEhValido(data.mes) && anoEhValido(data.ano));
}

bool diaEhValido(const unsigned int dia) {
    return (dia >= 1 || dia <= 31);
}

bool mesEhValido(const unsigned int mes) {
    return (mes >= 1 || mes <= 12);
}

bool anoEhValido(const unsigned int ano) {
    return (ano > 0);
}

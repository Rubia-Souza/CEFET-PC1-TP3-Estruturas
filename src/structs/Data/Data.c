#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

Data buildData(const unsigned int dia, const unsigned int mes, const unsigned int ano) {
    Data novaData;
    setAno(&novaData, ano);
    setMes(&novaData, mes);
    setDia(&novaData, dia);

    return novaData;
}

Data buildDataVazia() {
    Data vazia = buildData(0, 0, 0);
    return vazia;
}

struct tm dataAsTm(const Data data) {
    struct tm dataTm = {0};
    dataTm.tm_year = data.ano - ANO_MINIMO;
    dataTm.tm_mon = data.mes - 1;
    dataTm.tm_mday = data.dia;

    return dataTm;
}

time_t dataAsTimeT(const Data data) {
    struct tm dataTm = dataAsTm(data);
    return mktime(&dataTm);
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
    return (ano > ANO_MINIMO);
}

#ifndef DATA_H
#define DATA_H

#include <stdbool.h>
#include <time.h>

#define ANO_MINIMO 1900

typedef enum Meses {
    Janeiro = 1,
    Fevereiro = 2,
    Marco = 3,
    Abril = 4,
    Maio = 5,
    Junho = 6,
    Julho = 7,
    Agosto = 8,
    Setembro = 9,
    Outubro = 10,
    Novembro = 11,
    Dezembro = 12,
} Meses;

typedef struct Data {
    unsigned int dia;
    unsigned int mes;
    unsigned int ano;
} Data;

void setDia(Data* data, const unsigned int dia);
void setMes(Data* data, const unsigned int mes);
void setAno(Data* data, const unsigned int ano);

Data buildData(const unsigned int dia, const unsigned int mes, const unsigned int ano);
Data buildDataVazia();
char* dataAsString(const Data data);

bool dataEhValida(const Data data);
bool diaEhValido(const unsigned int dia);
bool mesEhValido(const unsigned int mes);
bool anoEhValido(const unsigned int ano);

struct tm dataAsTm(const Data data);
time_t dataAsTimeT(const Data data);

#endif

#ifndef NODOCABECERA_H
#define NODOCABECERA_H
#include <string>
#include "nodo.h"


class nodoCabecera
{
public:
    nodoCabecera();
    nodoCabecera(const std::string& dia);
    void insertarAct(nodo * nuevo);
    nodo* getInicial();
    int getDato();
    string getDia();
    void setInicial(nodo* act);
    nodoCabecera * getSig();
    void setSig(nodoCabecera* next);
    void imprimir();

private:
    string dia;
    int dato;
    nodoCabecera* sig;
    nodo* Inicial;
};

#endif // NODOCABECERA_H

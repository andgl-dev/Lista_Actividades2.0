#ifndef NODOCABHORA_H
#define NODOCABHORA_H
#include <cstdlib>
#include <string>
#include "nodo.h"

class nodoCabHora
{
public:
    nodoCabHora();
    nodoCabHora(const std::string& hora,int hr);
    void insertarAct(nodo * nuevo);
    nodo * getInicial();
    int getHora();
    string getStHora();
    nodoCabHora * getAbajo();
    void setAbajo(nodoCabHora * next);
    void imprimir();

private:
    int hora;
    string sthora;
    nodoCabHora * abajo;
    nodo * inicial;
};

#endif // NODOCABHORA_H

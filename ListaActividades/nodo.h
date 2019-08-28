#ifndef NODO_H
#define NODO_H
#include <cstring>
#include <string> //llamada para usar cadenas
#include <cstdlib> //llamada para usar NULL
#include <iostream> // biblioteca que contiene las funciones de entrada y salida de c++ . Viene Input/Output Stream
using namespace std;

class nodo
{
public:
    nodo();
    nodo(int dia, int hr,const std::string& act);
    string getActividad();
    nodo* getSiguiente();
    nodo* getAnterior();
    void setSiguiente(nodo* sig);
    void setAnterior(nodo* ant);
    //---------------------------------------------
    nodo* getArriba();
    nodo* getAbajo();
    void setArriba(nodo* sig);
    void setAbajo(nodo* ant);
    int dia;
    int hr;

private:
    string actividad;
    nodo* sig;
    nodo* ant;
    //---------------------------------------------
    nodo* arriba;
    nodo* abajo;
};

#endif // NODO_H

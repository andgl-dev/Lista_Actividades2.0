#include "nodo.h"

nodo::nodo()
{
    this->sig = NULL;
    this->abajo = NULL;
    this->arriba = NULL;
    this->ant = NULL;
    this->actividad = "";
    this->dia = 0;
    this->hr = 0;
}

     nodo::nodo(int dia,int hr,const std::string& act)
{
    this->actividad =act;
    this->dia = dia;
    this->hr = hr;
    this->ant = NULL;
    this->sig = NULL;
    this->abajo = NULL;
    this->arriba = NULL;
}

string nodo::getActividad()
{
    return this->actividad;
}

nodo *nodo::getSiguiente()
{
    return this->sig;
}

nodo *nodo::getAnterior()
{
    return this->ant;
}

void nodo::setSiguiente(nodo *sig)
{
    this->sig = sig;
}

void nodo::setAnterior(nodo *ant)
{
    this->ant = ant;
}
//------------------------------------------
nodo *nodo::getArriba()
{
    return this->arriba;
}

nodo *nodo::getAbajo()
{
    return this->abajo;
}

void nodo::setArriba(nodo *arr)
{
    this->arriba = arr;
}

void nodo::setAbajo(nodo *aba)
{
    this->abajo = aba;
}

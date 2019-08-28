#include "nodocabhora.h"

nodoCabHora::nodoCabHora()
{
    this->hora = 0;
    this->inicial = NULL;
    this->sthora = "";
    this->abajo = NULL;
}

nodoCabHora::nodoCabHora(const string &hora, int hr)
{
    this->abajo = NULL;
    this->inicial = NULL;
    this->sthora = hora;
    this->hora = hr;
}

void nodoCabHora::insertarAct(nodo * nuevo)
{
    if(this->inicial == NULL)
    {
        this->inicial = nuevo;
    }
    else if(nuevo->dia < this->inicial->dia)
    {
        nuevo->setSiguiente(this->inicial);
        this->inicial->setAnterior(nuevo);
        this->inicial = nuevo;
    }
    else
    {
        nodo*aux = this->inicial;
        bool insertado = false;
        while(aux->getSiguiente() != NULL)
        {
            if(nuevo->dia < aux->getSiguiente()->dia)
            {
                nuevo->setAnterior(aux);
                nuevo->setSiguiente(aux->getSiguiente());
                aux->getSiguiente()->setAnterior(nuevo);
                aux->setSiguiente(nuevo);
                insertado = true;
                break;
            }
            aux = aux->getSiguiente();
        }
        if(!(insertado))
        {
            nuevo->setAnterior(aux);
            aux->setSiguiente(nuevo);
        }

    }
}

nodo *nodoCabHora::getInicial()
{
    return this->inicial;
}

int nodoCabHora::getHora()
{
    return this->hora;
}

string nodoCabHora::getStHora()
{
    return this->sthora;
}

nodoCabHora *nodoCabHora::getAbajo()
{
    return this->abajo;
}

void nodoCabHora::setAbajo(nodoCabHora *next)
{
    this->abajo = next;
}

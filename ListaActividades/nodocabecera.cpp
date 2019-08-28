#include "nodocabecera.h"

nodoCabecera::nodoCabecera()
{
    this->dia="";
    this->dato=0;
    this->sig = NULL;
    this->Inicial = NULL;
}

nodoCabecera::nodoCabecera(const std::string& dia_)
{
    string dia = dia_;
    this->dia = dia;
    if(dia=="lunes")
    {
        this->dato=1;
    }
    else if(dia=="martes")
    {
        this->dato=2;
    }
    else if(dia=="miercoles")
    {
        this->dato=3;
    }
    else if(dia=="jueves")
    {
        this->dato=4;
    }
    else if(dia=="viernes")
    {
        this->dato=5;
    }
    else if(dia=="sabado")
    {
        this->dato=6;
    }
    else if(dia=="domingo")
    {
        this->dato=7;
    }

    this->Inicial = NULL;
    this->sig = NULL;
}

void nodoCabecera::insertarAct(nodo*nuevo)
{

    if(this->Inicial == NULL)
    {
        this->Inicial=nuevo;
    }
    else if(nuevo->hr < this->Inicial->hr)
    {
        nuevo->setAbajo(this->Inicial);
        this->Inicial->setArriba(nuevo);
        this->Inicial = nuevo;
    }
    else
    {
        nodo*aux = this->Inicial;
        bool insertado = false;
        while(aux->getAbajo()!=NULL)
        {
            if(nuevo->hr < aux->getAbajo()->hr)
            {
                nuevo->setArriba(aux->getArriba());
                aux->getArriba()->setAbajo(nuevo);
                nuevo->setAbajo(aux);
                aux->setArriba(nuevo);
                insertado =true;
                break;
            }
            aux = aux->getAbajo();
        }
        if(!(insertado))
        {
            nuevo->setArriba(aux);
            aux->setAbajo(nuevo);
        }

    }

}

nodo *nodoCabecera::getInicial()
{
    return this->Inicial;
}

int nodoCabecera::getDato()
{
    return this->dato;
}

string nodoCabecera::getDia()
{
    return this->dia;
}

void nodoCabecera::setInicial(nodo *act)
{
    this->Inicial = act;
}

nodoCabecera *nodoCabecera::getSig()
{
    return this->sig;
}

void nodoCabecera::setSig(nodoCabecera *next)
{
    this->sig = next;
}

void nodoCabecera::imprimir()
{
    nodo*aux = this->getInicial();
    while(aux != NULL)
    {
        std::cout<<aux->getActividad()<<std::endl;
        aux = aux->getAbajo();
    }
}

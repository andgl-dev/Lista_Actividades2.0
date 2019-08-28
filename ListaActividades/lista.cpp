#include "lista.h"

lista::lista()
{
    this->diaUno=NULL;
}

void lista::crearActividad(const std::string& dia,const std::string& hora, const std::string& act)
{
    int hr = stoi(hora.substr(0,hora.length()-2));
    nodoCabecera* cabDia = new nodoCabecera(dia);
    nodoCabHora* cabHora = new nodoCabHora(hora,hr);
    nodo * actividad = new nodo(cabDia->getDato(),hr,act);

    if(this->diaUno == NULL)
    {
        cabDia->insertarAct(actividad);
        this->diaUno = cabDia;
    }
    else if(cabDia->getDato() < this->diaUno->getDato())
    {
        cabDia->insertarAct(actividad);
        cabDia->setSig(this->diaUno);
        this->diaUno = cabDia;
    }
    else
    {
        nodoCabecera* aux= this->diaUno;
        bool existe = false;
        while(aux->getSig() != NULL)
        {
            if(aux->getDato() == cabDia->getDato())
            {
                aux->insertarAct(actividad);
                existe = true;
                break;
            }
            else if(aux->getSig()->getDato() > cabDia->getDato())
            {
                cabDia->insertarAct(actividad);
                cabDia->setSig(aux->getSig());
                aux->setSig(cabDia);
                existe = true;
                break;
            }
            aux = aux->getSig();
        }
        if(!existe)
        {
            if(aux->getDato() == cabDia->getDato())
            {
                aux->insertarAct(actividad);
            }
            else
            {
                cabDia->insertarAct(actividad);
                aux->setSig(cabDia);
            }
        }

    }

    this->insertarEnHora(cabHora,actividad);

}



void lista::insertarEnHora(nodoCabHora *nuevo,nodo*nuevo_)
{

    if(this->horaUno == NULL)
    {
        nuevo->insertarAct(nuevo_);
        this->horaUno = nuevo;
    }
    else if(nuevo->getHora() < this->horaUno->getHora())
    {
        nuevo->insertarAct(nuevo_);
        nuevo->setAbajo(this->horaUno);
        this->horaUno = nuevo;
    }
    else
    {
        nodoCabHora * aux = this->horaUno;
        bool insertado = false;
        while(aux->getAbajo() != NULL)
        {
            if(aux->getHora()==nuevo->getHora())
            {
                aux->insertarAct(nuevo_);
                insertado = true;
                break;
            }
            else if(nuevo->getHora() < aux->getAbajo()->getHora())
            {
                nuevo->insertarAct(nuevo_);
                nuevo->setAbajo(aux->getAbajo());
                aux->setAbajo(nuevo);
                insertado = true;
                break;
            }
            aux = aux->getAbajo();
        }
        if(!(insertado))
        {
            if(aux->getHora() == nuevo->getHora())
            {
                aux->insertarAct(nuevo_);
            }
            else
            {
                nuevo->insertarAct(nuevo_);
                aux->setAbajo(nuevo);
            }

        }
    }
}

void lista::imprimirLista()
{
    if(this->diaUno != NULL)
    {
        nodoCabecera*aux = this->diaUno;
        nodoCabHora*aux2 = this->horaUno;
        std::cout <<"Imprimiendo Actividades"<<std::endl;
        while(aux != NULL)
        {
            std::cout <<"Dia: "<<aux->getDia()<<std::endl;
            nodo*auxAct = aux->getInicial();
            while(auxAct != NULL)
            {
                std::cout <<"Actividad: "<<auxAct->getActividad()<<" hora: "<<auxAct->hr<<std::endl;
                auxAct = auxAct->getAbajo();
            }
            std::cout <<"---------------------------------------"<<std::endl;
            aux=aux->getSig();
        }

        std::cout <<"---------Imprimiendo por horas-------------"<<std::endl;

        while(aux2 != NULL)
        {
            std::cout <<"Hora: "<<aux2->getStHora()<<" --> "<<std::ends;
            nodo*auxAct = aux2->getInicial();
            while(auxAct != NULL)
            {
                std::cout <<"Actividad: "<<auxAct->getActividad()<<" dia: "<<auxAct->dia<<" --> "<<std::ends;
                auxAct = auxAct->getSiguiente();
            }
            std::cout<<"\n"<<std::endl;
            aux2=aux2->getAbajo();
        }

    }
    else
    {
        std::cout <<"la lista de actividades esta vacia"<<std::endl;
    }

}


void lista::imprimirDia(const string &dia)
{
    if(this->diaUno != NULL)
    {
        nodoCabecera *aux = this->diaUno;
        while(aux != NULL)
        {
            if(aux->getDia()==dia)
            {
                break;
            }
            aux = aux->getSig();
        }
        if(aux != NULL)
        {
            std::cout <<"---------------------------------------"<<std::endl;
            std::cout <<"Dia: "<<aux->getDia()<<std::endl;
            nodo*auxAct = aux->getInicial();
            while(auxAct != NULL)
            {
                std::cout <<"Actividad: "<<auxAct->getActividad()<<std::endl;
                auxAct = auxAct->getAbajo();
            }
            std::cout <<"---------------------------------------"<<std::endl;
        }
        else
        {
            std::cout <<"El dia "<<dia<< " no existe :'("<<std::endl;
        }
    }
    else
    {
        std::cout <<"la lista de actividades esta vacia"<<std::endl;
    }
}



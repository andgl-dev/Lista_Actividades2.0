#ifndef LISTA_H
#define LISTA_H
#include <string>
#include "nodocabhora.h"
#include "nodocabecera.h"

class lista
{
public:
    lista();
    void crearActividad(const std::string& dia,const std::string& hora, const std::string& act);
    void imprimirDia(const std::string& dia);
    void insertarEnHora(nodoCabHora *nuevo,nodo* nuevo_);
    void imprimirLista();

private:
    nodoCabecera* diaUno;
    nodoCabHora * horaUno;
};

#endif // LISTA_H

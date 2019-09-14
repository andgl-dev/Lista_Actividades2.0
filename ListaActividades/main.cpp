#include "lista.h"
#include "nodocabhora.h"
int main()
{

    lista *l = new lista();

    l->crearActividad("miercoles","7am","desayunar");
    l->crearActividad("martes","7am","despertar");
    l->crearActividad("jueves","7am","correr");
    l->crearActividad("lunes","7am","mundo");
    l->crearActividad("viernes","7am","nadar");
    l->crearActividad("sabado","7am","volar");
    l->crearActividad("domingo","7am","regresar");
    l->crearActividad("lunes","8am","hola");
    l->crearActividad("lunes","9am","sudo");
    l->crearActividad("lunes","10am","apt");
    l->crearActividad("lunes","11am","get");
    l->crearActividad("lunes","12am","gg");
    l->crearActividad("lunes","13pm","fin");
    l->crearActividad("domingo","8am","otra");
    l->crearActividad("domingo","9am","prueba");
    l->imprimirLista();
    std::cout <<"-----imprimiendo dia especifico----------"<<std::endl;
    l->imprimirDia("lunes");
    std::cout <<"-----imprimiendo dia especifico----------"<<std::endl;
    l->imprimirDia("sabado");
    return 0;
}

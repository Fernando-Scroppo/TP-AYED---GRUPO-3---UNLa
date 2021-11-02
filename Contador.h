#ifndef CONTADOR_H_INCLUDED
#define CONTADOR_H_INCLUDED
#include <sstream>

using namespace std;
struct Contador{
    int idVino;
    int cantidad;

};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre: el contador debe haberse creado.
  post: Deja un contador cargado con el id del vino y la cantidad seteada en cero.
*/

Contador* crearContador(Contador *contador,int idVino);
/*----------------------------------------------------------------------------*/
/*
  pre: el contador debe haberse creado.
  post: reserva espacio de memoria y devuelve un tipo Contador vacio.
*/
Contador* crearContadorVacio(Contador *contador);
/*----------------------------------------------------------------------------*/
/*
  pre: el contador debe haberse creado.
  post: Devuelve el Id del vino, que esta contabilizando.
*/

int getContadorIdVino(Contador *contador);

/*----------------------------------------------------------------------------*/

/*
  pre: el contador debe haberse creado.
  post: Devuelve la cantidad del contador.
*/

int getContadorCantidad(Contador *contador);

/*----------------------------------------------------------------------------*/

/*
  pre: el contador debe haberse creado.
  post: setea el id del vino que almacena el contador.
*/
void setContadorIdVino(Contador *contador, int idVino);
/*----------------------------------------------------------------------------*/

/*
  pre: el contador debe haberse creado.
  post: Setea la cantidad que almacena el contador.
*/

void setContadorCantidad(Contador *contador, int cantidad);


#endif // CONTADOR_H_INCLUDED

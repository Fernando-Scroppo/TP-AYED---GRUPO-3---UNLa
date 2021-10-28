#ifndef CONTADOR_H_INCLUDED
#define CONTADOR_H_INCLUDED
#include <sstream>

using namespace std;
struct Contador{
    int idVino;
    string bodega;
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

void setContadorIdVino(Contador *contador, int idVino);

void setContadorCantidad(Contador *contador, int cantidad);

//-------------------------------------------------------------- ultima actualizacion

/*
  pre: el contador debe haberse creado.
  post: Deja un contador cargado con el string bodega y la cantidad seteada en cero.
*/
Contador* crearContador(Contador *contador,string bodega);

/*
  pre : el contador no debe haber sido creado.
  post: el contador queda creado y preparado para ser usado con valores 0.
*/

Contador* crearContadorVacio(Contador *contador);

/*
  pre: el contador debe haberse creado.
  post: Devuelve la la bodega.
*/
string getContadorBodega(Contador *contador);





#endif // CONTADOR_H_INCLUDED

#ifndef CONTADORBODEGA_H_INCLUDED
#define CONTADORBODEGA_H_INCLUDED

#include <sstream>
using namespace std;

struct ContadorBodega{
    string bodega;
    int cantidad;

};

/*
  pre: el contador debe haberse creado.
  post: Deja un contador cargado con el string bodega y la cantidad seteada en cero.
*/
ContadorBodega* crearContadorBodega(ContadorBodega *contadorBodega,string bodega);

/*
  pre : el contador no debe haber sido creado.
  post: el contador queda creado y preparado para ser usado con valores 0.
*/

ContadorBodega* crearContadorVacioBodega(ContadorBodega *contadorBodega);

/*
  pre: el contador debe haberse creado.
  post: Devuelve la la bodega.
*/
string getContadorBodega(ContadorBodega *contadorBodega);

/*
  pre: el contador debe haberse creado.
  post: setea la bodega.
*/

void setContadorBodega(ContadorBodega *contadorBodega,string bodega);

/*
  pre: el contador debe haberse creado.
  post: Devuelve la cantidad del contador.
*/

int getContadorCantidad(ContadorBodega *contadorBodega);


/*
  pre: el contador debe haberse creado.
  post: setea la cantidad .
*/
void setContadorCantidad(ContadorBodega *contadorBodega, int cantidad);

#endif // CONTADOR_H_INCLUDED

#ifndef CONTADORVARIETAL_H_INCLUDED
#define CONTADORVARIETAL_H_INCLUDED
#include <sstream>
using namespace std;


struct ContadorVarietal{
    string varietal;
    int cantidad;
};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre: el contador debe haberse creado.
  post: Deja un contador cargado con el id del vino y la cantidad seteada en cero.
*/

ContadorVarietal* crearContadorVarietal(ContadorVarietal *contador,string varietal);
/*----------------------------------------------------------------------------*/
/*
  pre: el contador debe haberse creado.
  post: reserva espacio de memoria y devuelve un puntero de tipo ContadorVarietal vacio.
*/
ContadorVarietal* crearContadorVarietalVacio(ContadorVarietal *contador);
/*----------------------------------------------------------------------------*/
/*
  pre: el contador debe haberse creado.
  post: Devuelve el Id del vino, que esta contabilizando.
*/

string getContadorObtenerVarietal(ContadorVarietal *contador);

/*----------------------------------------------------------------------------*/

/*
  pre: el contador debe haberse creado.
  post: Devuelve la cantidad del contador.
*/

int getContadorVarietalCantidad(ContadorVarietal *contador);

/*----------------------------------------------------------------------------*/

/*
  pre: el contador debe haberse creado.
  post: Setea el varietal a contar.
*/

void setContadorVarietal(ContadorVarietal *contador, string varietal);

/*----------------------------------------------------------------------------*/

/*
  pre: el contador debe haberse creado.
  post: Setea la cantidad.
*/

void setContadorVarietalCantidad(ContadorVarietal *contador, int cantidad);


#endif // CONTADORVARIETAL_H_INCLUDED

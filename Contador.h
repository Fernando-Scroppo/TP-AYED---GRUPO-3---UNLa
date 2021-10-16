#ifndef CONTADOR_H_INCLUDED
#define CONTADOR_H_INCLUDED

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


#endif // CONTADOR_H_INCLUDED

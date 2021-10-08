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


#endif // CONTADOR_H_INCLUDED

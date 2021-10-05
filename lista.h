#ifndef LISTAVOID_H_INCLUDED
#define LISTAVOID_H_INCLUDED
#include <sstream>
using namespace std;

/******************************************************************************/
/* Definiciones de Tipos de Datos */
/*--------------------------------*/

/* Tipo de Estructura del Nodo de la lista */
struct Nodo {
    void *dato;
    Nodo *siguiente;
};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  PRE : La lista no debe a ver sido creada previamente.
  POST: Se crea el primer nodo de la lista apuntando a NULL.
*/
//[retorno de la funcion = Un puntero de tipo Nodo.] [nombre de la funcion = crearLista]([datos que necesita mi funcion = No necesita parametros])

Nodo* crearLista();

/*
  PRE : La lista tiene que estar creada.
  POST: A la lista se le asigna un nuevo nodo.

[retorno de la funcion = No tiene retorno]
[nombre de la funcion = insertarNodo]
[datos que necesita mi funcion = La lista a la que se va a insertar y la estructura del tipo que sea: (Vino, Usuario o Membresia)])
*/
void insertarNodo(Nodo *&lista,void *n);

/*
  PRE : La lista tiene que estar creada y con por lo menos un nodo cargado.
  POST: Se muestra la lista de circulos

[retorno de la funcion = No tiene retorno]
[nombre de la funcion = mostrarListaDeVinos]
[datos que necesita mi funcion = Una lista que contenga una estructura del tipo vino])
*/
void mostrarListaDeVinos(Nodo *lista);

/*
  PRE : La lista tiene que estar creada y con por lo menos un Nodo.
  POST: La lista queda sin nodos.

[retorno de la funcion = No tiene retorno]
[nombre de la funcion = vaciarLista]
[datos que necesita mi funcion = La lista que se va a vaciar])
*/

void vaciarLista( Nodo *& lista);

/*
  PRE : La lista tiene que estar creada y con por lo menos un nodo.
  POST: Se remueve el nodo de la lista, en la posicion que se indique.

[retorno de la funcion = No tiene retorno]
[nombre de la funcion = eliminarNodo]
[datos que necesita mi funcion = La lista a la que se le va a eliminar el nodo y la posicion del nodo que quiere eliminar -comienza en 0 (cero)-])
*/

void eliminarNodo(Nodo *&lista, int indiceP);

/*---------------------------------------------------------------*/

/*
  PRE : La lista tiene que estar creada vacia y el archivo.txt tiene que existir.
  POST: Se carga la lista con el archivo que tiene el catalogo de vinos.

[retorno de la funcion = Retorna la lista cargada con sus respectivos Vinos]
[nombre de la funcion = cargarCatalogoDeVinos]
[datos que necesita mi funcion = Una lista vacia y el nombre del archivo .txt que contienen los datos])
*/

Nodo* cargarCatalogoDeVinos(Nodo *lista,string nombreFile);


#endif // LISTAVOID_H_INCLUDED

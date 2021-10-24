#ifndef LISTAVOID_H_INCLUDED
#define LISTAVOID_H_INCLUDED
#include <sstream>
#include "Vino.h"
#include "Cliente.h"
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
  PRE : La lista tiene que estar creada y cargada.
  POST: Te devuelve el nodo, en la posicion pasada por parametro, siempre y cuando exista.

[retorno de la funcion = Retorna un Nodo de la lista]
[nombre de la funcion = obtenerNodoPorPosicion]
[datos que necesita mi funcion = Una lista, y la posicion del Nodo que quiero obtener de esa lista])
*/

Nodo* obtenerNodoPorPosicion(Nodo *&lista, int posicion);

/*
  PRE : La lista tiene que estar creada y con por lo menos un nodo cargado.
  POST: Se muestra la lista de vinos.

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

/*---------------------------------------------------------------*/

/*
  PRE : La lista de vinos tiene que estar creada y con los vinos ya precargados.
  POST: Devuelve una lista con los id de los vinos y una variable entera que permite la contabilidad de los mismos.

[retorno de la funcion = Retorna la lista cargada con los contadores de vinos]
[nombre de la funcion = cargarContadorDeVinos]
[datos que necesita mi funcion = La lista de vinos])
*/
Nodo* InicializarContadorDeVinos( Nodo *listaDeVinos);
//----------------------------------------------------------------------------------------------


/*
  PRE : La lista de contabilidad de  vinos tiene que estar creada y el id del vino tiene que existir en la misma.
  POST: suma uno al id del vino indicado.

[retorno de la funcion = Retorno la lista de contador de vinos, actualizada]
[nombre de la funcion = sumarUnoAlIdVino]
[datos que necesita mi funcion = La lista que tiene los contadores de los vinos, y el id del vino al cual hay que sumarle uno])
*/

Nodo* sumarUnoAlIdVino(Nodo *&listaContadorVinos, int idVino);

//----------------------------------------------------------------------------------------------

/*
  PRE : La lista de vinos tiene que estar creada y el id del vino tiene que existir.
  POST: Devuelve el Nodo donde se encuentra el vino buscado.

[retorno de la funcion = Devuelve el nodo, con un dato de tipo Vino]
[nombre de la funcion = obtenerNodoVino]
[datos que necesita mi funcion = La lista de los vinos, y el id del vino que se va a buscar])
*/

Vino* obtenerNodoVino(Nodo *nodoVino,Nodo *&listaVinos, int idVino);
//----------------------------------------------------------------------------------------------


Nodo* cargarCatalogoDeClientes(Nodo *lista,string nombreFile);

/*
  PRE : La lista tiene que estar creada y con por lo menos un nodo cargado.
  POST: Se muestra la lista de Clientes

[retorno de la funcion = No tiene retorno]
[nombre de la funcion = mostrarListaDeClientes]
[datos que necesita mi funcion = Una lista que contenga una estructura del tipo Cliente])
*/
void mostrarListaDeClientes(Nodo *lista);

/*-----------------------------------------------------------------------------------------------*/
Nodo* cargarCatalogoDeMembresia(Nodo *lista,string nombreFile);

/*
  PRE : La lista tiene que estar creada y con por lo menos un nodo cargado.
  POST: Se muestra la lista de Membresia

[retorno de la funcion = No tiene retorno]
[nombre de la funcion = mostrarListaDeMembresia]
[datos que necesita mi funcion = Una lista que contenga una estructura del tipo Membresia])
*/
void mostrarListaDeMembresia(Nodo *lista);

/*-----------------------------------------------------------------------------------------------*/

/*
  PRE : La lista tiene que estar previamente creada.
  POST: Ordenada la lista de Contadores, de mayor a menor basandose en la cantidad.

[retorno de la funcion = No tiene retorno]
[nombre de la funcion = insertarContadorDescendentemente]
[datos que necesita mi funcion = Una lista vacia y una estructura de tipo Contador a agregar a la misma])
*/

void insertarContadorDescendentemente (Nodo *&listaAOrdenar, void *contador);

/*-----------------------------------------------------------------------------------------------*/
/*
  PRE : Las lista de membresia (creada y cargada), la lista contabilizadora de vinos (creada y cargada) , la lista de vinos (creada y cargada) y el anio tiene que estar previamente
  ingresado por el usuario.
  POST: Devuelve el ranking de vinos de forma descendente de acuerdo al anio ingresado por el usuario.

[retorno de la funcion = No tiene retorno ]
[nombre de la funcion = rankingDeVinos]
[datos que necesita mi funcion = lista de Membresia, lista contabilizado de Vinos, Lista de vinos y el anio ingresado por el usuario])
*/

void rankingDeVinos(Nodo *listaDeMembresia, Nodo *listaContabilizadoraDeVinos,Nodo *listaDeVinos);

/*-----------------------------------------------------------------------------------------------*/

/*
  PRE : La lista de clientes tiene que estar previamente creada y cargada con los clientes.
  POST: Devuelve un punto de tipo Cliente, que coincida con el idCliente ingresado por parametro.

[retorno de la funcion = Retorna un puntero de tipo Cliente ]
[nombre de la funcion = obtenerClientePorId]
[datos que necesita mi funcion = La lista de clientes y  el id del cliente a obtener])
*/

Cliente* obtenerClientePorId(Nodo *listaDeClientes,int idCliente);

/*-----------------------------------------------------------------------------------------------*/

/*
  PRE :
  - La lista de membresia, lista de vinos y lista de clientes tienen que estar previamente cargadas y creadas.
  - El usuario tiene que elejir de que rango etario quiere obtener el ranking de varietales.

  POST: Muestra por consola el ranking de varietales, segun el rango etario seleccionado.

[retorno de la funcion = No tiene retorno.]
[nombre de la funcion = rankingDeVarietales]
[datos que necesita mi funcion :  La lista de membresia, la lista de vinos, la lista de clientes y el rango etario (1,2,3)])
*/

void rankingDeVarietales(Nodo *listaDeMembresia,Nodo *listaDeVinos,Nodo *listaDeClientes,int rangoEtario);

/*----------------------------------------------------------------------------------------------------*/

/*
  PRE : Debe crearse la lista de varietales.
  POST: Devuelve la lista de varietales actualizada, ya sea con un contador nuevo o la actualizacion de la cantidad de alguno.

[retorno de la funcion = retorna el puntero head de la lista de varietales]
[nombre de la funcion = updateContadorDeVarietales]
[datos que necesita mi funcion = La lista de varietales, la cantidad de vinos de ese mismo ID, y el varietal del mismo vino])
*/

Nodo* updateContadorDeVarietales(Nodo *&listaDeVarietales, int cantidad, string varietal);

/*-----------------------------------------------------------------------------------------------*/

/*
  PRE : Debe crearse una lista de varietales a ordenar, y un contador de tipo Varietal.
  POST: Ordena la lista de varietales ascendentemente, segun la cantidad de los contadores.

[retorno de la funcion = No tiene retorno]
[nombre de la funcion = insertarContadorVarietalDescendentemente]
[datos que necesita mi funcion = La lista de varietales a ordenar y un contador de tipo ContadorVarietal])
*/

void insertarContadorVarietalDescendentemente (Nodo *&listaAOrdenar, void *contador);

/*-----------------------------------------------------------------------------------------------*/

#endif // LISTAVOID_H_INCLUDED

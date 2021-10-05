#ifndef LISTAVINO_H_INCLUDED
#define LISTAVINO_H_INCLUDED


/* Tipo de Informacion que esta contenida en los Nodos de la
   Lista, identificada como Dato. */
typedef void* PtrDato;

/* Tipo de Estructura de los Nodos de la Lista. */
struct NodoListaVino{
    PtrDato ptrDato; //dato almacenado
    NodoListaVino* sgte;// puntero al siguiente

};


typedef NodoListaVino* PtrNodoLista;

/* Tipo de Estructura de la Lista */
struct ListaVino{

    PtrNodoListaVino primero; //puntero al primer nodo de la lista

};


/******************************************************************************/
/* Definicion de Primitivas */

/*----------------------------------------------------------------------------*/

/*
    PRE: La lista no debe haber sido creada.
    POST: ListaVino queda creada y preparada para ser usada.
    ATRIBUTOS: ListaVino.
    RETORNO: No aplica.
*/

void crearListaVino(Vino& vino);

/*
    PRE: Lista Creada con crearListaFigura().
    POST: Devuelve true si lista esta vacia, sino devuelve false.
    ATRIBUTOS: ListaFigura.
    RETORNO: true o false.
*/

bool listaVacia(Vino& vino);

/*
    PRE: Lista Creada con crearListaVino().
    POST: Devuelve la representacion de lo Siguiente al último Nodo de la lista,
    o sea el valor Null, que en esta implementacion representa el final de la ListaVino.
    ATRIBUTOS: No aplica.
    RETORNO: PtrNodoListaVino.
*/

PtrNodoListaVino finLista();

/*
    PRE: Lista Creada con crearListaVino().
    POST: Devuelve el puntero al primer elemento de la lista, o devuelve finLista() si esta vacia.
    ATRIBUTOS: ListaVino.
    RETORNO: Puntero al primer nodo.
*/

PtrNodoListaVino primero(ListaVino& lista);

/*
    PRE: Lista Creada con crearListaVino().
    POST: Devuelve el puntero al nodo proximo del apuntado, o devuelve finLista()
    si ptrNodo apuntaba a finLista() o si lista esta vacia.
    ATRIBUTOS: ListaVino, ptrNodoListaVino.
    RETORNO: Puntero al nodo siguiente.
*/

PtrNodoListaVino siguiente(ListaVino& lista, PtrNodoListaVino ptrSig);

/*
    PRE: El vino debe ser creada con el TDA Vino.
    POST: Retorna ptrNodoListaVino.
    ATRIBUTOS: Vino.
    RETORNO: PtrNodoListaVino.
*/

PtrNodoListaVino crearNodo(Vino vino);

/*
    PRE: Lista creada con crearListaVino().
    POST: Agrega un nodo despues del apuntado por ptrNodo con el dato
    proporcionado y devuelve un puntero apuntado al elemento insertado.
    Si la lista esta vacía agrega un nodo al principio de esta y devuelve
    un puntero al nodo insertado. Si ptrNodo apunta a finLista() no inserta
    nada y devuelve finLista().
    ATRIBUTOS: ListaVino,Vino, PtrNodoListaVino.
    RETORNO: Puntero al nodo adicionado.
*/

PtrNodoListaVino adicionarDespues(ListaVino& lista, Vino vino, PtrNodoListaVino ptr);

/*
    PRE: Lista creada con crearListaVino().
    POST: Agrega un nodo al final de la lista con el dato proporcionado y devuelve un puntero al nodo insertado.
    ATRIBUTOS: ListaVino,Vino.
    RETORNO: Puntero al nodo adicionado.
*/

PtrNodoListaVino adicionarFinal(ListaVino lista,Vino vino);

/*
    PRE: Lista creada con crearListaVino().
    POST: Al principio de la lista se adiciona el vino.
    ATRIBUTOS: ListaVino, Vino.
    RETORNO: PtrNodoListaVino.
*/

PtrNodoListaVino adicionarPrimero(ListaVino& lista,Vino vino);

/*
    PRE: Lista creada con crearListaVino().ptrNodo es un puntero a un nodo de lista.
    POST: Devuelve el puntero al nodo anterior del apuntado, o devuelve finLista() si
    ptrNodo apuntaba al primero o si lista esta vacia.
    ATRIBUTOS: ListaVino, PtrNodoListaVino.
    RETORNO: Puntero al nodo anterior.
*/

PtrNodoListaVino anterior(ListaVino& lista, PtrNodoListaVino ptroNodo);

/*
    PRE: Lista creada con crearListaVino().
    POST: Devuelve el puntero al ultimo nodo de la lista, o devuelve finLista() si lista esta vacia.
    ATRIBUTOS: ListaVino.
    RETORNO: Puntero al ultimo nodo.
*/

PtrNodoListaVino ultimo(ListaVino& vino);

/*
    PRE: Lista creada con crearListaVino(), no vacia. ptrNodo es distinto de finLista().
    POST: Devuelve el dato del nodo apuntado por ptrNodo.
    ATRIBUTOS: ListaVino, Vino, PtrNodoListaVino.
    RETORNO: Puntero al nodo del cual se quiere obtener el dato.
*/

void obtenerDato(ListaVino& lista, Vino& vino, PtrNodoListaVino ptrNodo);

/*
    PRE: Lista fue creada con crearListaVino().
    POST: Elimina el nodo apuntado por ptrNodo. No realiza accion si la lista
    esta vacia o si ptrNodo apunta a finLista().
    ATRIBUTOS: ListaVino, PtrNodoListaVino.
    RETORNO: No aplica.
*/

void eliminarNodoListaVino(Vino& vino, PtrNodoListaVino ptrNodo);

/*
    PRE: Lista fue creada con crearListaVino().
    POST: Elimina todos los Nodos de la lista quedando destruida e inhabilitada para su uso.
    ATRIBUTOS: ListaVino.
    RETORNO: No aplica.
*/

void eliminarLista(ListaVino& lista);

};

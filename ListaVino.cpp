#include "ListaVino.h"

void crearListaVino(ListaVino& lista)
{
	lista.primero = finLista();
}


bool listaVacia(ListaVino& lista)
{
	return primero(lista) == finLista();
}


PtrNodoListaVino finLista()
{
	return NULL;
}

PtrNodoListaVino primero(ListaVino& lista)
{
	return lista.primero;
}

PtrNodoListaVino siguiente(ListaVino& lista, PtrNodoListaVino ptrSig)
{
	PtrNodoListaVino aux;
	if ((!listaVacia(lista)) && (ptrSig != finLista()))
		aux = ptrSig->sgte;
	else
		aux = finLista();
	return aux;

}


PtrNodoListaVino crearNodo(Vino vino)
{
	PtrNodoListaVino aux = new NodoListaVino;
	aux->vino = vino;
	aux->sgte = finLista();
	return aux;
}

PtrNodoListaVino adicionarDespues(ListaVino& lista,Vino vino, PtrNodoListaVino ptr)
{
	PtrNodoListaVino nvoNodo = finLista();
	if (listaVacia(lista))
		nvoNodo = adicionarPrimero(lista, vino);
	else
	{
		nvoNodo = crearNodo(vino);
		nvoNodo->sgte = ptr->sgte;
		ptr->sgte = nvoNodo;
	}
	return nvoNodo;
}


PtrNodoListaVino adicionarFinal(ListaVino lista,Vino vino)
{
	return adicionarDespues(lista, vino, ultimo(lista));
}

PtrNodoListaVino adicionarPrimero(ListaVino& lista,Vino vino)
{
	PtrNodoListaVino aux = crearNodo(vino);
	aux->sgte = lista.primero;
	lista.primero = aux;
	return aux;
}

PtrNodoListaVino anterior(ListaVino& lista, PtrNodoListaVino ptroNodo)
{
	PtrNodoListaVino ptrPrevio = finLista();
	PtrNodoListaVino Ptrocursor = primero(lista);
	while (Ptrocursor != finLista() && Ptrocursor != ptroNodo)
	{
		ptrPrevio = Ptrocursor;
		Ptrocursor = siguiente(lista, Ptrocursor);
	}
	return ptrPrevio;
}

PtrNodoListaVino ultimo(ListaVino& lista)
{
	return anterior(lista, finLista());
}


void obtenerDato(ListaVino& lista, Vino& vino, PtrNodoListaVino ptrNodo)
{
	if ((!listaVacia(lista)) && (ptrNodo != finLista()))
		figura = ptrNodo->figura;
}

void eliminarNodoListaVino(ListaVino& lista, PtrNodoListaVino ptrNodo)
{
	PtrNodoListaVino ptrPrevio;

	/* verifica que la lista no esté vacia y que nodo no sea finListaVino*/
	if ((!listaVacia(lista)) && (ptrNodo != finLista())) {

		if (ptrNodo == primero(lista))
		{
			lista.primero = siguiente(lista, primero(lista));
		}
		else
		{
			ptrPrevio = anterior(lista, ptrNodo);
			ptrPrevio->sgte = ptrNodo->sgte;
		}

		delete ptrNodo;
	}
}

void eliminarLista(ListaVino& lista)
{
	/* retira uno a uno los nodos de la lista */
	while (!listaVacia(lista))
		eliminarNodoListaVino(lista, primero(lista));
}



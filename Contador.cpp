#include "Contador.h"



Contador* crearContadorVacio(Contador *contador) {
    contador = new Contador();
    return contador;
}

Contador* crearContador(Contador *contador,int idVino){
    contador = new Contador();
    contador->idVino = idVino;
    contador->cantidad = 0;
}

int getContadorIdVino(Contador *contador) {
    return contador->idVino;
}

int getContadorCantidad(Contador *contador) {
    return contador->cantidad;
}


void setContadorIdVino(Contador *contador,int idVino){
    contador->idVino = idVino;
}

void setContadorCantidad(Contador *contador, int cantidad){
    contador->cantidad = cantidad;
}




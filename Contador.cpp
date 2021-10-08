#include "Contador.h"


Contador* crearContador(Contador *contador,int idVino){
    contador = new Contador();
    contador->idVino = idVino;
    contador->cantidad = 0;
}


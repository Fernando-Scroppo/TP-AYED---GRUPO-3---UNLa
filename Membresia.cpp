#include <iostream>
#include <stdlib.h>
#include "Membresia.h"

using namespace std;

/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

/*----------------------------------------------------------------------------*/
Membresia* crearMembresiaVacia(Membresia *membresia) {
    membresia = new Membresia();
    return membresia;
}

/*----------------------------------------------------------------------------*/
Membresia* crearMembresia(Membresia *membresia, int idUsuario,int mes,int anio,array vinos[5]) {
    membresia = new Membresia();
    setIdUsuario(membresia,idUsuario);
    setMes(membresia,mes);
    setAnio(membresia,anio);
    setArrayVinos(membresia,vinos);
    return membresia;
}

/*----------------------------------------------------------------------------*/
void destruirMembresia(Membresia *membresia) {
    delete membresia;
}

/*----------------------------------------------------------------------------*/
void setIdUsuario(Membresia *membresia, int idUsuario) {
    membresia->idUsuario = idUsuario;

/*----------------------------------------------------------------------------*/
int getIdUsuario(Membresia *membresia) {
    return membresia->idUsuario;
}

int getMes(Membresia *membresia) {
    return membresia->mes_de_la_seleccion;
}

/*----------------------------------------------------------------------------*/
void setMes(Membresia *membresia, int mes) {
    membresia->mes_de_la_seleccion = mes;
}


/*----------------------------------------------------------------------------*/
int getAnio(Membresia *membresia) {
    return membresia->año_seleccion;
}

void setAnio(Membresia *membresia, int anio) {
    membresia->año_seleccion = anio;
}

/*----------------------------------------------------------------------------*/
void setArray(Membresia *membresia, array vinos) {
    membresia->vinos = vinos;
}

/*----------------------------------------------------------------------------*/
array getArray(Membresia *membresia) {
    return membresia->vinos;
}

/*----------------------------------------------------------------------------*/

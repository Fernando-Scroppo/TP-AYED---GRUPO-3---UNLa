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
Membresia* crearMembresia(Membresia *membresia, int idUsuario,int mes,int anio,int vinos[]) {
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
}
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
    return membresia->anio_seleccion;
}

void setAnio(Membresia *membresia, int anio) {
    membresia->anio_seleccion = anio;
}

/*----------------------------------------------------------------------------*/
void setArrayVinos(Membresia *membresia, int vinos[]) {
    membresia->vinos[] = vinos[];
}

/*----------------------------------------------------------------------------*/
int getArrayVinos(Membresia *membresia) {
    return membresia->vinos;
}

/*----------------------------------------------------------------------------*/

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
//Pasar la direccion de memoria membresia, puntero integer.
void setArrayVinos(Membresia *membresia, int vinosP[]) {

    for(int i=0; i<=5 ; i++){
        membresia->vinos[i] = vinosP[i];
    }

}

/*----------------------------------------------------------------------------*/
int* getArrayVinos(Membresia *membresia) {
<<<<<<< HEAD
    return membresia->vinos;
    //https://www.youtube.com/watch?v=rxAUwddWfQk
    //como tomar  el puntero que devuelve.
=======

    for(int i=0; i<=5 ; i++){
       cout<<" vino: "<<i+1<<" es :"<<membresia->vinos[i]<<endl;
       //return membresia-> &vinos[i];
    }



>>>>>>> 43c9c7af22d51e05e13066216016b16b7682f566
}

/*----------------------------------------------------------------------------*/

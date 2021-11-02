#include "ContadorBodega.h"

ContadorBodega* crearContadorBodega(ContadorBodega *contadorBodega,string bodega){
    contadorBodega = new ContadorBodega();
    contadorBodega->bodega = bodega;
    contadorBodega->cantidad = 0;
}

ContadorBodega* crearContadorVacioBodega(ContadorBodega *contadorBodega) {
    contadorBodega = new ContadorBodega();
    return contadorBodega;
}

string getContadorBodega(ContadorBodega *contadorBodega) {
    return contadorBodega->bodega;
}


int getContadorCantidadBodega(ContadorBodega *contadorBodega) {
    return contadorBodega->cantidad;
}


void setContadorCantidadBodega(ContadorBodega *contadorBodega, int cantidad){
    contadorBodega->cantidad = cantidad;
}

void setContadorBodega(ContadorBodega *contadorBodega,string bodega){
    contadorBodega->bodega = bodega;
}

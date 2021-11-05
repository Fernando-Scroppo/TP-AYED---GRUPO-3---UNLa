#include "ContadorVarietal.h"


ContadorVarietal* crearContadorVarietal(ContadorVarietal *contador,string varietal){
    contador = new ContadorVarietal();
    contador->varietal = varietal;
    contador->cantidad = 0;
}

ContadorVarietal* crearContadorVarietalVacio(ContadorVarietal *contador) {
    contador = new ContadorVarietal();
    return contador;
}

string getContadorObtenerVarietal(ContadorVarietal *contador){
    return contador->varietal;
}

int getContadorVarietalCantidad(ContadorVarietal *contador) {
    return contador->cantidad;
}


void setContadorVarietal(ContadorVarietal *contador, string varietal){
    contador->varietal = varietal;
}

void setContadorVarietalCantidad(ContadorVarietal *contador, int cantidad){
    contador->cantidad = cantidad;
}

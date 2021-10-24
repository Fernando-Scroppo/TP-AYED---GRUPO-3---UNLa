#include "ContadorVarietal.h"


ContadorVarietal* crearContador(ContadorVarietal *contador,string varietal){
    contador = new ContadorVarietal();
    contador->varietal = varietal;
    contador->cantidad = 0;
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

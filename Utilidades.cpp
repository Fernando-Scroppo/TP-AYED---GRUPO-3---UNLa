#include "Utilidades.h"


string removerEspacios(string cadena){

   string contenido="";

   for(int i= 0; i<cadena.length();i++){
                //El codigo 32 es para los espacios. 32 == "" y el codigo 9 es para las tabulaciones
                if(cadena.at(i)==9 || cadena.at(i)==32){
                     //Se agrega los espacios entre medio de la palabra
                    if(i>0&&i<(cadena.length()-1)&&cadena.at(i-1)!=32 && cadena.at(i+1)!=32){
                        contenido += cadena.at(i);
                    }
                } else{
                        //Agrego la letra a la palabra.
                       contenido += cadena.at(i);
                }
            }

    return contenido;
}

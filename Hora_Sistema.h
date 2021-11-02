#ifndef HORA_SISTEMA_H_INCLUDED
#define HORA_SISTEMA_H_INCLUDED


#include<iostream>
#include<ctime>
using namespace std;
// Inicio funcion mostrar hora
void hora_sistema(void){
	// Inicializacion de hora
   time_t now = time(0);
   tm *ltm = localtime(&now);
   // Impresion y validacion de hora
   if(ltm->tm_hour>=12){// Si hora es mayor o igual a las 12 pm entonces...
   	cout<<"\t\t\t                Hora del Sistema: "<<ltm->tm_hour<<":"<<ltm->tm_min<<" pm."<<endl<<endl;
   }else{// De lo contrario...
   	cout<<"\t\t\t                Hora del Sistema: "<<ltm->tm_hour<<":"<<ltm->tm_min<<" am."<<endl<<endl;
   }// Fin if else ltm->tm_hour validacion
}// Fin funcion mostrar hora

#endif // HORA_SISTEMA_H_INCLUDED

#include <iostream>
#include "Vino.h"
#include "Cliente.h"
#include "lista.h"
using namespace std;

int main()
{
    //Inicializo las listas
    Nodo *listaDeVinos = crearLista();
    Nodo *listaDeClientes = crearLista();

    //Cargo la lista con el catalogo de vinos.
    listaDeVinos = cargarCatalogoDeVinos(listaDeVinos,"catalos_test.txt");
    listaDeClientes= cargarCatalogoDeClientes(listaDeClientes,"usuarios_test.txt");
    int opcion;

    do{
        cout<<"\t.:SISTEMA DE RANKINGS:."<<endl;
        cout<<"1. Ranking General de Vinos seleccionados en el ultimo a?o"<<endl;
        cout<<"2. Ranking por bodegas elejidas en el ultimo a?o"<<endl;
        cout<<"3. Ranking por bodegas elejidas en el ultimo a?o"<<endl;
        cout<<"4. Mostrar la lista de Vinos cargada"<<endl;
        cout<<"5. Mostrar la lista de Clientes cargada"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cin>>opcion;

        switch(opcion){

        case 4:
            mostrarListaDeVinos(listaDeVinos);
            system("pause");
            break;


        case 5:
            mostrarListaDeClientes(listaDeClientes);
            system("pause");
            break;
        }



        system("cls");
    } while(opcion != 0);


    return 0;
}

#include <iostream>
#include "Vino.h"
#include "Cliente.h"
#include "lista.h"
#include "Membresia.h"
using namespace std;

int main()
{

    system("color 0b");
    //Inicializo las listas
    Nodo *listaDeVinos = crearLista();
    Nodo *listaDeClientes = crearLista();
    Nodo *listaContabilizadoraDeVinos = crearLista();
    Nodo *listaDeMembresia= crearLista();


    //Cargo la lista con el catalogo de vinos.
    listaDeVinos = cargarCatalogoDeVinos(listaDeVinos,"catalos_test.txt");
    listaDeClientes= cargarCatalogoDeClientes(listaDeClientes,"usuarios_test.txt");


    //Se carga la lista de vinos en una lista auxiliar para realizar la contabilidad
    listaContabilizadoraDeVinos = InicializarContadorDeVinos(listaDeVinos);

    /* Ejemplo para obtener una posicion.
    Nodo *nodoObtener = obtenerNodoPorPosicion(listaDeVinos,2);
    //Vino* vino;
    Vino* vino = crearVinoVacio(vino);
    vino = (Vino*)nodoObtener->dato;
    cout<<vino->idVino<<endl;
    system("pause");*/

    listaDeMembresia=cargarCatalogoDeMembresia(listaDeMembresia,"elecion_test.txt");

    int opcion;
    int anio;
    Nodo *nodoVino;
    Vino* vino = crearVinoVacio(vino);

    do{
        cout<<"\t.:SISTEMA DE RANKINGS:."<<endl;
        cout<<"1. Ranking General de Vinos seleccionados por año"<<endl;
        cout<<"2. Ranking por bodegas elejidas en el ultimo año"<<endl;
        cout<<"3. Ranking de varietales elegidos por rango etario"<<endl;
        cout<<"4. Mostrar la lista de Vinos cargada"<<endl;
        cout<<"5. Mostrar la lista de Clientes cargada"<<endl;
        cout<<"6. Mostrar la lista de Membresia cargada"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cin>>opcion;


        switch(opcion){

        case 1:
            cout<<"El ranking de vinos correspodiente a que año quiere obtener:"<<endl;
            cin>>anio;
            rankingDeVinos(listaDeMembresia,listaContabilizadoraDeVinos,listaDeVinos,anio);
            break;

        case 4:
            mostrarListaDeVinos(listaDeVinos);
            system("pause");
            break;


        case 5:
            mostrarListaDeClientes(listaDeClientes);
            system("pause");
            break;


        case 6:
            mostrarListaDeMembresia(listaDeMembresia);
            system("pause");
            break;
        }



        system("cls");
    } while(opcion != 0);


    //Elimino las listas
    vaciarLista(listaDeVinos);
    vaciarLista(listaDeClientes);
    vaciarLista(listaContabilizadoraDeVinos);
    vaciarLista(listaDeMembresia);

    return 0;
}

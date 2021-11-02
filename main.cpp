#include <iostream>
#include "Vino.h"
#include "Cliente.h"
#include "lista.h"
#include "Membresia.h"
#include "Hora_Sistema.h"
using namespace std;

int main()
{
/*
  Autores: Fernando Scroppo, Yago Rexad, Alan Bruoni, Erika Valdez.
  Curso: Algoritmos & Estructura de Datos
  Ejercicio: TRABAJO PRACTICO INTEGRADOR DE LA CARRERA
  IDE: CodeBlocks */


    system("color 0b");
    //Inicializo las listas
    Nodo *listaDeVinos = crearLista();
    Nodo *listaDeClientes = crearLista();
    Nodo *listaContabilizadoraDeVinos = crearLista();
    Nodo *listaDeMembresia= crearLista();
    Nodo *listaContabilizadoraDeBodegas=crearLista();

    //Cargo la lista con el catalogo de vinos.
    listaDeVinos = cargarCatalogoDeVinos(listaDeVinos,"catalos_test.txt");
    listaDeClientes= cargarCatalogoDeClientes(listaDeClientes,"usuarios_test.txt");


    //Se carga la lista de vinos en una lista auxiliar para realizar la contabilidad
    listaContabilizadoraDeVinos = InicializarContadorDeVinos(listaDeVinos);
    listaContabilizadoraDeBodegas =InicializarContadorDeBodegas(listaDeVinos);
    listaDeMembresia=cargarCatalogoDeMembresia(listaDeMembresia,"elecion_test.txt");

    int opcion;
    int rangoEtario;

    Cliente* cli = new Cliente();
    //string atributo;

    do{
            cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"                               \t\t .:SISTEMA DE RANKINGS:. "<<endl<<endl;
			cout<<"                   \t\t  .:ALGORITMOS Y ESTRUCTURAS DE DATOS:.\t   "<<endl<<endl;
                        hora_sistema();// Invoca a funcion para mostrar hora actual del sistema
            cout<<"------------------------------------------------------------------------------------------------------------------------\n";




        cout<<"1. Ranking General de Vinos seleccionados por año"<<endl;
        cout<<"2. Ranking por bodegas elejidas en el ultimo año"<<endl;
        cout<<"3. Ranking de varietales elegidos por rango etario"<<endl;

         cout<<"\n.:FUNCIONES UTILES:.\n"<<endl;
        cout<<"4. Opcion Para ver Listas"<<endl;
        cout<<"0. Salir del programa"<<endl;
        cin>>opcion;


        switch(opcion){

        case 1:
            rankingDeVinos(listaDeMembresia,listaContabilizadoraDeVinos,listaDeVinos);
            break;

        case 2:
            rankingDeBodegas(listaDeMembresia,listaContabilizadoraDeVinos,listaContabilizadoraDeBodegas,listaDeVinos);
            break;

        case 3:
            cout<<"El ranking de varietales correspondiente a que grupo etario quiere obtener:"<<endl;
            cout<<"1. Menores de 30 años"<<endl;
            cout<<"2. Entre 30 y 50 años"<<endl;
            cout<<"3. Mayores de 50 años"<<endl;
            cin>>rangoEtario;
            rankingDeVarietales(listaDeMembresia,listaDeVinos,listaDeClientes,rangoEtario);
            break;

        case 4:

            char opcion;

             do {
                    cout << "\n " << endl;
                    cout << "==========================================================" << endl;
                    cout << "1. Mostrar la lista de Vinos cargada" << endl;
                    cout << "2. Mostrar la lista de Clientes cargada" << endl;
                    cout << "3. Mostrar la lista de Membresia cargada" << endl;
                    cout<<  "4. Mostrar la lista de Bodegas cargada"<<endl;
                    cout << "=========================================================" << endl;
                    cout << "Elije una opcion: ";

                            cin >> opcion;

                            switch(opcion)
                            {
                                case '1':

                                    system("cls");
                                    cout << "1. Mostrar la lista de Vinos cargada" << endl;
                                    mostrarListaDeVinos(listaDeVinos);
                                    system("pause");
                                    break;

                                case '2':
                                    system("cls");
                                    cout << "2. Mostrar la lista de Clientes cargada" << endl;
                                    mostrarListaDeClientes(listaDeClientes);
                                    system("pause");
                                    break;

                                case '3':
                                    system("cls");
                                    cout << "3. Mostrar la lista de Membresia cargada" << endl;
                                    mostrarListaDeMembresia(listaDeMembresia);
                                    system("pause");
                                    break;
                                case '4':
                                    system("cls");
                                    cout<<  "4. Mostrar la lista de Bodegas cargada"<<endl;
                                    mostrarListaDeLasBodegas(listaContabilizadoraDeBodegas);
                                    system("pause");
                                    break;

                                default:
                                    cout << "\n\nOPCION NO VALIDA" << endl;
                                    break;
                            }
                            system("cls");
                        } while (opcion != '4');


        }


        system("cls");
    } while(opcion != 0);


    //Elimino las listas
    vaciarLista(listaDeVinos);
    vaciarLista(listaDeClientes);
    vaciarLista(listaContabilizadoraDeVinos);
    vaciarLista(listaDeMembresia);
    vaciarLista(listaContabilizadoraDeBodegas);

    return 0;
}

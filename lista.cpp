#include "lista.h"
#include "Vino.h"
#include "Cliente.h"
#include "Contador.h"
#include "Membresia.h"
#include <fstream>
#include <iostream>

using namespace std;

/******************************************************************************/
/* Implementacion de Primitivas */

/* Metodos de la lista */

Nodo* crearLista(){
     Nodo *lista = new Nodo();
     lista = NULL;
     return lista;
}

Nodo* obtenerNodoPorPosicion(Nodo *lista, int posicion){

    int indice = 0;

    if(lista != NULL){

        Nodo *aux_lista;
        Nodo *anterior = NULL;
        aux_lista = lista;

        //Mientras que no encuentre la posicion que quiero borrar continua.
        while((aux_lista != NULL)&& (indice != posicion )){
            anterior = aux_lista;
            aux_lista = aux_lista->siguiente;
            indice++;
        }

        //En este caso nunca entro al While por la tanto el elemento que quiere borrar no existe
        if(aux_lista == NULL){
            cout<<"Esa posicion no existe en la lista"<<endl;
        }
        //El elemento que quiere eliminar esta al principio de la lista
        else if(anterior == NULL){
            return aux_lista;
        }
        //Si el elemento esta entre medio de la lista
        else{
            return aux_lista;
        }
    }
}


void insertarNodo(Nodo *&lista,void *n){

    //Creo un nuevo nodo, y le asigno los datos del vino.
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while(aux1 != NULL){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    //Primer nodo de la lista
    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        //Ultimo nodo de la lista.
        aux2->siguiente=nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;

    //YOUTUBE: https://www.youtube.com/watch?v=cPcDuIUqEO4&t=882s
}

void eliminarNodo(Nodo *&lista, int indiceP){

    int indice = 0;

    if(lista != NULL){

        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;

        //Mientras que no encuentre la posicion que quiero borrar continua.
        while((aux_borrar != NULL)&& (indice != indiceP )){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
            indice++;
        }

        //En este caso nunca entro al While por la tanto el elemento que quiere borrar no existe
        if(aux_borrar == NULL){
            cout<<"Esa posicion No existe en la lista"<<endl;
        }
        //El elemento que quiere eliminar esta al principio de la lista
        else if(anterior == NULL){
            lista = lista->siguiente;
            cout<<"El Nodo fue eliminado exitosamente de la lista"<<endl;
            delete aux_borrar;
        }
        //Si el elemento esta entre medio de la lista
        else{
            anterior->siguiente = aux_borrar->siguiente;
            cout<<"El Nodo fue eliminado exitosamente de la lista"<<endl;
            delete aux_borrar;
        }
    }

}

void vaciarLista( Nodo *& lista){
    void *n;
    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->siguiente;
    delete aux;
}

//****************************************************************************/

/* Metodos para manejar los Vinos */

void mostrarListaDeVinos(Nodo *lista){

    Vino* vino;
    vino = crearVinoVacio(vino);
    Nodo *actual = new Nodo();
    actual = lista;

if(actual == NULL){
    cout<<"La lista esta vacia"<<endl;
}
//Generamos la cabecera de la tabla
cout<<"|ID|"<<"ETIQUETA|"<<"BODEGA|"<<"SEGMENTO DEL VINO|"<<"VARIETAL|"<<"ANIO DE COSECHA|"<<"TERROIR|"<<endl;
while(actual != NULL)

    {   //CASTEO EL DATO A TIPO VINO, PARA OBTENER LA INFORMACION
        vino = (Vino*)actual->dato;
        cout<<"|"<<getIdVino(vino)<<"|"<<getEtiqueta(vino)<<"|"<<getBodega(vino)<<"|"<<getSegmento(vino)<<"|"<<getVarietal(vino)<<"|"<<getAnioCosecha(vino)<<"|"<<getTerroir(vino)<<"|"<<endl;
        actual = actual->siguiente;
    }

cout<<endl;

}

string removerEspacios(string cadena){

   string contenido="";

   for(int i= 0; i<cadena.length();i++){
                //El codigo 32 es para los espacios. 32 == ""
                if(cadena.at(i)==32){
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

Nodo* obtenerNodoVino(Nodo *listaVinos, int idVino){

    Vino* vino;
    vino = crearVinoVacio(vino);
    bool encontrado = 0;
    while(listaVinos != NULL && encontrado != 0){

        vino = (Vino*)listaVinos->dato;
        if(vino->idVino == idVino){
            encontrado = 1;
            return listaVinos;
        }
    }

}

Nodo* cargarCatalogoDeVinos(Nodo *lista, string nombreFile){

     //Variables del Vino
    int idVino;
    string etiqueta;
    string bodega ;
    string segmento_del_vino;
    string varietal;
    int anioCosecha;
    string terroir;

    string filename(nombreFile);
    string contenido;
    string line;
    int contador = 0;
    string atributo;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    }


    //Como levanta los datos, con el indice.
    while (getline(input_file, line,';')){
            for(int i= 0; i<line.length();i++){
                if( line.at(i)!= '-'){
                    contenido += line.at(i);
                }
                else{

                    atributo=removerEspacios(contenido);
                    //Cargamos los atributos de los vinos, obtenidos del txt en las variables.
                    switch(contador){

                    case 0:
                        idVino = stoi(atributo, nullptr, 10); //stoi transforma de String a INT.
                        break;
                    case 1:
                        etiqueta = atributo;
                        break;
                    case 2:
                        bodega = atributo;
                        break;
                    case 3:
                        segmento_del_vino = atributo;
                    case 4:
                        varietal = atributo;
                        break;
                    case 5:
                        anioCosecha = stoi(atributo, nullptr, 10);
                        break;
                    }
                    contador++;
                    contenido="";
                }
            }

             contador = 0;
             terroir = removerEspacios(contenido);
             contenido="";
             atributo="";
             //Creo el vino
             Vino* vino = crearVino(vino,idVino,etiqueta,bodega,segmento_del_vino,varietal,anioCosecha,terroir);
             insertarNodo(lista,vino);

    }
    input_file.close();
    return lista;
}

//ATENCION!!!,
void ordenarDescendentemente(Nodo *&listaContadorVinos){

    int aux;
    int pos = 0;
    int posIzquierda =0;
    Nodo* nodoIzquierdo;
    Nodo* nodoDerecho;
    Contador* contadorCambio = new Contador();
    while(listaContadorVinos != NULL){

        Contador* contador = (Contador*)listaContadorVinos->dato;
        aux = contador->cantidad;

        if(pos>0){
            Contador* contadorIzquierdo = (Contador*) obtenerNodoPorPosicion(listaContadorVinos,pos-1);
            posIzquierda = contadorIzquierdo->cantidad;
        }


        while((pos>0)&&(posIzquierda < aux)){
            nodoIzquierdo = obtenerNodoPorPosicion(listaContadorVinos,pos);
            nodoDerecho = obtenerNodoPorPosicion(listaContadorVinos,pos-1);
            nodoIzquierdo = nodoDerecho;
            pos--;
        }

        contadorCambio = (Contador*)nodoIzquierdo->dato;
        contadorCambio->cantidad = aux;
    }
}






void sumarUnoAlIdVino(Nodo *&listaContadorVinos, int idVino){

    bool encontrado = 0;
    while (listaContadorVinos != NULL && encontrado != 0){
        Contador* contador = (Contador*)listaContadorVinos->dato;
        if(contador->idVino == idVino){
            contador->cantidad =+1;
            encontrado = 1;
        }
        listaContadorVinos->siguiente;
    }
}



Nodo* InicializarContadorDeVinos( Nodo *listaDeVinos){

    Nodo *listaDeVinosAux = new Nodo();

    Nodo *listaNumeroVinos = new Nodo();

    while(listaDeVinos != NULL){
           listaDeVinosAux = listaDeVinos;
           Vino* vino = (Vino*)listaDeVinosAux->dato;
           Contador* numeroVino = crearContador(numeroVino,getIdVino(vino));
           insertarNodo(listaNumeroVinos,numeroVino);

           listaDeVinos = listaDeVinos->siguiente;
    }
    return listaNumeroVinos;
}

Nodo* rankingDeVinos(Nodo *listaDeMembresia, Nodo *listaDeVinos){

    Membresia* membresia;
    membresia = crearMembresiaVacia(membresia);
    Nodo *listaMembresiaAux = crearLista();
    Nodo *listarankingVinos = crearLista();
    Nodo *listaContadoraDeVinos = InicializarContadorDeVinos(listaDeVinos);
    int vueltas=0;
    int cantidadDeAnios;
    cout<<"Indicar la cantidad de años distintos de los cuales se debe obtener los ranking anuales"<<endl;
    cin>>cantidadDeAnios;
    int *pArray = new int[cantidadDeAnios];

    //Mientras se tengan anios para obtener el ranking se continua.
    while( vueltas < cantidadDeAnios ){

        while(listaDeMembresia != NULL){

            listaMembresiaAux = listaDeMembresia;
            membresia = (Membresia*)listaMembresiaAux->dato;
            for(int i=0; i<5 ; i++){
                if(membresia->anio_seleccion == pArray[vueltas]){
                    sumarUnoAlIdVino(listaContadoraDeVinos,membresia->vinos[i]);
                }
            }
        }

            vueltas=+1;
            //Ordenar la lista de contadora de vinos -- Chequear que ordene los contadores por cantidad.
            ordenarDescendentemente(listaContadoraDeVinos);
            //recorrerla y obtener por id los nodos de los vinos
            //ir cargando esos nodos en una lista nueva
            cout<<"RANKING ANUAL DE VINOS CORRESPONDIENTE AL AÑO: "<<pArray[vueltas]<<endl;
            //mostrar la lista de vinos

    }







}



//-----------------------------------------------------------------------------------------

// Clientes

Nodo* cargarCatalogoDeClientes(Nodo *lista, string nombreFile){

     //Variables del Cliente
    int id;
    string nombreYapellido;
    string direccion ;
    int edad;


    string filename(nombreFile);
    string contenido;
    string line;
    int contador = 0;
    string atributo;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    }


    //Como levanta los datos, con el indice.
    while (getline(input_file, line,';')){
            for(int i= 0; i<line.length();i++){
                if( line.at(i)!= '-'){
                    contenido += line.at(i);
                }
                else{

                    atributo=removerEspacios(contenido);
                    //Cargamos los atributos de los Clientes, obtenidos del txt en las variables.
                    switch(contador){

                    case 0:
                        id = stoi(atributo, nullptr, 10); //stoi transforma de String a INT.
                        break;
                    case 1:
                        nombreYapellido = atributo;
                        break;
                    case 2:
                        direccion = atributo;
                        break;
                    case 3:
                        edad = stoi(atributo, nullptr, 10);
                        break;
                    }
                    contador++;
                    contenido="";
                }
            }

             contador = 0;
             //edad = removerEspacios(contenido);
             contenido="";
             atributo="";
             //Creo el Cliente
             Cliente *cliente = crearCliente(cliente,id,nombreYapellido,direccion,edad);
             insertarNodo(lista,cliente);

    }
    input_file.close();
    return lista;
}

void mostrarListaDeClientes(Nodo *lista){

    Cliente* cliente;
    cliente = crearClienteVacio(cliente);
    Nodo *actual = new Nodo();
    actual = lista;

if(actual == NULL){
    cout<<"La lista esta vacia"<<endl;
}
//Generamos la cabecera de la tabla
cout<<"|ID|"<<"NOMBRE Y APELLIDO|"<<"DIRECCION|"<<"EDAD|"<<endl;
while(actual != NULL)

    {   //CASTEO EL DATO A TIPO CLIENTE, PARA OBTENER LA INFORMACION
        cliente = (Cliente*)actual->dato;
        cout<<"|"<<getIdCliente(cliente)<<"|"<<getNombreYapellido(cliente)<<"|"<<getDireccion(cliente)<<"|"<<getEdad(cliente)<<"|"<<endl;
        actual = actual->siguiente;
    }

cout<<endl;

}

/*-------------------------------------------------------------------------------------------------*/

//Membresia

Nodo* cargarCatalogoDeMembresia(Nodo *lista, string nombreFile){

     //Variables de Membresia
    int idUsuario;
    int mes_de_la_seleccion;
    int anio_seleccion ;
    int vinos[5];


    string filename(nombreFile);
    string contenido;
    string line;
    int contador = 0;
    string atributo;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    }


    //Como levanta los datos, con el indice.
    while (getline(input_file, line,';')){
            for(int i= 0; i<line.length();i++){
                if( line.at(i)!= '-'){
                    contenido += line.at(i);
                }
                else{

                    atributo=removerEspacios(contenido);
                    //Cargamos los atributos del TDA Membresia, obtenidos del txt en las variables.
                    switch(contador){

                    case 0:
                        idUsuario = stoi(atributo, nullptr, 10); //stoi transforma de String a INT.
                        break;
                    case 1:
                        mes_de_la_seleccion = stoi(atributo, nullptr, 10);
                        break;
                    case 2:
                        anio_seleccion = stoi(atributo, nullptr, 10);
                        break;

                    case 3:
                        vinos[0] = stoi(atributo, nullptr, 10);
                        break;

                    case 4:
                        vinos[1]= stoi(atributo, nullptr, 10);
                        break;

                    case 5:
                        vinos[2]= stoi(atributo, nullptr, 10);
                        break;

                    case 6:
                        vinos[3]= stoi(atributo, nullptr, 10);
                        break;

                    case 7:
                        vinos[4]= stoi(atributo, nullptr, 10);
                        break;

                    }


                    contador++;
                    contenido="";

                }

            }
             contador=0;
             vinos[5]= stoi(removerEspacios(contenido));


             contenido="";
             atributo="";


             //Creo la Membresia
             Membresia *membresia = crearMembresia(membresia,idUsuario,mes_de_la_seleccion,anio_seleccion,vinos);
             insertarNodo(lista,membresia);

    }
    input_file.close();
    return lista;
}

void mostrarListaDeMembresia(Nodo *lista){

    Membresia* membresia;
    membresia = crearMembresiaVacia(membresia);
    Nodo *actual = new Nodo();
    actual = lista;

if(actual == NULL){
    cout<<"La lista esta vacia"<<endl;
}

//Generamos la cabecera de la tabla
cout<<"|ID|"<<"MES SELECCION|"<<"ANIO DE LA SELECCION|"<<"VINO ELEGIDO|"<<endl;
while(actual != NULL)

    {   //CASTEO EL DATO A TIPO MEMBRESIA, PARA OBTENER LA INFORMACION
        membresia = (Membresia*)actual->dato;
        cout<<"\n |"<<getIdUsuario(membresia)<<"|"<<getMes(membresia)<<"|"<<getAnio(membresia)<<"|\n"<<endl;

         int* parray = getArrayVinos(membresia);
         for(int i=0; i<=5 ; i++){
            cout<<" El vino es: "<<(*parray++)<<endl;
        }

        actual = actual->siguiente;
    }

cout<<endl;

}

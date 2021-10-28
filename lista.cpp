#include "lista.h"
#include "Vino.h"
#include "Cliente.h"
#include "Contador.h"
#include "ContadorBodega.h"
#include "ContadorVarietal.h"
#include "Membresia.h"
#include "Utilidades.h"
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

Nodo* obtenerNodoPorPosicion(Nodo *&lista, int posicion){

    int indice = 0;

    if(lista != NULL){

        Nodo *aux_lista;
        Nodo *anterior = NULL;
        aux_lista = lista;


        while((aux_lista != NULL)&& (indice != posicion )){
            anterior = aux_lista;
            aux_lista = aux_lista->siguiente;
            indice++;
        }


        if(aux_lista == NULL){
            cout<<"Esa posicion no existe en la lista"<<endl;
        }

        else if(anterior == NULL){
            return aux_lista;
        }

        else{
            return aux_lista;
        }
    }
}


void insertarNodo(Nodo *&lista,void *n){

    //Creo un nuevo nodo
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

//***********************************************************************************************************************************************/

/* Metodos para manejar los Vinos */

void mostrarListaDeVinos(Nodo *lista){

    Vino* vino = crearVinoVacio(vino);
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


Vino* obtenerNodoVino(Nodo *&listaVinos, int idVino){

    Vino* vino;
    Nodo *listaAux = listaVinos;
    bool encontrado = 0;

    while(listaAux != NULL && encontrado == 0){
        vino = (Vino*)listaAux->dato;
        if(getIdVino(vino) == idVino){
            encontrado = 1;
            vino=(Vino*)listaAux->dato;
            return vino;
        }

        listaAux = listaAux->siguiente;
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


void insertarContadorVarietalDescendentemente (Nodo *&listaAOrdenar, void *contador){

    //Creo un nuevo nodo.
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = contador;

    Nodo *aux1 = listaAOrdenar;
    Nodo *aux2;
    ContadorVarietal* contadorDato;

    if(aux1!= NULL){
        contadorDato = (ContadorVarietal*)aux1->dato;
    }

    ContadorVarietal* contadorP = (ContadorVarietal*)contador;

    while((aux1 != NULL)&&(contadorDato->cantidad > contadorP->cantidad)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
        if(aux1!=NULL){
           contadorDato = (ContadorVarietal*)aux1->dato;
        }
    }
    //Primer nodo de la lista
    if(listaAOrdenar == aux1){
        listaAOrdenar = nuevo_nodo;
    }else{
        //Ultimo nodo de la lista.
        aux2->siguiente=nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;
}


void insertarContadorDescendentemente (Nodo *&listaAOrdenar, void *contador){

    //Creo un nuevo nodo.
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = contador;

    Nodo *aux1 = listaAOrdenar;
    Nodo *aux2;
    Contador* contadorDato;

    if(aux1!= NULL){
        contadorDato = (Contador*)aux1->dato;
    }

    Contador* contadorP = (Contador*)contador;

    while((aux1 != NULL)&&(contadorDato->cantidad > contadorP->cantidad)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
        if(aux1!=NULL){
           contadorDato = (Contador*)aux1->dato;
        }
    }
    //Primer nodo de la lista
    if(listaAOrdenar == aux1){
        listaAOrdenar = nuevo_nodo;
    }else{
        //Ultimo nodo de la lista.
        aux2->siguiente=nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;
}

Nodo* sumarUnoAlIdVino(Nodo *&listaContadorVinos, int idVino){
    Nodo* nodo = new Nodo();
    int cantidad;
    bool encontrado = 0;
    Nodo* listaContadorVino = listaContadorVinos;

    while (listaContadorVino != NULL && encontrado == 0){

        Contador* contador = (Contador*)listaContadorVino->dato;

        if(contador->idVino == idVino){
            contador = (Contador*)listaContadorVino->dato;
            setContadorCantidad(contador,getContadorCantidad(contador)+1);
            setContadorIdVino(contador,idVino);
            encontrado = 1;
            nodo->dato = contador;
            nodo->siguiente = listaContadorVino->siguiente;
            listaContadorVino = nodo;
        }
        listaContadorVino = listaContadorVino->siguiente;

    }
    return listaContadorVinos;
}

Nodo* updateContadorDeVarietales(Nodo *&listaDeVarietales, int cantidad, string varietal){

    Nodo *listaVarietales = listaDeVarietales;
    Nodo* nuevoNodo = new Nodo();
    bool encontrado = 0;
    int sumaDeCantidades=0;
    ContadorVarietal* contadorAux = new ContadorVarietal();
    ContadorVarietal* varietalNuevo = new ContadorVarietal();


    //HACER UN INICIALIZADOR CONTADOR VARIETAL.
    while(listaVarietales != NULL){

        contadorAux=(ContadorVarietal*)listaVarietales->dato;
        /*cout<<"///////////////////////////////////////////////////////"<<endl;
        cout<<"Varietal de la lista que recibo"<<endl;
        cout<<getContadorObtenerVarietal(contadorAux)<<endl;
        cout<<"Varietal Parametro"<<endl;
        cout<<varietal<<endl;
        system("pause");
        cout<<"///////////////////////////////////////////////////////"<<endl;
        */

        if(varietal == getContadorObtenerVarietal(contadorAux)){
            //cout<<"Actualiza un Nodo"<<endl;
            sumaDeCantidades = getContadorVarietalCantidad(contadorAux)+cantidad;
            setContadorVarietalCantidad(contadorAux,sumaDeCantidades);
            nuevoNodo->dato = contadorAux;
            nuevoNodo->siguiente = listaVarietales->siguiente;
            listaVarietales = nuevoNodo;
            encontrado = 1;
        }
        listaVarietales = listaVarietales->siguiente;
    }

    //cout<<"Termino de recorrer la lista que recibio"<<endl;

    //En caso de que no este el varietal lo agrego en la lista.
    if(encontrado == 0){
        //cout<<"cargo el primer nodo"<<endl;
        setContadorVarietalCantidad(varietalNuevo,cantidad);
        setContadorVarietal(varietalNuevo,varietal);
        insertarNodo(listaDeVarietales,varietalNuevo);
    }

    return listaDeVarietales;
}



//Devuelvo una lista de Contadores, con cada id de vino existente.
Nodo* InicializarContadorDeVinos( Nodo *listaDeVinos){

    //Nodo *listaDeVinosAux = new Nodo();
    Vino* vino = new Vino();
    Contador* numeroVino;
    Nodo *listaNumeroVinos = crearLista();

    while(listaDeVinos != NULL){
           //listaDeVinosAux = listaDeVinos;
           vino = (Vino*)listaDeVinos->dato;
           numeroVino = crearContador(numeroVino,getIdVino(vino));
           insertarNodo(listaNumeroVinos,numeroVino);
           listaDeVinos = listaDeVinos->siguiente;
    }
    return listaNumeroVinos;
}

void rankingDeVinos(Nodo *listaDeMembresia, Nodo *listaContabilizadoraDeVinos,Nodo *listaDeVinos){

    //Inicializacion de variables.
    Membresia* membresia;
    Nodo *listaMembresiaAux = crearLista();
    Nodo *listarankingVinos = crearLista();
    Nodo *listaContadoraDeVinos = listaContabilizadoraDeVinos;
    Nodo *listaCantidadDeVinosOrdenada = crearLista();
    Nodo *nodoVino = new Nodo();
    Nodo *listaDeVinosAux = listaDeVinos;
    Contador* contadorAux;

    Contador* contador;
    int cantidadInicial;
    int cantidadAnterior;
    Vino* vino;
    vino = crearVinoVacio(vino);
    int posicion = 0;
    int posicionAux;

        //Recorre la lista de membresia
        while(listaDeMembresia != NULL){
            membresia = (Membresia*)listaDeMembresia->dato;
            for(int i=0; i<6 ; i++){
                if(getAnio(membresia) == 2021){
                    //Si es el anio que estoy buscando, le sumo uno al contador del id del vino.
                     listaContadoraDeVinos = sumarUnoAlIdVino(listaContadoraDeVinos,membresia->vinos[i]);
                }

            }
            listaDeMembresia = listaDeMembresia->siguiente;
        }


            //AGREGAR VALIDACION: RECORRER  LA LISTA CONTADORA DE VINOS,
            //SI ESTAN TODOS LOS CONTADORES CON CANTIDAD 0, NO EXISTE EL ANIO INGRESADO

            while(listaContadoraDeVinos != NULL){

                Contador* contador = (Contador*)listaContadoraDeVinos->dato;
                //Inserto los contadores en orden descendente, en listaCantidadDeVinosOrdenada.
                insertarContadorDescendentemente(listaCantidadDeVinosOrdenada,contador);
                listaContadoraDeVinos = listaContadoraDeVinos->siguiente;

            }

            cout<<"//-----------------------------------------------------------------------------------------------------//"<<endl;
            cout<<".::.RANKING DE VINOS CORRESPONDIENTE AL ANIO 2021.::."<<endl;
            cout<<"POSICION|ID|"<<"ETIQUETA|"<<"BODEGA|"<<"SEGMENTO DEL VINO|"<<"VARIETAL|"<<"ANIO DE COSECHA|"<<"TERROIR|"<<endl;

            //Recorro la lista contadores de vino, ya ordenados de mayor a menor
            while(listaCantidadDeVinosOrdenada != NULL){
                //Muestro la lista de contador

                contador = (Contador*)listaCantidadDeVinosOrdenada->dato;
               if((contador->cantidad != cantidadAnterior)){
                    posicion = posicion +1;
                }

                 vino = obtenerNodoVino(listaDeVinosAux,contador->idVino);

                cout<<posicion<<"|"<<getIdVino(vino)<<"|"<<getEtiqueta(vino)<<"|"<<getBodega(vino)<<"|"<<getSegmento(vino)<<"|"<<getVarietal(vino)<<"|"<<getAnioCosecha(vino)<<"|"<<getTerroir(vino)<<"|"<<endl;
                cantidadAnterior = contador->cantidad;
                listaCantidadDeVinosOrdenada = listaCantidadDeVinosOrdenada->siguiente;

            }

            system("pause");
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
        cerr << "No se puede leer el archivo "
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
                    }
                    contador++;
                    contenido="";
                }
            }

             contador = 0;
             edad = stoi(contenido, nullptr, 10);
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

Cliente* obtenerClientePorId(Nodo *listaDeClientes,int idCliente){

    Cliente* cliente;
    Nodo *listaAux = listaDeClientes;
    bool encontrado = 0;

    while(listaAux != NULL && encontrado == 0){
        cliente = (Cliente*)listaAux->dato;
        if(getIdCliente(cliente) == idCliente){
            encontrado = 1;
            cliente=(Cliente*)listaAux->dato;
            return cliente;
        }

        listaAux = listaAux->siguiente;
    }
}

void rankingDeVarietales(Nodo *listaDeMembresia,Nodo *listaDeVinos, Nodo *listaDeClientes,int rangoEtario){

    //Inicializacion de variables
    Membresia *membresia = crearMembresiaVacia(membresia);
    Cliente *cliente = crearClienteVacio(cliente);
    Nodo *listaContadoraDeVinos;
    listaContadoraDeVinos = InicializarContadorDeVinos(listaDeVinos);
    Nodo *listaCantidadDeVarietalesOrdenada = crearLista();
    Nodo *listaDeVarietales = crearLista();
    Vino* vino = crearVinoVacio(vino);
    Contador* contador;
    ContadorVarietal* contadorVAUX=  new ContadorVarietal();
    ContadorVarietal* conta = new ContadorVarietal();
    int cantidadAnterior;
    int posicion=0;
    string stringRango;


    while(listaDeMembresia != NULL){

        membresia = (Membresia*)listaDeMembresia->dato;
        cliente=obtenerClientePorId(listaDeClientes,getIdUsuario(membresia));

        //Si el rango etario corresponde al ingresado por el usuario, se le suma uno a los vinos elejidos por el cliente.
        switch(rangoEtario){

        case 1:
                if(cliente->edad<=30){
                    for(int i=0; i<6 ; i++){
                     listaContadoraDeVinos = sumarUnoAlIdVino(listaContadoraDeVinos,membresia->vinos[i]);

                    }
                }
            break;

        case 2:
                if(cliente->edad>=30&&cliente->edad<=50){
                    for(int i=0; i<6 ; i++){
                     listaContadoraDeVinos = sumarUnoAlIdVino(listaContadoraDeVinos,membresia->vinos[i]);
                    }
                }
            break;

        case 3:
                if(cliente->edad>=50){
                    for(int i=0; i<6 ; i++){
                     listaContadoraDeVinos = sumarUnoAlIdVino(listaContadoraDeVinos,membresia->vinos[i]);
                    }
                }
            break;
        }

        listaDeMembresia = listaDeMembresia->siguiente;
    }

    //Recorremos la lista de contadores de vinos y los ordenamos por varietales
     while(listaContadoraDeVinos != NULL){
                 Contador* contador = (Contador*)listaContadoraDeVinos->dato;
                 vino=obtenerNodoVino(listaDeVinos,getContadorIdVino(contador));
                 //Chequeo de contador de vinos para los clientes menores de 30 años de edad --TEST--BORRAR--
                 //cout<<"Cantidad: "<<contador->cantidad<<"Varietal: "<<vino->varietal<<endl;
                 //------------------FIN TEST ------------------------------------------------
                 //Agrupo los vinos por varietal
                 listaDeVarietales=updateContadorDeVarietales(listaDeVarietales,getContadorCantidad(contador),getVarietal(vino));
                 listaContadoraDeVinos = listaContadoraDeVinos->siguiente;
            }

    while(listaDeVarietales != NULL){

                    contadorVAUX=(ContadorVarietal*)listaDeVarietales->dato;
                    //Chequeo de agrupacion de varietales -- TEST -- BORRAR --
                    //cout<<contadorVAUX->varietal<<" "<<contadorVAUX->cantidad<<endl;
                    //---------------------------FIN TEST ----------------------------
                    //Ordeno los contadores de varietales en forma descendente de acuerdo a la cantidad.
                    insertarContadorVarietalDescendentemente(listaCantidadDeVarietalesOrdenada,contadorVAUX);
                    listaDeVarietales = listaDeVarietales->siguiente;
                 }


    //Cargo la variable, para mostrar el rango etario elejido
    if(rangoEtario == 1){
        stringRango="MENORES DE 30";
    }else if(rangoEtario==2){
            stringRango="ENTRE 30 Y 50";
        }else{
            stringRango="MAYORES DE 50";
        }


    cout<<"//-----------------------------------------------------------------------------------------------------//"<<endl;
            cout<<".::.RANKING DE VARIETALES CORRESPONDIENTES AL RANGO ETARIO "<<stringRango<<".::."<<endl;
            cout<<"POSICION|"<<"VARIETAL"<<endl;

            //Recorro la lista contadores de varietales, ya ordenados de mayor a menor
            while(listaCantidadDeVarietalesOrdenada != NULL){
                //Muestro la lista de contador

               conta = (ContadorVarietal*)listaCantidadDeVarietalesOrdenada->dato;
               //cout<<"Varietal: "<<conta->varietal<<"Cantidad: "<<conta->cantidad<<endl;
               system("pause");
               if((getContadorVarietalCantidad(conta) != cantidadAnterior)){
                    posicion = posicion +1;
                }


                cout<<posicion<<"|"<<getContadorObtenerVarietal(conta)<<endl;
                cantidadAnterior = getContadorVarietalCantidad(conta);
                listaCantidadDeVarietalesOrdenada = listaCantidadDeVarietalesOrdenada->siguiente;

            }

            system("pause");

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
//------------------------------------------------------------------------------------------------------------

//Ranking bodegas

//3 PARTE DEL RANKING BODEGA

Nodo* sumarUnoAlaBodega(Nodo *&listaDeVinos,Nodo *&listaContadorBodegas,int idVino){

    Nodo* nodo = new Nodo();
    int cantidad  = 0;
    bool encontrado = 0;
    Nodo* listaDeVinosAux = listaDeVinos;
    Nodo* listaContadorBodega = listaContadorBodegas;
    Vino* vino = crearVinoVacio(vino);
    vino = obtenerNodoVino(listaDeVinosAux,idVino);


    while (listaContadorBodega != NULL && encontrado == 0){


        ContadorBodega* contadorBodega = (ContadorBodega*)listaContadorBodega->dato;
        //Se va sumando uno al contador de bodega
        if( getContadorBodega(contadorBodega) == getBodega(vino)){
            contadorBodega = (ContadorBodega*)listaContadorBodega->dato;
            cantidad = getContadorCantidad(contadorBodega) +1 ;
            setContadorCantidad(contadorBodega,cantidad);
            setContadorBodega(contadorBodega,getContadorBodega(contadorBodega));
            encontrado = 1;
            nodo->dato = contadorBodega;
            nodo->siguiente = listaDeVinosAux->siguiente;
            listaContadorBodega = nodo;
        }
        listaContadorBodega = listaContadorBodega->siguiente;

    }
    return listaContadorBodegas;
}


Nodo* InicializarContadorDeBodegas(Nodo *listaDeVinos){


    //reservo un espacio en la memoria para el TDA de tipo vino
    Vino* vino = new Vino();
    ContadorBodega* numerobodega;
    Nodo *listaNumeroBodegas = crearLista();

    int numero = mostrarBodegasNumero( listaDeVinos);
    string* bodegas = new string [numero];
    int i=0;
    bool salida =false;
    int contador =0;


    while(listaDeVinos != NULL){
            salida=false;
            contador=0;
           //el primer dato es un vino
           vino = (Vino*)listaDeVinos->dato;


           if(i==0){
            // Agrega la primer bodega
            numerobodega = crearContadorBodega(numerobodega,getBodega(vino));
            bodegas[i]=getBodega(vino); // lo guardo en el array para iniciar la comparacion

            insertarNodo(listaNumeroBodegas,numerobodega); // inserto el primer nodo
           }



            // (El array comienza en la segunda vuelta && mientras ARRAY < cantidad de registros && salida no sea verdad)
           while ( (i>0) && (i<numero) && salida==false){

                numerobodega = crearContadorBodega(numerobodega,getBodega(vino)); //creo un contador y su bodega
                bodegas[i]=getBodega(vino); //inserto la bodega en el array

                for (int k=0 ;k<i+1; k++){ //repite  N veces ,segun lo que valga  i
                    if(bodegas[k-1]==bodegas[i]){ //compara que no se repita

                        contador= contador+1; // si se repite incrementa contador
                        k=i+1;// finalizo el for


                    }

                }
                if(contador==0){ // sino se repitio inserta el nodo
                    // primer nodo en la Lista de Bodegas  (ListaBodega, puntero a Contador )
                    insertarNodo(listaNumeroBodegas,numerobodega);

                }
                salida =true;

           }


             // Recorre el siguiente nodo de la lista de vinos
           listaDeVinos = listaDeVinos->siguiente;
           i=i+1;
    }
    return listaNumeroBodegas;
}

// 2 PARTE DEL RANKING

void rankingDeBodegas(Nodo *listaDeMembresia, Nodo *listaContabilizadoraDeVinos, Nodo *listaContabilizadoraDeBodegas, Nodo *listaDeVino){

    //Inicializacion de variables.
    Membresia* membresiaAux = crearMembresiaVacia(membresiaAux);
    Nodo *listaMembresiaAux = crearLista();
    Nodo *listarankingBodegas = crearLista();
    Nodo *listaContadoraDeVinos = listaContabilizadoraDeVinos;
    Nodo *listaContadoraDeBodegas = listaContabilizadoraDeBodegas;
    Nodo *listaCantidadDeBodegasOrdenada = crearLista(); // nose
    Nodo *nodoVino = new Nodo(); //nuevo nodo vino
    Nodo *listaDeVinosAux = listaDeVino; //lista aux de vinos
    Contador* contadorAux; // contador auxiliar para contador

    ContadorBodega* contadorBodega;
    int cantidadInicial;
    int cantidadAnterior;
    Vino* vino;
    vino = crearVinoVacio(vino);
    int posicion = 0;
    int posicionAux;

        //Recorre la lista de membresia
        while(listaDeMembresia != NULL){
            membresiaAux = (Membresia*)listaDeMembresia->dato;
            for(int i=0; i<6 ; i++){

                if(getAnio(membresiaAux) == 2021){
                    //Si es el anio que estoy buscando, le sumo uno al contador de la bodega.
                     listaContadoraDeBodegas = sumarUnoAlaBodega(listaDeVinosAux ,listaContadoraDeBodegas,membresiaAux->vinos[i]);
                }
        }

        listaDeMembresia = listaDeMembresia->siguiente;



            //AGREGAR VALIDACION: RECORRER  LA LISTA CONTADORA DE VINOS,
            //SI ESTAN TODOS LOS CONTADORES CON CANTIDAD 0, NO EXISTE EL ANIO INGRESADO


            //NO SE ESTA CARGANDO LA LISTA DE BODEGAS ORDENADA.
            while(listaContadoraDeBodegas != NULL){

                ContadorBodega* contadorBodega = (ContadorBodega*)listaContadoraDeBodegas->dato;
                //Inserto los contadores en orden descendente, en listaCantidadDeVinosOrdenada.
                insertarContadorDescendentemente(listaCantidadDeBodegasOrdenada,contadorBodega);
                listaContadoraDeBodegas = listaContadoraDeBodegas->siguiente;
            }

            cout<<"//-----------------------------------------------------------------------------------------------------//"<<endl;
            cout<<".::.RANKING DE BODEGAS CORRESPONDIENTE AL ANIO : "<<2021<<".::."<<endl;
            cout<<"POSICION|ID|"<<"BODEGA|"<<endl;

            //Recorro la lista contadores de vino, ya ordenados de mayor a menor
            while(listaCantidadDeBodegasOrdenada != NULL){
                //Muestro la lista de contador

                contadorBodega = (ContadorBodega*)listaCantidadDeBodegasOrdenada->dato;
                cout<<contadorBodega->bodega<<contadorBodega->cantidad<<endl;
                system("pause");

                if((contadorBodega->cantidad != cantidadAnterior)){
                    posicion = posicion +1;
                }

                    // arreglar la linea
               //vino = obtenerNodoVino(listaDeVinosAux,contador->idVino);//contadorBodega no tiene  un IDVino.

                cout<<posicion<<"|"<<getBodega(vino)<<endl;
                cantidadAnterior = contadorBodega->cantidad;
                listaCantidadDeBodegasOrdenada = listaCantidadDeBodegasOrdenada->siguiente;

            }

            system("pause");
    }

    //CONTROL DE LA LISTA CONTADORA DE BODEGAS
    /*
     while (listaContadoraDeBodegas != NULL){

            Contador* conta = new Contador();

            conta=(Contador*)listaContadoraDeBodegas->dato;
            cout<<"Contador Final Cantidad: "<<getContadorCantidad(conta)<<"Contador Final Bodega: "<<getContadorBodega(conta)<<endl;

            listaContadoraDeBodegas = listaContadoraDeBodegas->siguiente;
        }*/

}
//-----------------------------------------------------------------------------------------

// Cuenta los registros de los vinos
int mostrarBodegasNumero(Nodo *lista){

    Vino* vino;
    vino = crearVinoVacio(vino);
    Nodo *actual = new Nodo();
    actual = lista;

    int i=0;


if(actual == NULL){
    cout<<"La lista esta vacia"<<endl;
}
//Generamos la cabecera de la tabla
cout<<"BODEGA|"<<endl;
while(actual != NULL)

    {
        vino = (Vino*)actual->dato;

        actual = actual->siguiente;
        i = i+1;
    }

return i;

}


void mostrarListaDeLasBodegas(Nodo *lista){

    ContadorBodega* contadorBodega;
    contadorBodega = crearContadorVacioBodega(contadorBodega);
    Nodo *actual = new Nodo();
    actual = lista;

if(actual == NULL){
    cout<<"La lista esta vacia"<<endl;
}


cout<<"----------Lista de todas las Bodegas--------------"<<endl;


while(actual != NULL)

    {   //CASTEO EL DATO A TIPO CONTADOR, PARA OBTENER LA INFORMACION
        contadorBodega = (ContadorBodega*)actual->dato;

        cout<<"|"<<getContadorBodega(contadorBodega)<<"|"<<endl;
        actual = actual->siguiente;
    }

cout<<endl;

}


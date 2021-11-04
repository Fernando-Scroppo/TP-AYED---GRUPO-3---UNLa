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

/* Metodos get y set de los nodos */

Nodo* getNodoSiguiente(Nodo *nodo){
    return nodo->siguiente;
}

void* getNodoDato(Nodo *nodo){
    return nodo->dato;
}

void setNodoSiguiente(Nodo *nodo, Nodo *nodoSiguiente){
    nodo->siguiente = nodoSiguiente;
}

void setNodoDato(Nodo *nodo, void *dato){
    nodo->dato = dato;
}

/* Fin de get y set */


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
    setNodoDato(nuevo_nodo,n);

    Nodo *aux1 = lista;
    Nodo *aux2;

    while(aux1 != NULL){
        aux2 = aux1;
        aux1 = getNodoSiguiente(aux1);
    }
    //Primer nodo de la lista
    if(lista == aux1){
        lista = nuevo_nodo;
    }else{
        //Ultimo nodo de la lista.
       setNodoSiguiente(aux2,nuevo_nodo);

    }
    setNodoSiguiente(nuevo_nodo,aux1);

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
            aux_borrar = getNodoSiguiente(aux_borrar);
            indice++;
        }

        //En este caso nunca entro al While por la tanto el elemento que quiere borrar no existe
        if(aux_borrar == NULL){
            cout<<"Esa posicion NO existe en la lista"<<endl;
        }
        //El elemento que quiere eliminar esta al principio de la lista
        else if(anterior == NULL){
            lista = getNodoSiguiente(lista);
            cout<<"El Nodo fue eliminado exitosamente de la lista"<<endl;
            delete aux_borrar;
        }
        //Si el elemento esta entre medio de la lista
        else{
            anterior->siguiente = aux_borrar->siguiente;
            setNodoSiguiente(anterior,getNodoSiguiente(aux_borrar));
            cout<<"El Nodo fue eliminado exitosamente de la lista"<<endl;
            delete aux_borrar;
        }
    }

}

void vaciarLista( Nodo *&lista){
    while (lista != NULL){
        Nodo *aux = lista;
        lista = getNodoSiguiente(aux);
        delete aux;
    }
}

//***********************************************************************************************************************************************/

/* Metodos para manejar los Vinos */

void mostrarListaDeVinos(Nodo *lista){

    Vino* vino = crearVinoVacio(vino);
    Nodo *actual = new Nodo();
    actual = lista;

if(actual == NULL){
    cout<<"La lista esta vacia"<<endl;
}
//Generamos la cabecera de la tabla
cout<<"|ID|"<<"ETIQUETA|"<<"BODEGA|"<<"SEGMENTO DEL VINO|"<<"VARIETAL|"<<"ANIO DE COSECHA|"<<"TERROIR|"<<endl;
while(actual != NULL)

    {   //CASTEO EL DATO A TIPO VINO, PARA OBTENER LA INFORMACION
        vino = (Vino*) getNodoDato(actual);

        cout<<"|"<<getIdVino(vino)<<"|"<<getEtiqueta(vino)<<"|"<<getBodega(vino)<<"|"<<getSegmento(vino)<<"|"<<getVarietal(vino)<<"|"<<getAnioCosecha(vino)<<"|"<<getTerroir(vino)<<"|"<<endl;
        actual = getNodoSiguiente(actual);
    }

cout<<endl;

}


Vino* obtenerNodoVino(Nodo *&listaVinos, int idVino){

    Vino* vino = crearVinoVacio(vino);
    Nodo *listaAux = listaVinos;
    bool encontrado = 0;

    while(listaAux != NULL && encontrado == 0){
        vino = (Vino*)listaAux->dato;
        vino = (Vino*)getNodoDato(listaAux);
        if(getIdVino(vino) == idVino){
            encontrado = 1;
            vino = (Vino*)getNodoDato(listaAux);
            return vino;
        }

        listaAux = getNodoSiguiente(listaAux);
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
    setNodoDato(nuevo_nodo,contador);

    Nodo *aux1 = listaAOrdenar;
    Nodo *aux2;
    ContadorVarietal* contadorDato;

    if(aux1!= NULL){
        contadorDato= (ContadorVarietal*)getNodoDato(aux1);
    }

    ContadorVarietal* contadorP = (ContadorVarietal*)contador;

    while((aux1 != NULL)&&( getContadorVarietalCantidad(contadorDato) > getContadorVarietalCantidad(contadorP))){
        aux2 = aux1;
        aux1 = getNodoSiguiente(aux1);

        if(aux1!=NULL){
           contadorDato = (ContadorVarietal*)getNodoDato(aux1);
        }
    }
    //Primer nodo de la lista
    if(listaAOrdenar == aux1){
        listaAOrdenar = nuevo_nodo;
    }else{
        //Ultimo nodo de la lista.
        setNodoSiguiente(aux2,nuevo_nodo);
    }

    setNodoSiguiente(nuevo_nodo,aux1);
}


void insertarContadorDescendentemente (Nodo *&listaAOrdenar, void *contador){

    //Creo un nuevo nodo.
    Nodo *nuevo_nodo = new Nodo();
    setNodoDato(nuevo_nodo,contador);

    Nodo *aux1 = listaAOrdenar;
    Nodo *aux2;
    Contador* contadorDato = crearContadorVacio(contadorDato);

    if(aux1!= NULL){
        contadorDato = (Contador*)getNodoDato(aux1);
    }

    Contador* contadorP = (Contador*)contador;

    while((aux1 != NULL)&&(getContadorCantidad(contadorDato) > getContadorCantidad(contadorP))){
        aux2 = aux1;
        aux1 = getNodoSiguiente(aux1);
        if(aux1!=NULL){
           contadorDato = (Contador*)getNodoDato(aux1);
        }
    }
    //Primer nodo de la lista
    if(listaAOrdenar == aux1){
        listaAOrdenar = nuevo_nodo;
    }else{
        //Ultimo nodo de la lista.
        setNodoSiguiente(aux2,nuevo_nodo);
    }
    setNodoSiguiente(nuevo_nodo,aux1);
}

Nodo* sumarUnoAlIdVino(Nodo *&listaContadorVinos, int idVino){
    Nodo* nodo = new Nodo();
    int cantidad;
    bool encontrado = 0;
    Nodo* listaContadorVino = listaContadorVinos;

    while (listaContadorVino != NULL && encontrado == 0){

        Contador* contador = (Contador*)getNodoDato(listaContadorVino);

        //Cuando encontramos el vino, actualizamos la cantidad
        if(contador->idVino == idVino){
            contador = (Contador*)getNodoDato(listaContadorVino);
            setContadorCantidad(contador,getContadorCantidad(contador)+1);
            setContadorIdVino(contador,idVino);
            encontrado = 1;
            setNodoDato(nodo,contador);
            setNodoSiguiente(nodo,getNodoSiguiente(listaContadorVino));
            listaContadorVino = nodo;
        }

        listaContadorVino = getNodoSiguiente(listaContadorVino);

    }
    //Devuelvo la lista, con los contadores de vino actualizados
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

        contadorAux= (ContadorVarietal*)getNodoDato(listaVarietales);

        if(varietal == getContadorObtenerVarietal(contadorAux)){
            //cout<<"Actualiza un Nodo"<<endl;
            sumaDeCantidades = getContadorVarietalCantidad(contadorAux)+cantidad;
            setContadorVarietalCantidad(contadorAux,sumaDeCantidades);
            setNodoDato(nuevoNodo,contadorAux);
            setNodoSiguiente(nuevoNodo,getNodoSiguiente(listaVarietales));
            listaVarietales = nuevoNodo;
            encontrado = 1;
        }

        listaVarietales = getNodoSiguiente(listaVarietales);
    }


    //En caso de que no este el varietal lo agrego en la lista.
    if(encontrado == 0){
        //cout<<"cargo el primer nodo"<<endl;
        setContadorVarietalCantidad(varietalNuevo,cantidad);
        setContadorVarietal(varietalNuevo,varietal);
        insertarNodo(listaDeVarietales,varietalNuevo);
    }

    //Retorno la lista con la cantidad de varietales o con un varietal nuevo actualizada.
    return listaDeVarietales;
}



//Devuelvo una lista de Contadores, con cada id de vino existente.
Nodo* InicializarContadorDeVinos(Nodo *listaDeVinos){

    Vino* vino = crearVinoVacio(vino);
    Contador* numeroVino = new Contador();
    Nodo *listaNumeroVinos = crearLista();

    //Creo una lista de contadores de vinos
    while(listaDeVinos != NULL){
           vino = (Vino*)getNodoDato(listaDeVinos);
           numeroVino = crearContador(numeroVino,getIdVino(vino));
           insertarNodo(listaNumeroVinos,numeroVino);
           listaDeVinos = getNodoSiguiente(listaDeVinos);
    }
    //retorno una lista con todos los id de vinos y cantidades en cero.
    return listaNumeroVinos;

}

void rankingDeVinos(Nodo *listaDeMembresia,Nodo *listaDeVinos){

    //Inicializacion de variables.
    Membresia* membresia = crearMembresiaVacia(membresia);
    Nodo *listaMembresiaAux = crearLista();
    Nodo *listarankingVinos = crearLista();
    Nodo *listaContadoraDeVinos = InicializarContadorDeVinos(listaDeVinos);
    Nodo *listaCantidadDeVinosOrdenada = crearLista();
    Nodo *nodoVino = new Nodo();
    Nodo *listaDeVinosAux = listaDeVinos;
    Contador* contadorAux = new Contador();

    Contador* contador = crearContadorVacio(contador);
    int* vinos;
    int cantidadInicial;
    int cantidadAnterior;
    Vino* vino;
    vino = crearVinoVacio(vino);
    int posicion = 0;
    int posicionAux;


        //Recorre la lista de membresia
        while(listaDeMembresia != NULL){
            membresia = (Membresia*)getNodoDato(listaDeMembresia);
            //Si es el anio que estoy buscando, le sumo uno al contador del id del vino.
            if(getAnio(membresia) == 2021){
                  for(int i=0; i<6 ; i++){
                    //Si es el anio que estoy buscando, le sumo uno al contador del id del vino.
                     listaContadoraDeVinos = sumarUnoAlIdVino(listaContadoraDeVinos,membresia->vinos[i]);

                    }
            }

            listaDeMembresia = getNodoSiguiente(listaDeMembresia);
        }


            while(listaContadoraDeVinos != NULL){

                contador = (Contador*)getNodoDato(listaContadoraDeVinos);
                //Inserto los contadores en orden descendente, en listaCantidadDeVinosOrdenada.
                insertarContadorDescendentemente(listaCantidadDeVinosOrdenada,contador);
                listaContadoraDeVinos = getNodoSiguiente(listaContadoraDeVinos);

            }

            cout<<"//-----------------------------------------------------------------------------------------------------//"<<endl;
            cout<<".::.RANKING DE VINOS CORRESPONDIENTE AL ANIO 2021.::."<<endl;
            cout<<"P| ID  |"<<"      ETIQUETA     |"<<"       BODEGA      |"<<"SEG. VINO  |"<<"        VARIETAL       |"<<"ANIO|"<<"       TERROIR"<<endl;

            //Recorro la lista contadores de vino, ya ordenados de mayor a menor
            while(listaCantidadDeVinosOrdenada != NULL){
                //Muestro la lista de contador

                contador = (Contador*)getNodoDato(listaCantidadDeVinosOrdenada);
                //Si la cantidad de los vinos es la misma, la posicion no avanza.
               if((contador->cantidad != cantidadAnterior)){
                    posicion = posicion +1;
                }

                 vino = obtenerNodoVino(listaDeVinosAux,contador->idVino);

                cout<<posicion<<"|"<<getIdVino(vino)<<"|"<<getEtiqueta(vino)<<"|"<<getBodega(vino)<<"|"<<getSegmento(vino)<<"|"
                <<getVarietal(vino)<<"|"<<getAnioCosecha(vino)<<"|"<<getTerroir(vino)<<endl;

                cantidadAnterior = getContadorCantidad(contador);
                listaCantidadDeVinosOrdenada = getNodoSiguiente(listaCantidadDeVinosOrdenada);

            }

            system("pause");

            //liberarMemoria
            vaciarLista(listaMembresiaAux);
            vaciarLista(listarankingVinos);
            vaciarLista(listaContadoraDeVinos);
            vaciarLista(listaCantidadDeVinosOrdenada);
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
        cliente = (Cliente*)getNodoDato(actual);
        cout<<"|"<<getIdCliente(cliente)<<"|"<<getNombreYapellido(cliente)<<"|"<<getDireccion(cliente)<<"|"<<getEdad(cliente)<<"|"<<endl;
        actual = getNodoSiguiente(actual);
    }

cout<<endl;

}

Cliente* obtenerClientePorId(Nodo *listaDeClientes,int idCliente){

    Cliente* cliente;
    Nodo *listaAux = listaDeClientes;
    bool encontrado = 0;

    while(listaAux != NULL && encontrado == 0){
        cliente = (Cliente*)getNodoDato(listaAux);
        if(getIdCliente(cliente) == idCliente){
            encontrado = 1;
            //cliente=(Cliente*)listaAux->dato;
            return cliente;
        }

        listaAux = getNodoSiguiente(listaAux);
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
    Contador* contador = crearContadorVacio(contador);
    ContadorVarietal* contadorVAUX=  new ContadorVarietal();
    ContadorVarietal* conta = new ContadorVarietal();
    int cantidadAnterior;
    int posicion=0;
    string stringRango;


    while(listaDeMembresia != NULL){

        membresia = (Membresia*)getNodoDato(listaDeMembresia);
        cliente=obtenerClientePorId(listaDeClientes,getIdUsuario(membresia));
        //Un puntero que devuelve la primera posicion del array.
        int* parray = getArrayVinos(membresia);

        //Si el rango etario corresponde al ingresado por el usuario, se le suma uno a los vinos elejidos por el cliente.
        switch(rangoEtario){

        case 1:
                if(getEdad(cliente)<=30){
                    for(int i=0; i<6 ; i++){
                     //(*parray) con esta instruccion estamos tomando el valor del puntero.
                     listaContadoraDeVinos = sumarUnoAlIdVino(listaContadoraDeVinos,(*parray));

                    }
                }
            break;

        case 2:
                if(getEdad(cliente)>=30&&getEdad(cliente)<=50){
                    for(int i=0; i<6 ; i++){
                     listaContadoraDeVinos = sumarUnoAlIdVino(listaContadoraDeVinos,(*parray));
                    }
                }
            break;

        case 3:
                if(getEdad(cliente)>=50){
                    for(int i=0; i<6 ; i++){
                     listaContadoraDeVinos = sumarUnoAlIdVino(listaContadoraDeVinos,(*parray));
                    }
                }
            break;
        }

        listaDeMembresia = getNodoSiguiente(listaDeMembresia);
    }

    //Recorremos la lista de contadores de vinos y los ordenamos por varietales
     while(listaContadoraDeVinos != NULL){
                 Contador* contador = (Contador*)getNodoDato(listaContadoraDeVinos);
                 vino=obtenerNodoVino(listaDeVinos,getContadorIdVino(contador));
                 //Agrupo los vinos por varietal
                 listaDeVarietales=updateContadorDeVarietales(listaDeVarietales,getContadorCantidad(contador),getVarietal(vino));
                 listaContadoraDeVinos = listaContadoraDeVinos->siguiente;
                 listaContadoraDeVinos = getNodoSiguiente(listaContadoraDeVinos);
            }

    while(listaDeVarietales != NULL){

                    contadorVAUX=(ContadorVarietal*)getNodoDato(listaDeVarietales);
                    //Ordeno los contadores de varietales en forma descendente de acuerdo a la cantidad.
                    insertarContadorVarietalDescendentemente(listaCantidadDeVarietalesOrdenada,contadorVAUX);
                    listaDeVarietales = getNodoSiguiente(listaDeVarietales);
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
            cout<<"P|"<<"    VARIETAL"<<endl;

            //Recorro la lista contadores de varietales, ya ordenados de mayor a menor
            while(listaCantidadDeVarietalesOrdenada != NULL){

                //Muestro la lista de contador
               conta = (ContadorVarietal*)getNodoDato(listaCantidadDeVarietalesOrdenada);

               if((getContadorVarietalCantidad(conta) != cantidadAnterior)){
                    posicion = posicion +1;
                }


                cout<<posicion<<"|"<<getContadorObtenerVarietal(conta)<<"|"<<getContadorVarietalCantidad(conta)<<endl;
                cantidadAnterior = getContadorVarietalCantidad(conta);
                listaCantidadDeVarietalesOrdenada = getNodoSiguiente(listaCantidadDeVarietalesOrdenada);

            }

            system("pause");

            //Liberar Memoria
            vaciarLista(listaContadoraDeVinos);
            vaciarLista(listaCantidadDeVarietalesOrdenada);
            vaciarLista(listaDeVarietales);
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
        membresia = (Membresia*)getNodoDato(actual);
        cout<<"\n |"<<getIdUsuario(membresia)<<"|"<<getMes(membresia)<<"|"<<getAnio(membresia)<<"|\n"<<endl;

         int* parray = getArrayVinos(membresia);
         for(int i=0; i<=5 ; i++){
            cout<<" El vino es: "<<(*parray++)<<endl;
        }

        actual = getNodoSiguiente(actual);
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
    //metodo para obtener la
    vino = obtenerNodoVino(listaDeVinosAux,idVino);


    while (listaContadorBodega != NULL && encontrado == 0){

        ContadorBodega* contadorBodega = (ContadorBodega*)getNodoDato(listaContadorBodega);
        //Se va sumando uno al contador de bodega
        if( getContadorBodega(contadorBodega) == getBodega(vino)){
            contadorBodega = (ContadorBodega*)getNodoDato(listaContadorBodega);
            cantidad = getContadorCantidadBodega(contadorBodega)+1;
            setContadorCantidadBodega(contadorBodega,cantidad);
            setContadorBodega(contadorBodega,getContadorBodega(contadorBodega));
            encontrado = 1;
            setNodoDato(nodo,contadorBodega);
            setNodoSiguiente(nodo,getNodoSiguiente(listaDeVinosAux));
            listaContadorBodega = nodo;
        }
        listaContadorBodega = getNodoSiguiente(listaContadorBodega);
    }
    return listaContadorBodegas;
}


Nodo* InicializarContadorDeBodegas(Nodo *listaDeVinos){


    //reservo un espacio en la memoria para el TDA de tipo vino
    Vino* vino = crearVinoVacio(vino);
    ContadorBodega* numerobodega = crearContadorVacioBodega(numerobodega);
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
           vino = (Vino*)getNodoDato(listaDeVinos);


           if(i==0){
            // Agrega la primer bodega
            numerobodega = crearContadorBodega(numerobodega,getBodega(vino));
            bodegas[i]=getBodega(vino); // lo guardo en el array para iniciar la comparacion

            insertarNodo(listaNumeroBodegas,numerobodega); // inserto el primer nodo
           }



            // (El array comienza en la segunda vuelta && ARRAY < cantidad de registros && salida no sea verdad)
           while ( (i>0) && (i<numero) && salida==false){

                numerobodega = crearContadorBodega(numerobodega,getBodega(vino)); //creo un contador y su bodega
                bodegas[i]=getBodega(vino); //inserto la bodega en el array

                for (int k=0 ;k<i+1; k++){ //repite  N veces ,segun lo que valga  i
                    if(bodegas[k-1]==bodegas[i]){ //compara que no se repita

                        contador= contador+1; // si se repite incrementa el contador
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
           listaDeVinos = getNodoSiguiente(listaDeVinos);
           i=i+1;
    }
    return listaNumeroBodegas;
}

// 2 PARTE DEL RANKING DE BODEGAS

void rankingDeBodegas(Nodo *listaDeMembresia,Nodo *listaDeVino){

    //Inicializacion de variables.
    Membresia* membresiaAux = crearMembresiaVacia(membresiaAux);
    Nodo *listaMembresiaAux = crearLista();
    Nodo *listarankingBodegas = crearLista();
    Nodo *listaContadoraDeVinos = InicializarContadorDeVinos(listaDeVino);
    Nodo *listaContadoraDeBodegas = InicializarContadorDeBodegas(listaDeVino);
    Nodo *listaCantidadDeBodegasOrdenada = crearLista(); // nose
    Nodo *nodoVino = new Nodo(); //nuevo nodo vino
    Nodo *listaDeVinosAux = listaDeVino; //lista aux de vinos
    Contador* contadorAux = crearContadorVacio(contadorAux); // contador auxiliar para contador


    ContadorBodega* contadorBodega = crearContadorVacioBodega(contadorBodega);
    int cantidadInicial;
    int cantidadAnterior;
    Vino* vino;
    vino = crearVinoVacio(vino);
    int posicion = 0;


        //Recorre la lista de membresia
        while(listaDeMembresia != NULL){
            membresiaAux = (Membresia*)getNodoDato(listaDeMembresia);

            if(getAnio(membresiaAux) == 2021){
                int* pArray = getArrayVinos(membresiaAux);
                for(int i=0; i<6 ; i++){
                    //Si es el anio que estoy buscando, le sumo uno al contador de la bodega.
                     listaContadoraDeBodegas = sumarUnoAlaBodega(listaDeVinosAux ,listaContadoraDeBodegas,(*pArray));
                }
            }

            listaDeMembresia = getNodoSiguiente(listaDeMembresia);

        }

            while(listaContadoraDeBodegas != NULL){

                ContadorBodega* contadorBodega = (ContadorBodega*)getNodoDato(listaContadoraDeBodegas);
                //Inserto los contadores en orden descendente, en listaCantidadDeVinosOrdenada.
                insertarContadorBodegaDescendentemente(listaCantidadDeBodegasOrdenada,contadorBodega);
                listaContadoraDeBodegas = getNodoSiguiente(listaContadoraDeBodegas);

                }


            cout<<"//-----------------------------------------------------------------------------------------------------//"<<endl;
            cout<<".::.RANKING DE BODEGAS CORRESPONDIENTE AL ANIO : "<<2021<<".::."<<endl;
            cout<<"POSICION|"<<"BODEGA|"<<endl;

            //Recorro la lista contadores de vino, ya ordenados de mayor a menor
            while(listaCantidadDeBodegasOrdenada != NULL){

                //Muestro la lista de contador
                contadorBodega = (ContadorBodega*)getNodoDato(listaCantidadDeBodegasOrdenada);
                cout<<"LA BODEGA ES :"<<getContadorBodega(contadorBodega)<<"|CANTIDAD:"<<getContadorCantidadBodega(contadorBodega)<<endl;


                if((getContadorCantidadBodega(contadorBodega) != cantidadAnterior)){
                    posicion = posicion +1;
                }


                cout<<posicion<<"|"<<endl;
                cantidadAnterior = getContadorCantidadBodega(contadorBodega);
                listaCantidadDeBodegasOrdenada = getNodoSiguiente(listaCantidadDeBodegasOrdenada);

            }

            system("pause");

            //Liberamos la memoria
            vaciarLista(listaContadoraDeVinos);
            vaciarLista(listaMembresiaAux);
            vaciarLista(listarankingBodegas);
            vaciarLista(listaCantidadDeBodegasOrdenada);
            vaciarLista(listaContadoraDeBodegas);
    }


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

// SE COMENTO PORQUE SE IMPRIMIA BODEGA EN LA PANTALLA PRINCIPAL DEL MAIN //
//cout<<"BODEGA|"<<endl;

while(actual != NULL)

    {

        vino = (Vino*)getNodoDato(actual);
        actual = getNodoSiguiente(actual);
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
        contadorBodega = (ContadorBodega*)getNodoDato(actual);
        cout<<"|"<<getContadorBodega(contadorBodega)<<"|"<<endl;
        actual = getNodoSiguiente(actual);
    }

cout<<endl;

}


void insertarContadorBodegaDescendentemente (Nodo *&listaAOrdenar, void *contador){

    //Creo un nuevo nodo.
    Nodo *nuevo_nodo = new Nodo();
    setNodoDato(nuevo_nodo,contador);

    Nodo *aux1 = listaAOrdenar;
    Nodo *aux2;
    ContadorBodega* contadorDato;

    if(aux1!= NULL){
        contadorDato = (ContadorBodega*)getNodoDato(aux1);
    }

    ContadorBodega* contadorP = (ContadorBodega*)contador;

    while((aux1 != NULL)&&(getContadorCantidadBodega(contadorDato) > getContadorCantidadBodega(contadorP))){
        aux2 = aux1;
        aux1 = getNodoSiguiente(aux1);
        if(aux1!=NULL){
           contadorDato = (ContadorBodega*)getNodoDato(aux1);
        }
    }
    //Primer nodo de la lista
    if(listaAOrdenar == aux1){
        listaAOrdenar = nuevo_nodo;
    }else{
        //Ultimo nodo de la lista.
        setNodoSiguiente(aux2,nuevo_nodo);
    }
    setNodoSiguiente(nuevo_nodo,aux1);
}



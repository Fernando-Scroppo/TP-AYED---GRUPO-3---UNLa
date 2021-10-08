#include "Cliente.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

/*----------------------------------------------------------------------------*/
Cliente* crearClienteVacio(Cliente *cliente) {
    cliente = new Cliente();
    return cliente;
}

/*----------------------------------------------------------------------------*/
Cliente* crearCliente(Cliente *cliente,int id,string nombreYapellido,string direccion,int edad) {
    cliente = new Cliente();
    setIdCliente(cliente,id);
    setNombreYapellido(cliente,nombreYapellido);
    setDireccion(cliente,direccion);
    setEdad(cliente,edad);

    return cliente;
}


/*----------------------------------------------------------------------------*/
void destruirC(Cliente *cliente) {
    delete cliente;
}

/*----------------------------------------------------------------------------*/
void setIdCliente(Cliente *cliente, int id) {
    cliente->id = id;
}

/*----------------------------------------------------------------------------*/
int getIdCliente(Cliente *cliente) {
    return cliente->id;
}

/*----------------------------------------------------------------------------*/
void setNombreYapellido(Cliente *cliente, string nombreYapellido) {
    cliente->nombreYapellido = nombreYapellido;
}

/*----------------------------------------------------------------------------*/
string getNombreYapellido(Cliente *cliente) {
    return cliente->nombreYapellido;
}

/*----------------------------------------------------------------------------*/
void setEdad(Cliente *cliente, int edad) {
    cliente->edad = edad;
}

/*----------------------------------------------------------------------------*/
int getEdad(Cliente *cliente) {
    return cliente->edad;
}

/*----------------------------------------------------------------------------*/
string getDireccion(Cliente *cliente) {
    return cliente->direccion;
}

/*----------------------------------------------------------------------------*/
void setDireccion(Cliente *cliente,string direccion){
    cliente->direccion = direccion;
}
/*----------------------------------------------------------------------------*/

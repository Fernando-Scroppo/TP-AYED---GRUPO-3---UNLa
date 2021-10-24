#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <sstream>

using namespace std;


struct Cliente{
int id;
 string nombreYapellido;
 string direccion;
 int edad;

};


/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : el cliente no debe haber sido creado.
  post: el cliente queda creado y preparado para ser usado con valores 0.
*/

Cliente* crearClienteVacio(Cliente *Cliente);
/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido
  post: deja la instacia de la lista para ser usado. Los parametros se aplica al tda (cliente).
*/

Cliente* crearCliente(Cliente *Cliente,int id,string nombreYapellido,string direccion,int edad);
/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido.
  post: destruye la instancia del tda y ya no podrá ser usado.
*/
void destruirC(Cliente *Cliente); // ¿En C++ existe la sobrecarga de metodos?

/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido.
  post: asigna el valor de id a la instancia de Cliente.
*/
void setIdCliente(Cliente *Cliente, int id);

/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido.
  post: devuelve el id.
*/
int getIdCliente(Cliente *Cliente);
int getIdCliente();

/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido.
  post: asigna el valor de nombre a la instancia de cliente.
*/
void setNombreYapellido(Cliente *Cliente, string nombreYapellido);
void setNombreYapellido(string nombreYapellido);
/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido.
  post: devuelve el nombre y apellido.
*/
string getNombreYapellido(Cliente *Cliente);
string getNombreYapellido();
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido.
  post: asigna el valor de direccion a la instancia de cliente.
*/
void setDireccion(Cliente *Cliente, string direccion);

/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido.
  post: devuelve la direccion.
*/
string getDireccion(Cliente *Cliente);
string getDireccion();
/*----------------------------------------------------------------------------*/


/*
  pre: el cliente debe haberse creado y no destruido.
  post: asigna el valor de edad a la instancia de cliente.
*/
void setEdad(Cliente *Cliente, int edad);

/*----------------------------------------------------------------------------*/
/*
  pre: el cliente debe haberse creado y no destruido.
  post: devuelve  la edad del cliente.
*/
int getEdad(Cliente *Cliente);


/*----------------------------------------------------------------------------*/

#endif // CLIENTE_H_INCLUDED

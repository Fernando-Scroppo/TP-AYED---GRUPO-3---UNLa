#ifndef MEMBRESIA_H_INCLUDED
#define MEMBRESIA_H_INCLUDED

struct Membresia{

int idUsuario;
int mes_de_la_seleccion;
int año_seleccion;
array vinos[5];

};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : la membresia no debe haber sido creado.
  post: la membresia queda creada y preparada.
*/

Membresia* crearMembresiaVacia(Membresia *membresia);
/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido
  post: deja la instacia de la lista para ser usado. Los parametros se aplica al tda (membresia).
*/

Membresia* crearMembresia(Membresia *membresia,int idUsuario,int mes,int anio,array vinos[5]);
/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: destruye la instancia del tda y ya no podrá ser usado.
*/
void destruir (Membresia *membresia);

/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: asigna el valor de id a la instancia de Membresia.
*/
void setIdUsuario(Membresia *membresia, int idUsuario);

/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: devuelve el idUsuario.
*/
int getIdUsuario(Membresia *membresia);

/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: asigna el valor de nombre a la instancia de membresia .
*/
void setMes(Membresia *membresia, int mes);

/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: devuelve el nombre.
*/
string getMes(Membresia *membresia);

/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: asigna el valor de añoCosecha a la instancia de membresia.
*/
void setAnio(Membresia *membresia, int anio);

/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: devuelve el año de la membresia.
*/
int getAnio(Membresia *membresia);


/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: asigna los valores de los vinos seleccionados por el usuario .
*/
void setArray(Membresia *membresia, array vinos);

/*----------------------------------------------------------------------------*/
/*
  pre: la membresia debe haberse creado y no destruido.
  post: devuelve los vinos seleciconados por el usuario.
*/
string getArray(Membresia *membresia);

/*----------------------------------------------------------------------------*/
/*

#endif // MEMBRESIA_H_INCLUDED

#ifndef VINO_H_INCLUDED
#define VINO_H_INCLUDED
#include <sstream>
using namespace std;

struct Vino{

int idVino;
string etiqueta;
string bodega ;
string segmento_del_vino;
string varietal;
int anioCosecha;
string terroir;

};

/******************************************************************************/
/* Definicion de Primitivas */
/*--------------------------*/

/*
  pre : el vino no debe haber sido creado.
  post: el vino queda creado y preparada para ser usada con valores 0.
*/

Vino* crearVinoVacio(Vino *Vino);
/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido
  post: deja la instacia de la lista para ser usado. Los parametros se aplica al tda (vino).
*/

Vino* crearVino(Vino *Vino,int idVino,string etiqueta,string bodega,string segmento_del_vino,string varietal,int anioCosecha,string terroir);
/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: destruye la instancia del tda y ya no podrá ser usado.
*/
void destruir (Vino *Vino);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: asigna el valor de id a la instancia de Vino.
*/
void setId(Vino *Vino, int idVino);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: devuelve el id.
*/
int getIdVino(Vino *Vino);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: asigna el valor de nombre a la instancia de vino.
*/
void setEtiqueta(Vino *Vino, string etiqueta);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: devuelve el nombre.
*/
string getEtiqueta(Vino *Vino);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: asigna el valor de añoCosecha a la instancia de vino.
*/
void setAnioCosecha(Vino *Vino, int anioCosecha);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: devuelve  el añoCosecha.
*/
int getAnioCosecha(Vino *Vino);


/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: asigna el valor de Bodega a la instancia de vino.
*/
void setBodega(Vino *Vino, string bodega);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: devuelve el nombre bodega.
*/
string getBodega(Vino *Vino);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: asigna el valor de segmento_del_vino a la instancia de vino.
*/
void setSegmento(Vino *Vino, string segmento_del_vino);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: devuelve el nombre segmento_del_vino.
*/
string getSegmento(Vino *Vino);

/*----------------------------------------------------------------------------*/
/*
  pre: el vino debe haberse creado y no destruido.
  post: devuelve el nombre varieltal.
*/
string getVarietal(Vino *Vino);

/*----------------------------------------------------------------------------*/
/*
pre: el vino debe haberse creado y no destruido.
post: El campo varietal pasa a contener el dato ingresado.
*/
void setVarietal(Vino *vino,string varietal);
/*----------------------------------------------------------------------------*/

/*
  pre: el vino debe haberse creado y no destruido.
  post: devuelve el nombre terroir.
*/
string getTerroir(Vino *Vino);

/*----------------------------------------------------------------------------*/
/*
pre: el vino debe haberse creado y no destruido.
post: El campo terroir pasa a contener el dato ingresado.
*/
void setTerroir(Vino *vino, string terroir);
/*----------------------------------------------------------------------------*/


#endif // VINO_H_INCLUDED


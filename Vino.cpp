#include <iostream>
#include <stdlib.h>
#include "Vino.h"

using namespace std;

/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/

/*----------------------------------------------------------------------------*/
Vino* crearVinoVacio(Vino *vino) {
    vino = new Vino();
    return vino;
}

/*----------------------------------------------------------------------------*/
Vino* crearVino(Vino *vino, int idVino, string etiqueta,string bodega,string segmento_del_vino,string varietal, int anioCosecha,string terroir) {
    vino = new Vino();
    setId(vino,idVino);
    setEtiqueta(vino,etiqueta);
    setBodega(vino,bodega);
    setSegmento(vino,segmento_del_vino);
    setVarietal(vino,varietal);
    setAnioCosecha(vino,anioCosecha);
    setTerroir(vino,terroir);
    return vino;
}


/*----------------------------------------------------------------------------*/
void destruir(Vino *vino) {
    delete vino;
}

/*----------------------------------------------------------------------------*/
void setId(Vino *vino, int idVino) {
    vino->idVino = idVino;
}

/*----------------------------------------------------------------------------*/
int getIdVino(Vino *vino) {
    return vino->idVino;
}

/*----------------------------------------------------------------------------*/
void setEtiqueta(Vino *vino, string etiqueta) {
    vino->etiqueta = etiqueta;
}

/*----------------------------------------------------------------------------*/
string getEtiqueta(Vino *vino) {
    return vino->etiqueta;
}

/*----------------------------------------------------------------------------*/
void setAnioCosecha(Vino *vino, int anioCosecha) {
    vino->anioCosecha = anioCosecha;
}

/*----------------------------------------------------------------------------*/
int getAnioCosecha(Vino *vino) {
    return vino->anioCosecha;
}

/*----------------------------------------------------------------------------*/
string getBodega(Vino *vino) {
    return vino->bodega;
}

/*----------------------------------------------------------------------------*/
void setBodega(Vino *vino,string bodega){
    vino->bodega = bodega;
}
/*----------------------------------------------------------------------------*/
string getSegmento(Vino *vino) {
    return vino->segmento_del_vino;
}
/*----------------------------------------------------------------------------*/
void setSegmento(Vino *vino,string segmento){
    vino->segmento_del_vino = segmento;
}

/*----------------------------------------------------------------------------*/
string getVarietal(Vino *vino) {
    return vino->varietal;
}

/*----------------------------------------------------------------------------*/
void setVarietal(Vino *vino, string varietal){
    vino->varietal = varietal;
}
/*----------------------------------------------------------------------------*/
string getTerroir(Vino *vino) {
    return vino->terroir;
}

/*----------------------------------------------------------------------------*/

void setTerroir(Vino *vino,string terroir){
    vino->terroir = terroir;
}

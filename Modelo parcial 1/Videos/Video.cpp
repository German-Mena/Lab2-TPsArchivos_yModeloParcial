#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include "Video.h"

Video::Video()
{
    //ctor
}

int Video::getID() { return _id; }
void Video::setID(int val) { _id = val; }
char* Video::getTitulo() { return _titulo; }
void Video::setTitulo(const char *val) { strcpy(_titulo, val); }
bool Video::getContenidoNinios() { return _ninios; }
void Video::setContenidoNinios(bool val) { _ninios = val; }
Fecha Video::getFecha() { return _fecha; }
void Video::setFecha(Fecha val) { _fecha = val; }
int Video::getDuracion() { return _duracion; }
void Video::setDuracion(int val) { _duracion = val; }
int Video::getVisualizaciones() { return _visualizaciones; }
void Video::setVisualizaciones(int val) { _visualizaciones = val; }

void Video::mostrar(){
    cout << _id << "," << _titulo << "," << _ninios << "," << _fecha.getDia();
    cout << "/" << _fecha.getMes() << "/" << _fecha.getAnio() << ",";
    cout << _duracion << "," << _visualizaciones << endl;
}

void Video::mostrar2(){
    cout << _titulo << "," << _duracion << "," << _visualizaciones << "," << _fecha.getDia();
    cout << "/" << _fecha.getMes() << "/" << _fecha.getAnio() << endl;
}


void Video::mostrar3(){
    cout << _id << "," << _titulo << "," << _visualizaciones << endl;
}

bool Video::leerDeDisco(int pos){
    FILE *p;
    p = fopen("videos.dat", "rb");
    if (p == NULL){
        return false;
    }
    bool ok;
    fseek(p, sizeof(Video) * pos , 0);
    ok = fread(this, sizeof(Video), 1, p);
    fclose(p);
    return ok;
}
bool Video::grabarEnDisco(){
    FILE *p;
    p = fopen("videos.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool ok;
    ok = fwrite(this, sizeof(Video), 1, p);
    fclose(p);
    return ok;
}
bool Video::grabarEnDisco(int pos){
    FILE *p;
    p = fopen("videos.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p,pos * sizeof (Video),0);
    bool ok = fwrite(this, sizeof(Video), 1, p);
    fclose(p);
    return ok;
}

int buscarPosicionVideo(int ID){

    Video v1;
    int pos = 0;
    while(v1.leerDeDisco(pos++)){
        if(v1.getID() == ID) return pos-1;
    }
    return -1;
}

int contarVideos(){
    Video v1;
    int pos = 0;
    while(v1.leerDeDisco(pos++));
    return pos-1;
}

void ordenarVideosPorVisualizaciones(Video *v1){

    Video v2;

    int pos = 0;
    while(v2.leerDeDisco(pos++)){
        v1[pos-1] = v2;
    }

    int cantidadVideos = contarVideos();
    for(int i=0;i<cantidadVideos;i++){
        for(int j=0;j<cantidadVideos-1;j++){

            if(v1[j].getVisualizaciones() < v1[j+1].getVisualizaciones()){
                v2 = v1[j];
                v1[j] = v1[j+1];
                v1[j+1] = v2;
            }
        }
    }
}

int contarVideosPorAnio(int anio){

    Video v1;
    int pos = 0, cantidad = 0;
    while(v1.leerDeDisco(pos++)){
        if(v1.getFecha().getAnio() == anio) cantidad++;
    }
    return cantidad;
}

float porcentajeVideosNinios(int anio){

    Video v1;
    int pos = 0;
    float cantidad = 0;

    while(v1.leerDeDisco(pos++)){

        if(v1.getContenidoNinios() &&
           v1.getFecha().getAnio() == anio) cantidad++;
    }

    float porcentaje = (cantidad / contarVideosPorAnio(anio)) * 100;
    return porcentaje;
}

float porcentajeVideosAdultos(int anio){

    Video v1;
    int pos = 0;
    float cantidad = 0;

    while(v1.leerDeDisco(pos++)){

        if(!v1.getContenidoNinios() &&
           v1.getFecha().getAnio() == anio) cantidad++;
    }

    float porcentaje = (cantidad / contarVideosPorAnio(anio)) * 100;
    return porcentaje;
}

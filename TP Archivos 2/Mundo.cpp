#include "Mundo.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;

void Mundo::setCodigoPais(char *codigoPais){
    strcpy(_codigoPais,codigoPais);
}

void Mundo::setNombrePais(char *nombrePais){
    strcpy(_nombrePais,nombrePais);
}

void Mundo::setNombreCiudad(char *nombreCiudad){
    strcpy(_nombreCiudad, nombreCiudad);
}

void Mundo::setPoblacion(int poblacion){
    _poblacion = poblacion;
}

char* Mundo::getCodigoPais(){
    return _codigoPais;
}

char* Mundo::getNombrePais(){
    return _nombrePais;
}

char* Mundo::getNombreCiudad(){
    return _nombreCiudad;
}

int Mundo::getPoblacion(){
    return _poblacion;
}

bool Mundo::leerDeDisco(int pos){

    FILE *p = fopen("mundo.dat","rb+");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de mundo!";
        exit(1);
    }

    fseek(p,pos * sizeof (Mundo),0);
    bool read = fread(this,sizeof (Mundo),1,p);
    fclose(p);
    return read;
}

bool Mundo::escribirEnDisco(int pos){

    FILE *p = fopen("mundo.dat","rb+");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de mundo!";
        exit(1);
    }

    fseek(p,pos * sizeof (Mundo),0);
    bool write = fwrite(this,sizeof (Mundo),1,p);
    fclose(p);
    return write;
}

bool Mundo::escribirEnDisco(){

    FILE *p = fopen("mundo.dat","ab");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de mundo!";
        exit(1);
    }

    bool write = fwrite(this,sizeof (Mundo),1,p);
    fclose(p);
    return write;
}

void Mundo::mostrar(){
    cout << _codigoPais << " " << _nombrePais << " " << _nombreCiudad << " " << _poblacion << endl;
}


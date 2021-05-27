#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"
#include "funciones.h"
#include "Mundo.h"

void pto1(){

    system("cls");
    int cantidad = contarPaises();

    Pais *vectorPaises = new Pais[cantidad];
    if(vectorPaises == NULL){
        delete []vectorPaises;
        cout<<"No hay espacio en memoria!";
        exit(1);
    }

    if(cargarVector(vectorPaises)){

        ordenarVector(vectorPaises, cantidad);

        mostrarVector(vectorPaises, cantidad);
    } else {
        cout<<"No se pudo abrir el archivo de paises!";
    }


    delete []vectorPaises;
    system("pause>null");
}

int contarPaises(){

    FILE *p;
    p = fopen("paises.dat","rb");
    if(p==NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de paises!";
        exit(1);
    }

    fseek(p,0,2);
    int cantidad = ftell(p) /sizeof (Pais);
    fclose(p);
    return cantidad;
}

bool cargarVector(Pais *vectorPaises){

    FILE *p;
    p = fopen("paises.dat","rb");
    if(p==NULL){
        fclose(p);
        return false;
    }

    int pos = 0;
    Pais p1;
    while(fread(&p1,sizeof (Pais),1,p)){
        vectorPaises[pos] = p1;
        pos ++;
    }

    fclose(p);
    return true;
}

void mostrarVector(Pais *vectorPaises, int cantidad){

    for(int i=0;i<cantidad;i++){
        cout<<vectorPaises[i].getCodigo()<<" "<<vectorPaises[i].getNombre()<<" "<<vectorPaises[i].getPoblacion()<<endl;
    }
}

void ordenarVector(Pais *vectorPaises, int cantidad){

    Pais p;

    for(int i=0;i<cantidad;i++){

        for(int j=0;j<cantidad-1;j++){

            if(vectorPaises[j].getPoblacion() < vectorPaises[j+1].getPoblacion()){

                p = vectorPaises[j];
                vectorPaises[j] = vectorPaises[j+1];
                vectorPaises[j+1] = p;
            }
        }
    }
}

void pto2(){

    system("cls");

    int ID, poblacion;
    char nombre[35], IDPais[4];

    Ciudad nuevaCiudad;

    cout<<"ID: ";
    cin>>ID;

    while(buscarIDCiudad(ID)){
        cout<<"El ID ya existe, ingrese nuevamente: ";
        cin>>ID;
    }

    cout<<"Nombre: ";
    cin>>nombre;

    cout<<"ID de Pais: ";
    cin>>IDPais;

    while(!buscarIDPais(IDPais)){
        cout<<"ID de Pais inexistente, ingrese nuevamente: ";
        cin>>IDPais;
    }

    cout<<"Poblacion: ";
    cin>>poblacion;

    while(poblacion < 0){
        cout<<"poblacion invalida, ingrese nuevamente: ";
        cin>>poblacion;
    }

    nuevaCiudad.setID(ID);
    nuevaCiudad.setIDPais(IDPais);
    nuevaCiudad.setNombre(nombre);
    nuevaCiudad.setPoblacion(poblacion);

    if(guardarNuevaCiudad(nuevaCiudad)){
        cout<<"Ciudad guardada con exito!";
    } else {
        cout<<"No se pudo guardar la ciudad";
    }

    system("pause>null");
}

bool buscarIDCiudad(int ID){

    FILE *p = fopen("ciudades.dat","rb");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de ciudades!";
        exit(1);
    }

    Ciudad c1;

    while(fread(&c1,sizeof c1,1,p)){
        if(c1.getID() == ID){
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

bool buscarIDPais(char *IDPais){

    FILE *p = fopen("paises.dat","rb");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de paises!";
        exit(1);
    }

    Pais p1;

    while(fread(&p1,sizeof p1,1,p)){
        if(strcmp(p1.getCodigo(),IDPais) == 0){
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

bool guardarNuevaCiudad(Ciudad nuevaCiudad){

    FILE *p = fopen("ciudades.dat","ab");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de ciudades!";
        exit(1);
    }

    bool write = fwrite(&nuevaCiudad,sizeof nuevaCiudad,1,p);
    fclose(p);
    return write;
}

void pto3(){

    system("cls");
    char nombreCiudad[35];

    cout<<"Ingrese el nombre de la ciudad: ";
    cin>>nombreCiudad;

    while(!buscarNombreCiudad(nombreCiudad)){
        cout<<"Ciudad inexistente, ingrese nuevamente: ";
        cin>>nombreCiudad;
    }

    cout<<"Posicion de ciudad "<<nombreCiudad<<" en ranking por poblacion: "<<posicionEnRankingPorPoblacion(nombreCiudad);
    system("pause>null");
}

int posicionEnRankingPorPoblacion(char *nombreCiudad){

    int cantidad = cantidadCiudades();
    Ciudad *vectorCiudades = new Ciudad[cantidad];

    if(vectorCiudades == NULL){
        delete []vectorCiudades ;
        cout<<"No se pudo pedir memoria dinamica!";
        exit(1);
    }

    cargarVectorCiudades(vectorCiudades);
    ordenarVectorCiudades(vectorCiudades, cantidad);

    int pos = posicionCiudad(nombreCiudad, vectorCiudades, cantidad);
    delete []vectorCiudades;
    return pos;
}

void mostrarVectorCiudades(Ciudad *vectorCiudades, int cantidad){

    for(int i=0;i<cantidad;i++){
        vectorCiudades[i].mostrar();
    }
    cout<<endl;
}

bool buscarNombreCiudad(char *nombreCiudad){

    FILE *p;
    p = fopen("ciudades.dat","rb");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de ciudades!";
        exit(1);
    }

    Ciudad c1;

    while(fread(&c1,sizeof c1,1,p)){
        if(strcmp(c1.getNombre(), nombreCiudad) == 0){
            fclose(p);
            return true;
        }
    }

    fclose(p);
    return false;
}

int cantidadCiudades(){

    FILE *p = fopen("ciudades.dat","rb+");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de ciudades!";
        exit(1);
    }

    fseek(p,0,2);
    int cantidad = ftell(p) / sizeof (Ciudad);
    fclose(p);
    return cantidad;
}

void cargarVectorCiudades(Ciudad *vectorCiudades){

    FILE *p;
    p = fopen("ciudades.dat","rb");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de ciudades!";
        exit(1);
    }

    Ciudad c1;
    int pos = 0;

    while(fread(&c1,sizeof (Ciudad),1,p)){
        vectorCiudades[pos] = c1;
        pos++;
    }

    fclose(p);
}

void ordenarVectorCiudades(Ciudad *vectorCiudades, int cantidad){

    Ciudad c;

    for(int i=0;i<cantidad;i++){

        for(int j=0;j<cantidad-1;j++){

            if(vectorCiudades[j].getPoblacion() < vectorCiudades[j+1].getPoblacion()){

                c = vectorCiudades[j];
                vectorCiudades[j] = vectorCiudades[j+1];
                vectorCiudades[j+1] = c;
            }
        }
    }
}

int posicionCiudad(char *nombreCiudad, Ciudad *vectorCiudades, int cantidad){

    for(int i=0;i<cantidad;i++){
        if(strcmp(vectorCiudades[i].getNombre(), nombreCiudad) == 0){
            return i + 1;
        }
    }
}

void pto4(){

    system("cls");
    char IDPais[4];

    cout<<"Ingrese el codigo del pais: ";
    cin>>IDPais;

    while(!buscarIDPais(IDPais)){
        cout<<"Codigo de pais inexistente, ingrese nuevamente: ";
        cin>>IDPais;
    }

    int poblacion;

    cout<<"Ingrese el nuevo valor de poblacion: ";
    cin>>poblacion;

    while(poblacion < 0){

        cout<<"Valor de poblacion invalido, ingrese nuevamente: ";
        cin>>poblacion;
    }

    if(actualizarPoblacionPais(IDPais,poblacion)){
        cout<<"Poblacion actualizada con exito!";
    } else {
        cout<<"No se pudo actualizar la poblacion";
    }

    system("pause>null");
}

bool actualizarPoblacionPais(char *IDPais, int poblacion){

    Pais p1;
    int pos = 0;
    while(p1.leerDeDisco(pos++)){
        if(strcmp(p1.getCodigo(),IDPais) == 0){
            p1.setPoblacion(poblacion);
            return p1.guardarEnDisco(pos);
        }
    }
}

void pto5(){

    system("cls");

    Pais p1;
    Mundo m1;
    int pos = 0;

    //IMPORTANTE: Tengo que pasar la ciudad como referencia porque la funcion
    //ciudadConMaximaPoblacion devuelve un puntero a un vector que se elimina
    //cuando termina esa funcion. Es decir, apunta a un lugar que no hay nada.
    //Para evitar eso, creo la cadena de caracteres aca y la completo en la funcion.
    char ciudad[35];

    while(p1.leerDeDisco(pos++)){
        m1.setCodigoPais(p1.getCodigo());
        m1.setNombrePais(p1.getNombre());
        ciudadConMaximaPoblacion(p1.getCodigo(), ciudad);
        m1.setNombreCiudad(ciudad);
        m1.setPoblacion(poblacionCiudad(m1.getNombreCiudad()));
        m1.mostrar();
        m1.escribirEnDisco();
    }
}

void ciudadConMaximaPoblacion(char *codigoPais, char *ciudad){

    Ciudad c1;
    int pos = 0;
    int maxPoblacion = -1;

    while(c1.leerDeDisco(pos++)){
        if(strcmp(c1.getIDPais(),codigoPais) == 0){
            if(c1.getPoblacion() > maxPoblacion){
                maxPoblacion = c1.getPoblacion();
                strcpy(ciudad,c1.getNombre());
            }
        }
    }
}

int poblacionCiudad(char *nombreCiudad){

    Ciudad c1;
    int pos = 0;

    while(c1.leerDeDisco(pos++)){
        if(strcmp(c1.getNombre(),nombreCiudad) == 0){
            return c1.getPoblacion();
        }
    }
}

void mostrarMundo(){

    system("cls");

    Mundo m1;
    int pos = 0;

    while(m1.leerDeDisco(pos++)){
        m1.mostrar();
    }

    system("pause>null");
}

void mostrarPaises(){

    system("cls");

    Pais p1;
    FILE *p;
    p = fopen("paises.dat", "rb");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo paises!";
        exit(1);
    }

    while(fread(&p1,sizeof p1,1,p) == 1){
        p1.mostrar();
    }

    fclose(p);
    system("pause>null");
}

void mostrarCiudades(){

    system("cls");

    Ciudad c1;
    FILE *p;
    p = fopen("ciudades.dat", "rb");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de ciudades!";
        exit(1);
    }

    while(fread(&c1,sizeof c1,1,p)){
        c1.mostrar();
    }

    fclose(p);
    system("pause>null");
}

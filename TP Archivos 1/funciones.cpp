#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"
#include "funciones.h"

void pto1(){

    system("cls");
    char codigoPais[4];

    cout<<"Ingrese el codigo de pais: ";
    cin>>codigoPais;

    if(buscarPais(codigoPais)){
        cout<<"El pais existe";
    } else {
        cout<<"El pais no existe";
    }

    system("pause>null");
}

bool buscarPais(char *codigoPais){
    Pais p1;
    FILE *p;
    p = fopen("paises.dat","rb");

    if(p == NULL){
        cout<<"No se pudo abrir el archivo paises!";
        exit(1);
    }

    while(fread(&p1,sizeof p1,1,p)){
        if(strcmp(codigoPais, p1.getCodigo()) == 0){
            fclose(p);
            return true;
        }
    }

    return false;
}

bool pto2(Pais Pais2){

    FILE *p;
    p = fopen("paises.dat","ab");
    if(p==NULL){
        cout<<"No se pudo abrir el archivo paises!";
        exit(1);
    }

    if(fwrite(&Pais2,sizeof Pais2,1,p)){
        fclose(p);
        return true;
    }

    else return false;
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

void pto4(){

    system("cls");
    char codigoPais[4];

    cout<<"Ingrese el codigo de pais: ";
    cin>>codigoPais;

    if(buscarPais(codigoPais)){
        mostrarCiudadesPorCodigoPais(codigoPais);
    } else {
        cout<<"El pais no existe";
    }

    system("pause>null");
}


int buscarCapitalPais(char *codigoPais){
    Pais p1;
    FILE *p;
    p = fopen("paises.dat","rb");
    if(p==NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de paises!";
        exit(1);
    }

    while(fread(&p1,sizeof p1,1,p)){
        if(strcmp(p1.getCodigo(),codigoPais) == 0){
            return p1.getIDCapital();
        }
    }

    return -1;
}


void mostrarCiudadesPorCodigoPais(char *codigoPais){

    int capitalPais = buscarCapitalPais(codigoPais);
    char nombreCapital[35];
    Ciudad c1;
    FILE *p;
    p = fopen("ciudades.dat","rb");

    if(p==NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de ciudades!";
        exit(1);
    }

    while(fread(&c1,sizeof c1,1,p)){
        if(strcmp(c1.getIDPais(),codigoPais) == 0){

            if(c1.getID() == capitalPais){
                strcpy(nombreCapital,c1.getNombre());
            }

            cout<<"Ciudad: "<<c1.getNombre()<<endl;
            cout<<"Poblacion: "<<c1.getPoblacion()<<endl<<endl;
        }
    }

    fclose(p);
    cout<<"Capital: "<<nombreCapital;
}

void pto5(){

    system("cls");

    float superficieTotal = calcularSuperficieTotal();
    Pais p1;
    FILE *p;
    p = fopen("paises.dat","rb");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de paises!";
        exit(1);
    }

    while(fread(&p1,sizeof p1,1,p)){
        cout<<"Pais: "<<p1.getNombre()<<endl;
        cout<<"Superficie: "<<p1.getSuperficie()<<endl;
        cout<<"Porcentaje: %"<<(p1.getSuperficie() / superficieTotal) * 100 <<endl<<endl;
    }

    fclose(p);
    system("pause>null");
}

int calcularSuperficieTotal(){

    float superficieTotal = 0;
    Pais p1;
    FILE *p;
    p = fopen("paises.dat","rb");
    if(p == NULL){
        fclose(p);
        cout<<"No se pudo abrir el archivo de paises!";
        exit(1);
    }

    while(fread(&p1,sizeof p1,1,p)){
        superficieTotal += p1.getSuperficie();
    }

    fclose(p);
    return superficieTotal;
}




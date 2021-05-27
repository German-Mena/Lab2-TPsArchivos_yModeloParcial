#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
#include "funciones.h"
#include "Video.h"

void visualizarVideo(){

    system("cls");

    int ID;
    Video v1;

    cout<<"Ingrese el ID del video: ";
    cin>>ID;

    while(buscarPosicionVideo(ID) == -1){
        cout<<"El ID no existe, ingrese el ID del video: ";
        cin>>ID;
    }

    v1.leerDeDisco(buscarPosicionVideo(ID));
    v1.mostrar2();
    v1.setVisualizaciones(v1.getVisualizaciones()+1);
    if(v1.grabarEnDisco(buscarPosicionVideo(ID))){
        cout<<"Visualizaciones de '"<<v1.getTitulo()<<"' actualizadas!";
    }else{
        cout<<"No se pudo actualizar las visualizaciones de "<<v1.getTitulo();
    }

    system("pause>null");
}

void ranking10(){

    system("cls");

    Video *v1 = new Video[contarVideos()];
    if(v1 == NULL){
        delete []v1;
        cout<<"Ocurrio un error!";
        exit(1);
    }

    ordenarVideosPorVisualizaciones(v1);

    for(int i=0;i<10;i++) v1[i].mostrar3();

    delete []v1;
    system("pause>null");
}

void mostrarPorcentaje(){

    system("cls");

    int anioInicio, anioFin;

    cout<<"Ingrese el anio de inicio: ";
    cin>>anioInicio;

    cout<<"Ingrese el anio de fin: ";
    cin>>anioFin;

    while(anioInicio > anioFin){

        cout<<endl<<"Anios invalidos!"<<endl;

        cout<<"Ingrese el anio de inicio: ";
        cin>>anioInicio;

        cout<<"Ingrese el anio de fin: ";
        cin>>anioFin;
    }

    int cantidadAnios = anioFin - anioInicio;
    float aux;

    for(int i=0;i<=cantidadAnios;i++){

        cout<<endl<<"Anio "<<anioInicio+i<<":"<<endl;

        aux = porcentajeVideosNinios(anioInicio+i);

        if(isnan(aux)){
            cout<<"Porcentaje de videos con contenido para ninios: Sin videos"<<endl;
        } else {
            cout<<"Porcentaje de videos con contenido para ninios: "<<aux<<"%"<<endl;
        }

        aux = porcentajeVideosAdultos(anioInicio+i);

        if(isnan(aux)){
            cout<<"Porcentaje de videos con contenido para adultos: Sin videos"<<endl;
        } else {
            cout<<"Porcentaje de videos con contenido para adultos: "<<aux<<"%"<<endl;
        }
    }

    system("pause>null");
}





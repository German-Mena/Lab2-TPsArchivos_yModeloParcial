#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Pais.h"
#include "Ciudad.h"


void pto1();
    int contarPaises();
    bool cargarVector(Pais*);
    void ordenarVector(Pais*,int);
    void mostrarVector(Pais*,int);
void pto2();
    bool buscarIDCiudad(int);
    bool buscarIDPais(char*);
    bool guardarNuevaCiudad(Ciudad);
void pto3();
    bool buscarNombreCiudad(char*);
    int posicionEnRankingPorPoblacion(char*);
    int cantidadCiudades();
    void cargarVectorCiudades(Ciudad*);
    void ordenarVectorCiudades(Ciudad*,int);
    void mostrarVectorCiudades(Ciudad*,int);
    int posicionCiudad(char*,Ciudad*,int);
void pto4();
    bool actualizarPoblacionPais(char*,int);
void pto5();
    void ciudadConMaximaPoblacion(char*,char*);
    int poblacionCiudad(char*);


void mostrarPaises();
void mostrarCiudades();
void mostrarMundo();


#endif // FUNCIONES_H_INCLUDED

#include "LaraIce.h"
#include <cstring>
#include <cstdio>
#include <iostream>
#include <stdlib.h>
using namespace std;

LaraIce::LaraIce(bool encendido){
    _encendido = encendido;
    _deposito = 0;
}


bool LaraIce::llenar(float cantidad){

    if(_deposito + cantidad > 2000) return false;
    else _deposito += cantidad;
    return true;
}

int LaraIce::getHielo(int tam){
    if(_encendido){
        if(tam == 1 && _deposito > 15){
            _deposito -= 15;
            _cantidadHielosChicos++;
            return 1;
        }
        if(tam == 2 && _deposito > 25){
            _deposito -= 25;
            _cantidadHielosGrandes++;
            return 2;
        }
    }

    return 0;
}

void LaraIce::vaciar(){
    _deposito = 0;
}

void LaraIce::encender(){

    if(!_encendido){
        _encendido = true;
        _cantidadHielosChicos = 0;
        _cantidadHielosGrandes = 0;
    }
}

void LaraIce::apagar(){
    if(_encendido){
        _encendido = false;
        cout<<"Hielos chicos realizados: "<<_cantidadHielosChicos<<endl;
        cout<<"Hielos grandes realizados: "<<_cantidadHielosGrandes<<endl<<endl;
    }
}


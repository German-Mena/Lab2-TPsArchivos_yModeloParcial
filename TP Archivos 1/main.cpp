#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Pais.h"
#include "Ciudad.h"
#include "funciones.h"

int main()
{

    int opc;
    bool salir = false;

    while(!salir){

        system("cls");

        cout<<"1-Buscar pais"<<endl;
        cout<<"2-Cargar pais"<<endl;
        cout<<"3-Mostrar paises"<<endl;
        cout<<"4-Mostrar ciudades de pais"<<endl;
        cout<<"5-Punto 5"<<endl<<endl;
        cout<<"00-Salir"<<endl;

        cout<<"Opc: ";
        cin>>opc;

        switch(opc){

            case 1:{pto1();}break;

            //case 2:{pto2();}break;

            case 3:{mostrarPaises();}break;

            case 4:{pto4();}break;

            case 5:{pto5();}break;

            case 00:{salir = true;}break;

            default:{
                cout<<"Opcion incorrecta!";
                system("pause>null");
            }break;
        }
    }

    return 0;
}

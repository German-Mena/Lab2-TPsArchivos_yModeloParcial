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

        cout<<"1-Punto 1"<<endl;
        cout<<"2-Punto 2"<<endl;
        cout<<"3-Punto 3"<<endl;
        cout<<"4-Punto 4"<<endl;
        cout<<"5-Punto 5"<<endl;
        cout<<"6-Mostrar archivo mundo"<<endl<<endl;
        cout<<"00-Salir"<<endl;

        cout<<"Opc: ";
        cin>>opc;

        switch(opc){

            case 1:{pto1();}break;

            case 2:{pto2();}break;

            case 3:{pto3();}break;

            case 4:{pto4();}break;

            case 5:{pto5();}break;

            case 6:{mostrarMundo();}break;

            case 00:{salir = true;}break;

            default:{
                cout<<"Opcion incorrecta!";
                system("pause>null");
            }break;
        }
    }

    return 0;
}

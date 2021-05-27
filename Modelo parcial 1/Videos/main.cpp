#include <iostream>
#include <stdlib.h>
using namespace std;
#include "Video.h"
#include "funciones.h"

int main()
{
    int opc;
    bool salir = false;

    while(!salir){

        system("cls");

        cout<<"1-Visualizar Video"<<endl;
        cout<<"2-Ranking 10 videos mas vistos"<<endl;
        cout<<"3-Mostrar Porcentaje"<<endl;
        cout<<"4-Mostrar todos los Videos"<<endl<<endl;
        cout<<"00-Salir"<<endl;

        cout<<"Opc: ";
        cin>>opc;

        switch(opc){

            case 1:{visualizarVideo();}break;

            case 2:{ranking10();}break;

            case 3:{mostrarPorcentaje();}break;

            case 4:{
                system("cls");
                Video v1;
                int pos = 0;
                while(v1.leerDeDisco(pos++)){
                    v1.mostrar();
                }
                system("pause>null");

            }break;

            case 00:{salir = true;}break;

            default:{
                cout<<"Opcion incorrecta!";
                system("pause>null");
            }break;
        }
    }

    return 0;
}

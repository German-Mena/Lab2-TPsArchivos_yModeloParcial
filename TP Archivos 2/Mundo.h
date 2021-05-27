#ifndef MUNDO_H_INCLUDED
#define MUNDO_H_INCLUDED

class Mundo{

private:
    char _codigoPais[4];
    char _nombrePais[45];
    char _nombreCiudad[35];
    int _poblacion;

public:
    void setCodigoPais(char*);
    void setNombrePais(char*);
    void setNombreCiudad(char*);
    void setPoblacion(int);

    char* getCodigoPais();
    char* getNombrePais();
    char* getNombreCiudad();
    int getPoblacion();

    bool leerDeDisco(int);
    bool escribirEnDisco(int);
    bool escribirEnDisco();

    void mostrar();

};

#endif // MUNDO_H_INCLUDED

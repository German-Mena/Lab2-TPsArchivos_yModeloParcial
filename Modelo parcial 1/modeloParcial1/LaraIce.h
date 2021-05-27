#ifndef LARAICE_H_INCLUDED
#define LARAICE_H_INCLUDED

class LaraIce{

private:
    bool _encendido;
    float _deposito;
    int _cantidadHielosChicos;
    int _cantidadHielosGrandes;

public:

    LaraIce(bool = false);

    bool llenar(float);
    int getHielo(int);
    void vaciar();
    bool encender();
    void apagar();
};

#endif // LARAICE_H_INCLUDED

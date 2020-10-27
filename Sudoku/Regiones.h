/*
 * Universidad la Fuerzas Armadas ESPE
 *
 * @autor David Munoz & Daniela Orellana
 * @date Jueves, 7 de julio de 2020 17:16:14
 * @function Declaration of Regiones
*/

#ifndef REGIONES_H
#define REGIONES_H


class Regiones
{
public:
    Regiones();
    Regiones(int**);
    int** llenar(int, int);
    void mostrar(int, int);
    int** get_Region();
    void set_Region(int**);
    void iniciar();

    virtual ~Regiones();
protected:
private:
    int** cuadrado;
};

#endif // REGIONES_H

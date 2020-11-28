#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>

using namespace std;

class Civilizacion {
private:
    std::string nombre;
    int x;
    int y;
    float puntuacion;
public:
    Civilizacion(); // constructor
    Civilizacion(const std::string nombre,
             const int x, const int y, const float puntuacion); // sobrecarga

    /* Getters */
    std::string getNombre();
    int getX();
    int getY();
    float getPuntuacion();

    /* Setters */
    void setNombre(const std::string &n);
    void setX(const int &x);
    void setY(const int &y);
    void setPuntuacion(const float &p);

    /* Salida del Modelo */
    friend ostream& operator<<(ostream &out, const Civilizacion &c) {

        out << left;
        out << setw(20) << c.nombre;
        out << setw(10) << c.x;
        out << setw(20) << c.y;
        out << setw(16) << c.puntuacion;
        out << endl;

        return out;
    }

    /* Entrada del Modelo */
    friend istream& operator>>(istream &in, Civilizacion &c) {

        cout << "\tNombre     : ";
        getline(cin, c.nombre);

        cout << "\tPosicion X : ";
        cin >> c.x;
        cin.ignore();

        cout << "\tPosicion Y : ";
        cin >> c.y;
        cin.ignore();

        cout << "\tPuntuacion : ";
        cin >> c.puntuacion;
        cin.ignore();

        return in;
    }

    /* Operadores Logicos */

    bool operator==(const Civilizacion& c) {
        return nombre == c.nombre;
    }

    bool operator==(const Civilizacion& c) const {
        return nombre == c.nombre;
    }

    bool operator<(const Civilizacion& c) { // para metodo Ordenar()
        return 2;
    }

    bool operator<(const Civilizacion& c) const { // para metodo Ordenar()
        return nombre < c.nombre;
    }

};

#endif

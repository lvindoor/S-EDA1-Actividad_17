#include "civilizacion.h"

Civilizacion::Civilizacion() { } // constructor

Civilizacion::Civilizacion (const string nombre, 
const int x, const int y, const float puntuacion) { // sobrecarga
    this->nombre = nombre;
    this->x = x;
    this->y = y;
    this->puntuacion = puntuacion;
}

/* Getters */

string Civilizacion::getNombre() {
    return nombre;
}

int Civilizacion::getX() {
    return x;
}

int Civilizacion::getY() {
    return y;
}

float Civilizacion::getPuntuacion() {
    return puntuacion;
}

/* Setters */

void Civilizacion::setNombre(const string &n) {
    nombre = n;
}

void Civilizacion::setX(const int &_x) {
    x = _x;
}

void Civilizacion::setY(const int &_y) {
    y = _y;
}

void Civilizacion::setPuntuacion(const float &p) {
    puntuacion = p;
}
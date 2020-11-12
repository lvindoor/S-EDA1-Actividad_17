#ifndef VIDEOJGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class Videogame {

    std::string nombreUsuario;
    vector<Civilizacion> civilizaciones;

public:

    Videogame(); // constructor
    void agregarCivilizacion(const Civilizacion &c); // sobrecarga

    void mostrar();
    void respaldar_tabla();
    void respaldar();
    void recuperar();

    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    Civilizacion front();
    Civilizacion back();
    void inicializar(const Civilizacion &c, size_t n);
    void eliminar(size_t pos);
    
    /* Ordenamientos */

    void ordenarNombre(); 
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();
    
    Civilizacion* buscar(const Civilizacion &c);

    friend Videogame& operator<<(Videogame &v, const Civilizacion &c)
    {
        v.agregarCivilizacion(c);

        return v;
    }
};

#endif
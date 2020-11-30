#include <iostream>
#include "videogame.h"

using namespace std;

#ifdef _WIN32
#define CLEAN_SCREEN "cls"
#else
#define CLEAN_SCREEN "clear"
#endif // _WIN32

/* Opciones Menu */
enum {
    NOMBRE_USUARIO = 1,
    AGREGAR,
    INSERTAR,
    INICIALIZAR,
    PRIMERA,
    ULTIMA,
    ORDENAR,
    ELIMINAR,
    BUSCAR,
    MODIFICAR,
    MOSTRAR,
    SALIR
};

/* Opciones Sub-Menu -> Ordenar */

enum {
    ORDENAR_NOMBRE = 1,
    ORDENAR_X,
    ORDENAR_Y,
    ORDENAR_PUNTUACION,
    ORDENAR_REGRESAR
};

/* Opciones Sub-Menu -> Modificar */

enum {
    MODIFICAR_NOMBRE = 1,
    MODIFICAR_X,
    MODIFICAR_Y,
    MODIFICAR_PUNTUACION,
    MODIFICAR_REGRESAR
};

int main() {

    Videogame v;

    int opc; // creamos una opcion para el menu
    Civilizacion c; // creamos una variable civilización temporal
    string nombreUsuario; // variable para nombre de usuario -> civilizacion
    bool continueProgram = true; // comenzamos el menu ciclico

    do {

        cout << endl;
        cout << "\t--------------------------------------------" << endl;
        cout << "\t                  MENU                     " << endl;
        cout << "\t--------------------------------------------" << endl << endl;
        cout << "\t1-. Nombre Usuario - " << c.getNombre() << endl;
        cout << "\t2-. Agregar Civilizacion" << endl;
        cout << "\t3-. Insertar" << endl;
        cout << "\t4-. Inicializar" << endl;
        cout << "\t5-. Primer Civilizacion" << endl;
        cout << "\t6-. Ultima Civilizacion" << endl;
        cout << "\t7-. Ordenar" << endl;
        cout << "\t8-. Eliminar" << endl;
        cout << "\t9-. Buscar" << endl;
        cout << "\t10-. Modificar" << endl;
        cout << "\t11-. Resumen" << endl;
        cout << "\t12-. Salir" << endl;
        cout << endl << "\topcion : ";
        cin >> opc; cin.ignore();

        if(opc!=SALIR) {
            cout << endl << "\tPresione entrar para continuar ..." << endl;
            cin.get();
            system(CLEAN_SCREEN);
            cout << endl << endl;
        }

        /* Evaluamos */
        switch(opc) {

        case NOMBRE_USUARIO: {
            cout << "\tIngrese el nombre de usuario : ";
            getline(cin,nombreUsuario); // guardamos
            c.setNombre(nombreUsuario); // agregamos a la actual civilización

        }
        break;

        case AGREGAR: {

            if(nombreUsuario == "") { // no se ha agregado nombre de usuario
                cin >> c; // pedimos datos y guardamos
                v.agregarCivilizacion(c); // agregamos al arreglo
            } else { // ya hay un nombre usuario
                /* Variables temporales */
                int tempInt;
                float tempFloat;
                /* Pedimos datos faltantes */
                cout << "\tPosicion X : ";
                cin >> tempInt;
                c.setX(tempInt);
                cin.ignore();
                cout << "\tPosicion Y : ";
                cin >> tempInt;
                c.setY(tempInt);
                cin.ignore();
                cout << "\tPuntuacion : ";
                cin >> tempFloat;
                c.setPuntuacion(tempFloat);
                cin.ignore();
                v.agregarCivilizacion(c); // agregamos al arreglo
                nombreUsuario = ""; // limpiamos el nombre de usuario
            }

        }
        break;

        case INSERTAR:
            size_t p; // creamos una variable posición

            cout << "\tPosicion a insertar : ";
            cin >> p; cin.ignore();
            cin >> c; // pedimos datos y guardamos
            cout << endl;

            if (p >= v.size()) { // ¿Posición valida?
                cout << "\tposicion no valida" << endl;
            } else {
                v.insertar(c,p); // insertamos en p
            }
            break;

        case INICIALIZAR:
            size_t n; // creamos una variable de tamaño

            cout << "\tDimension de vector : ";
            cin >> n; cin.ignore(); // guardamos el nuevo tamaño
            cout << endl << "\t  Inicializando con ... " << endl << endl;
            cin >> c; // guardamos la cadena a inicializar
            cout << endl;

            v.inicializar(c,n); // declaramos el cambio en el vector
            break;

        case PRIMERA:
            cout << "\tLa primera civilizacion es: " << endl;
            if(v.size()>0) {
                cout << "\t" << v.front(); // traemos la primera civilizacion
            } else {
                cout << "\tNo hay civilizaciones" << endl;
            }
            break;

        case ULTIMA:
            cout << "\tLa ultima civilizacion es: " << endl;
            if(v.size()>0) {
                cout  << "\t" << v.back(); // traemos la ultima civilizacion
            } else {
                cout << "\tNo hay civilizaciones" << endl;
            }
            break;

        case ORDENAR: {

            int opc; // creamos una opcion para el submenu
            bool continueProgram = true; // comenzamos el submenu ciclico

            do {

                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t               ORDENACIONES POR              " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\t1-. Nombre Usuario " << endl;
                cout << "\t2-. Posicion en X" << endl;
                cout << "\t3-. Posicion en Y" << endl;
                cout << "\t4-. Puntuacion" << endl;
                cout << "\t5-. Regresar" << endl;
                cout << endl << "\topcion : ";
                cin >> opc; cin.ignore();
                cout << endl;

                /* Evaluamos */
                switch(opc) {
                    case ORDENAR_NOMBRE:
                        v.ordenarNombre();
                        break;
                    case ORDENAR_X:
                        v.ordenarX();
                        break;
                    case ORDENAR_Y:
                        v.ordenarY();
                        break;
                    case ORDENAR_PUNTUACION:
                        v.ordenarPuntuacion();
                        break;
                    case ORDENAR_REGRESAR:
                        continueProgram = false;
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                        break;
                }

                cout << endl << "\tDesea seguir modificando (S/N) : ";
                if(cin.get() != 'S') {
                    continueProgram = false;
                }

                if(continueProgram) {
                    cout << endl << "\tPresione entrar para continuar ..." << endl;
                    cin.get();
                    system(CLEAN_SCREEN);
                    cout << endl << endl;
                }
            } while(continueProgram);
        }
        break;

        case ELIMINAR: {

            cout << "\tEscriba el nombre de la civilizacion a borrar..." << endl << endl;
            cout << "\tNombre : ";
            getline(cin,nombreUsuario); // pedimos la civilizacion
            c.setNombre(nombreUsuario); // agregamos al modelo
            cout << endl;

            Civilizacion *ptr = v.buscar(c); // buscamos

            if(ptr==nullptr) {
                cout << "\tNo encontrado" << endl;
            } else {
                v.eliminar(*ptr); // eliminamos en p
            }
        }
        break;

        case BUSCAR: {
                cout << "\tEscriba el nombre de la civilizacion a buscar..." << endl << endl;
                cout << "\tNombre : ";
                getline(cin,nombreUsuario); // pedimos la civilizacion
                c.setNombre(nombreUsuario); // agregamos al modelo
                cout << endl;

                Civilizacion *ptr = v.buscar(c); // buscamos

                if(ptr==nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *ptr << endl;
                }
            }
            break;

        case MODIFICAR: {

            int opc; // creamos una opcion para el submenu
            bool continueProgram = true; // comenzamos el submenu ciclico

            do {

                cout << endl;
                cout << "\t--------------------------------------------" << endl;
                cout << "\t                   MODIFICAR               " << endl;
                cout << "\t--------------------------------------------" << endl << endl;
                cout << "\tEscriba el nombre de la civilizacion a buscar. " << endl << endl;

                cout << "\tNombre : ";
                getline(cin,nombreUsuario); // pedimos la civilizacion
                c.setNombre(nombreUsuario); // agregamos al modelo

                Civilizacion *ptr = v.buscar(c); // hacemos una busqueda

                if(ptr == nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *ptr << endl << endl; // imprimimos el lo que tiene el puntero
                    /* Variables temporales */
                    string tempString;
                    int tempInt;
                    float tempFloat;

                    cout << "\tEscoga el campo a Modificar" << endl << endl;
                    cout << "\t1.- Nombre" << endl;
                    cout << "\t2.- Ubicacion en X" << endl;
                    cout << "\t3.- Ubicacion en Y" << endl;
                    cout << "\t4.- Puntuacion" << endl;
                    cout << "\t5.- Regresar" << endl << endl;
                    cout << "\tOpcion : ";
                    cin >> opc;
                    cout << endl;
                    cin.ignore();

                    switch(opc) {
                        case MODIFICAR_NOMBRE:
                            cout << "\tNombre : ";
                            getline(cin, tempString);
                            ptr->setNombre(tempString);
                            break;
                        case MODIFICAR_X:
                            cout << "\tUbicacion en x : ";
                            cin >> tempInt;
                            ptr->setX(tempInt);
                            break;
                        case MODIFICAR_Y:
                            cout << "\tUbicacion en y : ";
                            cin >> tempInt;
                            ptr->setX(tempInt);
                            break;
                        case MODIFICAR_PUNTUACION:
                            cout << "\tPuntuacion : ";
                            cin >> tempFloat;
                            ptr->setPuntuacion(tempFloat);
                            break;
                        case MODIFICAR_REGRESAR:
                            continueProgram = false;
                            break;
                        default:
                            cout << "\tNo existe tal opcion" << endl;
                            cin.ignore();
                    }

                    cout << endl << "\tDesea seguir modificando (S/N) : ";
                    if(cin.get() != 'S') {
                        continueProgram = false;
                    }

                    if(continueProgram) {
                        cout << endl << "\tPresione entrar para continuar ..." << endl;
                        cin.get();
                        system(CLEAN_SCREEN);
                        cout << endl << endl;
                    }
                }
            } while(continueProgram);
        }
        break;

        case MOSTRAR:
            v.mostrar(); // mostramos
            break;

        case SALIR:
            continueProgram = false; // cerramos ciclo
            break;

        default:
            cout << "\tOpcion Invalida" << endl;
            break;
        }

        if(opc!=SALIR) {
            cout << endl << "\tPresione entrar para continuar ..." << endl;
            cin.get();
            system(CLEAN_SCREEN);
        }

    } while (continueProgram);

    return 0;
}

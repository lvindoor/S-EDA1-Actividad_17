#include <iostream>
#include "videogame.h"

using namespace std;

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
    RESPALDAR,
    RECUPERAR,
    SALIR
};

/* Opciones Sub-Menu */

enum {
    ORDENAR_NOMBRE = 1,
    ORDENAR_X,
    ORDENAR_Y,
    ORDENAR_PUNTUACION,
    REGRESAR
};

int main() {

    Videogame v;
    
    int opc; // creamos una opcion para el menu
    Civilizacion c; // creamos una variable civilización temporal
    size_t p; // declaramos una variable de tipo posición
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
        cout << "\t12-. Respaldar - Extra" << endl;
        cout << "\t13-. Recuperar - Extra" << endl;        
        cout << "\t14-. Salir" << endl;
        cout << endl << "\topcion : ";
        cin >> opc; cin.ignore();
        cout << endl;
        
        /* Evaluamos */
        switch(opc) {

        case NOMBRE_USUARIO: {
            string temp; // variable temporal para nombre
            cout << "Ingrese el nombre de usuario : ";
            cin >> temp; // guardamos
            
            c.setNombre(temp); // agregamos a la actual civilización
            cin.ignore();
            break;
        }

        case AGREGAR:
            cin >> c; // pedimos datos y guardamos

            v.agregarCivilizacion(c); // agregamos al arreglo
            cin.ignore();
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
            cout << "  Inicializar con : " << endl;
            cin >> c; // guardamos la cadena a inicializar
            cout << endl;

            v.inicializar(c,n); // declaramos el cambio en el vector
            break;

        case PRIMERA:
            cout << "\tLa primera civilizacion es: " << endl;
            if(v.size()>0) {
                cout << v.front(); // traemos la primera civilizacion
            } else {
                cout << "\tNo hay civilizaciones" << endl;
            }
            break;

        case ULTIMA:
            cout << "\tLa ultima civilizacion es: " << endl;
            if(v.size()>0) {
                cout << v.back(); // traemos la ultima civilizacion
            } else {
                cout << "\tNo hay civilizaciones" << endl;
            }
            break;

        case ORDENAR:
            int opc2; // creamos una opcion para el submenu
            bool continueProgram2 = true; // comenzamos el submenu ciclico

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
                cin >> opc2; cin.ignore();
                cout << endl;
                
                /* Evaluamos */
                switch(opc2) { 
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
                    case REGRESAR:
                        continueProgram2 = false;
                        break;
                    default:
                        cout << "\tOpcion Invalida" << endl;
                        break;
                }
            } while(continueProgram2);

            break;

        case ELIMINAR:
            cout << "\tPosicion para eliminar : ";
            cin >> p; cin.ignore();

            if (p >= v.size()) { // ¿Posición valida?
                cout << "\tposicion no valida" << endl;
            } else {
                v.eliminar(p); // eliminamos en p
            }
            break;

        case BUSCAR: {
                cin >> c; // pedimos la civilizacion
                cout << endl;

                Civilizacion *ptr = v.buscar(c); // buscamos

                if(ptr==nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *ptr << endl;
                }
            }
            break;

        case MODIFICAR:
            /* Buscamos */
            cin >> c; // pedimos la civilizacion
                cout << endl;

                Civilizacion *ptr = v.buscar(c); // buscamos

                if(ptr==nullptr) {
                    cout << "\tNo encontrado" << endl;
                } else {
                    cout << "\t" << *ptr << endl << endl;

                    int subMenu;
                    string nombre;
                    int xy;
                    float puntuacion;

                    cout << "Que deseas modificar?" << endl;
                    cout << "1.- Nombre           " << endl;
                    cout << "2.- Ubicacion en X   " << endl;
                    cout << "3.- Ubicacion en Y   " << endl;
                    cout << "4.- Puntuacion       " << endl;
                    cout << "5.- Nada             " << endl; 
                    cin >> subMenu;
                    cin.ignore();

                    if(subMenu == 1){
                        cout << "Nombre: ";
                        getline(cin, nombre);
                        ptr->setNombre(nombre);
                    }

                    else if(subMenu == 2){
                        cout << "Ubicacion en X: ";
                        cin >> xy;
                        ptr->setX(xy);
                    }

                    else if(subMenu == 3){
                        cout << "Ubicacion en Y: ";
                        cin >> xy;
                        ptr->setY(xy);
                    }

                    else if(subMenu == 4){
                        cout << "Puntuacion: ";
                        cin >> puntuacion;
                        ptr->setPuntuacion(puntuacion);
                    }

                    else if(subMenu == 5){
                        cout << "Volviendo al menu..." << endl;
                    }

                    else {
                        cout << "No existe tal opcion" << endl;
                    }
                    cin.ignore();
                }
            break;

        case MOSTRAR:
            v.mostrar(); // mostramos
            break;

        case RESPALDAR:
            v.respaldar(); // respaldamos
            break;

        case RECUPERAR:
            v.recuperar(); // recuperamos
            break;

        case SALIR: 
            continueProgram = false; // cerramos ciclo
            break;

        default: 
            cout << "\tOpcion Invalida" << endl;
            break;
        }
        
    } while (continueProgram);
    
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

struct Pasajero {
    string nombre;
    string cedula;
};

int main() {
    Pasajero sillas[50];  // 8 sillas ejecutivas y 42 económicas
    int opcion = 0;
    bool continuar = true;

    while (continuar) {
        cout << "1. Asignar silla\n2. Buscar reserva\n3. Salir\n";
        cin >> opcion;

        if (opcion == 1) {
            string nombre, cedula;
            int clase, inicio, fin;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Cedula: ";
            cin >> cedula;
            cout << "Clase (0: Económica, 1: Ejecutiva): ";
            cin >> clase;

            if (clase == 1) {
                inicio = 0;
                fin = 8;
            } else if (clase == 0) {
                inicio = 8;
                fin = 50;
            } else {
                cout << "Clase no válida.\n";
                continue;
            }

            bool sillaAsignada = false;
            for (int i = inicio; i < fin; i++) {
                if (sillas[i].cedula == "") {
                    sillas[i].nombre = nombre;
                    sillas[i].cedula = cedula;
                    cout << "Silla asignada: " << i + 1 << endl;
                    sillaAsignada = true;
                    break;
                }
            }

            if (!sillaAsignada) {
                cout << "No hay sillas disponibles en la clase seleccionada.\n";
            }
        } else if (opcion == 2) {
            string cedula;
            cout << "Cedula: ";
            cin >> cedula;

            bool reservaEncontrada = false;
            for (int i = 0; i < 50; i++) {
                if (sillas[i].cedula == cedula) {
                    cout << "Reserva de " << sillas[i].nombre << " en silla " << i + 1 << endl;
                    reservaEncontrada = true;
                    break;
                }
            }

            if (!reservaEncontrada) {
                cout << "Reserva no encontrada.\n";
            }
        } else if (opcion == 3) {
            continuar = false;
        } else {
            cout << "Opción no válida.\n";
        }
    }

    return 0;
}
    }

    return 0;
}


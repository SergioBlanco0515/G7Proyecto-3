#include <iostream>
#include <string>
using namespace std;

struct Pasajero {
    string nombre;
    string cedula;
};

const int EJECUTIVA = 8;
const int TOTAL_SILLAS = 50;

Pasajero sillas[TOTAL_SILLAS];

void asignarSilla(int clase) {
    string nombre, cedula;
    int inicio, fin;

    if (clase == 1) {
        inicio = 0;
        fin = EJECUTIVA;
    } else if (clase == 0) {
        inicio = EJECUTIVA;
        fin = TOTAL_SILLAS;
    } else {
        cout << "Clase no válida. Debe ser 0 (Económica) o 1 (Ejecutiva).\n";
        return;
    }

    cout << "Nombre: ";
    cin >> nombre;
    cout << "Cedula: ";
    cin >> cedula;

    for (int i = inicio; i < fin; i++) {
        if (sillas[i].cedula == "") {
            sillas[i].nombre = nombre;
            sillas[i].cedula = cedula;
            cout << "Silla asignada: " << i + 1 << endl;
            return;
        }
    }
    cout << "No hay sillas disponibles en la clase seleccionada.\n";
}

void buscarReserva() {
    string cedula;
    cout << "Cedula: ";
    cin >> cedula;


    for (int i = 0; i < TOTAL_SILLAS; i++) {
        if (sillas[i].cedula == cedula) {
            cout << "Reserva de " << sillas[i].nombre << " en silla " << i + 1 << endl;
            return;
        }
    }
    cout << "Reserva no encontrada.\n";
}

int main() {
    int opcion, clase;
    bool continuar = true;

    while (continuar) {
        cout << "1. Asignar silla\n2. Buscar reserva\n3. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Clase (0: Económica, 1: Ejecutiva): ";
                cin >> clase;
                asignarSilla(clase);
                break;
            case 2:
                buscarReserva();
                break;
            case 3:
                continuar = false;
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    }

    return 0;
}


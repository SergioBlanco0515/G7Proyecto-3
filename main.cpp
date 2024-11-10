#include <iostream>
#include <string>
using namespace std;

const int NUM_SILLAS = 50;
const int EJECUTIVAS = 8;
const int ECONOMICAS = NUM_SILLAS - EJECUTIVAS;

struct Silla {
    int numero;
    string clase;
    string posicion;
    string nombrePasajero;
    string cedula;
    bool ocupada = false;
};

Silla sillas[NUM_SILLAS];

void inicializarSillas() {
    for (int i = 0; i < NUM_SILLAS; i++) {
        sillas[i].numero = i + 1;
        sillas[i].clase = (i < EJECUTIVAS) ? "Ejecutiva" : "Económica";
        sillas[i].posicion = (i % 3 == 0) ? "Ventana" : (i % 3 == 1) ? "Centro" : "Pasillo";
        if (sillas[i].clase == "Ejecutiva" && sillas[i].posicion == "Centro") {
            sillas[i].posicion = (i % 2 == 0) ? "Ventana" : "Pasillo";  // Las ejecutivas no tienen "Centro"
        }
    }
}

void asignarSilla() {
    string nombre, cedula;
    int claseSeleccionada;
    string clase, posicion;
    bool asignada = false;

    cout << "Ingrese el nombre del pasajero: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese la cédula del pasajero: ";
    getline(cin, cedula);

    cout << "Elija la clase (0 para Ejecutiva, 1 para Económica): ";
    cin >> claseSeleccionada;
    if (claseSeleccionada != 0 && claseSeleccionada != 1) {
        cout << "Clase no válida. Debe ser 0 (Ejecutiva) o 1 (Económica).\n";
        return;
    }

    clase = (claseSeleccionada == 0) ? "Ejecutiva" : "Económica";

    cout << "Elija la posición (Ventana, Centro, Pasillo): ";
    cin >> posicion;
    if (posicion != "Ventana" && posicion != "Centro" && posicion != "Pasillo") {
        cout << "Posición no válida. Debe ser Ventana, Centro o Pasillo.\n";
        return;
    }

    for (int i = 0; i < NUM_SILLAS; i++) {
        if (!sillas[i].ocupada && sillas[i].clase == clase && sillas[i].posicion == posicion) {
            sillas[i].nombrePasajero = nombre;
            sillas[i].cedula = cedula;
            sillas[i].ocupada = true;
            cout << "Silla asignada: " << sillas[i].numero << " (" << sillas[i].clase << ", " << sillas[i].posicion << ")\n";
            asignada = true;
            break;
        }
    }

    if (!asignada) {
        cout << "No hay sillas disponibles en esa clase y posición.\n";
    }
}

void consultarReserva() {
    string cedula;
    cout << "Ingrese la cédula del pasajero: ";
    cin >> cedula;

    bool encontrada = false;
    for (int i = 0; i < NUM_SILLAS; i++) {
        if (sillas[i].ocupada && sillas[i].cedula == cedula) {
            cout << "Reserva encontrada:\n";
            cout << "Nombre: " << sillas[i].nombrePasajero << "\n";
            cout << "Silla: " << sillas[i].numero << " (" << sillas[i].clase << ", " << sillas[i].posicion << ")\n";
            encontrada = true;
            break;
        }
    }

    if (!encontrada) {
        cout << "No se encontró ninguna reserva para esa cédula.\n";
    }
}

void eliminarReserva() {
    string cedula;
    cout << "Ingrese la cédula del pasajero para eliminar la reserva: ";
    cin >> cedula;

    bool eliminada = false;
    for (int i = 0; i < NUM_SILLAS; i++) {
        if (sillas[i].ocupada && sillas[i].cedula == cedula) {
            sillas[i].ocupada = false;
            cout << "Reserva eliminada para el pasajero con cédula " << cedula << ".\n";
            eliminada = true;
            break;
        }
    }

    if (!eliminada) {
        cout << "No se encontró ninguna reserva para esa cédula.\n";
    }
}

void buscarPasajero() {
    string cedula;
    cout << "Ingrese la cédula del pasajero: ";
    cin >> cedula;

    bool encontrado = false;
    for (int i = 0; i < NUM_SILLAS; i++) {
        if (sillas[i].ocupada && sillas[i].cedula == cedula) {
            cout << "Reserva encontrada para el pasajero con cédula " << cedula << ":\n";
            cout << "Nombre: " << sillas[i].nombrePasajero << "\n";
            cout << "Silla: " << sillas[i].numero << " (" << sillas[i].clase << ", " << sillas[i].posicion << ")\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró ninguna reserva para la cédula " << cedula << ".\n";
    }
}

void calcularPorcentajeOcupacion() {
    int ocupadas = 0;
    for (int i = 0; i < NUM_SILLAS; i++) {
        if (sillas[i].ocupada) {
            ocupadas++;
        }
    }
    double porcentaje = (ocupadas * 100.0) / NUM_SILLAS;
    cout << "Porcentaje de ocupación del avión: " << porcentaje << "%\n";
}

int main() {
    inicializarSillas();
    int opcion;

    do {
        cout << "\n--- Menú de Reservas ---\n";
        cout << "1. Asignar silla\n";
        cout << "2. Consultar reserva\n";
        cout << "3. Eliminar reserva\n";
        cout << "4. Buscar pasajero (por cédula)\n";
        cout << "5. Calcular porcentaje de ocupación\n";
        cout << "6. Salir\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                asignarSilla();
                break;
            case 2:
                consultarReserva();
                break;
            case 3:
                eliminarReserva();
                break;
            case 4:
                buscarPasajero();
                break;
            case 5:
                calcularPorcentajeOcupacion();
                break;
            case 6:
                cout << "Saliendo del sistema de reservas.\n";
                break;
            default:
                cout << "Opción no válida. Intente nuevamente.\n";
        }
    } while (opcion != 6);

    return 0;
}


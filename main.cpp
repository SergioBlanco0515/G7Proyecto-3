#include <iostream>

using namespace std;
int main() {
    string nombre;
    string cedula;
    int asiento; 
    string clase; 
    string posicion;
    Avion avion;
    int opcion;

    do {
        cout << "\n--- Sistema de Reservas de Avión ---\n";
        cout << "1. Asignar silla\n";
        cout << "2. Consultar reserva\n";
        cout << "3. Eliminar reserva\n";
        cout << "4. Calcular porcentaje de ocupación\n";
        cout << "5. Consultar valor total de ventas\n";
        cout << "6. Consultar valor promedio de ventas por pasajero\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                avion.asignarAsiento();
                break;
            case 2:
                avion.consultarReserva();
                break;
            case 3:
                avion.eliminarReserva();
                break;
            case 4:
                avion.calcularOcupacion();
                break;
            case 5:
                avion.valorTotalVentas();
                break;
            case 6:
                avion.valorPromedioPorPasajero();
                break;
            case 7:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción no válida.\n";
                break;
        }
    } while (opcion != 7);

    return 0;
}

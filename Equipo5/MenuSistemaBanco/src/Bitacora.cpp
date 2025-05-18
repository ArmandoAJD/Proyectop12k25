//Programado por Priscila Sarai Guzm�n Calgua 9959-23-450
//Boris de Le�n 9959-24-6203
#include "Bitacora.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstring>

using namespace std;

// Registra una acci�n realizada por un usuario en la bit�cora
void Bitacora::insertar(const string& usuario, int codigo, const std::string& aplicacion, const std::string& accion) {
    ofstream archivo("bitacora.txt", ios::app);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de bit�cora.\n";
        return;
    }

    time_t now = time(nullptr); // obtener fecha y hora
    char* fechaHora = ctime(&now); // convierte el tiempo en cadena
    fechaHora[strcspn(fechaHora, "\n")] = '\0';  // eliminar salto de l�nea

    archivo << left << setw(15) << usuario
            << setw(10) << codigo
            << setw(20) << aplicacion
            << setw(30) << accion
            << setw(25) << fechaHora << '\n';

    archivo.close();
}
string quitarEspaciosFinales(const string& str) {
    size_t end = str.find_last_not_of(" \t");
    return (end == string::npos) ? "" : str.substr(0, end + 1);
}

// Muestra todos los registros almacenados en la bit�cora
void Bitacora::mostrar() {
    ifstream archivo("bitacora.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo de bit�cora.\n";
        return;
    }

    string linea;
    cout << "\n--- BIT�CORA DE USUARIO ---\n";
    while (getline(archivo, linea)) {
        if (linea.length() < 80) continue;  // L�nea malformada

        string usuario     = linea.substr(0, 15);
        string codigoStr   = linea.substr(15, 10);
        string aplicacion  = linea.substr(25, 20);
        string accion      = linea.substr(45, 30);
        string fechaHora   = linea.substr(75);  // Hasta el final

        // Limpiar espacios finales
        usuario    = quitarEspaciosFinales(usuario);
        codigoStr  = quitarEspaciosFinales(codigoStr);
        aplicacion = quitarEspaciosFinales(aplicacion);
        accion     = quitarEspaciosFinales(accion);

        int codigo = stoi(codigoStr);

        cout << "Usuario: " << usuario << "\n"
             << "C�digo: " << codigo << "\n"
             << "Aplicaci�n: " << aplicacion << "\n"
             << "Acci�n: " << accion << "\n"
             << "Fecha y Hora: " << fechaHora << "\n"
             << "-----------------------------\n";
    }

    archivo.close();
}



// Men� para desplegar la bit�cora
void Bitacora::menuBitacora() {
    int opcion;

    do {
        cout << "\n--- MEN� DE BIT�CORA ---\n";
        cout << "1. Desplegar bit�cora\n";
        cout << "2. Regresar al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            opcion = 0;
        }

        switch (opcion) {
            case 1:
                mostrar();
                break;
            case 2:
                cout << "Regresando al men� principal...\n";
                break;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }

    } while (opcion != 2);
}


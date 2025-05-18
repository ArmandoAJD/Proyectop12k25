// Inclusi�n de encabezados propios
#include "MenuClientes.h"
#include "Clientes.h"

// Inclusi�n de librer�as est�ndar
#include <iostream>
#include <vector>
#include <string>
#include <limits> // Para manejar entradas inv�lidas y limpiar el buffer de entrada

using namespace std;

// Definici�n de rangos v�lidos para los ID de clientes
const int CODIGO_INICIAL = 3107;
const int CODIGO_FINAL = 3157;

/**
 * Muestra el men� de gesti�n de clientes.
 * Permite agregar, mostrar, modificar o eliminar clientes.
 * @param listaClientes Vector que contiene la lista de todos los clientes registrados.
 * @param usuarioActual Objeto que representa al usuario que est� utilizando el sistema.
 */
void MenuClientes::mostrar(vector<Clientes>& listaClientes, usuarios& usuarioActual) {
    int opcion;
    string input;

    do {
        system("cls");
        cout << "\n--------------------------------------------------------------------------------\n";
        cout << "                        SISTEMA DE GESTION DE CLIENTES                          \n";
        cout << "--------------------------------------------------------------------------------\n";
        cout << "   Usuario actual: " << usuarioActual.getNombre() << "\n";
        cout << "--------------------------------------------------------------------------------\n";
        cout << "   [1] Agregar cliente\n";
        cout << "   [2] Mostrar clientes\n";
        cout << "   [3] Modificar cliente\n";
        cout << "   [4] Eliminar cliente\n";
        cout << "   [5] Volver al menu principal\n";
        cout << "--------------------------------------------------------------------------------\n";
        cout << "                     Seleccione una opcion: ";

        // Validaci�n de entrada
        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n   Entrada invalida. Ingrese un numero valido: ";
        }
        cin.ignore();

        switch (opcion) {
            case 1:
                Clientes::agregar(listaClientes, usuarioActual.getNombre());
                break;

            case 2:
                Clientes::mostrar(listaClientes);
                break;

            case 3: {
                Clientes::mostrar(listaClientes);
                if (!listaClientes.empty()) {
                    cout << "\n   Ingrese ID del cliente a modificar: ";
                    getline(cin, input);
                    if (Clientes::esIdValido(input)) {
                        Clientes::modificar(listaClientes, usuarioActual.getNombre(), input);
                    } else {
                        cout << "   ID no valido. Debe estar entre " << CODIGO_INICIAL
                             << " y " << CODIGO_FINAL << "\n";
                        system("pause");
                    }
                }
                break;
            }

            case 4: {
                Clientes::mostrar(listaClientes);
                if (!listaClientes.empty()) {
                    cout << "\n   Ingrese ID del cliente a eliminar: ";
                    getline(cin, input);
                    if (Clientes::esIdValido(input)) {
                        Clientes::eliminar(listaClientes, usuarioActual.getNombre(), input);
                    } else {
                        cout << "   ID no valido. Debe estar entre " << CODIGO_INICIAL
                             << " y " << CODIGO_FINAL << "\n";
                        system("pause");
                    }
                }
                break;
            }

            case 5:
                Clientes::guardarEnArchivo(listaClientes);
                cout << "\n   Regresando al menu principal...\n";
                break;

            default:
                cout << "\n   Opcion invalida.\n";
                system("pause");
                break;
        }

    } while (opcion != 5);
}

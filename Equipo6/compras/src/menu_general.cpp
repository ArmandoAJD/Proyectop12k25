<<<<<<< HEAD
 #include "menu_general.h"
#include "menu_cliente.h"
#include "menu_producto.h"
#include "menu_compra.h"
#include "menu_archivo.h"
#include <iostream>

using namespace std;

void mostrarMenuGeneral() {
    int opcion;
    do {
        cout << "\n=== MEN� PRINCIPAL ==="
             << "\n1. Gesti�n de Clientes"
             << "\n2. Gesti�n de Productos"
             << "\n3. Gesti�n de Compras"
             << "\n4. Herramientas de Archivo"
             << "\n5. Cerrar sesi�n"
             << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: mostrarMenuCliente(); break;
            case 2: mostrarMenuProducto(); break;
            case 3: mostrarMenuCompra(); break;
            case 4: menuArchivo(); break;
            case 5: cout << "Cerrando sesi�n...\n"; break;
            default: cerr << "Opci�n inv�lida\n";
        }
    } while(opcion != 5);
=======
#include "menu_general.h"
#include "usuario.h"
#include "menu_producto.h"
#include <iostream>
#include <string>

using namespace std;

void MenuGeneral::mostrar() {
    string usuario, contrasena;
    int opcion;

    cout << "=== SISTEMA DE GESTI�N ===\n";

    // Login o registro simple
    do {
        cout << "1. Iniciar sesi�n\n2. Registrar usuario\nSeleccione opci�n: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "Usuario: ";
            getline(cin, usuario);
            cout << "Contrase�a: ";
            getline(cin, contrasena);

            if (Usuario::iniciarSesion(usuario, contrasena)) {
                cout << "Sesi�n iniciada correctamente.\n";
                break;
            } else {
                cout << "Usuario o contrase�a incorrectos.\n";
            }
        } else if (opcion == 2) {
            cout << "Nuevo usuario: ";
            getline(cin, usuario);
            cout << "Nueva contrase�a: ";
            getline(cin, contrasena);
            Usuario::registrarUsuario(usuario, contrasena);
        } else {
            cout << "Opci�n inv�lida.\n";
        }
    } while (true);

    // Men� principal
    do {
        cout << "\n=== MEN� PRINCIPAL ===\n"
             << "1. Gesti�n de productos\n"
             << "2. Salir\n"
             << "Seleccione opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                MenuProducto::mostrarMenuProducto();
                break;
            case 2:
                cout << "Saliendo del sistema...\n";
                return;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (true);
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
}

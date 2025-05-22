#include "menu_general.h"  // Para acceder a usuarioActual
#include "menu_producto.h"
#include "producto.h"
#include <iostream>
#include <limits>

using namespace std;

void MenuProducto::mostrarMenuProducto() {
    int opcion;
    do {
        string usuario = MenuGeneral::getUsuarioActual();
        if (usuario.empty()) {
            usuario = "Desconocido";
        }

        cout << "\n=== GESTI�N DE PRODUCTOS ==="
             << "\nUsuario: " << usuario << "\n"
             << "1. Registrar nuevo producto"
             << "\n2. Listar productos"
             << "\n3. Modificar producto"
             << "\n4. Eliminar producto"
             << "\n5. Volver al men� principal"
             << "\nSeleccione una opci�n: ";

        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inv�lida. Intente de nuevo.\n";
            continue;
        }
        cin.ignore();

        switch (opcion) {
            case 1:
                system("cls");
                Producto::ingresarProducto();
                break;
            case 2:
                system("cls");
                Producto::consultarProductos();
                break;
            case 3:
                system("cls");
                Producto::modificarProducto();
                break;
            case 4:
                system("cls");
                Producto::borrarProducto();
                break;
            case 5:
                system("cls");
                cout << "Volviendo al men� principal...\n";
                break;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
}

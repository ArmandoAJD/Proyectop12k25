#include "menu_producto.h"
#include "producto.h"
#include <iostream>

using namespace std;

<<<<<<< HEAD
void mostrarMenuProducto() {
=======
void MenuProducto::mostrarMenuProducto() {
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
    int opcion;
    do {
        cout << "\n=== GESTI�N DE PRODUCTOS ==="
             << "\n1. Registrar nuevo producto"
             << "\n2. Listar productos"
             << "\n3. Modificar producto"
             << "\n4. Eliminar producto"
             << "\n5. Volver al men� principal"
             << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

<<<<<<< HEAD
        switch(opcion) {
            case 1: ingresarProducto(); break;
            case 2: consultarProductos(); break;
            case 3: modificarProducto(); break;
            case 4: borrarProducto(); break;
            case 5: cout << "Volviendo...\n"; break;
            default: cerr << "Opci�n inv�lida\n";
        }
    } while(opcion != 5);
=======
        switch (opcion) {
            case 1:
                Producto::ingresarProducto();
                break;
            case 2:
                Producto::consultarProductos();
                break;
            case 3:
                Producto::modificarProducto();
                break;
            case 4:
                Producto::borrarProducto();
                break;
            case 5:
                cout << "Volviendo al men� principal...\n";
                break;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
}

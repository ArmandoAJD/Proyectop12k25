#include "menu_compra.h"
#include "compras.h"
#include <iostream>
#include <iomanip>
<<<<<<< HEAD

using namespace std;

void mostrarMenuCompra() {
    vector<Producto> listaCompras;
=======
#include <vector>

using namespace std;

void MenuCompra::mostrarMenuCompra() {
    vector<Producto> listaCompras;
    Compras compras;  // objeto para llamar los métodos
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
    int opcion;

    do {
        cout << "\n=== MENÚ DE COMPRAS ==="
             << "\n1. Registrar nueva compra"
             << "\n2. Ver historial de compras"
             << "\n3. Buscar por proveedor"
             << "\n4. Ver total gastado"
             << "\n5. Volver al menú principal"
             << "\nSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
<<<<<<< HEAD
                registrarCompra(listaCompras);
                break;
            case 2:
                mostrarHistorial(listaCompras);
                break;
            case 3:
                buscarPorProveedor(listaCompras);
                break;
            case 4:
                cout << "\n💰 Total gastado: $" << fixed << setprecision(2)
                     << calcularTotalGastado(listaCompras) << endl;
=======
                compras.registrarCompra(listaCompras);
                break;
            case 2:
                compras.mostrarHistorial(listaCompras);
                break;
            case 3:
                compras.buscarPorProveedor(listaCompras);
                break;
            case 4:
                cout << "\nTotal gastado: $" << fixed << setprecision(2)
                     << compras.calcularTotalGastado(listaCompras) << endl;
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
                break;
            case 5:
                cout << "Volviendo...\n";
                break;
            default:
                cerr << "Opción inválida\n";
        }
    } while(opcion != 5);
}

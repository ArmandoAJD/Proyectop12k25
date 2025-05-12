#include "MenuCatalogos.h"
#include "MenuClientes.h"
#include "MenuProveedores.h"
#include "MenuProductos.h"
#include "MenuAlmacenes.h"
#include "MenuAdministracion.h"
#include "MenuTransportistas.h"
#include <iostream>
#include <limits>

//JENNIFER ALBA DAYAMI BARRIOS FLORES
//9959-24-10016
//MAYO 2025

using namespace std;

// Implementaci�n del men� de cat�logos
void MenuCatalogos::mostrar(vector<Clientes>& clientes,
                          vector<Proveedor>& proveedores,
                          vector<Producto>& productos,
                          vector<Almacen>& almacenes,
                          vector<Administracion>& administradores,
                          vector<Transportistas>& transportistas,
                          usuarios& usuarioActual) {
    int opcion;
    do {
        system("cls");
        // Mostrar encabezado del men�
        cout << "\t\t====================================\n"
             << "\t\t|        MEN� CAT�LOGOS           |\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t| Nivel: " << usuarioActual.getNivelAcceso() << "\n"
             << "\t\t====================================\n"
             << "\t\t1. Clientes\n"
             << "\t\t2. Proveedores\n"
             << "\t\t3. Productos\n"
             << "\t\t4. Almacenes\n"
             << "\t\t5. Transportistas\n";

        // Control de acceso para administraci�n
        if(usuarioActual.getNivelAcceso() >= 3) {
            cout << "\t\t6. Administraci�n\n";
        }

        cout << "\t\t7. Volver al men� principal\n"
             << "\t\t====================================\n"
             << "\t\tSeleccione una opci�n: ";

        // Validaci�n de entrada num�rica
        while(!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\tEntrada inv�lida. Ingrese un n�mero: ";
        }
        cin.ignore(); // Limpiar buffer de entrada

        // Manejo de opciones del men�
        switch(opcion) {
            case 1:
                MenuClientes::mostrar(clientes, usuarioActual);
                break;
            case 2:
                MenuProveedores::mostrar(proveedores, usuarioActual);
                break;
            case 3:
                MenuProductos::mostrar(productos, usuarioActual);
                break;
            case 4:
                MenuAlmacenes::mostrar(almacenes, usuarioActual);
                break;
            case 5:
                MenuTransportistas::mostrar(transportistas, usuarioActual);
                break;
            case 6:
                // Verificaci�n de nivel de acceso
                if(usuarioActual.getNivelAcceso() >= 3) {
                    MenuAdministracion::mostrar(administradores, usuarioActual);
                } else {
                    cout << "\n\t\tAcceso denegado. Nivel insuficiente.\n";
                    system("pause");
                }
                break;
            case 7:
                return; // Salir del men�
            default:
                cout << "\n\t\tOpci�n inv�lida. Intente nuevamente.\n";
                system("pause");
        }
    } while(true); // Bucle infinito hasta que se seleccione salir
}

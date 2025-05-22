#include "menu_general.h"
#include "menu_producto.h"
#include "menu_archivo.h"
#include "menu_cliente.h"
#include "menu_compra.h"
#include <iostream>

using namespace std;

// Definici�n de la variable est�tica
string MenuGeneral::usuarioActual = "Desconocido";

// Getter para obtener el usuario actual
string MenuGeneral::getUsuarioActual() {
    return usuarioActual;
}

// Setter para establecer el usuario actual
void MenuGeneral::setUsuarioActual(const string& usuario) {
    usuarioActual = usuario;
}

// Muestra el men� principal del sistema despu�s de iniciar sesi�n correctamente
void MenuGeneral::mostrar() {
    int opcion;

    do {
        system("cls"); // Limpia pantalla antes de mostrar el men�

        cout << "\n=== MEN� PRINCIPAL ===\n"
             << "Usuario: " << usuarioActual << "\n"
             << "1. Gesti�n de productos\n"
             << "2. Archivo\n"
             << "3. Cliente\n"
             << "4. Compras\n"
             << "5. Salir\n"
             << "Seleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                system("cls");
                MenuProducto::mostrarMenuProducto();
                break;
            case 2:
                system("cls");
                MenuArchivo::menuArchivo();
                break;
            case 3:
                system("cls");
                MenuCliente::mostrarMenuCliente();
                break;
            case 4:
                system("cls");
                MenuCompra::mostrarMenuCompra();  // Aqu� llamamos al men� compras
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                return;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
                system("pause");
        }

    } while (true);
}

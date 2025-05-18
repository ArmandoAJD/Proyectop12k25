#include "MenuProcesos.h"
#include "usuarios.h"
#include <iostream>
#include "pedidos.h"
#include "inventario.h"
#include "envios.h"
#include "facturacion.h"
#include "reportes.h"
#include "globals.h"
#include "clientes.h"
#include "producto.h"
#include "Almacen.h"

// Creado JENNIFER ALBA DAYAMI BARRIOS FLORES
//9959-24-10016
//MAYO 2025
//Modificado por Camila Araujo

using namespace std;

// Declaraci�n externa del usuario registrado actual
extern usuarios usuarioRegistrado;

// Muestra el men� principal de procesos y redirige seg�n la opci�n elegida
void MenuProcesos::mostrar(std::vector<Clientes>& clientes,
                         std::vector<Producto>& productos,
                         std::vector<Almacen>& almacenes) {
    int choice;
    do {
        // Limpiar pantalla antes de mostrar el men�
        system("cls");

        // Mostrar encabezado del men� y nombre del usuario actual
        cout << "\t\t========================================\n"
             << "\t\t|          MENu DE PROCESOS            |\n"
             << "\t\t========================================\n"
             << "\t\t| Usuario: " << usuarioRegistrado.getNombre() << "\n"
             << "\t\t========================================\n"
             << "\t\t 1. Gestion de Pedidos\n"
             << "\t\t 2. Control de Inventario\n"
             << "\t\t 3. Envios y Transportes\n"
             << "\t\t 4. Facturacion\n"
             << "\t\t 5. Reportes\n"
             << "\t\t 6. Volver\n"
             << "\t\t========================================\n"
             << "\t\tIngresa tu opcion: ";

        cin >> choice;

        switch(choice) {
            case 1:
                {
                    Pedidos gestorPedidos;
                    gestorPedidos.gestionPedidos(clientes, productos, almacenes);
                }
                break;

            case 2:
                gestorInventario.mostrarInventario(); // Cambiado a mostrarInventario
                break;

            case 3:
                gestorEnvios.gestionEnvios();
                break;

            case 4:
                gestorFacturacion.mostrarMenuFacturacion();
                break;

            case 5:
                // Generar reportes disponibles en el sistema
                gestorReportes.generarReportes();
                break;

            case 6:
                // Salir del men� de procesos
                return;

            default:
                // Manejar opci�n inv�lida
                cout << "\n\t\tOpci�n inv�lida...";
        }

        // Esperar una tecla antes de volver a mostrar el men�
        cin.ignore(); // Limpiar buffer
        cin.get();    // Esperar entrada del usuario
    } while(choice != 6); // Repetir hasta que se seleccione salir
}

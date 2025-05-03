//funcionamiento del men� (kevin)
//funcionamiento del men� (Luis)
//Actualizacion (Anthony)
#include "Menu.h"

Menu::Menu() {}

void Menu::mostrarOpciones(Inventario& inventario, Facturacion& factura, const string& nombreUsuario) {
    int opcion;
    bitacora auditoria;


void Menu::mostrarOpciones(Inventario& inventario, Facturacion& factura) {
    int opcion;
    do {
        system("cls"); // Usa "clear" y mejora en lo visual por Anthony Suc
        cout << "=====================================\n";
        cout << "         SISTEMA DE INVENTARIO       \n";
        cout << "=====================================\n";
        cout << " 1. Agregar Producto\n";
        cout << " 2. Ver Inventario\n";
        cout << " 3. Facturar\n";
        cout << " 4. Salir\n";
        cout << "-------------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                system("cls");
                int codigo, stock;
                float precio;
                string nombre, tipo;
                cout << "Codigo: "; cin >> codigo;
                cout << "Nombre: "; cin >> nombre;
                cout << "Precio: "; cin >> precio;
                cout << "Stock: "; cin >> stock;
                cout << "Tipo (ventas, stock, compras): "; cin >> tipo;
                inventario.agregarProducto(codigo, nombre, precio, stock, tipo);
                break;
            }

            case 2: {
                system("cls");
                int subopcion;
                do {
                    cout << "\n=====================================\n";
                    cout << "      --- SUBMENU INVENTARIO ---\n";
                    cout << "=====================================\n";
                    cout << "1. Inventario General\n";
                    cout << "2. Inventario para Ventas\n";
                    cout << "3. Inventario para Stock\n";
                    cout << "4. Inventario para Compras\n";
                    cout << "5. Regresar al menu principal\n";
                    cout << "-------------------------------------\n";
                    cout << "Seleccione una opcion: ";
                    cin >> subopcion;

                    switch (subopcion) {
                        case 1:
                            auditoria.insertar(nombreUsuario, 2001, "Ver Inventario General");
                            inventario.mostrarInventarioGeneral();
                            break;
                        case 2:
                            auditoria.insertar(nombreUsuario, 2002, "Ver Inventario Ventas");
                            inventario.mostrarInventarioPorTipo("ventas");
                            break;
                        case 3:
                            auditoria.insertar(nombreUsuario, 2003, "Ver Inventario Stock");
                            inventario.mostrarInventarioPorTipo("stock");
                            break;
                        case 4:
                            auditoria.insertar(nombreUsuario, 2004, "Ver Inventario Compras");
                            inventario.mostrarInventarioPorTipo("compras");
                            break;
                        case 5:
                            cout << "Regresando al menu principal...\n";
                            break;
                        default:
                            cout << "Opci�n no valida, intente de nuevo.\n";
                    }
                } while (subopcion != 5);
                break;
            }

            case 3:
                factura.generarFactura(inventario);
                break;

            case 4:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion no valida, intente de nuevo.\n";
        }
    } while (opcion != 4);
}

Menu::~Menu() {}


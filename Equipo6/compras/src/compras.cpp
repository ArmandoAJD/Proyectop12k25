#include "compras.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Compras::registrarCompra(vector<Producto>& listaCompras) {
    Producto p;
    string temp;

    cout << "Ingrese código del producto: ";
    getline(cin, temp);
    p.setCodigo(temp);

    cout << "Ingrese nombre del producto: ";
    getline(cin, temp);
    p.setNombre(temp);

    cout << "Ingrese descripción del producto: ";
    getline(cin, temp);
    p.setDescripcion(temp);

    double precio;
    cout << "Ingrese precio: ";
    cin >> precio;
    p.setPrecio(precio);

    int stock;
    cout << "Ingrese cantidad (stock): ";
    cin >> stock;
    p.setStock(stock);
    cin.ignore();

    listaCompras.push_back(p);

    cout << "Compra registrada exitosamente.\n";
}

void Compras::mostrarHistorial(const vector<Producto>& listaCompras) {
    if (listaCompras.empty()) {
        cout << "No hay compras registradas.\n";
        return;
    }

    cout << "\n--- Historial de Compras ---\n";
    for (const auto& p : listaCompras) {
        cout << "Código: " << p.getCodigo() << "\n"
             << "Nombre: " << p.getNombre() << "\n"
             << "Descripción: " << p.getDescripcion() << "\n"
             << "Precio: $" << fixed << setprecision(2) << p.getPrecio() << "\n"
             << "Cantidad: " << p.getStock() << "\n\n";
    }
}

void Compras::buscarPorProveedor(const vector<Producto>& listaCompras) {
    string proveedor;
    cout << "Ingrese nombre del proveedor para buscar: ";
    getline(cin, proveedor);

    bool encontrado = false;
    for (const auto& p : listaCompras) {
        if (p.getDescripcion() == proveedor) {
            cout << "Código: " << p.getCodigo() << "\n"
                 << "Nombre: " << p.getNombre() << "\n"
                 << "Precio: $" << fixed << setprecision(2) << p.getPrecio() << "\n"
                 << "Cantidad: " << p.getStock() << "\n\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron compras de ese proveedor.\n";
    }
}

double Compras::calcularTotalGastado(const vector<Producto>& listaCompras) {
    double total = 0.0;
    for (const auto& p : listaCompras) {
        total += p.getPrecio() * p.getStock();
    }
    return total;
}

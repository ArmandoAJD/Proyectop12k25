//Karina Alejandra Arriaza Ortiz
#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <vector>
#include <string>
#include "Producto.h"
#include "Almacen.h"
#include "proveedor.h"

class Inventario {
public:
    // Estructura para representar un �tem de inventario
    struct ItemInventario {
        std::string idProducto;
        std::string idAlmacen;
        int cantidad;
        std::string ubicacion;  // Ejemplo: "Pasillo A, Estante 3"
        std::string fechaIngreso;
        std::string lote;
    };

    // M�todos para gesti�n de archivos
    static std::vector<ItemInventario> cargarInventarioDesdeArchivo();
    static void guardarInventarioEnArchivo(const std::vector<ItemInventario>& inventario);

    // M�todos para gesti�n de inventario
    static void agregarProductoAInventario();
    static void ajustarStock();
    static void transferirEntreAlmacenes();
    static void mostrarInventario();
    static void buscarProductoEnInventario();
    static void generarReporteInventario();

    // M�todos auxiliares
    static bool verificarDisponibilidad(const std::string& idProducto, int cantidadRequerida);
    static std::vector<ItemInventario> obtenerProductosBajoStockMinimo();
    static std::vector<ItemInventario> obtenerProductosPorAlmacen(const std::string& idAlmacen);
    static int obtenerStockTotalProducto(const std::string& idProducto);

private:
    // M�todos internos
    static std::string generarIdRegistroUnico(const std::vector<ItemInventario>& inventario);
};

#endif // INVENTARIO_H

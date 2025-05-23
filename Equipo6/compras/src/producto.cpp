#include "producto.h"
<<<<<<< HEAD
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

using namespace std;

string generarCodigoProducto() {
    static int counter = 0;
    stringstream ss;
    ss << "PROD-" << setw(4) << setfill('0') << ++counter;
    return ss.str();
}

void guardarProductos(const vector<Producto>& productos) {
    ofstream archivo("productos.txt");
    if (archivo.is_open()) {
        for (const auto& producto : productos) {
            archivo << producto.codigo << "|"
                    << producto.nombre << "|"
                    << producto.descripcion << "|"
                    << producto.precio << "|"
                    << producto.stock << "\n";
        }
        archivo.close();
    }
}

vector<Producto> cargarProductos() {
=======
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <limits>

using namespace std;

// Inicializar contador estático
int Producto::contadorCodigo = 0;

// Constructores
Producto::Producto() : codigo(""), nombre(""), descripcion(""), precio(0.0), stock(0) {}

Producto::Producto(const string& codigo, const string& nombre,
                   const string& descripcion, double precio, int stock)
    : codigo(codigo), nombre(nombre), descripcion(descripcion), precio(precio), stock(stock) {}

// Getters
string Producto::getCodigo() const { return codigo; }
string Producto::getNombre() const { return nombre; }
string Producto::getDescripcion() const { return descripcion; }
double Producto::getPrecio() const { return precio; }
int Producto::getStock() const { return stock; }

// Setters
void Producto::setCodigo(const string& c) { codigo = c; }
void Producto::setNombre(const string& n) { nombre = n; }
void Producto::setDescripcion(const string& d) { descripcion = d; }
void Producto::setPrecio(double p) { precio = p; }
void Producto::setStock(int s) { stock = s; }

// Generar código único
string Producto::generarCodigoProducto() {
    ++contadorCodigo;
    stringstream ss;
    ss << "PROD-" << setw(4) << setfill('0') << contadorCodigo;
    return ss.str();
}

// Ajustar contador según los productos existentes
void Producto::ajustarContador(const vector<Producto>& productos) {
    int maxContador = 0;
    for (const auto& p : productos) {
        const string& c = p.getCodigo();
        if (c.size() == 9 && c.substr(0, 5) == "PROD-") {
            try {
                int num = stoi(c.substr(5));
                if (num > maxContador)
                    maxContador = num;
            } catch (...) {}
        }
    }
    contadorCodigo = maxContador;
}

// Guardar productos en archivo
void Producto::guardarProductos(const vector<Producto>& productos) {
    ofstream archivo("productos.txt");
    if (archivo.is_open()) {
        for (const auto& p : productos) {
            archivo << p.codigo << "|"
                    << p.nombre << "|"
                    << p.descripcion << "|"
                    << p.precio << "|"
                    << p.stock << "\n";
        }
        archivo.close();
    } else {
        cerr << "❌ Error al abrir archivo para guardar productos.\n";
    }
}

// Cargar productos desde archivo
vector<Producto> Producto::cargarProductos() {
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
    vector<Producto> productos;
    ifstream archivo("productos.txt");
    string linea;

    while (getline(archivo, linea)) {
        stringstream ss(linea);
<<<<<<< HEAD
        Producto producto;
        string token;

        getline(ss, producto.codigo, '|');
        getline(ss, producto.nombre, '|');
        getline(ss, producto.descripcion, '|');

        getline(ss, token, '|');
        producto.precio = stod(token);

        getline(ss, token);
        producto.stock = stoi(token);

        productos.push_back(producto);
    }

    return productos;
}

void ingresarProducto() {
    Producto nuevo;
    nuevo.codigo = generarCodigoProducto();

    cout << "\n--- REGISTRAR PRODUCTO ---\n";
    cout << "Código: " << nuevo.codigo << endl;
    cout << "Nombre: ";
    getline(cin, nuevo.nombre);
    cout << "Descripción: ";
    getline(cin, nuevo.descripcion);
    cout << "Precio: ";
    cin >> nuevo.precio;
    cout << "Stock: ";
    cin >> nuevo.stock;
    cin.ignore();

    vector<Producto> productos = cargarProductos();
    productos.push_back(nuevo);
    guardarProductos(productos);

    cout << "✔ Producto registrado\n";
}

void consultarProductos() {
=======
        string codigo, nombre, descripcion, token;
        double precio = 0;
        int stock = 0;

        getline(ss, codigo, '|');
        getline(ss, nombre, '|');
        getline(ss, descripcion, '|');

        try {
            getline(ss, token, '|');
            precio = stod(token);
            getline(ss, token);
            stock = stoi(token);
        } catch (...) {
            cerr << "❌ Error al cargar producto. Línea: " << linea << "\n";
            continue;
        }

        productos.emplace_back(codigo, nombre, descripcion, precio, stock);
    }

    ajustarContador(productos);
    return productos;
}

// Ingresar nuevo producto
void Producto::ingresarProducto() {
    vector<Producto> productos = cargarProductos();
    Producto nuevo;

    nuevo.setCodigo(generarCodigoProducto());

    cout << "\n--- REGISTRAR PRODUCTO ---\n";
    cout << "Código: " << nuevo.getCodigo() << endl;

    cout << "Nombre: ";
    getline(cin, nuevo.nombre);

    cout << "Descripción: ";
    getline(cin, nuevo.descripcion);

    cout << "Precio: ";
    while (!(cin >> nuevo.precio) || nuevo.precio < 0) {
        cout << "❌ Ingrese un precio válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Stock: ";
    while (!(cin >> nuevo.stock) || nuevo.stock < 0) {
        cout << "❌ Ingrese un stock válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    productos.push_back(nuevo);
    guardarProductos(productos);
    cout << "✔ Producto registrado correctamente.\n";
}

// Consultar productos
void Producto::consultarProductos() {
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
    vector<Producto> productos = cargarProductos();

    cout << "\n--- LISTA DE PRODUCTOS ---\n";
    if (productos.empty()) {
<<<<<<< HEAD
        cout << "No hay productos registrados\n";
        return;
    }

    for (const auto& producto : productos) {
        cout << "Código: " << producto.codigo << "\n"
             << "Nombre: " << producto.nombre << "\n"
             << "Descripción: " << producto.descripcion << "\n"
             << "Precio: $" << fixed << setprecision(2) << producto.precio << "\n"
             << "Stock: " << producto.stock << "\n\n";
    }
}

void modificarProducto() {
    consultarProductos();
    vector<Producto> productos = cargarProductos();

    if (productos.empty()) return;
=======
        cout << "No hay productos registrados.\n";
        return;
    }

    for (const auto& p : productos) {
        cout << "Código: " << p.codigo << "\n"
             << "Nombre: " << p.nombre << "\n"
             << "Descripción: " << p.descripcion << "\n"
             << "Precio: $" << fixed << setprecision(2) << p.precio << "\n"
             << "Stock: " << p.stock << "\n\n";
    }
}

// Modificar producto
void Producto::modificarProducto() {
    vector<Producto> productos = cargarProductos();

    if (productos.empty()) {
        cout << "No hay productos para modificar.\n";
        return;
    }
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b

    string codigo;
    cout << "Ingrese código del producto a modificar: ";
    getline(cin, codigo);

    auto it = find_if(productos.begin(), productos.end(),
        [&codigo](const Producto& p) { return p.codigo == codigo; });

    if (it == productos.end()) {
<<<<<<< HEAD
        cerr << "❌ Producto no encontrado\n";
=======
        cout << "❌ Producto no encontrado.\n";
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
        return;
    }

    cout << "Nuevo nombre [" << it->nombre << "]: ";
<<<<<<< HEAD
    getline(cin, it->nombre);
    cout << "Nueva descripción [" << it->descripcion << "]: ";
    getline(cin, it->descripcion);
    cout << "Nuevo precio [" << it->precio << "]: ";
    cin >> it->precio;
    cout << "Nuevo stock [" << it->stock << "]: ";
    cin >> it->stock;
    cin.ignore();

    guardarProductos(productos);
    cout << "✔ Producto actualizado\n";
}

void borrarProducto() {
    consultarProductos();
    vector<Producto> productos = cargarProductos();

    if (productos.empty()) return;
=======
    string nuevoNombre;
    getline(cin, nuevoNombre);
    if (!nuevoNombre.empty()) it->nombre = nuevoNombre;

    cout << "Nueva descripción [" << it->descripcion << "]: ";
    string nuevaDesc;
    getline(cin, nuevaDesc);
    if (!nuevaDesc.empty()) it->descripcion = nuevaDesc;

    cout << "Nuevo precio [" << it->precio << "]: ";
    while (!(cin >> it->precio) || it->precio < 0) {
        cout << "❌ Ingrese un precio válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Nuevo stock [" << it->stock << "]: ";
    while (!(cin >> it->stock) || it->stock < 0) {
        cout << "❌ Ingrese un stock válido: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore();
    guardarProductos(productos);
    cout << "✔ Producto actualizado correctamente.\n";
}

// Borrar producto
void Producto::borrarProducto() {
    vector<Producto> productos = cargarProductos();

    if (productos.empty()) {
        cout << "No hay productos para eliminar.\n";
        return;
    }
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b

    string codigo;
    cout << "Ingrese código del producto a eliminar: ";
    getline(cin, codigo);

    auto it = remove_if(productos.begin(), productos.end(),
        [&codigo](const Producto& p) { return p.codigo == codigo; });

    if (it == productos.end()) {
<<<<<<< HEAD
        cerr << "❌ Producto no encontrado\n";
=======
        cout << "❌ Producto no encontrado.\n";
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
        return;
    }

    productos.erase(it, productos.end());
    guardarProductos(productos);
<<<<<<< HEAD
    cout << "✔ Producto eliminado\n";
=======
    cout << "✔ Producto eliminado correctamente.\n";
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
}

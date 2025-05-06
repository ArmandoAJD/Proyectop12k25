<<<<<<< HEAD
<<<<<<< HEAD
#include "Empleados.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Bitacora.h"
=======
// Karla Patricia Ruiz Ordoñez 9959-24-6859
#include "Empleados.h"      // Inclusión del encabezado de empleados (clase y prototipos)
#include <iostream>         // Para entrada/salida estándar
#include <fstream>          // Para manejo de archivos
#include <algorithm>        // Para funciones como sort()
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
=======
//Karla Patricia Ruiz Ordo�ez 9959-24-6859
#include "Empleados.h"
#include "Bitacora.h" // Incluimos la bit�cora si no est� en el .h
#include <iostream>
#include <fstream>
#include <algorithm>
>>>>>>> 1ffb03612c47ce1169541ede7ad209ab9ac9dae4

using namespace std;        // Espacio de nombres estándar

<<<<<<< HEAD
<<<<<<< HEAD
Bitacora bitacoralogEmpleados;

// Limpia la pantalla seg�n el sistema operativo
=======
// ===================================================
// FUNCIONES UTILITARIAS
// ===================================================

// Limpia la pantalla dependiendo del sistema operativo
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
=======
// Constructor: carga empleados desde archivo
Empleados::Empleados() {
    cargarEmpleados();
}

// Limpia la pantalla seg�n el sistema operativo
>>>>>>> 1ffb03612c47ce1169541ede7ad209ab9ac9dae4
void Empleados::limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

<<<<<<< HEAD
<<<<<<< HEAD
// Pausa el programa hasta que el usuario presione ENTER
=======
// Pausa la ejecución hasta que el usuario presione ENTER
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
void Empleados::pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
=======
// Pausa para que el usuario vea los mensajes
void Empleados::pausar() {
    cout << "\nPresione Enter para continuar...";
    cin.ignore();
}

// Carga empleados desde el archivo empleados.txt
void Empleados::cargarEmpleados() {
    empleados.clear();
    ifstream archivo("empleados.txt");
    Empleado e;
    while (getline(archivo, e.nombre)) {
        getline(archivo, e.codigo);
        getline(archivo, e.puesto);
        getline(archivo, e.telefono);
        empleados.push_back(e);
    }
    archivo.close();
    ordenarEmpleados();
}

// Guarda los empleados en empleados.txt
void Empleados::guardarEmpleados() {
    ofstream archivo("empleados.txt");
    for (const auto& e : empleados) {
        archivo << e.nombre << '\n'
                << e.codigo << '\n'
                << e.puesto << '\n'
                << e.telefono << '\n';
    }
    archivo.close();
}

// Ordena empleados alfab�ticamente por nombre
void Empleados::ordenarEmpleados() {
    sort(empleados.begin(), empleados.end(), [](const Empleado& a, const Empleado& b) {
        return a.nombre < b.nombre;
    });
}

// Men� principal de empleados
void Empleados::menuEmpleados(const string& usuario) {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== Men� de Empleados =====\n";
        cout << "1. Crear empleado\n";
        cout << "2. Borrar empleado\n";
        cout << "3. Buscar empleado\n";
        cout << "4. Modificar empleado\n";
        cout << "5. Desplegar empleados\n";
        cout << "6. Volver al men� principal\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        switch (opcion) {
            case 1: crearEmpleado(usuario); break;
            case 2: borrarEmpleado(usuario); break;
            case 3: buscarEmpleado(usuario); break;
            case 4: modificarEmpleado(usuario); break;
            case 5: desplegarEmpleados(usuario); break;
            case 6: limpiarPantalla(); break;
            default: cout << "Opci�n inv�lida."; pausar(); break;
        }
    } while (opcion != 6);
}

// ============================
// FUNCIONES CRUD CON BIT�CORA
// ============================

// Crea un nuevo empleado y lo guarda
void Empleados::crearEmpleado(const string& usuario) {
    limpiarPantalla();
    Empleado e;
    cout << "\n=== Crear Empleado ===\n";
    cout << "Nombre: "; getline(cin, e.nombre);
    cout << "C�digo: "; getline(cin, e.codigo);
    cout << "Puesto de trabajo: "; getline(cin, e.puesto);
    cout << "Tel�fono: "; getline(cin, e.telefono);

    empleados.push_back(e);
    ordenarEmpleados();
    guardarEmpleados();

    // Registro de bit�cora (c�digo 4001)
    bitacoralogEmpleados.insertar(usuario, 4001, "Empleados", "Crear");

    cout << "\nEmpleado agregado correctamente.";
    pausar();
}

// Borra un empleado por nombre y c�digo
void Empleados::borrarEmpleado(const string& usuario) {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Borrar Empleado ===\n";
    cout << "Nombre: "; getline(cin, nombre);
    cout << "C�digo: "; getline(cin, codigo);

    bool eliminado = false;
    vector<Empleado> nuevaLista;

    for (const auto& e : empleados) {
        if (e.nombre != nombre || e.codigo != codigo) {
            nuevaLista.push_back(e);
        } else {
            eliminado = true;
        }
    }

    if (eliminado) {
        empleados = nuevaLista;
        guardarEmpleados();

        // Registro de bit�cora (c�digo 4002)
        bitacoralogEmpleados.insertar(usuario, 4002, "Empleados", "Borrar");

        cout << "\nEmpleado eliminado correctamente.";
    } else {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

// Busca un empleado por nombre y c�digo
void Empleados::buscarEmpleado(const string& usuario) {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Buscar Empleado ===\n";
    cout << "Nombre: "; getline(cin, nombre);
    cout << "C�digo: "; getline(cin, codigo);

    bool encontrado = false;

    for (const auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nEmpleado encontrado:";
            cout << "\nNombre   : " << e.nombre;
            cout << "\nC�digo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTel�fono : " << e.telefono;

            // Registro de bit�cora (c�digo 4003)
            bitacoralogEmpleados.insertar(usuario, 4003, "Empleados", "Buscar");

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

// Modifica la informaci�n de un empleado
void Empleados::modificarEmpleado(const string& usuario) {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Modificar Empleado ===\n";
    cout << "Nombre: "; getline(cin, nombre);
    cout << "C�digo: "; getline(cin, codigo);

    bool modificado = false;

    for (auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nIngrese nueva informaci�n:\n";
            cout << "Nuevo Nombre: "; getline(cin, e.nombre);
            cout << "Nuevo C�digo: "; getline(cin, e.codigo);
            cout << "Nuevo Puesto: "; getline(cin, e.puesto);
            cout << "Nuevo Tel�fono: "; getline(cin, e.telefono);
            modificado = true;
            break;
        }
    }

    if (modificado) {
        ordenarEmpleados();
        guardarEmpleados();

        // Registro de bit�cora (c�digo 4004)
        bitacoralogEmpleados.insertar(usuario, 4004, "Empleados", "Modificar");

        cout << "\nEmpleado modificado correctamente.";
    } else {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

// Muestra todos los empleados
void Empleados::desplegarEmpleados(const string& usuario) {
    limpiarPantalla();
    cout << "\n=== Empleados Registrados ===\n";

    if (empleados.empty()) {
        cout << "\nNo hay empleados registrados.";
    } else {
        for (const auto& e : empleados) {
            cout << "\n----------------------------";
            cout << "\nNombre   : " << e.nombre;
            cout << "\nC�digo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTel�fono : " << e.telefono;
        }
        cout << "\n----------------------------";

        // Registro de bit�cora (c�digo 4005)
        bitacoralogEmpleados.insertar(usuario, 4005, "Empleados", "Desplegar");
    }

    pausar();
>>>>>>> 1ffb03612c47ce1169541ede7ad209ab9ac9dae4
}

<<<<<<< HEAD
// Carga los empleados desde el archivo empleados.txt
void Empleados::cargarEmpleados() {
    empleados.clear();  // Limpiar el vector actual
=======
// ===================================================
// FUNCIONES DE MANEJO DE ARCHIVOS
// ===================================================

// Carga los empleados desde el archivo "empleados.txt" y los almacena en el vector
void Empleados::cargarEmpleados() {
    empleados.clear();  // Limpia cualquier dato anterior
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
    ifstream archivo("empleados.txt");
    Empleado e;
    string linea;

<<<<<<< HEAD
=======
    // Lee línea por línea el archivo
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
    while (getline(archivo, linea)) {
        size_t pos = 0;
        string datos[4];

<<<<<<< HEAD
=======
        // Extrae los campos separados por comas (nombre, código, puesto, teléfono)
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
        for (int i = 0; i < 3; ++i) {
            pos = linea.find(',');
            datos[i] = linea.substr(0, pos);
            linea.erase(0, pos + 1);
        }
<<<<<<< HEAD
        datos[3] = linea; // �ltimo campo

=======
        datos[3] = linea; // El último campo (teléfono)

        // Asigna los datos al objeto empleado
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
        e.nombre = datos[0];
        e.codigo = datos[1];
        e.puesto = datos[2];
        e.telefono = datos[3];

<<<<<<< HEAD
        empleados.push_back(e);
    }

    archivo.close();
    ordenarEmpleados();
}

// Guarda todos los empleados en el archivo empleados.txt
=======
        empleados.push_back(e);  // Lo agrega al vector
    }

    archivo.close();  // Cierra el archivo
    ordenarEmpleados();  // Ordena los empleados
}

// Guarda los empleados actuales en el archivo "empleados.txt"
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
void Empleados::guardarEmpleados() {
    ofstream archivo("empleados.txt");
    for (const auto& e : empleados) {
        archivo << e.nombre << "," << e.codigo << "," << e.puesto << "," << e.telefono << "\n";
    }
    archivo.close();
}

<<<<<<< HEAD
// Ordena empleados alfab�ticamente por nombre
=======
// Ordena alfabéticamente por nombre usando `std::sort` y lambda
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
void Empleados::ordenarEmpleados() {
    sort(empleados.begin(), empleados.end(), [](const Empleado& a, const Empleado& b) {
        return a.nombre < b.nombre;
    });
}

<<<<<<< HEAD
// Men� principal de empleados
void Empleados::menuEmpleados() {
    int opcion;
    do {
        cargarEmpleados(); // Cargar antes de mostrar men�
        limpiarPantalla();
        cout << "\n===== MEN� DE EMPLEADOS =====";
=======
// ===================================================
// MENÚ Y OPCIONES PRINCIPALES
// ===================================================

// Menú principal para gestión de empleados
void Empleados::menuEmpleados() {
    int opcion;
    do {
        cargarEmpleados();  // Se actualiza la lista antes de mostrar el menú
        limpiarPantalla();

        // Menú de opciones
        cout << "\n===== MENÚ DE EMPLEADOS =====";
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
        cout << "\n1. Crear Empleado";
        cout << "\n2. Borrar Empleado";
        cout << "\n3. Buscar Empleado";
        cout << "\n4. Modificar Empleado";
        cout << "\n5. Despliegue de Empleados";
        cout << "\n6. Salir";
<<<<<<< HEAD
        cout << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

=======
        cout << "\nSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        // Control de opciones
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
        switch (opcion) {
            case 1: crearEmpleado(); break;
            case 2: borrarEmpleado(); break;
            case 3: buscarEmpleado(); break;
            case 4: modificarEmpleado(); break;
            case 5: desplegarEmpleados(); break;
            case 6:
<<<<<<< HEAD
                limpiarPantalla();
                return;
            default:
                cout << "\nOpci�n inv�lida.";
=======
                limpiarPantalla();  // Limpia antes de salir
                return;
            default:
                cout << "\nOpción inválida.";
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
                pausar();
        }
    } while (true);
}

<<<<<<< HEAD
// Crea un nuevo empleado
void Empleados::crearEmpleado() {
    limpiarPantalla();
    Empleado e;
    cout << "\n=== Crear Empleado ===";
    cout << "\nNombre: "; getline(cin, e.nombre);
    cout << "C�digo: "; getline(cin, e.codigo);
    cout << "Puesto de trabajo: "; getline(cin, e.puesto);
    cout << "Tel�fono: "; getline(cin, e.telefono);

    empleados.push_back(e);
    ordenarEmpleados();
    guardarEmpleados();

    bitacoralogEmpleados.insertar("Admin", 5001, "Empleados", "Crear");
=======
// ===================================================
// FUNCIONES DE CRUD (Crear, Leer, Modificar, Eliminar)
// ===================================================

// Crea un nuevo empleado y lo guarda
void Empleados::crearEmpleado() {
    limpiarPantalla();
    Empleado e;

    // Entrada de datos
    cout << "\n=== Crear Empleado ===";
    cout << "\nNombre: "; getline(cin, e.nombre);
    cout << "Código: "; getline(cin, e.codigo);
    cout << "Puesto de trabajo: "; getline(cin, e.puesto);
    cout << "Teléfono: "; getline(cin, e.telefono);

    empleados.push_back(e);  // Añadir al vector
    ordenarEmpleados();
    guardarEmpleados();  // Persistencia

    // Bitácora: registrar la acción
    bitacoralogEmpleados.insertar("Admin", 4001, "Empleados", "Crear");
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
    cout << "\nEmpleado agregado correctamente.";
    pausar();
}

<<<<<<< HEAD
// Borra un empleado por nombre y c�digo
=======
// Elimina un empleado que coincida con nombre y código
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
void Empleados::borrarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Borrar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
<<<<<<< HEAD
    cout << "C�digo: "; getline(cin, codigo);
=======
    cout << "Código: "; getline(cin, codigo);
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71

    bool eliminado = false;
    vector<Empleado> nuevaLista;

<<<<<<< HEAD
=======
    // Reconstruye la lista sin el empleado a eliminar
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
    for (const auto& e : empleados) {
        if (e.nombre != nombre || e.codigo != codigo) {
            nuevaLista.push_back(e);
        } else {
            eliminado = true;
        }
    }

    if (eliminado) {
        empleados = nuevaLista;
        guardarEmpleados();
<<<<<<< HEAD
        bitacoralogEmpleados.insertar("Admin", 5002, "Empleados", "Borrar");
=======
        bitacoralogEmpleados.insertar("Admin", 4002, "Empleados", "Borrar");
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
        cout << "\nEmpleado eliminado correctamente.";
    } else {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

<<<<<<< HEAD
// Busca un empleado por nombre y c�digo
=======
// Busca un empleado específico por nombre y código
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
void Empleados::buscarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Buscar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
<<<<<<< HEAD
    cout << "C�digo: "; getline(cin, codigo);

    bool encontrado = false;

=======
    cout << "Código: "; getline(cin, codigo);

    bool encontrado = false;

    // Recorre los empleados en búsqueda de coincidencias
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
    for (const auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nEmpleado encontrado:";
            cout << "\nNombre   : " << e.nombre;
<<<<<<< HEAD
            cout << "\nC�digo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTel�fono : " << e.telefono;
            bitacoralogEmpleados.insertar("Admin", 5003, "Empleados", "Buscar");
=======
            cout << "\nCódigo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTeléfono : " << e.telefono;
            bitacoralogEmpleados.insertar("Admin", 4003, "Empleados", "Buscar");
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

<<<<<<< HEAD
// Modifica la informaci�n de un empleado
=======

// Modifica la información de un empleado existente
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
void Empleados::modificarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Modificar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
<<<<<<< HEAD
    cout << "C�digo: "; getline(cin, codigo);

    bool modificado = false;

    for (auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nIngrese nueva informaci�n:";
            cout << "\nNuevo Nombre: "; getline(cin, e.nombre);
            cout << "Nuevo C�digo: "; getline(cin, e.codigo);
            cout << "Nuevo Puesto: "; getline(cin, e.puesto);
            cout << "Nuevo Tel�fono: "; getline(cin, e.telefono);
=======
    cout << "Código: "; getline(cin, codigo);

    bool modificado = false;

    // Busca y actualiza los datos del empleado
    for (auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nIngrese nueva información:";
            cout << "\nNuevo Nombre: "; getline(cin, e.nombre);
            cout << "Nuevo Código: "; getline(cin, e.codigo);
            cout << "Nuevo Puesto: "; getline(cin, e.puesto);
            cout << "Nuevo Teléfono: "; getline(cin, e.telefono);
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
            modificado = true;
            break;
        }
    }

    if (modificado) {
        ordenarEmpleados();
        guardarEmpleados();
<<<<<<< HEAD
        bitacoralogEmpleados.insertar("Admin", 5004, "Empleados", "Modificar");
=======
        bitacoralogEmpleados.insertar("Admin", 4004, "Empleados", "Modificar");
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
        cout << "\nEmpleado modificado correctamente.";
    } else {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

<<<<<<< HEAD
// Muestra todos los empleados
=======
// Muestra la lista de todos los empleados
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
void Empleados::desplegarEmpleados() {
    limpiarPantalla();
    cout << "\n=== Empleados Registrados ===\n";

    if (empleados.empty()) {
        cout << "\nNo hay empleados registrados.";
    } else {
        for (const auto& e : empleados) {
            cout << "\n----------------------------";
            cout << "\nNombre   : " << e.nombre;
<<<<<<< HEAD
            cout << "\nC�digo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTel�fono : " << e.telefono;
        }
        cout << "\n----------------------------";
        bitacoralogEmpleados.insertar("Admin", 5005, "Empleados", "Desplegar");
=======
            cout << "\nCódigo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTeléfono : " << e.telefono;
        }
        cout << "\n----------------------------";
        bitacoralogEmpleados.insertar("Admin", 4005, "Empleados", "Desplegar");
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71
    }

    pausar();
}

<<<<<<< HEAD

=======
>>>>>>> 3509a453d075eb4d294700013dae9ae14bc31c71

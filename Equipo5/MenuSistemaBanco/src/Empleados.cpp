<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 8b33fe42d0419989d49c8c78957c66ac41406032
#include "Empleados.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Bitacora.h"
<<<<<<< HEAD
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
=======
>>>>>>> 8b33fe42d0419989d49c8c78957c66ac41406032

using namespace std;

<<<<<<< HEAD
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
=======
Bitacora bitacoralogEmpleados;

// Limpia la pantalla seg�n el sistema operativo
>>>>>>> 8b33fe42d0419989d49c8c78957c66ac41406032
void Empleados::limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 8b33fe42d0419989d49c8c78957c66ac41406032
// Pausa el programa hasta que el usuario presione ENTER
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

// Carga los empleados desde el archivo empleados.txt
void Empleados::cargarEmpleados() {
    empleados.clear();  // Limpiar el vector actual
    ifstream archivo("empleados.txt");
    Empleado e;
    string linea;

    while (getline(archivo, linea)) {
        size_t pos = 0;
        string datos[4];

        for (int i = 0; i < 3; ++i) {
            pos = linea.find(',');
            datos[i] = linea.substr(0, pos);
            linea.erase(0, pos + 1);
        }
        datos[3] = linea; // �ltimo campo

        e.nombre = datos[0];
        e.codigo = datos[1];
        e.puesto = datos[2];
        e.telefono = datos[3];

        empleados.push_back(e);
    }

    archivo.close();
    ordenarEmpleados();
}

// Guarda todos los empleados en el archivo empleados.txt
void Empleados::guardarEmpleados() {
    ofstream archivo("empleados.txt");
    for (const auto& e : empleados) {
        archivo << e.nombre << "," << e.codigo << "," << e.puesto << "," << e.telefono << "\n";
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
void Empleados::menuEmpleados() {
    int opcion;
    do {
        cargarEmpleados(); // Cargar antes de mostrar men�
        limpiarPantalla();
        cout << "\n===== MEN� DE EMPLEADOS =====";
        cout << "\n1. Crear Empleado";
        cout << "\n2. Borrar Empleado";
        cout << "\n3. Buscar Empleado";
        cout << "\n4. Modificar Empleado";
        cout << "\n5. Despliegue de Empleados";
        cout << "\n6. Salir";
        cout << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: crearEmpleado(); break;
            case 2: borrarEmpleado(); break;
            case 3: buscarEmpleado(); break;
            case 4: modificarEmpleado(); break;
            case 5: desplegarEmpleados(); break;
            case 6:
                limpiarPantalla();
                return;
            default:
                cout << "\nOpci�n inv�lida.";
                pausar();
        }
    } while (true);
}

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
    cout << "\nEmpleado agregado correctamente.";
    pausar();
}

// Borra un empleado por nombre y c�digo
void Empleados::borrarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Borrar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
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
        bitacoralogEmpleados.insertar("Admin", 5002, "Empleados", "Borrar");
        cout << "\nEmpleado eliminado correctamente.";
    } else {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

// Busca un empleado por nombre y c�digo
void Empleados::buscarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Buscar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
    cout << "C�digo: "; getline(cin, codigo);

    bool encontrado = false;

    for (const auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nEmpleado encontrado:";
            cout << "\nNombre   : " << e.nombre;
            cout << "\nC�digo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTel�fono : " << e.telefono;
            bitacoralogEmpleados.insertar("Admin", 5003, "Empleados", "Buscar");
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
void Empleados::modificarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Modificar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
    cout << "C�digo: "; getline(cin, codigo);

    bool modificado = false;

    for (auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nIngrese nueva informaci�n:";
            cout << "\nNuevo Nombre: "; getline(cin, e.nombre);
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
        bitacoralogEmpleados.insertar("Admin", 5004, "Empleados", "Modificar");
        cout << "\nEmpleado modificado correctamente.";
    } else {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

// Muestra todos los empleados
void Empleados::desplegarEmpleados() {
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
        bitacoralogEmpleados.insertar("Admin", 5005, "Empleados", "Desplegar");
    }

    pausar();
}



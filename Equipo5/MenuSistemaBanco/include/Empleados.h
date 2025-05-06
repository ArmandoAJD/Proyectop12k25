//Karla Patricia Ruiz Ordo�ez 9959-24-6859
#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include <vector>
#include <string>
#include "BitacoraLog.h" // <-- Aseg�rate de que este archivo exista y est� implementado

using namespace std;

// Variable global para registrar las acciones de empleados en la bit�cora
extern BitacoraLog bitacoralogEmpleados;

// ==============================
// Estructura de Datos Empleado
// ==============================
struct Empleado {
    string nombre;   // Nombre completo del empleado
    string codigo;   // C�digo identificador �nico del empleado
    string puesto;   // Puesto o cargo que ocupa en la empresa
    string telefono; // N�mero de contacto
};

// ============================
// Clase Empleados
// ============================
class Empleados {
private:
    vector<Empleado> empleados;  // Contenedor de todos los empleados registrados

public:
    // Constructor
    Empleados();

    // M�todos CRUD
    void crearEmpleado(const string& usuario);
    void borrarEmpleado(const string& usuario);
    void buscarEmpleado(const string& usuario);
    void modificarEmpleado(const string& usuario);
    void desplegarEmpleados(const string& usuario);

    // Interfaz de usuario
    void menuEmpleados(const string& usuario);

    // Utilidades
    void limpiarPantalla();
    void pausar();

    // Gesti�n de archivos
    void cargarEmpleados();
    void guardarEmpleados();
    void ordenarEmpleados();
};

#endif // EMPLEADOS_H

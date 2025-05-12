//Jonathan Samuel Gonzalez
//Karla Ruiz se agrego menu tipo de cuenta
#include "Bancos.h"
#include "Moneda.h"
#include <iostream>
#include "Bitacora.h"

using namespace std;

Bancos::Bancos() {
    bancoSeleccionado = "No configurado";
    tipoCuentaSeleccionada = "No configurada";
    monedaSeleccionada = "GTQ";
}

// Menú principal de configuración bancaria
void Bancos::menuConfiguracion() {
    menuSeleccionBanco();
<<<<<<< HEAD
    menuTipoCuenta(); //Código añadido
=======
    menuTipoCuenta(); // 🠖 Código añadido
>>>>>>> 883a5443c7cd0fb4ad4aa847ae9a4f0972ec9fda
    menuTipoMoneda();
}

// Muestra la configuración actual
void Bancos::mostrarConfiguracion() {
    limpiarPantalla();
    cout << "\n===== CONFIGURACIÓN ACTUAL =====";
    cout << "\nBanco: " << bancoSeleccionado;
    cout << "\nTipo de cuenta: " << tipoCuentaSeleccionada;
    cout << "\nMoneda: " << monedaSeleccionada << " (" << Moneda::getSimbolo() << ")";
    pausar();
}

// --- Menús internos ---
void Bancos::menuSeleccionBanco() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== SELECCIONE SU BANCO =====";
        cout << "\n1. Banco Industrial";
        cout << "\n2. Banco GyT Continental";
        cout << "\n3. Banco Banrural";
        cout << "\n4. Bac Credomatic";
        cout << "\n5. Bantrab";
        cout << "\nSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: bancoSeleccionado = "Banco Industrial"; break;
            case 2: bancoSeleccionado = "Banco GyT Continental"; break;
            case 3: bancoSeleccionado = "Banco Banrural"; break;
            case 4: bancoSeleccionado = "Bac Credomatic"; break;
            case 5: bancoSeleccionado = "Bantrab"; break;
            default: cout << "Opción inválida."; pausar();
        }

        if (opcion >= 1 && opcion <= 5) return;
    } while (true);
}

void Bancos::menuTipoCuenta() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== TIPO DE CUENTA =====";
        cout << "\nBanco seleccionado: " << bancoSeleccionado;
        cout << "\n1. Cuenta Monetaria";
        cout << "\n2. Cuenta de Ahorro";
        cout << "\n3. Volver al menú anterior";
        cout << "\nSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: tipoCuentaSeleccionada = "Monetaria"; break;
            case 2: tipoCuentaSeleccionada = "Ahorro"; break;
            case 3: menuSeleccionBanco(); // Vuelve al menú de bancos
            default: cout << "Opción inválida."; pausar();
        }

        if (opcion >= 1 && opcion <= 3) return;
    } while (true);
}

void Bancos::menuTipoMoneda() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\n===== TIPO DE MONEDA =====";
        cout << "\nBanco: " << bancoSeleccionado;
        cout << "\nCuenta: " << tipoCuentaSeleccionada;
        cout << "\n1. Quetzales (GTQ)";
        cout << "\n2. Dólares (USD)";
        cout << "\n3. Euros (EUR)";
<<<<<<< HEAD
        cout << "\n4. Volver al menú de tipo de cuenta";
=======
        cout << "\n4. Volver al menú de tipo de cuenta"; // 🠖 Corregido el mensaje
>>>>>>> 883a5443c7cd0fb4ad4aa847ae9a4f0972ec9fda
        cout << "\nSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                monedaSeleccionada = "GTQ";
                Moneda::moneda = "GTQ";
                limpiarPantalla(); // Limpia pantalla antes de salir
                return;
            case 2:
                monedaSeleccionada = "USD";
                Moneda::moneda = "USD";
                limpiarPantalla(); // Limpia pantalla antes de salir
                return;
            case 3:
                monedaSeleccionada = "EUR";
                Moneda::moneda = "EUR";
                limpiarPantalla(); // Limpia pantalla antes de salir
                return;
<<<<<<< HEAD
            case 4: menuTipoCuenta(); break; // Ahora llama a menuTipoCuenta()
=======
            case 4: menuTipoCuenta(); break; // 🠖 Ahora llama a menuTipoCuenta()
>>>>>>> 883a5443c7cd0fb4ad4aa847ae9a4f0972ec9fda
            default: cout << "Opción inválida."; pausar();
        }
    } while (true);
}

// --- Funciones auxiliares ---
void Bancos::limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Bancos::pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

// --- Getters ---
std::string Bancos::getBanco() const { return bancoSeleccionado; }
std::string Bancos::getCuenta() const { return tipoCuentaSeleccionada; }
std::string Bancos::getMoneda() const { return monedaSeleccionada; }

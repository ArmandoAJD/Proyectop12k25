#include "Login.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool usuarioExiste(const string& username) {
    ifstream file("usuarios.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (user == username) {
            return true;
        }
    }
    return false;
}

bool registrarUsuario() {
    system ("cls");
    string username, password;
    cout << "\n--- Registro de Usuario ---\n";
    cout << "Ingrese nombre de usuario: ";
    cin >> username;

    if (usuarioExiste(username)) {
        cout << "El usuario ya existe.\n";
        return false;
    }

    cout << "Ingrese contrase�a: ";
    cin >> password;

    ofstream file("usuarios.txt", ios::app);
    file << username << " " << password << "\n";
    file.close();

    cout << "Usuario registrado exitosamente.\n";
    return true;
}

bool iniciarSesion() {
    system ("cls");
    string username, password;
    cout << "\n--- Inicio de Sesion ---\n";
    cout << "Usuario: ";
    cin >> username;
    cout << "Contrase�a: ";
    cin >> password;

    ifstream file("usuarios.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (user == username && pass == password) {
            cout << "Inicio de sesi�n exitoso. Bienvenido, " << username << ".\n";
            return true;
        }
    }

    cout << "Credenciales incorrectas.\n";
    return false;
}

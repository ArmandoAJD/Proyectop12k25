#include "bitacora.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <unordered_map>
#include <chrono>

// Inicializaci�n de los c�digos de los m�dulos en la bit�cora
std::unordered_map<std::string, int> CodigosBitacora::rangos = {
    {"AUTENTICACION", 3000}, {"USUARIOS", 3050}, {"PEDIDOS", 3100},
    {"CLIENTES", 3150}, {"PROVEEDORES", 3200}, {"PRODUCTOS", 3250},
    {"ALMACENES", 3300}, {"TRANSPORTISTAS", 3350}, {"FACTURACION", 3400},
    {"REPORTES", 3450}, {"INVENTARIO", 3500}, {"ENVIOS", 3550},
    {"SISTEMA", 3600}
};

// Obtiene el c�digo asociado a un m�dulo. Si no existe, asigna un nuevo c�digo.
int CodigosBitacora::getCodigo(const std::string& modulo) {
    // Si el m�dulo no existe, lo a�ade con el c�digo inicial
    if (rangos.find(modulo) == rangos.end()) {
        rangos[modulo] = 3000;
    }
    return rangos[modulo]++; // Incrementa el c�digo para el pr�ximo uso
}

// Registra un evento en la bit�cora
void bitacora::registrar(const std::string& usuario,
                         const std::string& modulo,
                         const std::string& descripcion) {
    // Verifica si el archivo est� vac�o para agregar encabezado
    std::ifstream check("bitacora.txt");
    bool isEmpty = check.peek() == std::ifstream::traits_type::eof();
    check.close();

    // Abre el archivo en modo de append (agregar al final)
    std::ofstream file("bitacora.txt", std::ios::app);
    int codigo = CodigosBitacora::getCodigo(modulo);

    // Obtiene la fecha y hora actual
    std::time_t now = std::time(nullptr);
    char fecha[100];
    std::strftime(fecha, sizeof(fecha), "%d/%m/%Y %H:%M:%S", std::localtime(&now));

    if (file.is_open()) {
        // Si el archivo est� vac�o, agrega el encabezado
        if (isEmpty) {
            file << "-------------------------- BIT�CORA DEL SISTEMA --------------------------\n";
            file << std::left
                 << std::setw(12) << "ID_ACCION"
                 << std::setw(15) << "USUARIO"
                 << std::setw(20) << "MODULO"
                 << std::setw(35) << "DESCRIPCION"
                 << std::setw(20) << "FECHA_HORA" << "\n";
            file << "---------------------------------------------------------------------------\n";
        }

        // Escribe el nuevo registro en la bit�cora
        file << std::left
             << std::setw(12) << codigo
             << std::setw(15) << usuario
             << std::setw(20) << modulo
             << std::setw(35) << descripcion
             << std::setw(20) << fecha << "\n";
    }
}

// Obtiene la fecha actual en formato "DD/MM/AAAA"
std::string bitacora::obtenerFechaActual() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&time);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d/%m/%Y");
    return oss.str();
}

// Muestra el contenido de la bit�cora en la consola
void bitacora::mostrarBitacora() {
#ifdef _WIN32
    system("cls");  // Limpiar consola en Windows
#else
    system("clear");  // Limpiar consola en Linux/Mac
#endif

    std::ifstream file("bitacora.txt");

    std::cout << "\t\t========================================================\n";
    std::cout << "\t\t|                      BIT�CORA                        |\n";
    std::cout << "\t\t========================================================\n";

    // Si el archivo est� abierto, muestra su contenido
    if (file.is_open()) {
        std::string linea;
        while (std::getline(file, linea)) {
            std::cout << "\t\t" << linea << "\n";
        }
        file.close();
    } else {
        std::cout << "\t\tNo hay registros en la bit�cora.\n";
    }

    std::cout << "\t\t===============================================================\n";
    system("pause"); // Pausa la ejecuci�n para que el usuario vea la bit�cora
}

// Genera un backup de la bit�cora
void bitacora::generarBackup() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&time);

    std::ostringstream oss;
    oss << "backup_bitacora_" << std::put_time(&tm, "%Y%m%d_%H%M%S") << ".txt";

    std::ifstream src("bitacora.bin", std::ios::binary);
    std::ofstream dst(oss.str(), std::ios::binary);

    if (src && dst) {
        dst << src.rdbuf(); // Copia el contenido de la bit�cora a un nuevo archivo
        registrar("SISTEMA", "SISTEMA", "Backup de bit�cora generado: " + oss.str());
        std::cout << "\n\t\tBackup generado exitosamente: " << oss.str() << "\n";
    } else {
        std::cerr << "\n\t\tError al generar backup!\n";
    }
    system("pause");
}

// Reinicia el contenido de la bit�cora (elimina todo)
void bitacora::reiniciarBitacora() {
    std::ofstream file("bitacora.txt", std::ios::trunc);  // Abre el archivo para truncarlo (vaciarlo)
    if (file.is_open()) {
        file.close();
        std::cout << "Bit�cora reiniciada con �xito.\n";
    } else {
        std::cout << "Error al reiniciar la bit�cora.\n";
    }
    system("pause");
}

// Permite buscar registros en la bit�cora por el c�digo de usuario
void bitacora::buscarPorCodigoUsuario() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    std::string usuarioBuscar;
    std::cout << "\n\t\tIngrese el ID o nombre del usuario a buscar: ";
    std::cin >> usuarioBuscar;

    std::ifstream file("bitacora.txt");
    bool encontrado = false;

    if (file.is_open()) {
        std::string linea;
        std::cout << "\n\t\tRegistros encontrados:\n";
        while (std::getline(file, linea)) {
            if (linea.find(usuarioBuscar) != std::string::npos) {
                std::cout << "\t\t" << linea << "\n";
                encontrado = true;
            }
        }
        file.close();
        if (!encontrado) {
            std::cout << "\t\tNo se encontraron registros para ese usuario.\n";
        }
    } else {
        std::cout << "\t\tNo se pudo abrir la bit�cora.\n";
    }
    system("pause");
}

// Permite buscar registros en la bit�cora por fecha
void bitacora::buscarPorFecha() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    std::string fechaBuscar;
    std::cout << "\n\t\tIngrese la fecha a buscar (formato DD/MM/AAAA): ";
    std::cin >> fechaBuscar;

    std::ifstream file("bitacora.txt");
    bool encontrado = false;

    if (file.is_open()) {
        std::string linea;
        std::cout << "\n\t\tRegistros encontrados:\n";
        while (std::getline(file, linea)) {
            if (linea.find(fechaBuscar) != std::string::npos) {
                std::cout << "\t\t" << linea << "\n";
                encontrado = true;
            }
        }
        file.close();
        if (!encontrado) {
            std::cout << "\t\tNo se encontraron registros para esa fecha.\n";
        }
    } else {
        std::cout << "\t\tNo se pudo abrir la bit�cora.\n";
    }
    system("pause");
}

// Men� principal de la bit�cora para el administrador
void bitacora::menuBitacora() {
    int opcion;
    do {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        std::cout << "\t\t=======================================\n";
        std::cout << "\t\t|      ADMINISTRACI�N DE BIT�CORA     |\n";
        std::cout << "\t\t=======================================\n";
        std::cout << "\t\t 1. Ver registros completos\n";
        std::cout << "\t\t 2. Generar backup\n";
        std::cout << "\t\t 3. Buscar por c�digo de usuario\n";
        std::cout << "\t\t 4. Buscar por fecha\n";
        std::cout << "\t\t 5. Reiniciar bit�cora\n";
        std::cout << "\t\t 6. Volver al men� principal\n";
        std::cout << "\t\t=======================================\n";
        std::cout << "\t\tOpci�n: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: mostrarBitacora(); break;
            case 2: generarBackup(); break;
            case 3: buscarPorCodigoUsuario(); break;
            case 4: buscarPorFecha(); break;
            case 5: reiniciarBitacora(); break;
            case 6: break;
            default:
                std::cout << "\n\t\tOpci�n inv�lida!";
                std::cin.ignore();
                std::cin.get();
        }
    } while (opcion != 6);
}

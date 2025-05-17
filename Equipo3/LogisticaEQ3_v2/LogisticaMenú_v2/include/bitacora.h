#ifndef BITACORA_H
#define BITACORA_H

#include <string>
#include <unordered_map>  // Necesario para usar std::unordered_map

/**
 * Clase encargada de manejar los c�digos �nicos para cada m�dulo en la bit�cora.
 */
class CodigosBitacora {
private:
    // Mapa que contiene los rangos base de c�digos por m�dulo
    static std::unordered_map<std::string, int> rangos;

public:
    /**
     * Devuelve un c�digo �nico para cada acci�n seg�n el m�dulo.
     * Si el m�dulo no existe en el mapa, se inicializa en 3000.
     * @param modulo Nombre del m�dulo (ej. "USUARIOS", "PEDIDOS", etc.)
     * @return C�digo �nico para la bit�cora.
     */
    static int getCodigo(const std::string& modulo);
};

/**
 * Clase encargada de registrar y administrar acciones del sistema en una bit�cora.
 */
class bitacora {
public:
    /**
     * Registra una acci�n en la bit�cora con los datos del usuario, m�dulo y descripci�n.
     * @param usuario Nombre o ID del usuario que realiza la acci�n.
     * @param modulo M�dulo del sistema (ej. "USUARIOS", "PRODUCTOS", etc.).
     * @param descripcion Descripci�n de la acci�n realizada.
     */
    static void registrar(const std::string& usuario, const std::string& modulo, const std::string& descripcion);

    /**
     * Alias del m�todo registrar. Permite registrar acciones de forma m�s intuitiva en algunos contextos.
     */
    static void insertar(const std::string& usuario, const std::string& modulo, const std::string& descripcion) {
        registrar(usuario, modulo, descripcion);
    }

    /**
     * Muestra el contenido actual del archivo de bit�cora en consola.
     */
    static void mostrarBitacora();

    /**
     * Crea una copia de seguridad de la bit�cora con nombre basado en la fecha y hora actual.
     */
    static void generarBackup();

    /**
     * Borra todo el contenido del archivo de bit�cora.
     */
    static void reiniciarBitacora();

    /**
     * Busca registros en la bit�cora por nombre o ID de usuario.
     */
    static void buscarPorCodigoUsuario();

    /**
     * Busca registros en la bit�cora por fecha espec�fica (formato DD/MM/AAAA).
     */
    static void buscarPorFecha();

    /**
     * Muestra el men� interactivo para administrar la bit�cora desde la consola.
     */
    static void menuBitacora();

private:
    /**
     * Obtiene la fecha actual en formato DD/MM/AAAA.
     * @return Cadena con la fecha actual.
     */
    static std::string obtenerFechaActual();
};

#endif // BITACORA_H

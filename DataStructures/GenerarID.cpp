#include "GenerarID.h"
#include "Logic/Usuario_Manager.h"
#include <cstdlib>  // rand, srand
#include <ctime>    // time
#include <stdexcept> // std::runtime_error

int GenerarIDUnico(NodoABB* raiz) {

    static bool inicializado = false;
    if (!inicializado) {
        srand(static_cast<unsigned int>(time(nullptr)));
        inicializado = true;
    }

    int nuevoID;
    int intentos = 0;
    const int maxIntentos = 10000;

    do {
        nuevoID = rand() % 9000 + 1000;  // ID entre 1000 y 9999
        intentos++;
        if (intentos > maxIntentos) {
            throw std::runtime_error("No se pudo generar un ID único (demasiados intentos)");
        }
    } while (ExisteUsuario(raiz, nuevoID));

    return nuevoID;
}

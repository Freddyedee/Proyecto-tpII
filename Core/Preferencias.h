#ifndef CORE_PREFERENCIAS_H
#define CORE_PREFERENCIAS_H

#include <string>

#include "Productos.h"

struct Preferencia {

    std::string categoria;
    std::string marca;
    Producto* productosPreferidos;
    Preferencia* siguiente;
};

#endif

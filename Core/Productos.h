#ifndef CORE_PRODUCTO_H
#define CORE_PRODUCTO_H

#include <string>

struct Producto {
    
    int idProducto;
    std::string descripcion;
    std::string categoria;
    std::string marca;
    float precio;
    int calidad;

    Producto* siguiente = nullptr; // Lista enlazada simple

};

#endif // CORE_PRODUCTO_H

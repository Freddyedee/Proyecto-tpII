#ifndef PRODUCTOMANAGER_H
#define PRODUCTOMANAGER_H

#include "Core/Productos.h"
#include <string>

Producto* CrearCatalogo(); //Se utilizara para qml lea los productos

Producto* FiltrarporCategoriaMarca(Producto* catalogo, const std::string& categoria, const std::string& marca);

void LiberarCatalogo(Producto* catalogo);




#endif // PRODUCTOMANAGER_H

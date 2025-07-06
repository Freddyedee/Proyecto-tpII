#ifndef CORE_USUARIO_H
#define CORE_USUARIO_H

#include "Preferencias.h"
#include "Historial.h"
#include <string>

struct Usuario {
    std::string nombre;
    std::string apellido;
    std::string usuario;
    std::string contrasena;
    int idUsuario;

    Preferencia* preferencias = nullptr; //Se inicializan los punteros nulos al trabajar con listas enlazadas
    Historial* historial = nullptr;
};

#endif // CORE_USUARIO_H

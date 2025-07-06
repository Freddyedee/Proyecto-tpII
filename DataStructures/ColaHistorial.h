#ifndef  DATASTRUCTURE_COLAHISTORIAL_H
#define DATASTRUCTURE_COLAHISTORIAL_H

#include "../Core/Historial.h"  // Para Historial y NodoHistorial
#include "../Core/Productos.h"  // Para Producto
#include <iostream>

    // Métodos que reciben un Historial* para modificarlo

    bool estaLlena(Historial* historialusuario);
    bool estaVacia(Historial* historialusuario);
    void encolar(Producto* producto,Historial* historialusuario);
    void desencolar(Historial* historialusuario);
    void verCola(Historial* historialusuario); 
    void mostrarEstado(Historial* historialusuario); 

/*static void encolar(Producto* producto, Historial* historialUsuario);
    static void desencolar(Historial* historialUsuario);
    static bool estaVacia(const Historial* historialUsuario);*/
// Entradas
/*
encolar(Lavadora, Usuario.historial)
desencolar(Usuario.historial) //
estaVacia(Usuario.historial) //
*/
#endif // DATASTRUCTURES_COLA_H
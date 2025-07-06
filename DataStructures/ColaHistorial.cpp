#include "ColaHistorial.h"
#include <iostream>


bool estaLlena(Historial* historialusuario) {
    return historialusuario->elementos == TAMANO_COLA;
}

bool estaVacia(Historial* historialusuario) {
    return historialusuario->elementos == 0;
}

void encolar(Producto* producto,Historial* historialusuario) {
    historialusuario->final = (historialusuario->final + 1) % TAMANO_COLA; // 'final' avanza a la siguiente posición
    historialusuario->cola[historialusuario->final] = *producto;             // Encolar en la nueva posición de 'final'
    historialusuario->elementos++;
    std::cout << "Elemento " << producto->marca << " encolado.\n";
}

void desencolar(Historial* historialusuario) {
    if (estaVacia(historialusuario)) {
        std::cout << "Cola vacia, no se puede desencolar.\n";
        return;
    }
    std::cout << "Elemento " << historialusuario->cola[historialusuario->frente].marca << " desencolado.\n";
    historialusuario->cola[historialusuario->frente] = Producto(); // Se coloca el elemento a cero (opcional)
    historialusuario->frente = (historialusuario->frente + 1) % TAMANO_COLA; // 'frente' avanza
    historialusuario->elementos--;
}

void verCola(Historial* historialusuario) {
    std::cout << "Elementos en la cola:\n";
    std::cout << "Indice: ";
    for (int i = 0; i < historialusuario->elementos; ++i) {
        std::cout << (historialusuario->frente + i) % TAMANO_COLA << (i == historialusuario->elementos - 1 ? " " : "     ");
    }
    std::cout << std::endl;
    std::cout << "Valor:  ";
    for (int i = 0; i < historialusuario->elementos; ++i) {
        std::cout << historialusuario->cola[(historialusuario->frente + i) % TAMANO_COLA].marca << (i == historialusuario->elementos - 1 ? " " : " <- ");
    }
    std::cout << std::endl;
}

void mostrarEstado(Historial* historialusuario) {
    std::cout << "Estado de la Cola:\n";
    std::cout << "  Frente: " << historialusuario->frente << std::endl;
    std::cout << "  Final:  " << historialusuario->final << std::endl;
    std::cout << "  Elementos: " << historialusuario->elementos << std::endl;
    
}

//No usado, son listas enlazadas y creo que es mejor cola circular
/*// Añade un producto al final del historial (como cola FIFO)
void encolar(Producto* producto, Historial* historialUsuario) {
    NodoHistorial* nuevoNodo = new NodoHistorial(producto);

    if (historialUsuario->primero == NULL) {
        historialUsuario->primero = nuevoNodo;
    } else {
        NodoHistorial* temp = historialUsuario->primero;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
    historialUsuario->cantidad++;
}

// Elimina el producto más antiguo (frente de la cola)
void desencolar(Historial* historialUsuario) {
    if (estaVacia(historialUsuario)) return;

    NodoHistorial* temp = historialUsuario->primero;
    historialUsuario->primero = historialUsuario->primero->siguiente;
    delete temp;
    historialUsuario->cantidad--;
}

// Verifica si el historial está vacío
bool estaVacia(const Historial* historialUsuario) {
    return historialUsuario->primero == NULL;
}
*/
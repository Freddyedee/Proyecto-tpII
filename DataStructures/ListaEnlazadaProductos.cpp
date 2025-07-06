#include <iostream>
#include "ListaEnlazadaProductos.h"

void AgregarProductos(Producto*& cabeza, int id, const std::string &descripcion,
const std::string& marca, float precio, int calidad, const std::string& categoria){

    Producto *nuevo = new Producto {descripcion, marca,categoria,id,precio, calidad, nullptr};

    if(!cabeza){
        cabeza = nuevo; 
    }else{
        Producto* actual = cabeza;
        
        while(actual->siguiente){
            actual = actual->siguiente; 
            actual ->siguiente = nuevo; 
        }
    }
};

void MostrarProductos(const Producto* cabeza){
    
    const Producto* actual = cabeza; 
    while(actual){

        std::cout << "ID: " << actual -> id << " | " << actual->descripcion << std::endl; 
        std::cout << " | Marca: " << actual->marca << std::endl; 
        std::cout << " | Precio: $" << actual->precio << std::endl; 
        std::cout << " | Calidad: " << actual->calidad << std::endl; 
        std::cout << " | categoria: " << actual->categoria << std::endl; 

        actual = actual ->siguiente; 
    }
}; 

Producto* BuscarProductoID(Producto* cabeza, int id){

    Producto* actual = cabeza; 
    while(actual){
        if(actual->id == id){
            return actual;
            actual = actual ->siguiente;
        }
    }

    return nullptr;
}

void EliminarProducto(Producto*& cabeza, int id){

    Producto *actual = cabeza; 
    Producto* anterior = nullptr; 

    while(actual){

        if(actual->id == id){
            if(anterior){
                anterior->siguiente = actual->siguiente; 
            }
            else{
                cabeza = actual ->siguiente;
            }

            delete actual;
            return;

        }

        anterior = actual; 
        actual = actual->siguiente; 
    }
}

void LiberarProductos(Producto *&cabeza){

    while(cabeza){
        Producto* temp = cabeza;
        cabeza = cabeza -> siguiente; 
        delete temp; 
    }
    cabeza = nullptr;
}; 

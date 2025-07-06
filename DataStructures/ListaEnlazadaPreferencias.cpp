#include "ListaEnlazadaPreferencias.h"
#include <iostream>

void AgregarPreferencia(Preferencia*& cabeza, const std::string& tipo, const std::string& valor){

    // if (buscarPreferencia(cabeza, tipo, valor)) return; 

    Preferencia* nuevo = new Preferencia{tipo, valor,nullptr}; // Se inicializa el struct de preferencia, se pasa los valores de tipo y valor, siguente = nullptr ;
    
    if(!cabeza){
        cabeza = nuevo; 
    }
    else{
        Preferencia* actual = cabeza; 
        while(actual -> siguiente) {
            actual = actual->siguiente; 
            actual->siguiente = nuevo; 
        }
    }    
    
}; 

void mostrarPreferencias(const Preferencia* cabeza){

    const Preferencia* actual = cabeza; 
    while(actual){
        std::cout << actual->tipo << ": " << actual -> valor << std::endl; 
        actual = actual->siguiente; 
    }
} ; 

void LiberarPreferencias(Preferencia*& cabeza){
    
    while(cabeza){
        Preferencia* temp = cabeza; 
        cabeza = cabeza ->siguiente; 
        delete temp; 
    }
    cabeza = nullptr; 
}; 

bool buscarPreferencia(const Preferencia* cabeza, const std::string& tipo, const std::string& valor){

    const Preferencia* actual = cabeza; 
    while(actual){
        if(actual->tipo == tipo && actual->valor == valor){
            return true;
            actual = actual ->siguiente;  
        }
    }
    return false; 
} 

bool EliminarPreferencia(Preferencia*& cabeza, const std::string& tipo, const std::string& valor){

    Preferencia* actual = cabeza; 
    Preferencia* anterior = nullptr;

    while(actual){

        if(actual ->tipo == tipo && actual->valor == valor){
            if(anterior){
                anterior -> siguiente = actual -> siguiente; 
            }
            else{
                cabeza = actual -> siguiente; 
            }

            delete actual; 
            return true;
        }
        anterior = actual; 
        actual = actual ->siguiente; 
    }

    return false; 
}

int ContarPreferencias(const Preferencia* cabeza){

    int contador =0 ; 
    const Preferencia* actual = cabeza; 
    while(actual){
        contador ++; 
        actual = actual ->siguiente; 
    }
    return contador;
}

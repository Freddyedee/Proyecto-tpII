#include "ArbolBinarioBusqueda.h"
#include <iostream>

void insertarUsuario(NodoABB*& raiz, Usuario* nuevo){

    if(raiz == nullptr){
        raiz = new NodoABB{nuevo, nullptr, nullptr}; //Se inicializan los capos directamente 
    }
    else if(nuevo->idUsuario < raiz -> User->idUsuario){
        insertarUsuario(raiz -> izquierdo, nuevo);  //Se inserta por la izquierda en caso de ser menor
    }
    else if(nuevo -> idUsuario > raiz -> User -> idUsuario){
        insertarUsuario(raiz -> derecho, nuevo); //Se inserta por la Derecha en caso de ser mayor
    }
    else{
        std::cout << "ID duplicado, imposible insertar."; 
    }

};

Usuario* BuscarUsuario(NodoABB* raiz, int id){

    if(raiz == nullptr){
        return nullptr; 
    }

    if(id == raiz->User->idUsuario){
        return raiz ->User; 
    }
    else if(id < raiz->User->idUsuario){
        return BuscarUsuario(raiz->izquierdo, id);
    }
    else{
        return BuscarUsuario(raiz->derecho, id); 
    }
};

void MostrarUsuariosINORDEN(NodoABB* raiz){

    if(raiz != nullptr){
        MostrarUsuariosINORDEN(raiz -> izquierdo);
        std::cout << "Usuario: " << raiz->User->usuario << "ID: " << raiz->User->idUsuario << "\n";
        MostrarUsuariosINORDEN(raiz ->derecho); 
    }
};

void EliminarUsuario(NodoABB*& raiz, int id){

    if(raiz == nullptr){
        return;  // Si el arbol o sub arbol se encuentra vacio no hay nada que eliminar, el return sentencia la recursion. 
    }

    // Si el id a eliminar es menor al del nodo actual, se va por la izquierda. Si es mayor, por la derecha
    if(id < raiz->User->idUsuario){
        EliminarUsuario(raiz->izquierdo, id); 
    }
    else if(id > raiz->User->idUsuario){
        EliminarUsuario(raiz->derecho, id); 
    }

    //Encontrado
    else{

        NodoABB * temp = nullptr; 

        //caso 1: sin hijos (hoja)

        //Se libera memoria del usuario y del nodo, de esta manera se coloca el puntero raiz en null para que el padre deje de apuntar a el. 

        if(raiz-> izquierdo == nullptr && raiz ->derecho == nullptr){
            delete raiz -> User;
            delete raiz; 
            raiz = nullptr;  
        
        
        //caso 2: un hijo 
        }else if(raiz -> izquierdo == nullptr){

            temp = raiz; // guarda nodo actual en temporal
            raiz = raiz -> derecho;  //  reemplaza el nodo actual por su hijo derecho
            delete temp->User; // libera memoria del usuario asociado
            delete temp; // libera la memoria del nodo 

            //La condicion verifica si el nodo actual no tiene hijo izquierdo, si no, el nodo se reemplazara por su hijo derecho
        }

        else if(raiz -> derecho == nullptr){
            temp = raiz; 
            raiz = raiz->izquierdo; 
            delete temp ->User; 
            delete temp; 
        }

        //Caso 3: dos hijos 

        else{
            
            NodoABB* PadreSucesor = raiz; //PadreSucesor comienza apuntando a raiz, por si necesitamos actualizar conexiones más adelante.
            NodoABB* Sucesor = raiz -> derecho; //se inicializa el hijo derecho del nodo actual

            while(Sucesor ->izquierdo !=nullptr){ // se busca el nodo mas a la izquierda del subarbol derecho
                PadreSucesor = Sucesor; 
                Sucesor = Sucesor -> izquierdo;  //este nodo es el que tiene menor valor mayor que el nodod actual
            }

            // Se reemplaza los datos
            delete raiz->User; 
            raiz->User = new Usuario(*Sucesor -> User); // se copia la informacion del sucesor al nodo actual

            EliminarUsuario(raiz->derecho, Sucesor->User->idUsuario);

            // se elimina recursivamente, para eliminar el nodo duplicado que contiene los datos ya copiados 

        }

    }
}; 

void LiberarArbol(NodoABB*& raiz){

    if(raiz != nullptr){
        LiberarArbol(raiz->izquierdo);
        LiberarArbol(raiz->derecho);
        delete raiz -> User; 
        delete raiz; 
        raiz = nullptr; 
    }

}; 
#ifndef DATASTRUCTURES_ARBOLBINARIOBUSQUEDA_H
#define DATASTRUCTURES_ARBOLBINARIOBUSQUEDA_H

#include "../Core/Usuario.h"


//Nodo para el arbol, Declaracion 
struct NodoABB{

    Usuario *User;  //Dato 
    NodoABB *izquierdo; // hijo izquierdo
    NodoABB *derecho;  // hijo derecho
}; 

//Funciones que desarrollara en el arbol binario de busqueda. 

void insertarUsuario(NodoABB*&, Usuario*);
Usuario* BuscarUsuario(NodoABB* , int); 
void MostrarUsuariosINORDEN(NodoABB*);
void EliminarUsuario(NodoABB*&, int);
void LiberarArbol(NodoABB*& ); 



#endif // ARBOLBINARIOBUSQUEDA_H

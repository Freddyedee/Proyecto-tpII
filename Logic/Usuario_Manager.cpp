#include "Usuario_Manager.h"
#include <iostream>
#include "DataStructures/ArbolBinarioBusqueda.h"

#include <QObject>
#include <QString>

bool RegistrarUsuario(NodoABB*& raiz, Usuario* nuevo) {
    if (ExisteUsuario(raiz, nuevo->idUsuario)) return false;
    insertarUsuario(raiz, nuevo);  // ya está ordenado por ID
    return true;
}

//cambio
Usuario* loginPorNombre(NodoABB* raiz, const std::string& username, const std::string& contrasena) {
    Usuario* encontrado = BuscarUsuarioUsername(raiz, username);
    if (!encontrado){
        return nullptr;
    }

    Usuario* desdeABB = BuscarUserID(raiz, encontrado->idUsuario);

    if(desdeABB && desdeABB->contrasena == contrasena){
        return desdeABB;
    }

    return nullptr;

}

bool ExisteUsuario(NodoABB* raiz, int id) {
    return BuscarUserID(raiz, id) != nullptr;
}

Usuario* BuscarUserID(NodoABB* raiz, int id) {
    return BuscarUsuario(raiz, id);  // implementada en ABB
}

void MostrarUsuarioInOrden(NodoABB* raiz) {
    MostrarUsuariosINORDEN(raiz);  //  implementada en ABB
}

void liberarArbol(NodoABB*& raiz) {
    LiberarArbol(raiz);  // implementada en ABB
}

//cambio
Usuario* BuscarUsuarioUsername(NodoABB* raiz, const std::string& username){
    if(!raiz){
        return nullptr;
    }

    if(raiz->User->usuario == username){
        return raiz->User;
    }

    Usuario* izquierda = BuscarUsuarioUsername(raiz->izquierdo, username);

    if(izquierda){
        return izquierda;
    }

    return BuscarUsuarioUsername(raiz->derecho, username);
}




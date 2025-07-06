#ifndef LOGIC_USUARIOMANAGER_H
#define LOGIC_USUARIOMANAGER_H


#include "Core/Usuario.h"
#include "DataStructures/ArbolBinarioBusqueda.h"
#include <string>
#include <QRegularExpression>

#include <QObject>
#include <QString>

bool RegistrarUsuario(NodoABB*& raiz, Usuario *nuevo);
Usuario* loginPorNombre(NodoABB* raiz, const std::string& username, const std::string& contrasena);
bool ExisteUsuario(NodoABB* raiz, int id); 
Usuario* BuscarUserID(NodoABB* raiz, int id);
void MostrarUsuarioInOrden(NodoABB* raiz);
void LiberarArbol(NodoABB*& raiz);
Usuario* BuscarUsuarioUsername(NodoABB* raiz, const std::string& username);






#endif //LOGIC_USUARIOMANAGER_H

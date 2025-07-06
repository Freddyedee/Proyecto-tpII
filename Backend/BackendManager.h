// interface/BackendManager.h
#ifndef BACKENDMANAGER_H
#define BACKENDMANAGER_H

#include <QObject>
#include <QString>
#include "Core/Usuario.h"
#include "DataStructures/ArbolBinarioBusqueda.h"
#include "Logic/Usuario_Manager.h"

class BackendManager : public QObject {
    Q_OBJECT
public:
    explicit BackendManager(QObject* parent = nullptr);
    ~BackendManager();

    //Funciones de registro e inicio de sesion

    //implementadas
    Q_INVOKABLE bool iniciarSesion(const QString& username, const QString& contrasena);
    Q_INVOKABLE QString obtenerNombreUsuarioActual() const;

    //implementadas
    Q_INVOKABLE void CerrarSesion();
    Q_INVOKABLE bool UsuarioLogeado();
    Q_INVOKABLE int ObtenerIDUser() const;


    Q_INVOKABLE QString RegistrarUsuarioCompleto(const QString& nombre,
                                        const QString& apellido,
                                        const QString& username,
                                        const QString& contrasena);



    //funciones para qml sobre productos.

    Q_INVOKABLE QStringList ObtenerCategoriasDisponibles() const;
    Q_INVOKABLE QStringList ObtenerMarcasporCategoria(const QString& categoria) const;
    Q_INVOKABLE void GuardarPreferencia(const QStringList& categorias, const QStringList& marcas);
    Q_INVOKABLE QVariantList ObtenerProductosPreferidos() const;

private:
    NodoABB* raizUsuarios;
    Usuario* usuarioActivo;
    Producto* catalogoGlobal; //precargar el catalogo
    QString mensajeSesion;
};

#endif // BACKENDMANAGER_H

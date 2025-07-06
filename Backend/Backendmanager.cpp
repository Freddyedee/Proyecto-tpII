// interface/BackendManager.cpp
#include "BackendManager.h"
#include "Logic/Usuario_Manager.h"
#include "Datastructures/GenerarID.h"
#include "Logic/productomanager.h"
#include "Logic/PreferenciaManager.h"

#include <Qset>
#include <QVariantList>
#include <QVariantMap>

BackendManager::BackendManager(QObject* parent)
    : QObject(parent), raizUsuarios(nullptr), usuarioActivo(nullptr) {
    catalogoGlobal = CrearCatalogo();
    qDebug() << "Catalogo creado";  //cargar producto una vez
}

BackendManager::~BackendManager() {
    LiberarArbol(raizUsuarios); // usa la función de Usuario_Manager
}

Q_INVOKABLE QString BackendManager:: RegistrarUsuarioCompleto(const QString& nombre,
                                              const QString& apellido,
                                              const QString& username,
                                              const QString& contrasena) {

    //Crear y registrar nuevo usuario

    Usuario* nuevo = new Usuario;
    nuevo->idUsuario = GenerarIDUnico(raizUsuarios);
    nuevo->nombre = nombre.toStdString();
    nuevo->apellido = apellido.toStdString();
    nuevo->usuario = username.toStdString();  // Asumiendo que lo agregaste al struct Usuario
    nuevo->contrasena = contrasena.toStdString();

    bool ok = RegistrarUsuario(raizUsuarios,nuevo);
    if(ok)
    {usuarioActivo = nuevo;
    return "OK";
    }

    return "❌ No se pudo registrar el usuario (error desconocido)";
}


QString mensajeSesion = "";

bool BackendManager::iniciarSesion(const QString& username, const QString& contrasena) {
    usuarioActivo = loginPorNombre(raizUsuarios, username.toStdString(), contrasena.toStdString());

    if (usuarioActivo) {
        mensajeSesion = "Bienvenido, " + QString::fromStdString(usuarioActivo->nombre);
        return true;
    } else {
        mensajeSesion = "Usuario o contraseña incorrectos";
        return false;
    }
}



void BackendManager::CerrarSesion(){
    usuarioActivo = nullptr;
    mensajeSesion = "Sesion cerrada";
}



bool BackendManager::UsuarioLogeado(){

    return usuarioActivo != nullptr;

}



QString BackendManager::obtenerNombreUsuarioActual() const {
    if (usuarioActivo){

        return QString::fromStdString(usuarioActivo->nombre);
    }
    return "No logueado";
}



int BackendManager::ObtenerIDUser() const {
    return usuarioActivo ? usuarioActivo->idUsuario : -1;
}



// obtengo categorias disponibles

QStringList BackendManager::ObtenerCategoriasDisponibles() const {

    QSet<QString> categoriasUnicos;
    Producto* actual = catalogoGlobal;

    while(actual){
        categoriasUnicos.insert(QString::fromStdString(actual->categoria));
        qDebug() << "↪ Categoría encontrada:" << QString::fromStdString(actual->categoria);
        actual = actual -> siguiente;
    }

    return categoriasUnicos.values();

}



//obtener marcas disponibles para una categoria

QStringList BackendManager::ObtenerMarcasporCategoria(const QString& categoria) const {
    QSet<QString> marcasUnicas;
    Producto* actual = catalogoGlobal;

    while (actual) {
        if (QString::fromStdString(actual->categoria) == categoria) {
            marcasUnicas.insert(QString::fromStdString(actual->marca));
        }
        actual = actual->siguiente;
    }

    return marcasUnicas.values();
}



// Guardar las preferencias seleccionadas por el usuario activo
void BackendManager::GuardarPreferencia(const QStringList& categorias, const QStringList& marcas) {
    if (!usuarioActivo) return;

    for (const QString& categoria : categorias) {
        for (const QString& marca : marcas) {
            AsignarPreferencia(usuarioActivo, categoria.toStdString(), marca.toStdString(), catalogoGlobal);
        }
    }
}



// Obtener todos los productos preferidos del usuario activo (explicar)

QVariantList BackendManager::ObtenerProductosPreferidos() const {
    QVariantList productosList;

    if (!usuarioActivo) return productosList;

    Preferencia* pref = usuarioActivo->preferencias;
    while (pref) {
        Producto* prod = pref->productosPreferidos;
        while (prod) {
            QVariantMap item;
            item["id"] = prod->idProducto;
            item["descripcion"] = QString::fromStdString(prod->descripcion);
            item["categoria"] = QString::fromStdString(prod->categoria);
            item["marca"] = QString::fromStdString(prod->marca);
            item["precio"] = prod->precio;
            item["calidad"] = prod->calidad;
            productosList.append(item);
            prod = prod->siguiente;
        }
        pref = pref->siguiente;
    }

    return productosList;
}

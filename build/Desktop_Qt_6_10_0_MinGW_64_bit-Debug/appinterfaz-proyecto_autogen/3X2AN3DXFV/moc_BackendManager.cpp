/****************************************************************************
** Meta object code from reading C++ file 'BackendManager.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../Backend/BackendManager.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BackendManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN14BackendManagerE_t {};
} // unnamed namespace

template <> constexpr inline auto BackendManager::qt_create_metaobjectdata<qt_meta_tag_ZN14BackendManagerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BackendManager",
        "iniciarSesion",
        "",
        "username",
        "contrasena",
        "obtenerNombreUsuarioActual",
        "CerrarSesion",
        "UsuarioLogeado",
        "ObtenerIDUser",
        "RegistrarUsuarioCompleto",
        "nombre",
        "apellido",
        "ObtenerCategoriasDisponibles",
        "ObtenerMarcasporCategoria",
        "categoria",
        "GuardarPreferencia",
        "categorias",
        "marcas",
        "ObtenerProductosPreferidos",
        "QVariantList"
    };

    QtMocHelpers::UintData qt_methods {
        // Method 'iniciarSesion'
        QtMocHelpers::MethodData<bool(const QString &, const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QString, 3 }, { QMetaType::QString, 4 },
        }}),
        // Method 'obtenerNombreUsuarioActual'
        QtMocHelpers::MethodData<QString() const>(5, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'CerrarSesion'
        QtMocHelpers::MethodData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'UsuarioLogeado'
        QtMocHelpers::MethodData<bool()>(7, 2, QMC::AccessPublic, QMetaType::Bool),
        // Method 'ObtenerIDUser'
        QtMocHelpers::MethodData<int() const>(8, 2, QMC::AccessPublic, QMetaType::Int),
        // Method 'RegistrarUsuarioCompleto'
        QtMocHelpers::MethodData<QString(const QString &, const QString &, const QString &, const QString &)>(9, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 10 }, { QMetaType::QString, 11 }, { QMetaType::QString, 3 }, { QMetaType::QString, 4 },
        }}),
        // Method 'ObtenerCategoriasDisponibles'
        QtMocHelpers::MethodData<QStringList() const>(12, 2, QMC::AccessPublic, QMetaType::QStringList),
        // Method 'ObtenerMarcasporCategoria'
        QtMocHelpers::MethodData<QStringList(const QString &) const>(13, 2, QMC::AccessPublic, QMetaType::QStringList, {{
            { QMetaType::QString, 14 },
        }}),
        // Method 'GuardarPreferencia'
        QtMocHelpers::MethodData<void(const QStringList &, const QStringList &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QStringList, 16 }, { QMetaType::QStringList, 17 },
        }}),
        // Method 'ObtenerProductosPreferidos'
        QtMocHelpers::MethodData<QVariantList() const>(18, 2, QMC::AccessPublic, 0x80000000 | 19),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BackendManager, qt_meta_tag_ZN14BackendManagerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject BackendManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BackendManagerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BackendManagerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN14BackendManagerE_t>.metaTypes,
    nullptr
} };

void BackendManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BackendManager *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = _t->iniciarSesion((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->obtenerNombreUsuarioActual();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->CerrarSesion(); break;
        case 3: { bool _r = _t->UsuarioLogeado();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->ObtenerIDUser();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->RegistrarUsuarioCompleto((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: { QStringList _r = _t->ObtenerCategoriasDisponibles();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 7: { QStringList _r = _t->ObtenerMarcasporCategoria((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->GuardarPreferencia((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[2]))); break;
        case 9: { QVariantList _r = _t->ObtenerProductosPreferidos();
            if (_a[0]) *reinterpret_cast< QVariantList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *BackendManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackendManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN14BackendManagerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BackendManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP

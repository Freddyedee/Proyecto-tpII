#include "PreferenciaManager.h"
#include "productomanager.h"


void AsignarPreferencia(Usuario* usuario, const std::string &categoria, const std::string &marca, Producto* catalogo){

    Preferencia* nueva = new Preferencia;
    nueva->categoria = categoria;
    nueva->marca = marca;
    nueva->productosPreferidos = FiltrarporCategoriaMarca(catalogo, categoria, marca);
    nueva->siguiente = usuario ->preferencias;
    usuario ->preferencias = nueva;


}

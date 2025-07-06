#include "productomanager.h"

Producto* CrearCatalogo(){

    Producto *p1 = new Producto{1, "Zelda Breath of the Wild", "Juegos", "Nintendo", 55.99, 5, nullptr};
    Producto *p2 = new Producto{2, "Super Mario Bros", "Juegos", "Nintendo", 44.77, 4, nullptr };
    Producto *p3 = new Producto{3, "FIFA 22", "Juegos", "EA Sports", 22.66, 5, nullptr};
    Producto *p4 = new Producto{4, "Smart TV", "Electrónica", "Samsung", 149.99, 3, nullptr};
    Producto *p5 = new Producto{5, "Computadora", "Electrónica", "Lenovo", 180, 4, nullptr};

    p1 ->siguiente = p2;
    p2 ->siguiente = p3;
    p3 ->siguiente = p4;
    p4 ->siguiente = p5;
    p5 ->siguiente = nullptr;

    return p1;
}

Producto* FiltrarporCategoriaMarca(Producto* catalogo, const std::string& categoria, const std::string& marca){

    Producto* resultado = nullptr;
    Producto* ultimo = nullptr;

    while(catalogo){
        if(catalogo->categoria == categoria && catalogo->marca == marca){
            Producto* ref = catalogo;

            if(!resultado){
                resultado = ref;
                ultimo = ref;
            }else{
                ultimo->siguiente = ref;
                ultimo = ref;
            }
        }

        catalogo = catalogo->siguiente;
    }

    if(ultimo) ultimo->siguiente = nullptr;
    return resultado;
}

void LiberarCatalogo(Producto* catalogo){
    while(catalogo){
        Producto* temp = catalogo;
        catalogo = catalogo ->siguiente;
        delete temp;

    }
}

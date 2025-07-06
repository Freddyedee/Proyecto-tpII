//Definicion de el catalogo de preferencias desde el programa..

#ifndef CORE_CATALOGO_PREFERENCIAS_H
#define CORE_CATALOGO_PREFERENCIAS_H

#include <string>
#include <vector>

//Struct que definira los elementos para el nombre de la categoria y la marca
struct Categoria{

    std:: string Nombre; 
    std::vector<std::string> Marcas; 

}; 

//Se inicializa un nuevo espacio de nombres para las preferencias. 

namespace CatalogoPreferencias{

    //Categorias y marcas predefinidas en el sistema

    //La utilizacion de const se debe a que solo se trabajara con lectura. 
    // Se define un vecotr de struct en este caso Categoria

    const std::vector<Categoria> catalogo = {
    
        {"Electrónica" , {"Samsung", "Apple", "Sony"}}, 
        {"Ropa", {"Nike" , "Adidas" , "Puma"}}
    }; 
}
















#endif
#include "Logic/HistorialManager.h"

void AgregarAlHistorial(Producto* Producto, Historial* historialusuario){
    if(estaLlena(historialusuario)){
        desencolar(historialusuario);
        encolar(Producto, historialusuario);
    }else{
        encolar(Producto, historialusuario);
    }
}


void LimpiarHistorial(Historial* historialusuario){
    if (estaVacia(historialusuario))
    {
        return;
    }
    for (int i = historialusuario->elementos; i >= 0; i++)
    {
        desencolar(historialusuario);
    }
}

/*void RecomendacionesPorHistorial(){

}*/

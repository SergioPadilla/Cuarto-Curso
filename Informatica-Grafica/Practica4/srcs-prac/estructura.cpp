#include "estructura.hpp"

void Estructura::fijarh(float h1){
  h = h1;
  *(entradas[0].matriz) = MAT_Traslacion(0,2*h1+0.5,0);
}

Estructura::Estructura(float h1){
  agregar(MAT_Traslacion(0,h1+1.5,0));
  agregar(new Base());
  agregar(MAT_Traslacion(6,0,0));
  agregar(MAT_Escalado(5,1,1));
  agregar(new Base());
}

#include "brazo1.hpp"

void Brazo1::fijarh(float h1){
  h = h1;
  *(entradas[0].matriz) = MAT_Traslacion(0,h1+0.5,0);
  *(entradas[1].matriz) = MAT_Escalado(1,h1,1);
}

Brazo1::Brazo1(float h1){
  agregar(MAT_Traslacion(0,h1+0.5,0));
  agregar(MAT_Escalado(1,h1,1));
  agregar(new Cilindro(20));
}

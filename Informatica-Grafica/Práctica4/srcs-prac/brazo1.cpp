#include "brazo1.hpp"

void Brazo1::fijarh(float h1){
  h = h1;
//  entradas[0].objeto->fijarh(h1);
}

Brazo1::Brazo1(float h1){
  fijarh(h1);
  agregar(MAT_Traslacion(0.0,5.5,0.0));
  agregar(MAT_Escalado(0.5,5.0,1.0));
  agregar(new Cilindro(50));
}

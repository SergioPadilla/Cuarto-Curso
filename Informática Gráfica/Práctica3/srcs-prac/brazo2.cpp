#include "brazo2.hpp"

void Brazo2::fijarh(float h1){
  h = h1;
//  entradas[0].objeto->fijarh(h1);
}

Brazo2::Brazo2(float h1){
  fijarh(h1);
  //agregar(MAT_Escalado(0.5,5.0,1.0));
  agregar(MAT_Traslacion(0.0,-5.5,0.0));
  agregar(new Cilindro(50));
}

#include "brazo2.hpp"

void Brazo2::fijarh(float h1){
  h = h1;
  *(entradas[0].matriz) = MAT_Traslacion(2,2*h1,0);
}

void Brazo2::fijart(float t1){
  t = t1;
  *(entradas[1].matriz) = MAT_Traslacion(t,0,0);
}

Brazo2::Brazo2(float h1, float t1){
  agregar(MAT_Traslacion(2,h1+1,0));
  agregar(MAT_Traslacion(t1,0,0));
  agregar(new Base());
}

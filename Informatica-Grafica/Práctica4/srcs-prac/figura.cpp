#include "figura.hpp"

void Figura::fijarh(float h1){
  h = h1;
  //entradas[0].objeto->fijarh(h1);
}

Figura::Figura(float h1){
  fijarh(h1);
  agregar(new Base());
  //agregar(new Brazo1(5));
  agregar(new Brazo2(5));
  agregar(MAT_Traslacion(0.0,15.5,0.0));
  agregar(new Tetraedro());
}

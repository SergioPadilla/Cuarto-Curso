#include "figura.hpp"

void Figura::fijarh(float h1){
  h = h1;
  //entradas[0].objeto->fijarh(h1);
}

Figura::Figura(float h1){
  fijarh(h1);
  agregar(new Base());

  //agregar(MAT_Traslacion(0.0,5.5,0.0));
  //glutSolidSphere(1.0,50,50);
  agregar(new Brazo2(5));
  agregar(new Brazo1(5));
  agregar(MAT_Traslacion(0.0,15.5,0.0));
  agregar(new Tetraedro());
}

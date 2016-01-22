#include "figura.hpp"

void Figura::fijarh(float h1){
  h = h1;
  ((Brazo1*)(entradas[4].objeto))->fijarh(h);
  ((Estructura*)(entradas[6].objeto))->fijarh(h);
  ((Brazo2*)(entradas[8].objeto))->fijarh(h);
}

void Figura::fijarAlpha(float alpha1){
  alpha = alpha1;
  *(entradas[2].matriz) = MAT_Rotacion(alpha1,0,1,0);
}

void Figura::fijart(float t1){
  t=t1;
  ((Brazo2*)(entradas[8].objeto))->fijart(t1);
}

Figura::Figura(float alpha1, float h1, float t){
  agregar(new MaterialPeonMadera());
  agregar(new Base());
  agregar(MAT_Rotacion(alpha1,0,1,0));
  agregar(new MaterialPeonNegro());
  agregar(new Brazo1(h1));
  agregar(new MaterialPeonBlanco());
  agregar(new Estructura(h1));
  agregar(new MaterialPeonMadera());
  agregar(new Brazo2(h1,t));
}

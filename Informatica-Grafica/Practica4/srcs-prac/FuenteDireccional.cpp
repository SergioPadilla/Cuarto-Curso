#include "FuenteDireccional.hpp"

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial){
  longitud = alpha_inicial;
  latitud = beta_inicial;
  posvec = Tupla4f(0,0,0,0);
  colores[0] = Tupla4f(0.9,0.9,0.9,1);
  colores[1] = Tupla4f(0.9,0.9,0.9,1);
  colores[2] = Tupla4f(0.9,0.9,0.9,1);
}

void FuenteDireccional::variarAngulo(unsigned angulo, float incremento){
  if(angulo == 0)
    longitud = (longitud+incremento);
  else
    latitud = (latitud+incremento);
}

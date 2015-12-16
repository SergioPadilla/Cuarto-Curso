#include "FuenteDireccional.hpp"

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial){
  longitud = alpha_inicial;
  latitud = beta_inicial;
}

void FuenteDireccional::variarAngulo(unsigned angulo, float incremento){
  if(angulo == 0)
    longitud = (longitud+incremento)%360;
  else
    latitud = (latitud+incremento)%360;
}

#include "FuenteDireccional.hpp"

FuenteDireccional::FuenteDireccional(float alpha_inicial, float beta_inicial){
  alpha = alpha_inicial;
  beta = beta_inicial;
}

void FuenteDireccional::variarAngulo(unsigned angulo, float incremento){
  if(angulo == 0)
    alpha = (alpha+incremento)%360;
  else
    beta = (beta+incremento)%360;
}

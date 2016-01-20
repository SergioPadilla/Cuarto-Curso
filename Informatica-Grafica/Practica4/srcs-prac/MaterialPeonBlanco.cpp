#include "MaterialPeonBlanco.hpp"

MaterialPeonBlanco::MaterialPeonBlanco(){
  textura = NULL;
  color[0] = Tupla4f(0.5,0.5,0.5,1);
  color[1] = Tupla4f(0.05,0.05,0.05,1);
  color[2] = Tupla4f(0.7,0.7,0.7,1);
  color[3] = Tupla4f(1,1,1,1);
  exponente = 6;
}

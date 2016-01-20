#include "MaterialPeonNegro.hpp"

MaterialPeonNegro::MaterialPeonNegro(){
  textura = NULL;
  color[0] = Tupla4f(0,0,0,1);
  color[1] = Tupla4f(0,0,0,1);
  color[2] = Tupla4f(0.01,0.01,0.01,1);
  color[3] = Tupla4f(0.7,0.7,0.7,1);
  exponente = 5;
}

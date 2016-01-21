#include "MaterialTapasLata.hpp"

MaterialTapasLata::MaterialTapasLata(){
  textura = NULL;
  color[0] = Tupla4f(0.3,0.3,0.3,1);
  color[1] = Tupla4f(0.03,0.03,0.03,1);
  color[2] = Tupla4f(0.3,0.3,0.3,1);
  color[3] = Tupla4f(1,1,1,1);
  exponente = 6;
}

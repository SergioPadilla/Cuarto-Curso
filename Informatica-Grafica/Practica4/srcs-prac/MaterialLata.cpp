#include "MaterialLata.hpp"

MaterialLata::MaterialLata(){
  text = new Textura("../imgs/lata-coke.jpg");
  color[0] = Tupla4f(1,1,1,1);
  color[1] = Tupla4f(1,1,1,1);
  color[2] = Tupla4f(1,1,1,1);
  color[3] = Tupla4f(1,1,1,1);
  exponente = 0.5;
}

#include "MaterialLata.hpp"

MaterialLata::MaterialLata(){
  textura = new Textura("../imgs/lata-coke.jpg",0);
  color[0]=Tupla4f(0.2,0.2,0.2,1.0);
  color[1]=Tupla4f(0.02,0.02,0.02,1.0);
  color[2]=Tupla4f(0.4,0.4,0.4,1.0);
  color[3]=Tupla4f(1.0,1.0,1.0,1.0);
  exponente=5;
}

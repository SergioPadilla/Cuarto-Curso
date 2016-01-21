#include "FuentePosicional.hpp"

FuentePosicional::FuentePosicional(const Tupla3f & posicion){
  posvec = Tupla4f(posicion[0],posicion[1],posicion[2],1);
  colores[0] = Tupla4f(0.9,0,0,1);
  colores[1] = Tupla4f(0.2,0,0,1);
  colores[2] = Tupla4f(0.2,0,0,1);
}

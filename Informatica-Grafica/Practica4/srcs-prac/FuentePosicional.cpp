#include "FuentePosicional.hpp"

FuentePosicional::FuentePosicional(const Tupla3f & posicion){
  posvec = (posicion(0),posicion(1),posicion(2),1);
}

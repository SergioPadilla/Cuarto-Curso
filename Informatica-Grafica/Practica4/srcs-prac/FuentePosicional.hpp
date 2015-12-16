#ifndef FUENTEPOSICIONAL_HPP
#define FUENTEPOSICIONAL_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"

class FuentePosicional : public FuenteLuz{
private:
  Tupla3f pos;
public:
  FuentePosicional(const Tupla3f & posicion);
};

#endif

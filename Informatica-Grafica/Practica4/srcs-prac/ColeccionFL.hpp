#ifndef COLECCIONFL_HPP
#define COLECCIONFL_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "FuenteLuz.hpp"

class ColeccionFL{
public:
  std::vector<FuenteLuz *> fuentes; // vector de fuentes de luz
  void activar(); // activa todas las fuentes de luz
};

#endif

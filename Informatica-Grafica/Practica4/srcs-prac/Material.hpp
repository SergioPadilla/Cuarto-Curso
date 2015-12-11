#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"

class Material{
public:
  virtual void activar() = 0;
};

#endif

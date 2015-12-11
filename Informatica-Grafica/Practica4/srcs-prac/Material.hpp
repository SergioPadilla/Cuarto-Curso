#ifndef MALLAIND_HPP
#define MALLAIND_HPP

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

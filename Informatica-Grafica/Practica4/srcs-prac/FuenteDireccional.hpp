#ifndef FUENTEDIRECCIONAL_HPP
#define FUENTEDIRECCIONAL_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "FuenteLuz.hpp"

class FuenteDireccional : public FuenteLuz{
public:
  FuenteDireccional(float alpha_inicial, float beta_inicial);
  void variarAngulo(unsigned angulo, float incremento);  // angulo=0 --> variar alpha, angulo=1 --> variar beta
};

#endif

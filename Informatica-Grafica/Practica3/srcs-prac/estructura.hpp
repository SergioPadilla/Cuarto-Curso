#ifndef ESTRUCTURA_HPP
#define ESTRUCTURA_HPP

#include "NodoGrafoEscena.hpp"
#include "Cilindro.hpp"
#include "base.hpp"

class Estructura : public NodoGrafoEscena{
protected:
  float h, alpha;

public:
  Estructura(float h1);
  void fijarh(float h1);
};

#endif

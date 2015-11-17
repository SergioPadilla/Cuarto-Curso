#ifndef BRAZO2_HPP
#define BRAZO2_HPP

#include "NodoGrafoEscena.hpp"
#include "Cilindro.hpp"

class Brazo2 : public NodoGrafoEscena{
protected:
  float h;

public:
  Brazo2(float h1);
  void fijarh(float h1);
};

#endif

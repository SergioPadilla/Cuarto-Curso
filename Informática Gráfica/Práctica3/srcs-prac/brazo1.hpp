#ifndef BRAZO1_HPP
#define BRAZO1_HPP

#include "NodoGrafoEscena.hpp"
#include "Cilindro.hpp"

class Brazo1 : public NodoGrafoEscena{
protected:
  float h;

public:
  Brazo1(float h1);
  void fijarh(float h1);
};

#endif

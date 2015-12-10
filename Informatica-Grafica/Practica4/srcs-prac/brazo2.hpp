#ifndef BRAZO2_HPP
#define BRAZO2_HPP

#include "NodoGrafoEscena.hpp"
#include "Cilindro.hpp"
#include "base.hpp"

class Brazo2 : public NodoGrafoEscena{
protected:
  float h;
  float t;

public:
  Brazo2(float h1, float t1);
  void fijarh(float h1);
  void fijart(float t1);
};

#endif

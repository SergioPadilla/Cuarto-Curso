#ifndef BRAZO1_HPP
#define BRAZO1_HPP

#include "NodoGrafoEscena.hpp"
#include "Cilindro.hpp"
#include "base.hpp"
#include "estructura.hpp"

class Brazo1 : public NodoGrafoEscena{
protected:
  float h, alpha;

public:
  Brazo1(float h1);
  void fijarh(float h1);
};

#endif

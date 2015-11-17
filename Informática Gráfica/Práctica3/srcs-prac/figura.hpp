#ifndef FIGURA_HPP
#define FIGURA_HPP

#include "NodoGrafoEscena.hpp"
#include "Tetraedro.hpp"
#include "base.hpp"
#include "brazo2.hpp"
#include "brazo1.hpp"

class Figura : public NodoGrafoEscena{
protected:
  float h;

public:
  Figura(float h1);
  void fijarh(float h1);
};

#endif

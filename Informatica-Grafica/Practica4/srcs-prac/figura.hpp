#ifndef FIGURA_HPP
#define FIGURA_HPP

#include "NodoGrafoEscena.hpp"
#include "Tetraedro.hpp"
#include "base.hpp"
#include "brazo2.hpp"
#include "brazo1.hpp"

class Figura : public NodoGrafoEscena{
protected:
  float h, alpha, t;

public:
  Figura(float h1, float alpha1, float t1);
  void fijarh(float h1);
  void fijarAlpha(float alpha1);
  void fijart(float t1);
};

#endif

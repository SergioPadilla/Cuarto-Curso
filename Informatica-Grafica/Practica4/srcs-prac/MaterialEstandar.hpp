#ifndef MATERIAL_ESTANDAR_HPP
#define MATERIAL_ESTANDAR_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "Material.hpp"
#include "Textura.hpp"

class MaterialEstandar : public Material{
public:
  Textura * textura;        // puntero a la textura (NULL si no hay)
  Tupla4f color[4];    // colores: 0=emisión, 1=ambiental, 2=difuso, 3=especular
  float exponente;   // exponente para la componente pseudo-especular

  virtual void activar();
};

#endif

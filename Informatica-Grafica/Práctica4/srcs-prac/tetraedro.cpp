#include <vector>
#include "tetraedro.hpp"

Tetraedro::Tetraedro(){
  nombre_obj = "Tetraedro";
  Tupla3f a(0.866,0,-0.5), b(0,1.4142,0), c(0,0,1), d(-0.866,0,-0.5);
  vertices.push_back(a);
  vertices.push_back(b);
  vertices.push_back(c);
  vertices.push_back(d);
  Tupla3i i1(0,1,2), i2(0,1,3), i3(0,2,3), i4(1,2,3);
  caras.push_back(i1);
  caras.push_back(i2);
  caras.push_back(i3);
  caras.push_back(i4);
}

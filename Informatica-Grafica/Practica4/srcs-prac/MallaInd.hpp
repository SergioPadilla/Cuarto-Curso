#ifndef MALLAIND_HPP
#define MALLAIND_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "Objeto3D.hpp"

class MallaInd : public Objeto3D{
protected:
  //vectores de vertices y caras
  vector<Tupla3f> vertices;
  vector<Tupla3i> caras;
  //Vectores para las normales
  vector<Tupla3f> normalesCaras;
  vector<Tupla3f> normalesVertices;
  //Vector para las texturas
  vector<Tupla2f> texturas;
public:
  virtual void visualizar(ContextoVis cv);
  void calcularNormales();
};

#endif

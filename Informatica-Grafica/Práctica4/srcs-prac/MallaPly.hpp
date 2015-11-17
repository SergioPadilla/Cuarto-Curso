#ifndef MALLAPLY_HPP
#define MALLAPLY_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "MallaInd.hpp"


// clase mallas indexadas obtenidas de un archivo PLY
class MallaPLY : public MallaInd{
   public:
      // constructor
      // se debe especificar el nombre completo del archivo a leer
      MallaPLY(const char * archivo);
};
#endif

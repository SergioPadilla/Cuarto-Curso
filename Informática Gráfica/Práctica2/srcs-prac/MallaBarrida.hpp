#ifndef MALLABARRIDA_HPP
#define MALLABARRIDA_HPP

#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "MallaInd.hpp"

class MallaBarrida : public MallaInd
{
   public:
     /*
       Constructor:
         Se debe indicar el vector director y el número de contornos que dibujaremos
     */
      MallaBarrida(int x, int y, int z, unsigned n, const char * archivo);
};
#endif

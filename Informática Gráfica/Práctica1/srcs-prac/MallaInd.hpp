#include <vector>
#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include "tuplasg.hpp"
#include "aux.hpp"
#include "Objeto3D.hpp"

class MallaInd : public Objeto3D
{
   protected:
      // declarar aquí tablas de vértices y caras
      vector<Tupla3f> vertices;
      vector<Tupla3i> caras;
   public:
     virtual void visualizar( unsigned modo_vis ) ;
} ;

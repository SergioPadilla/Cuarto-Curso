#include <Objeto3D.hpp>
#include <vector>

class MallaInd : public Objeto3D
{
   protected:
      // declarar aquí tablas de vértices y caras
      std::vector<Tupla3f> tablavertices;
      std::vector<Tupla3i> tablacaras;
   public:
     virtual void visualizar( unsigned modo_vis ) ;
} ;

#include "Lata.hpp"

Lata::Lata(){
  agregar(new MallaRevol("../plys/lata-pinf.ply",10,false));
  agregar(MAT_Traslacion(0,0,0));
  agregar(new MallaRevol("../plys/lata-pcue.ply",10,false));
}

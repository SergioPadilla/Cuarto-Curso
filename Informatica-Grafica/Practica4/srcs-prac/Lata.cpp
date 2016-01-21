#include "Lata.hpp"

Lata::Lata(){
  agregar(MAT_Escalado(5,5,5));
  agregar(new MaterialLata());
  agregar(new MallaRevol("../plys/lata-pcue.ply",10,true));
  agregar(new MaterialTapasLata());
  agregar(new MallaRevol("../plys/lata-pinf.ply",10,false));
  agregar(MAT_Traslacion(0,0.03,0));
  agregar(new MallaRevol("../plys/lata-psup.ply",10,false));
}

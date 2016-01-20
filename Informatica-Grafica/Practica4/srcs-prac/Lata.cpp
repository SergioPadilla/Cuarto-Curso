#include "Lata.hpp"

Lata::Lata(){
  agregar(new MaterialTapasLata());
  agregar(new MallaRevol("../plys/lata-pinf.ply",10,true));
  //agregar(MAT_Traslacion(0,0,0));
  //agregar(new MallaRevol("../plys/lata-psup.ply",10,true));
  //agregar(new MaterialLata());
  //agregar(MAT_Traslacion(0,0,0));
  //agregar(new MallaRevol("../plys/lata-pcue.ply",10,true));
}

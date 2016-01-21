#include "Escena.hpp"

Escena::Escena(){
  //agregar(new Lata());
  //agregar(new MaterialTapasLata());
  //agregar(new MallaRevol("../plys/lata-pinf.ply",10,false));
  //agregar(new MaterialPeonMadera());
  agregar(MAT_Traslacion(2,0,0));
  agregar(new MaterialPeonBlanco());
  agregar(new MallaRevol("../plys/peon.ply",10,false));
  agregar(MAT_Traslacion(2,0,0));
  agregar(new MaterialPeonMadera());
  agregar(new MallaRevol("../plys/peon.ply",10,true));
  agregar(MAT_Traslacion(2,0,0));
  agregar(new MaterialPeonNegro());
  agregar(new MallaRevol("../plys/peon.ply",10,false));
  agregar(MAT_Escalado(5,5,5));
  agregar(new MaterialLata());
  agregar(new MallaRevol("../plys/lata-pcue.ply",10,true));
}

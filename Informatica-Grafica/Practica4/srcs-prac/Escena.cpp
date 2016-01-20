#include "Escena.hpp"

Escena::Escena(){
  //agregar(new Lata());
  //agregar(MAT_Traslacion(0,0,0));
  //agregar(new MaterialPeonBlanco());
  //agregar(new MallaRevol("../plys/peon.ply",10,false));
  //agregar(MAT_Traslacion(0,0,0));
  agregar(new MaterialPeonMadera());
  agregar(new MallaRevol("../plys/peon.ply",10,true));
  agregar(MAT_Traslacion(6,0,0));
  agregar(new MaterialPeonNegro());
  agregar(new MallaRevol("../plys/peon.ply",10,false));
}

#include "Escena.hpp"

Escena::Escena(){
  agregar(new Lata());
  agregar(MAT_Traslacion(2,1.5,3));
  agregar(new MaterialPeonBlanco());
  agregar(new MallaRevol("../plys/peon.ply",50,false));
  agregar(MAT_Traslacion(2,0,0));
  agregar(new MaterialPeonMadera());
  agregar(new MallaRevol("../plys/peon.ply",50,true));
  agregar(MAT_Traslacion(2,0,0));
  agregar(new MaterialPeonNegro());
  agregar(new MallaRevol("../plys/peon.ply",50,false));
}

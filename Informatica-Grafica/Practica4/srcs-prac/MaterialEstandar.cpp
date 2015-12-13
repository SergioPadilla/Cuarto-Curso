#include "MaterialEstandar.hpp"

void MaterialEstandar::activar(){
  glMaterialf(GL_FRONT_AND_BACK, color[0]); // Me
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]); //MA
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]); //MD
  glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, color[3]); //MS
  glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, exponente) ;
}

#include "MaterialEstandar.hpp"

void MaterialEstandar::activar(){
  glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color[0]); // Me duda si f o fv
  glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color[1]); //MA
  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color[2]); //MD
  glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, color[3]); //MS
  glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, exponente) ;
  glDisable(GL_COLOR_MATERIAL);

  if(textura == NULL){
    glDisable(GL_TEXTURE_2D);
  }
  else{
    textura->activar();
  }
}

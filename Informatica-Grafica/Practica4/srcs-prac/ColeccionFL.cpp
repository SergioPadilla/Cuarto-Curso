#include "ColeccionFL.hpp"

void ColeccionFL::activar(){
  glEnable(GL_LIGHTING);
  glEnable(GL_NORMALIZE);
  glDisable(GL_COLOR_MATERIAL);
  glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
  glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

  for(int i = 0; i < fuentes.size(); i++)
    fuentes[i]->activar(i);

  for(int i = fuentes.size(); i < 8; i++)
    glDisable(GL_LIGHT0+i);
}

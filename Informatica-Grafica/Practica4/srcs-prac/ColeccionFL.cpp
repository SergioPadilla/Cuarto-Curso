#include "ColeccionFL.hpp"
void ColeccionFL::activar(){
  for(int i = 0; i < fuentes.size(); i++)
    fuentes[i]->activar();

  for(int i = fuentes.size(), i < 8; i++)
    glDisable(GL_LIGHTi);
}

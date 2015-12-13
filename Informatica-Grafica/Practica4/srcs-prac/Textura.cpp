#include "Textura.hpp"

Textura::Textura(const std::string & archivoJPG){
  glGenTextures(1, &id_text);
  

  // crea un textura a partir de un archivo
}

void Textura::activar(){
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, id_text); //activa textura id_text
  glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);

  if(mgct != 0){
    glEnable(GL_TEXTURE_GEN_S); //Para generar las cc.tt. en cada pixel
    glEnable(GL_TEXTURE_GEN_T); //Para generar las cc.tt. en cada pixel
    if(mgct == 1){
      glTexGenfv(GL_S, GL_OBJECT_PLANE, cs);
      glTexGenfv(GL_T, GL_OBJECT_PLANE, ct);
    }else{
      glTexGenfv(GL_S, GL_EYE_PLANE, cs);
      glTexGenfv(GL_T, GL_EYE_PLANE, ct);
    }
  }
  // activa textura en el cauce fijo de OpenGL
}

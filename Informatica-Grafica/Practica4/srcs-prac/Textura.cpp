#include "Textura.hpp"

Textura::Textura(const std::string & archivoJPG, unsigned n){
  img = new jpg::Imagen(archivoJPG);
  if(n>2)
    mgct = 0;
  else
    mgct = n;
  cs[0]=1;
  cs[1]=0;
  cs[2]=0;
  cs[3]=0;
  ct[0]=0;
  ct[1]=1;
  ct[2]=0;
  ct[3]=0;
}

void Textura::activar(){
  glEnable(GL_TEXTURE_2D);

  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->tamX(),img->tamY(),0,GL_RGB,GL_UNSIGNED_BYTE,img->leerPixels());
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

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
  else{
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
  }
  // activa textura en el cauce fijo de OpenGL
}

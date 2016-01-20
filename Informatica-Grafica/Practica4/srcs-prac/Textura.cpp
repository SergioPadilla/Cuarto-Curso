#include "Textura.hpp"

Textura::Textura(const std::string & archivoJPG){
  img = new jpg::Imagen(archivoJPG);
  // crea un textura a partir de un archivo
}

void Textura::activar(){
  glEnable(GL_TEXTURE_2D);
  glEnable( GL_LIGHTING );
  glEnable( GL_NORMALIZE );
  glDisable( GL_COLOR_MATERIAL );
  glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
  glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR ) ;
  glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );
  //gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, img->tamX(), img->tamY(), GL_RGB, GL_UNSIGNED_BYTE, img->leerPixels());


  glTexImage2D(GL_TEXTURE_2D,0,3,img->tamX(),img->tamY(),0,GL_RGB,GL_UNSIGNED_BYTE,img->leerPixels());
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

  /*if(mgct != 0){
    glEnable(GL_TEXTURE_GEN_S); //Para generar las cc.tt. en cada pixel
    glEnable(GL_TEXTURE_GEN_T); //Para generar las cc.tt. en cada pixel
    if(mgct == 1){
      glTexGenfv(GL_S, GL_OBJECT_PLANE, cs);
      glTexGenfv(GL_T, GL_OBJECT_PLANE, ct);
    }else{
      glTexGenfv(GL_S, GL_EYE_PLANE, cs);
      glTexGenfv(GL_T, GL_EYE_PLANE, ct);
    }
  }*/
  // activa textura en el cauce fijo de OpenGL
}

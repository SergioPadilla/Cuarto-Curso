#include "FuenteLuz.hpp"

void FuenteLuz::activar(int i){
  glEnable(GL_LIGHT0+i);

  glLightfv(GL_LIGHT0+i, GL_AMBIENT, colores[0]); //SiA
  glLightfv(GL_LIGHT0+i, GL_DIFFUSE, colores[1]); //SiD
  glLightfv(GL_LIGHT0+i, GL_SPECULAR, colores[2]); //SiS

  if(posvec[3] == 1){
    glLightfv(GL_LIGHT0+i, GL_POSITION, posvec);
  }
  else{
    glMatrixMode( GL_MODELVIEW ) ;
    glPushMatrix() ;
      glLoadIdentity();
      glRotatef(longitud, 0.0, 1.0, 0.0);
      glRotatef(latitud, -1.0, 0.0, 0.0);
      Tupla4f ejeZ(0,0,1,0);
      glLightfv(GL_LIGHT0+i, GL_POSITION, ejeZ);
    glPopMatrix();
  }
}

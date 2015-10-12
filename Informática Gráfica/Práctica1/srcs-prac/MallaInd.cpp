#include "MallaInd.hpp"

virtual void visualizar( unsigned modo_vis ){
  switch (modo_vis) {
    case 0: //puntos
      /*glPolygonMode(GL_FRONT_AND_BACK,GL_POINT)
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3,GL_FLOAT,0,vertices);
      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,caras);
      glDisableCleintState(GL_VERTEX_ARRAY)*/
      break
    case 1: //lineas
      /*glPolygonMode(GL_FRONT_AND_BACK,GL_LINE)
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3,GL_FLOAT,0,vertices);
      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,caras);
      glDisableCleintState(GL_VERTEX_ARRAY)*/
      break
    case 2: //Relleno
      /*glPolygonMode(GL_FRONT_AND_BACK,GL_FILL)
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3,GL_FLOAT,0,vertices);
      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,caras);
      glDisableCleintState(GL_VERTEX_ARRAY)*/
      break
    case 3: //ajedrez
      /*glPolygonMode(GL_FRONT_AND_BACK,GL_FILL)
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3,GL_FLOAT,0,vertices);
      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,caras);
      glDisableCleintState(GL_VERTEX_ARRAY)*/
      break
  }
}

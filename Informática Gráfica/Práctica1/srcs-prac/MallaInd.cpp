#include "MallaInd.hpp"

void MallaInd::visualizar( unsigned modo_vis ){
  switch (modo_vis) {
    case 0: //puntos
      glEnableClientState(GL_VERTEX_ARRAY);
      glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
      glVertexPointer(3,GL_FLOAT,0,&(vertices.front()));
      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&(caras.front()));
      glDisableClientState(GL_VERTEX_ARRAY);
      break;
    case 1: //lineas
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3,GL_FLOAT,0,&(vertices.front()));
      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&(caras.front()));
      glDisableClientState(GL_VERTEX_ARRAY);
      break;
    case 2: //Relleno
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3,GL_FLOAT,0,&(vertices.front()));
      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&(caras.front()));
      glDisableClientState(GL_VERTEX_ARRAY);
      break;
    case 3: //ajedrez
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3,GL_FLOAT,0,&(vertices.front()));
      vector<Tupla3i> par,impar;
      for(int i=0; i < caras.size(); i++){
        if(i%2==0)
          par.push_back(caras.at(i));
        else
          impar.push_back(caras.at(i));
      }
      glColor3f(0,0,1);
      glDrawElements(GL_TRIANGLES,par.size()*3,GL_UNSIGNED_INT,&(par.front()));
      glColor3f(1,0,0);
      glDrawElements(GL_TRIANGLES,impar.size()*3,GL_UNSIGNED_INT,&(impar.front()));
      glDisableClientState(GL_VERTEX_ARRAY);
      break;
  }
}

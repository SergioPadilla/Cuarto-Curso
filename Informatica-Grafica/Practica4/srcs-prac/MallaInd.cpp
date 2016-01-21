#include "MallaInd.hpp"

void MallaInd::visualizar(ContextoVis cv){
  switch (cv.modo_vis) {
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
    {
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
    case 4: //iluminación y sombreado plano
      glEnable(GL_LIGHTING);
      glShadeModel(GL_FLAT);

      glVertexPointer(3,GL_FLOAT,0,&(vertices.front()));
      glEnableClientState(GL_VERTEX_ARRAY);

      if(!normalesVertices.empty()){
        glNormalPointer(GL_FLOAT,0,&(normalesVertices.front()));
        glEnableClientState(GL_NORMAL_ARRAY);
      }

      if(!texturas.empty()){
        glTexCoordPointer(2,GL_FLOAT,0,&(texturas.front()));
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
      }

      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&(caras.front()));

      glDisableClientState(GL_VERTEX_ARRAY);

      if(!texturas.empty())
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
      if(!normalesVertices.empty())
        glDisableClientState(GL_NORMAL_ARRAY);
      glDisable(GL_LIGHTING);
      break;
    case 5: //iluminación y sombreado de suave
      glEnable(GL_LIGHTING);
      glShadeModel(GL_SMOOTH);

      glVertexPointer(3,GL_FLOAT,0,&(vertices.front()));
      glEnableClientState(GL_VERTEX_ARRAY);

      if(!normalesVertices.empty()){
        glNormalPointer(GL_FLOAT,0,&(normalesVertices.front()));
        glEnableClientState(GL_NORMAL_ARRAY);
      }
      if(!texturas.empty()){
        glTexCoordPointer(2,GL_FLOAT,0,&(texturas.front()));
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
      }

      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&(caras.front()));

      glDisableClientState(GL_VERTEX_ARRAY);

      if(!texturas.empty())
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
      if(!normalesVertices.empty())
        glDisableClientState(GL_NORMAL_ARRAY);

      glDisable(GL_LIGHTING);
      break;
  }
}

void MallaInd::calcularNormales(){
  //Normales a las caras
  for(int i = 0; i < caras.size(); i ++){
    Tupla3f p = vertices.at(caras[i](0));
    Tupla3f q = vertices.at(caras[i](1));
    Tupla3f r = vertices.at(caras[i](2));

    Tupla3f a = q-p;
    Tupla3f b = r-q;

    Tupla3f m(a(1)*b(2)-a(2)*b(1),
              a(2)*b(0)-a(0)*b(2),
              a(0)*b(1)-a(1)*b(0));

    if(m[0] == 0 && m[1] == 0 && m[2] == 0)
      normalesCaras.push_back(Tupla3f(0,0,0));
    else
      normalesCaras.push_back(m.normalized());
  }

  //Normales a los vertices
  vector<Tupla3f> m;
  for(int i = 0; i < vertices.size(); i ++)
    m.push_back(Tupla3f(0,0,0));

  for(int i = 0; i < normalesCaras.size(); i ++){
    m[caras[i][0]] = m[caras[i][0]] + normalesCaras[i];
    m[caras[i][1]] = m[caras[i][1]] + normalesCaras[i];
    m[caras[i][2]] = m[caras[i][2]] + normalesCaras[i];
  }

  for(int i = 0; i < m.size(); i ++){
    if(m[i][0] == 0 && m[i][1] == 0 && m[i][2] == 0)
      normalesVertices.push_back(Tupla3f(0,0,0));
    else
      normalesVertices.push_back(m[i].normalized());
  }
}

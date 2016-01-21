#include "file_ply_stl.hpp"
#include "MallaRevol.hpp"

MallaRevol::MallaRevol(const char * archivo, unsigned nperfiles, bool textura){
  vector <float> vertices_ply;

  ply::read_vertices(archivo, vertices_ply);

  int puntosPerfil = vertices_ply.size()/3;

  for (int j = 0;j < nperfiles; j++){
    for (int i = 0;i < vertices_ply.size();i = i+3){
      vertices.push_back(Tupla3f(vertices_ply[i]*cos(2*M_PI*j/nperfiles), vertices_ply[i+1], vertices_ply[i]*sin(2*M_PI*j/nperfiles)));
    }
  }

  vertices.push_back(Tupla3f(0, vertices_ply[1], 0));
  vertices.push_back(Tupla3f(0, vertices_ply[vertices_ply.size()-2], 0));

  for(int i = 0;i < nperfiles-1; i++){
    caras.push_back(Tupla3i(i*puntosPerfil, puntosPerfil*nperfiles, (i+1)*puntosPerfil));
  }

  for(int j = 0; j < nperfiles-1; j++){
    for(int i = 0; i < puntosPerfil-1; i++){
      caras.push_back(Tupla3i(i+puntosPerfil*j,i+1+puntosPerfil*j,i+puntosPerfil*(j+1)));
      caras.push_back(Tupla3i(i+puntosPerfil*(j+1),i+1+puntosPerfil*(j+1),i+1+puntosPerfil*j));
    }
  }

  for(int i = 0;i < puntosPerfil-1; i++){
    caras.push_back(Tupla3i(i+puntosPerfil*(nperfiles-1),i+1+puntosPerfil*(nperfiles-1),i));
    caras.push_back(Tupla3i(i,i+1,i+1+puntosPerfil*(nperfiles-1)));
  }

  for (int i = 0;i < nperfiles-1; i++){
    caras.push_back(Tupla3i(puntosPerfil-1+i*puntosPerfil,puntosPerfil*nperfiles+1,(puntosPerfil-1)+(i+1)*puntosPerfil));
  }
  caras.push_back(Tupla3i(puntosPerfil-1+(nperfiles-1)*puntosPerfil,puntosPerfil*nperfiles+1,(puntosPerfil-1)));

  calcularNormales();

  if(textura){
    int mvertices = vertices_ply.size()/3;

    //Calculo posiciones de los vertices
    vector<Tupla3f> p;
    for(int i = 0; i < vertices_ply.size(); i+=3){
      p.push_back(Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]));
    }

    //Calculo distancias medias a lo largo del perfil
    vector<float> d;
    float di;
    d.push_back(0);
    for(int i = 1; i < mvertices; i++){
      di = d[i-1] + sqrt((p[i]-p[i-1]).lengthSq());
      d.push_back(di);
    }
    //Calculo coordenadas X e Y de la textura
    for(int i = 0; i < nperfiles; i++){
      float s=(i/(nperfiles-1.0));
      for(int j = 0; j < mvertices; j++){
        texturas.push_back(Tupla2f(s,(d[j]/d[mvertices-1])));
      }
    }
  }
}

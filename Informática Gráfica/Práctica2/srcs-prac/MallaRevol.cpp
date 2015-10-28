#include "file_ply_stl.hpp"
#include "MallaRevol.hpp"

MallaRevol::MallaRevol(const char * archivo, unsigned nperfiles ){
  vector <float> vertices_ply;

  ply::read_vertices(archivo, vertices_ply);

  for(int i = 0; i < vertices_ply.size(); i+=3){
    vertices.push_back(Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]));
    for(int j = 1; j < nperfiles; j++)
      vertices.push_back(Tupla3f(vertices_ply[i]*cos(2*M_PI*j/nperfiles),vertices_ply[i+1],vertices_ply[i]*sin(2*M_PI*j/nperfiles)));
  }
  for(int j=0; j < nperfiles; j++)
    for(int i = j; i < vertices.size()-nperfiles-1; i=nperfiles+i){
      caras.push_back(Tupla3i(i,i+1,nperfiles+i));
      caras.push_back(Tupla3i(i+1,nperfiles+i,nperfiles+i+1));
    }
  caras.push_back(Tupla3i(vertices.size()-nperfiles-1,vertices.size()-nperfiles,vertices.size()-1));
  caras.push_back(Tupla3i(0,nperfiles,nperfiles-1));

  //cara de abajo
  vertices.push_back(Tupla3f(0,vertices_ply[1],0));
  for(int i = 0; i < nperfiles; i++)
    caras.push_back(Tupla3i(vertices.size()-1,i,(i+1)%nperfiles));

  //cara de arriba
  vertices.push_back(Tupla3f(0,vertices_ply[vertices_ply.size()-2],0));
  int ver = (nperfiles)*((vertices_ply.size()/3)-1);
  for(int i = 0; i < nperfiles; i++)
    caras.push_back(Tupla3i(vertices.size()-1,ver+i,ver+((i+1)%nperfiles)));
}

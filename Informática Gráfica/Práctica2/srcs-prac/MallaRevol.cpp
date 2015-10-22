#include "file_ply_stl.hpp"
#include "MallaRevol.hpp"

MallaRevol::MallaRevol(unsigned nperfiles ){
  vector <float> vertices_ply;

  ply::read_vertices( "../plys/peon.ply", vertices_ply );

  for(int i = 0; i < vertices_ply.size(); i+=3){
    vertices.push_back(Tupla3f(vertices_ply[i],vertices_ply[i+1],vertices_ply[i+2]));
    for(int j = 1; j < nperfiles; j++)
      vertices.push_back(Tupla3f(vertices_ply[i]*cos(2*M_PI*j/nperfiles),vertices_ply[i+1],vertices_ply[i]*sin(2*M_PI*j/nperfiles)));
  }

  for(int i = 0; i < vertices.size(); i++){
    caras.push_back(Tupla3i(i,i+1,nperfiles+i));
    caras.push_back(Tupla3i(i+1,nperfiles+i,nperfiles+i+1));
  }
}

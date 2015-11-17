#include "file_ply_stl.hpp"
#include "MallaBarrida.hpp"

MallaBarrida::MallaBarrida(int x, int y, int z, unsigned n, const char * archivo){
  vector <float> vertices_ply;

  ply::read_vertices(archivo, vertices_ply);

  for(int j = 0; j <= n; j++)
    for(int i = 0; i < vertices_ply.size(); i+=3)
      vertices.push_back(Tupla3f(vertices_ply[i]+(j*x),
                                 vertices_ply[i+1]+(j*y),
                                 vertices_ply[i+2]+(j*z)));

  int ver = vertices_ply.size()/3;
  for(int j = 0; j < n; j++)
    for(int i = 0; i < ver; i++){
      caras.push_back((Tupla3i(i+(j*ver),(i+1)%ver+(j*ver),ver+i+(j*ver))));
      caras.push_back((Tupla3i(i+1+(j*ver),ver+i+(j*ver),(ver+i+1)%(2*ver)+(j*ver))));
    }
}

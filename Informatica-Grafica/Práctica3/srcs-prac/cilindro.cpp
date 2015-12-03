#include "cilindro.hpp"

Cilindro::Cilindro(int num){
  nombre_obj = "Cilindro";
  int n = num;
  // Vamos a hacer el tubo del cilindro
  for(int i=0; i < n; i++){
    vertices.push_back(Tupla3f(cos(i*2*M_PI/n),1,sin(i*2*M_PI/n)));
    vertices.push_back(Tupla3f(cos(i*2*M_PI/n),-1,sin(i*2*M_PI/n)));
  }

  for(int i=0; i < 2*n-2; i++){
    caras.push_back(Tupla3i(i,i+1,i+2));
  }
  caras.push_back(Tupla3i(2*n-1,2*n-2,0));
  caras.push_back(Tupla3i(1,2*n-1,0));

  //Ahora vamos a hacer las tapas del cilindro
  vertices.push_back(Tupla3f(0,1,0));
  vertices.push_back(Tupla3f(0,-1,0));

  for(int i=0; i < 2*n-2; i=i+2){
    caras.push_back(Tupla3i(i,i+2,2*n));
  }
  caras.push_back(Tupla3i(2*n-2,2*n,0));

  for(int i=1; i < 2*n-1; i=i+2){
    caras.push_back(Tupla3i(i,i+2,2*n+1));
  }
  caras.push_back(Tupla3i(2*n-1,2*n+1,1));
}

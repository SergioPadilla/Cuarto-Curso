#include "file_ply_stl.hpp"
#include "MallaRevol.hpp"

Tupla3f MallaRevol::girosobrey(Tupla3f punto,double angulo){
  return Tupla3f(punto[0]*cos(angulo)+punto[2]*sin(angulo),
                  punto[1],
                  punto[2]*cos(angulo)-punto[0]*sin(angulo));
}

MallaRevol::MallaRevol(const char * archivo, unsigned nperfiles, bool textura){
/*  std::vector<float> vertices_ply ; // coordenadas de vértices
ply::read_vertices( archivo, vertices_ply );
int tam = vertices_ply.size();
int n=tam/3;

for (int j=0;j<nperfiles;j++){
 for (int i=0;i<tam;i=i+3){
   vertices.push_back(Tupla3f(vertices_ply[i]*cos(2*M_PI*j/nperfiles),
   vertices_ply[i+1],vertices_ply[i]*sin(2*M_PI*j/nperfiles)));
 }
}
vertices.push_back(Tupla3f(0,vertices_ply[1],0));//primer Y(mas alto)
vertices.push_back(Tupla3f(0,vertices_ply[tam-2],0)); //Ultimo Y(mas bajo)

// Inserccion de indices de cara

for(int i=0;i<nperfiles-1;i++){
caras.push_back(Tupla3i(i*n,n*nperfiles,(i+1)*n));   // base inferior sin cerrar
}
//caras.push_back(Tupla3i(0,n*nperfiles,n*(nperfiles-1)));  //cierre base inferior

for(int j=0;j<nperfiles-1;j++){
for(int i=0;i<n-1;i++){
 caras.push_back(Tupla3i(i+n*j,i+1+n*j,i+n*(j+1)));      // caras laterales sin la ultima (cierre)
 caras.push_back(Tupla3i(i+n*(j+1),i+1+n*(j+1),i+1+n*j));
}
}

for(int i=0;i<n-1;i++){
caras.push_back(Tupla3i(i+n*(nperfiles-1),i+1+n*(nperfiles-1),i));
caras.push_back(Tupla3i(i,i+1,i+1+n*(nperfiles-1)));               //Cierre de la ultima cara lateral
}

for (int i=0;i<nperfiles-1;i++){
caras.push_back(Tupla3i(n-1+i*n,n*nperfiles+1,(n-1)+(i+1)*n)); // base superior sin cerrar
}
caras.push_back(Tupla3i(n-1+(nperfiles-1)*n,n*nperfiles+1,(n-1)));

calcularNormales();*/

  vector <float> vertices_ply;

  ply::read_vertices(archivo, vertices_ply);

//IVAN
  for(int i=0;i<vertices_ply.size()/3;i++){
		vertices.push_back(Tupla3f(vertices_ply[3*i],
                              vertices_ply[3*i+1],
                              vertices_ply[3*i+2]));
	}
	int npuntos= vertices.size();
	for(int j=1;j<nperfiles;j++){
		for(int i=0;i<npuntos;i++){
			vertices.push_back(girosobrey(vertices[i],2*M_PI*j/nperfiles));
		}
	}
	vertices.push_back(Tupla3f(0,vertices[0][1],0));
	vertices.push_back(Tupla3f(0,vertices[npuntos-1][1],0));

	for(int j=0;j<nperfiles-1;j++){
		for(int i=0;i<npuntos-1;i++){
			caras.push_back(Tupla3i(j*npuntos+i,(j+1)*npuntos+i,(j+1)*npuntos+i+1));
			caras.push_back(Tupla3i(j*npuntos+i,(j+1)*npuntos+i+1,j*npuntos+i+1));
		}
	}
	for(int i=0;i<npuntos-1;i++){
		caras.push_back(Tupla3i((nperfiles-1)*npuntos+i,i,i+1));
		caras.push_back(Tupla3i((nperfiles-1)*npuntos+i,i+1,(nperfiles-1)*npuntos+i+1));
	}
	int ult=nperfiles*npuntos;
	for(int j=0;j<nperfiles-1;j++){
		caras.push_back(Tupla3i(j*npuntos,ult,(j+1)*npuntos));
	}
	caras.push_back(Tupla3i(0,(nperfiles-1)*npuntos,ult));

	for(int j=0;j<nperfiles-1;j++){
		caras.push_back(Tupla3i(j*npuntos+npuntos-1,(j+1)*npuntos+npuntos-1,ult+1));
	}
	caras.push_back(Tupla3i(npuntos-1,ult+1,(nperfiles-1)*npuntos+npuntos-1));

	calcularNormales();

  /*for(int i = 0; i < vertices_ply.size(); i+=3){
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

  //calcularNormales();*/

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
    }

    //Calculo coordenadas X e Y de la textura
    for(int i = 0; i < nperfiles; i++){
      float s=(i/(nperfiles-1))+(i%(nperfiles-1));
      for(int j = 0; j < mvertices; j++){
        texturas.push_back(Tupla2f(s,(d[j]/d[mvertices-1])));
      }
    }
  }
}

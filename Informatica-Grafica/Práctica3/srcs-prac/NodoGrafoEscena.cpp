#include "NodoGrafoEscena.hpp"

EntradaNGE::EntradaNGE( Objeto3D * pObjeto ){
  tipoE=0;
  objeto = pObjeto;
}

EntradaNGE::EntradaNGE( const Matriz4f & pMatriz ){
  tipoE=1;
  matriz = new Matriz4f(pMatriz);
}

void NodoGrafoEscena::visualizar(unsigned cv){
  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPushMatrix(); // guarda modelview actual

  // recorrer todas las entradas del array que hay en el nodo:
  for( unsigned i = 0; i < entradas.size(); i++ )
    if( entradas[i].tipoE == 0 ) // si la entrada es sub-objeto:
      entradas[i].objeto->visualizar( cv ); // visualizarlo
    else // si la entrada es transformación:
      glMultMatrixf( *(entradas[i].matriz) ); // componerla

  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPopMatrix();
}

void NodoGrafoEscena::agregar( EntradaNGE * entrada ){
  entradas.push_back(*(entrada));
}
// construir una entrada y añadirla (al final)
void NodoGrafoEscena::agregar( Objeto3D * pObjeto ){
  EntradaNGE nuevo = EntradaNGE(pObjeto);

  entradas.push_back(nuevo);
}
void NodoGrafoEscena::agregar( const Matriz4f & pMatriz ){
  EntradaNGE nuevo = EntradaNGE(pMatriz);

  entradas.push_back(nuevo);
}

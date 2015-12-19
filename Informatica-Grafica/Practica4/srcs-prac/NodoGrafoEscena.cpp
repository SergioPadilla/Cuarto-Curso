#include "NodoGrafoEscena.hpp"

EntradaNGE::EntradaNGE( Objeto3D * pObjeto ){
  tipoE = 0;
  objeto = pObjeto;
}

EntradaNGE::EntradaNGE( const Matriz4f & pMatriz ){
  tipoE = 1;
  matriz = new Matriz4f(pMatriz);
}

EntradaNGE::EntradaNGE(Material * pMaterial){
  tipoE = 2;
  material = pMaterial;
}

void NodoGrafoEscena::visualizar(ContextoVis cv){
  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPushMatrix(); // guarda modelview actual

  Material * materialInicial = cv.materialActivo; //Guardamos copia del material activo al inicio

  // recorrer todas las entradas del array que hay en el nodo:
  for( unsigned i = 0; i < entradas.size(); i++ )
    if( entradas[i].tipoE == 0 ) // si la entrada es sub-objeto:
      entradas[i].objeto->visualizar( cv ); // visualizarlo
    else  if(entradas[i].tipoE == 1)// si la entrada es transformación:
      glMultMatrixf( *(entradas[i].matriz) ); // componerla
    else{// si la entrada es un material, activar
      if(entradas[i].material != cv.materialActivo){
        cv.materialActivo = entradas[i].material;
        entradas[i].material->activar();
      }
    }

  if(materialInicial != cv.materialActivo){  // si ha cambiado el material durante la vis. de este nodo:
    cv.materialActivo = materialInicial;    // restaurar el original en 'cv'
    if(cv.materialActivo != NULL)               // si el original no era NULL
      cv.materialActivo->activar();              //    reactivarlo
  }

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

void NodoGrafoEscena::agregar(Material * pMaterial){
  EntradaNGE nuevo = EntradaNGE(pMaterial);
  entradas.push_back(nuevo);
}

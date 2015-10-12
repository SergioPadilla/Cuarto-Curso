// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica1.hpp"

unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....
Cubo cubo();
Tetraedro tetraedro();

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....



// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{

}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla )
{
  bool usa = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
  switch (toupper(tecla))
  {
     case '0' :
        objeto_activo = 0;
        break ;
     case '1' :
        objeto_activo = 1;
        break;
     default:
        usa = false ;
  }
  return usa ;
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// modo: 0 - puntos, 1 - alambre, 2 - sólido, 3 - sólido ajedrez , >=4 otros....

void P1_DibujarObjetos( unsigned modo )
{
  if(objeto_activo==0)
    cubo.visualizar(modo);
  else if(objeto_activo==1)
    tetraedro.visualizar(modo);
    /*switch (modo) {
      case 0:
        glBegin(GL_POINTS);
          glVertex3f(0,0,0);
          glVertex3f(0,2,0);
          glVertex3f(0,0,2);
          glVertex3f(2,0,0);
        glEnd();
        break;
      case 1:
        glBegin(GL_LINE_LOOP);
          glVertex3f(0,0,0);
          glVertex3f(0,2,0);
          glVertex3f(0,0,2);
          glVertex3f(2,0,0);
        glEnd();
        break;
    }*/
}

Cubo(){
  nombre_obj = "Cubo";
  Tupla3f a(-2,-2,2), b(-2,-2,-2), c(2,-2,-2), d(2,-2,2), e(-2,2,2), f(-2,2,-2), g(2,2,-2), h(2,2,2);
  vertices.push_back(a);
  vertices.push_back(b);
  vertices.push_back(c);
  vertices.push_back(d);
  vertices.push_back(e);
  vertices.push_back(f);
  vertices.push_back(g);
  vertices.push_back(h);
  Tupla3i i1(1,8,5), i2(1,4,8), i3(4,7,8), i4(4,3,7), i5(3,6,7), i6(3,2,6), i7(2,5,6), i8(2,1,5), i9(5,3,6), i10(3,7,6),
            i11(1,3,2),i12(1,4,3);
  caras.push_back(i1);
  caras.push_back(i2);
  caras.push_back(i3);
  caras.push_back(i4);
  caras.push_back(i5);
  caras.push_back(i6);
  caras.push_back(i7);
  caras.push_back(i8);
  caras.push_back(i9);
  caras.push_back(i10);
  caras.push_back(i11);
  caras.push_back(i12);
}

Tetraedro(){
  nombre_obj = "Tetraedro";

}

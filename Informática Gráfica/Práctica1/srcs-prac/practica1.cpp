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
Cubo *cubo;
Tetraedro *tetraedro;

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....



// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
  tetraedro = new Tetraedro();
  cubo = new Cubo();
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
     case 'A' :
        objeto_activo = 0;
        break ;
     case 'C' :
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
    cubo->visualizar(modo);
  else if(objeto_activo==1)
    tetraedro->visualizar(modo);
}

Cubo::Cubo(){
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
  Tupla3i i1(0,7,4), i2(0,3,7), i3(3,6,7), i4(3,2,6), i5(2,5,6), i6(2,1,5), i7(1,4,5), i8(1,0,4), i9(4,6,7), i10(4,6,5),
            i11(0,2,1),i12(0,3,2);
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

Tetraedro::Tetraedro(){
  nombre_obj = "Tetraedro";
  Tupla3f a(0.866,0,-0.5), b(0,1.4142,0), c(0,0,1), d(-0.866,0,-0.5);
  vertices.push_back(a);
  vertices.push_back(b);
  vertices.push_back(c);
  vertices.push_back(d);
  Tupla3i i1(0,1,2), i2(0,1,3), i3(0,2,3), i4(1,2,3);
  caras.push_back(i1);
  caras.push_back(i2);
  caras.push_back(i3);
  caras.push_back(i4);
}

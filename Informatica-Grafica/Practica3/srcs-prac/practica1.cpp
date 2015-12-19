// *********************************************************************
// **
// ** Informática Gráfica, curso 2015-16
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica1.hpp"
#include "cilindro.hpp"
#include "tetraedro.hpp"

unsigned objeto_activo = 0; // objeto activo: cubo (0), tetraedro (1), otros....
int hueco = 0; //Variable para dejar hueco el cilindro y el cono, 0(cerrado)

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....

Cubo *cubo;
Tetraedro *tetraedro;
Cono *cono;
Cilindro *cilindro;

// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
  tetraedro = new Tetraedro();
  cubo = new Cubo();
  cono = new Cono(50);
  cilindro = new Cilindro(50);
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
     case 'O' :
        objeto_activo = (objeto_activo+1)%4;
        break ;
    case '1':
        delete cono;
        delete cilindro;
        cono = new Cono(10);
        cilindro = new Cilindro(10);
        break;
    case '2':
        delete cono;
        delete cilindro;
        cono = new Cono(20);
        cilindro = new Cilindro(20);
        break;
    case '3':
        delete cono;
        delete cilindro;
        cono = new Cono(30);
        cilindro = new Cilindro(30);
        break;
    case '4':
        delete cono;
        delete cilindro;
        cono = new Cono(40);
        cilindro = new Cilindro(40);
        break;
    case '5':
        delete cono;
        delete cilindro;
        cono = new Cono(50);
        cilindro = new Cilindro(50);
        break;
    case '6':
        delete cono;
        delete cilindro;
        cono = new Cono(60);
        cilindro = new Cilindro(60);
        break;
    case '7':
        delete cono;
        delete cilindro;
        cono = new Cono(70);
        cilindro = new Cilindro(70);
        break;
    case '8':
        delete cono;
        delete cilindro;
        cono = new Cono(80);
        cilindro = new Cilindro(80);
        break;
    case '9':
        delete cono;
        delete cilindro;
        cono = new Cono(90);
        cilindro = new Cilindro(90);
        break;
    case '0':
        delete cono;
        delete cilindro;
        cono = new Cono(100);
        cilindro = new Cilindro(100);
        break;
    case 'H':
        hueco = (hueco+1)%2;
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
  else if(objeto_activo==2)
    cono->visualizar(modo);
  else if(objeto_activo==3)
    cilindro->visualizar(modo);
}

Cubo::Cubo(){
  nombre_obj = "Cubo";
  Tupla3f a(-1,-1,1), b(-1,-1,-1), c(1,-1,-1), d(1,-1,1), e(-1,1,1), f(-1,1,-1), g(1,1,-1), h(1,1,1);
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

Cono::Cono(int num){
  nombre_obj = "Cono";
  int n = num;
  Tupla3f a(0,2,0);
  vertices.push_back(a);
  for(int i=0; i < n; i++)
    vertices.push_back(Tupla3f(cos(i*2*M_PI/n),0,sin(i*2*M_PI/n)));

  for(int i=1; i < n; i++)
    caras.push_back(Tupla3i(0,i,i+1));
  caras.push_back(Tupla3i(0,n,1));

  if(hueco == 0){
    //Tapa del cono
    vertices.push_back(Tupla3f(0,0,0));
    for(int i=1; i < n; i++)
      caras.push_back(Tupla3i(n+1,i,i+1));
    caras.push_back(Tupla3i(n+1,n,1));
  }
}

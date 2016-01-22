#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica2.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "MallaBarrida.hpp"
#include "practica3.hpp"
#include "base.hpp"
#include "Figura.hpp"
#include "Lata.hpp"
#include "Escena.hpp"
#include "FuenteDireccional.hpp"
#include "FuentePosicional.hpp"
#include "ColeccionFL.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int angulo_actual = 0; // 0-> alpha, 1->beta
static Escena * escena = NULL;
static ColeccionFL * colecFuentes = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void P4_Inicializar( int argc, char *argv[] ){
  escena = new Escena();
  FuenteDireccional * direc = new FuenteDireccional(0, 0);
  FuentePosicional * posi = new FuentePosicional(Tupla3f(4,2,0));
  colecFuentes = new ColeccionFL();
  colecFuentes->fuentes.push_back(posi);
  colecFuentes->fuentes.push_back(direc);
  colecFuentes->activar();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool P4_FGE_PulsarTeclaNormal( unsigned char tecla ){
  bool usa = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
  switch (toupper(tecla))
  {
    case 'G' :
       angulo_actual = (angulo_actual + 1) % 2;
       if(angulo_actual == 0)
          cerr << "Modificando ángulo alpha" << endl;
       else if(angulo_actual == 1)
          cerr << "Modificando ángulo beta" << endl;
       break;
    case '<':
      ((FuenteDireccional*)colecFuentes->fuentes.at(1))->variarAngulo(angulo_actual,-10);
      colecFuentes->activar();
      break;
    case '>':
      ((FuenteDireccional*)colecFuentes->fuentes.at(1))->variarAngulo(angulo_actual,10);
      colecFuentes->activar();
      break;
    default:
       usa = false ;
  }
  return usa ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void P4_DibujarObjetos( unsigned modo ){
  ContextoVis cv(modo);
  escena->visualizar(cv);
}

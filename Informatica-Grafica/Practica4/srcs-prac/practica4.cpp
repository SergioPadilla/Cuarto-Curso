#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica2.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "MallaBarrida.hpp"
#include "practica3.hpp"
#include "base.hpp"
#include "Figura.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int angulo_actual = 0; // 0-> alpha, 1->beta
static int alpha;
static int beta;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void P4_Inicializar( int argc, char *argv[] ){
  alpha = 0;
  beta = 0;
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
      switch (angulo_actual){
        case 0:
          if(alpha > 0)
            alpha -= 1;
          break;
        case 1:
          if(beta > 0)
            beta -= 1;
          break;
      }
      break;
    case '>':
    switch (angulo_actual){
      case 0:
        if(alpha < 360)
          alpha += 1;
        break;
      case 1:
        if(beta < 360)
          beta += 1;
        break;
    }
      break;
    default:
       usa = false ;
  }
  return usa ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void P4_DibujarObjetos( unsigned modo ){
  //objeto->visualizar(modo);
}
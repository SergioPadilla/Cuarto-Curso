#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica2.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned p2_objeto_activo = 0;

MallaPLY *ply = NULL;
MallaRevol *revol = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void P2_Inicializar( int argc, char *argv[] ){
  ply = new MallaPLY();
  revol = new MallaRevol(1);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool P2_FGE_PulsarTeclaNormal( unsigned char tecla ){
  bool usa = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
  switch (toupper(tecla))
  {
    case 'O' :
       p2_objeto_activo = (p2_objeto_activo+1)%2;
       break;
    case '1':
       delete revol;
       revol = new MallaRevol(3);
       break;
    case '2':
       delete revol;
       revol = new MallaRevol(4);
       break;
    case '3':
       delete revol;
       revol = new MallaRevol(5);
       break;
    case '4':
      delete revol;
      revol = new MallaRevol(6);
      break;
    default:
       usa = false ;
  }
  return usa ;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void P2_DibujarObjetos( unsigned modo ){
  if(p2_objeto_activo == 0)
    ply->visualizar(modo);
  else if(p2_objeto_activo == 1)
    revol->visualizar(modo);
}

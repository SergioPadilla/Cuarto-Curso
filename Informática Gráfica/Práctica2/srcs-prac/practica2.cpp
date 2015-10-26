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
  if(argc != 4){
    cerr << "Uso: " << endl << "1: archivo ply" << endl << "2: perfil ply para objeto de revolución" << endl
          << "3: número de perfiles para el objeto de revolución" << endl;
    ply = new MallaPLY("../plys/beethoven.ply");
    revol = new MallaRevol("../plys/peon.ply",10);
  }
  else{
    ply = new MallaPLY(argv[1]);
    revol = new MallaRevol(argv[2],atoi(argv[3]));
  }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool P2_FGE_PulsarTeclaNormal( unsigned char tecla ){
  bool usa = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
  switch (toupper(tecla))
  {
    case 'O' :
       p2_objeto_activo = (p2_objeto_activo+1)%2;
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

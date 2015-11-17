#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practica2.hpp"
#include "MallaPLY.hpp"
#include "MallaRevol.hpp"
#include "MallaBarrida.hpp"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned p2_objeto_activo = 0;

MallaPLY *ply = NULL;
MallaRevol *revol = NULL;
MallaBarrida *barrida = NULL;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void P2_Inicializar( int argc, char *argv[] ){
  if(argc != 9){
    cerr << "Uso: " << endl << "1: archivo ply" << endl <<
                               "2: perfil ply para objeto de revolución" << endl <<
                               "3: número de perfiles para el objeto de revolución" << endl <<
                               "4: archivo ply para vertices del objeto de barrido" << endl <<
                               "5: número de perfiles para el objeto de barrido" << endl <<
                               "6: coordenada x del vector director para el barrido" << endl <<
                               "7: coordenada y del vector director para el barrido" << endl <<
                               "8: coordenada z del vector director para el barrido" << endl;
    ply = new MallaPLY("../plys/beethoven.ply");
    revol = new MallaRevol("../plys/peon.ply",10);
    barrida = new MallaBarrida(0,0,1,5,"../plys/peon.ply");
  }
  else{
    ply = new MallaPLY(argv[1]);
    revol = new MallaRevol(argv[2],atoi(argv[3]));
    barrida = new MallaBarrida(atoi(argv[6]),atoi(argv[7]),atoi(argv[8]),atoi(argv[5]),argv[4]);
  }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


bool P2_FGE_PulsarTeclaNormal( unsigned char tecla ){
  bool usa = true ; // true si al acabar de procesar el evento resulta que es necesario redibujar
  switch (toupper(tecla))
  {
    case 'O' :
       p2_objeto_activo = (p2_objeto_activo+1)%3;
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
  else if(p2_objeto_activo == 2)
    barrida->visualizar(modo);
}
